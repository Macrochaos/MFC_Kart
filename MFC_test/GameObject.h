#pragma once
#include "World.h"
struct Vec3 {
	union {
		struct {
			float x = 0; 
			float y = 0; 
		};
		float v[2];
	};
	Vec3() {
		x = 0; y = 0;
	}
	Vec3(float xx, float yy) {
		x = xx; y = yy;
	}
	Vec3 operator = (Vec3 other) {
		x = other.x; y = other.y;
		return *this;
	}
	Vec3 operator +=(Vec3 other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	Vec3 operator *(float f) {
		x = x * f;
		y = y * f;
		return *this;
	}
	Vec3 operator *=(float f) {
		x *= f;
		y *= f;
		return *this;
	}
	Vec3 operator /(float f) {
		x /= f;
		y /= f;
		return *this;
	}
	Vec3 operator -(Vec3 other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}
	Vec3 operator +(Vec3 other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	void Normalize() {
		float mag = 0;
		mag = (x * x) + (y * y);
		mag = sqrt(mag);
		x *= mag; y *= mag;
	}
	Vec3 getNormalized(Vec3 &vect) {
		float mag = 0;
		mag = vect.x * vect.x + vect.y * vect.y;
		mag = sqrt(mag);
		vect.x *= mag; vect.y *= mag;
		return vect;
	}
	float Mag() {
		return sqrt((x * x) + (y * y));
	}
	Vec3 getDir() {
		Vec3 dirdir = *this;
		getNormalized(dirdir);
		return dirdir;
	}
	float getDist(Vec3 other) {
		return (other - *this).Mag;
	}
};

class GameObject
{
public:
	World * g_ZA_Waruldo;
	Vec3 color_RGB;
	Vec3 Pos;
	GameObject * m_objective;

	virtual void Update() = 0;
	GameObject();
	~GameObject();
};

