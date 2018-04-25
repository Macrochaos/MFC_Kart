#include "stdafx.h"
#include "Biod.h"
Biod::Biod() {

}
Biod::~Biod() {

}
// convert to Vec2 from void

Vec2 Biod::Seek(Vec2 & target, float scaling) {
	Vec2 Dir = (target - Pos);
	//Dir *= (scaling * FRAMESCALING);
	Dir *= scaling;
	return Dir;
}
Vec2 Biod::Flee(Vec2 & target, float scaling) {
	return Vec2();
}
Vec2 Biod::Arrive(Vec2 & target, float scaling) {
	return Vec2();
}
Vec2 Biod::Wander(Vec2 & target, float scaling) {
	return Vec2();
}
Vec2 Biod::Follow_Path(Vec2 & target, float scaling) {
	return Vec2();
}
