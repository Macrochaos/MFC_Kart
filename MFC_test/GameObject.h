#pragma once
//#include "World.h"
struct Vec2 {
	union {
		struct {
			float x; 
			float y; 
		};
	};
	Vec2() {
		x = 0; y = 0;
	}
	Vec2(const float xx, const float yy) {
		x = xx; y = yy;
	}
	Vec2& operator = (const Vec2 & other) {
		x = other.x;
		y = other.y;
		return *this;
	}
	Vec2& operator +=(const Vec2 & other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	Vec2 operator *(const float & f) {
		Vec2 res = *this;
		res.x *= f;
		res.y *= f;
		return res;
	}
	Vec2& operator *=(const float & f) {
		x *= f;
		y *= f;
		return *this;
	}
	Vec2 operator /(const float & f) {
		Vec2 res = *this;
		res.x /= f;
		res.y /= f;
		return res;
	}
	Vec2 operator -(const Vec2 & other) {
		Vec2 res = *this;
		res.x -= other.x;
		res.y -= other.y;
		return res;
	}
	Vec2 operator +(const Vec2 & other) {
		Vec2 res = *this;
		res.x += other.x;
		res.y += other.y;
		return res;
	}
	void Normalize() {
		float mag = 0;
		mag = (x * x) + (y * y);
		mag = sqrt(mag);
		x /= mag; y /= mag;
	}
	Vec2 getNormalized(const Vec2 & vect) {
		float mag = 0;
		Vec2 res = vect;
		mag = res.x * res.x + res.y * res.y;
		mag = sqrt(mag);
		res.x *= mag; res.y *= mag;
		return res;
	}
	float Mag() {
		return sqrt((x * x) + (y * y));
	}
	Vec2 getDir() {
		Vec2 dirdir = *this;
		getNormalized(dirdir);
		return dirdir;
	}
	float getDist(Vec2 & other) {
		Vec2 res;
		return (other - res).Mag();
	}
};

class World;

class GameObject
{
public:
	World * g_ZA_Waruldo;
	Vec2 Pos;
	//GameObject * m_objective;

	virtual void Update() = 0;
	//void SetColorRGBA(Vec2 color);
	GameObject();
	~GameObject();
};

