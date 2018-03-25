#pragma once
#include "GameObject.h"
#include <vector>

using std::vector;

class World {
public:
	vector<GameObject> m_vGO;

	void Update();
	World();
	~World();


};

