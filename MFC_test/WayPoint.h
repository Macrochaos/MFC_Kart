#pragma once
#include "GameObject.h"
#include "World.h"

class WayPoint : public GameObject {
public:
	WayPoint();
	~WayPoint();
	WayPoint(Vec2 & Poss, bool is_StartLine, Vec2 & m_assistDir);
	WayPoint(Vec2 & Poss, WayPoint * nextWP, bool is_StartLine, Vec2 & m_assistDir);

	void Update();

	void SetNext_WayPoint(WayPoint * nextWP);
	void SetPos(Vec2 & position);
	void SetPos(const int xx, const int yy);
	void SetWorld(World * ZA_Waruldo);

	float m_pathSize;
	unsigned long m_WPcolor;
	bool m_is_StartLine;
	WayPoint * m_nextWP;
	Vec2 nextWPDirNorm;
	Vec2 m_assistDir;
	
};

