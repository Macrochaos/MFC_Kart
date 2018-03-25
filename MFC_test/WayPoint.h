#pragma once
#include "GameObject.h"
#include "World.h"
class WayPoint : public GameObject {
public:
	
	World * g_ZA_Waruldo;
	bool m_is_StartLine;
	bool unused_b1;
	short unused_s1;
	WayPoint * m_nextWP;
	//WayPoint * m_prevWP;
	Vec3 nextWPDirNorm;
	Vec3 m_assistDir;

	WayPoint(Vec3 Poss, WayPoint * nextWP, bool is_StartLine, Vec3 m_assistDir);

};

