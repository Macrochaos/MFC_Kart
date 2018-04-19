#include "stdafx.h"
#include "Kart.h"
#include "World.h"
Kart::Kart(Vec3 Position, float maxSpd, World * p_World) {
	Pos = Position;
	maxSpeed = maxSpd;
	g_ZA_Waruldo = p_World;
}
void Kart::Update(){
	currSpeed = Speed.Mag();
	if (currSpeed > maxSpeed) {
		Speed.Normalize();
		Speed*maxSpeed;
		
	}
	else {
		Speed.Normalize();
		Speed*currSpeed;
		
	}
	if(currWP!=nullptr)
		Seek(currWP->Pos, Speed, 0.5);

	//Speed += currWP->m_assistDir;
	Speed *= FrictionDrag;
	Pos += Speed;
	for (int i = 0; i < g_ZA_Waruldo->m_vKart.size(); ++i) {
		if ((g_ZA_Waruldo->m_vKart[i].Pos - Pos).Mag() <= m_KartSize) {
			Speed += (g_ZA_Waruldo->m_vKart[i].Pos - Pos) * (maxSpeed * 0.5);
		}
	}
	if ((Pos - currWP->Pos).Mag() < 5)
		currWP = currWP->m_nextWP;
}

void Kart::setNextWP(WayPoint * next) {
	currWP = next;
}

void Kart::setStartWP(WayPoint * start) {
	startWP = start;
}
