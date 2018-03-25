#pragma once
#include "Biod.h"
#include "WayPoint.h"

class Kart : public Biod{
public:
	
	Vec3 dir;
	Vec3 Speed;
	float currSpeed = 0;
	float maxSpeed;
	const float FrictionDrag = 0.95;
	WayPoint * startWP;
	WayPoint * currWP;
	WayPoint * nextWP;
	void Update();

	Kart(Vec3 Position, float maxSpeed, Vec3 color, World * p_World);
};