#include "vector3d.h"
#ifndef COLLISIONSPHERE_H
#define COLLISIONSPHERE_H

class collisionsphere {
public:
	float r;
	vector3d center;
	collisionsphere();
	collisionsphere(vector3d& vec, float rad);
	
};

#endif
