#include "collisionsphere.h"



collisionsphere::collisionsphere()
{
	//center.x = center.y = center.z = 0;
	r = 0;
}

collisionsphere::collisionsphere(vector3d& vec, float rad)
{
	center = vec;
	r = rad;
}
