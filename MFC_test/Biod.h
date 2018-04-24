#pragma once
#include "GameObject.h"
class Biod : public GameObject {
public:

	// convert to vec3 from void
	void Seek(Vec3 target, Vec3 spd_out ,float scaling);
	void Flee(Vec3 target, Vec3 spd_out, float scaling);
	void Arrive(Vec3 target, Vec3 spd_out, float scaling);
	void Wander(Vec3 target, Vec3 spd_out, float scaling);
	void Follow_Path(Vec3 target, Vec3 spd_out, float scaling);

	virtual void Update() = 0;
	Biod();
	~Biod();
};

