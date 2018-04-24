#pragma once
#include "Biod.h"
//#include "WayPoint.h"

class WayPoint;

class Kart : public Biod{
public:

	Vec2 KPos;
	Vec2 Speed;
	float m_mass;
	float m_KartSize = 10;
	float maxSpeed;
	WayPoint * startWP;
	WayPoint * currWP;
	//WayPoint * nextWP;
	void Update();
	void setNextWP(WayPoint * next);
	void setStartWP(WayPoint * start);
	Vec2 KartCollisionAvoidance();

	Kart(Vec2 & Position, float maxSpeed, float mass, World * p_World);
	Kart(const Kart & otherK);
};