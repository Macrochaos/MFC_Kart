#pragma once
class WayPoint : public CDialog {
public:
	Vec3 Pos;
	bool is_StartLine;
	WayPoint * nextWP;
	WayPoint * prevWP;

	WayPoint(Vec3 Pos);

};

