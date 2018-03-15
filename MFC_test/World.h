#pragma once
struct Vec3 {
	union {
		float x, y, z = 0;
		float v[3];
	};
	Vec3() {
		x = 0; y = 0; z = 0;
	}
	Vec3(float xx, float yy, float zz) {
		x = xx; y = yy; z = zz;
	}
	Vec3 operator = (Vec3 other) {
		x = other.x; y = other.y; z = other.z;
		return *this;
	}
	Vec3 operator +=(Vec3 other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	Vec3 operator *(float f) {
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}
	Vec3 operator *=(float f) {
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}
	Vec3 operator /(float f) {
		x /= f;
		y /= f;
		z /= f;
		return *this;
	}
	Vec3 operator -(Vec3 other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	Vec3 operator +(Vec3 other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	void Normalize(Vec3 &vect) {
		float mag = 0;
		mag = vect.x * vect.x + vect.y * vect.y + vect.z * vect.z;
		mag = sqrt(mag);
		vect.x *= mag; vect.y *= mag; vect.z *= mag;
	}
	float Mag() {
		return sqrt(x*x + y*y + z*z);
	}
	//float
};
class World {
public:
	World();
	~World();
};

