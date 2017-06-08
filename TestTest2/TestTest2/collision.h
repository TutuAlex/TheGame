#pragma once
#include"objloader.h"
#include"vector3d.h"

#ifndef  COLLISION_H
#define COLLISION_H


class collision
{
public:
	


//collision spheres
static	bool spheresphere(vector3d& c1, float r1, vector3d c2, float r2);
static float pointdistance(vector3d c1, vector3d c2);


	
};
















#endif // ! COLLISION_H