#pragma once
#include "Biod.h"
//#include "WayPoint.h"

class WayPoint;

class Kart : public Biod{
public:

	//Vec2 Pos;
	Vec2 m_Speed;
	float m_mass;
	float m_KartSize;
	float m_maxm_Speed;
	unsigned int m_nKartLaps;
	WayPoint * m_prevWP;
	WayPoint * m_currWP;

	Vec2 m_steering;

	unsigned long m_color;
	void Update();
	void setNextWP(WayPoint * next);
	void setm_prevWP(WayPoint * last);
	void setm_Speed(const Vec2 spd);
	Vec2 KartCollisionAvoidance();
	Vec2 StayOnPath(Vec2 & target);

	Kart(Vec2 & Position, float m_maxm_Speed, float mass, World * p_World);
	Kart(const Kart & otherK);
};