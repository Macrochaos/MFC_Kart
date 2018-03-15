#pragma once
class Kart {
public:
	Vec3 Pos;
	Vec3 dir;
	float currSpeed;
	float maxSpeed;
	WayPoint * startWP;

	Kart(Vec3 Pos);
};