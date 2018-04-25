#include "stdafx.h"
#include "Kart.h"
#include "World.h"
Kart::Kart(Vec2 & Position, float maxSpd, float mass, World * p_World) {
	KPos = Position;
	maxSpeed = maxSpd;
	if (maxSpeed < 1 || maxSpeed > 20) {
		maxSpeed = 1;
	}
	g_ZA_Waruldo = p_World;
	currWP = nullptr;
	m_mass = 1 / mass*5;
}
Kart::Kart(const Kart & otherK) {
	KPos = otherK.KPos;
	Speed = otherK.Speed;
	maxSpeed = otherK.maxSpeed;
	startWP = otherK.startWP;
	currWP = otherK.currWP;
	m_mass = otherK.m_mass;
}
void Kart::Update() {
	Vec2 steering;
	Pos = KPos;
	// mass
	// add all force then truncate if > maxSpeed
	// dir becomes new speed
	//speed = (dir + steering) * maxSpeed;

	/////////////////////////////////////////////////
	////////////// Steering Behaivours //////////////
	/////////////////////////////////////////////////
	if (currWP != nullptr) {
		steering += Seek(currWP->Pos, 0.1);
		steering += KartCollisionAvoidance();
	}
	//////////////////////////////////////////////
	////////////// Truncating speed //////////////
	//////////////////////////////////////////////
	if (steering.Mag() > maxSpeed) {
		steering.Normalize();
		steering*maxSpeed;
	}
	Speed += (steering * 0.016);
	if (Speed.Mag() > maxSpeed) {
		Speed.Normalize();
		Speed*maxSpeed;
	}
	//////////////////////////////////////////////
	////////////// Position changes //////////////
	//////////////////////////////////////////////
	KPos =  KPos + Speed * m_mass;
	Speed = steering;
	/////////////////////////////////////////////
	////////////// Waypoint Switch //////////////
	/////////////////////////////////////////////
	if ((KPos - currWP->Pos).Mag() < 12)
		currWP = currWP->m_nextWP;
}

void Kart::setNextWP(WayPoint * next) {
	currWP = next;
}
void Kart::setStartWP(WayPoint * start) {
	startWP = start;
}
Vec2 Kart::KartCollisionAvoidance() {
	/////////////////////////////////////////////////
	////////////// Colission detection //////////////
	/////////////////////////////////////////////////
	Vec2 avoid;
	for (int i = 0; i < g_ZA_Waruldo->m_vKart.size(); ++i) {
		if ((g_ZA_Waruldo->m_vKart[i]->KPos - KPos).Mag() <= m_KartSize) {
			if(g_ZA_Waruldo->m_vKart[i]!=this)
				avoid += (KPos - g_ZA_Waruldo->m_vKart[i]->KPos) * (maxSpeed * 100);
		}
	}
	return avoid;
}
