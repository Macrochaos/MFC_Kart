#include "stdafx.h"
#include "Biod.h"
Biod::Biod() {

}
Biod::~Biod() {

}
// convert to vec3 from void

void Biod::Seek(Vec3 target, Vec3 spd_out, float scaling) {
	Vec3 Dir = (target - Pos);
	Dir.Normalize();
	spd_out += (Dir*scaling);
	Pos += spd_out;
}
void Biod::Flee(Vec3 target, Vec3 spd_out, float scaling) {

}
void Biod::Arrive(Vec3 target, Vec3 spd_out, float scaling) {

}
void Biod::Wander(Vec3 target, Vec3 spd_out, float scaling) {

}
void Biod::Follow_Path(Vec3 target, Vec3 spd_out, float scaling) {

}
