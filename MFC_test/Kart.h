#pragma once
#include "Biod.h"
//#include "WayPoint.h"

class WayPoint;

class Kart : public Biod{
public:
	
	Vec3 dir;
	Vec3 Speed;
	float m_KartSize = 2;
	float currSpeed = 0;
	float maxSpeed;
	float FrictionDrag = 0.95;
	WayPoint * startWP;
	WayPoint * currWP;
	//WayPoint * nextWP;
	void Update();
	void setNextWP(WayPoint * next);
	void setStartWP(WayPoint * start);

	Kart(Vec3 Position, float maxSpeed, World * p_World);
};