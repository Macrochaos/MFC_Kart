#include"Kart.h"




Kart::Kart(Vec3 Position, float maxSpd, Vec3 color, World * p_World) {
	Pos = Position;
	maxSpeed = maxSpd;
	color_RGB = color;
	g_ZA_Waruldo = p_World;
}
void Kart::Update(){
	currSpeed = Speed.Mag();
	if (currSpeed > maxSpeed) {
		Speed.Normalize();
		Speed*maxSpeed;
		
	}
	else {
		Speed.Normalize();
		Speed*currSpeed;
		
	}
	Seek(currWP->Pos, Speed, 0.5);
	Speed *= FrictionDrag;
	Pos += Speed;
}