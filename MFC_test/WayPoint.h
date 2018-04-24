#pragma once
#include "GameObject.h"
#include "World.h"

class WayPoint : public GameObject {
public:
	WayPoint();
	~WayPoint();
	WayPoint(Vec3 Poss, bool is_StartLine, Vec3 m_assistDir);
	WayPoint(Vec3 Poss, WayPoint * nextWP, bool is_StartLine, Vec3 m_assistDir);

	//World * g_ZA_Waruldo;
	bool m_is_StartLine;
	void Update();

	void SetNext_WayPoint(WayPoint * nextWP);
	void SetPos(Vec3 position);
	void SetWorld(World * ZA_Waruldo);

	WayPoint * m_nextWP;
	//WayPoint * m_prevWP;
	Vec3 nextWPDirNorm;
	Vec3 m_assistDir;
	

};

