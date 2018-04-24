#pragma once
#include "Kart.h"
#include "WayPoint.h"
#include <vector>

using std::vector;

class World {
public:
	vector<GameObject> m_vGO;
	vector<WayPoint*> m_vWP;
	vector<Kart*> m_vKart;

	
	unsigned int m_nWayPoints = 15;
	unsigned int m_nKarts = 20;
	void Update();
	World();
	~World();


};

