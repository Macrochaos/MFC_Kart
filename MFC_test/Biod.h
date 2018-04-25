#pragma once
#include "GameObject.h"

class Biod : public GameObject {
public:

	// convert to Vec2 from void
	const float FRAMESCALING = 0.016;
	Vec2 Seek(Vec2 & target, float scaling);
	Vec2 Flee(Vec2 & target,  float scaling);
	Vec2 Arrive(Vec2 & target,  float scaling);
	Vec2 Wander(Vec2 & target, float scaling);
	Vec2 Follow_Path(Vec2 & target, float scaling);

	virtual void Update() = 0;
	Biod();
	~Biod();
};

