#include "collision.h"


//makes collision sphere using proper maths (checks radius of one object if it comes into contact with the radius of another, is fo you have collision)
bool collision::spheresphere(vector3d& c1, float r1, vector3d c2, float r2)
{
	float dist = pointdistance(c1, c2);
	if (dist <= (r1 + r2)*(r1 + r2))
	{
		float a = sqrt(dist) - (r1 + r2);
		vector3d vec(c2.x - c1.x, c2.y - c1.y, c2.z - c1.z);  //c2-c1
		float len = sqrt((vec.x*vec.x + vec.y*vec.y + vec.z*vec.z));
		vec.x /= len;
		vec.y /= len;
		vec.z /= len;
		c1.x = c1.x + vec.x*a;
		c1.y = c1.y + vec.y*a;
		c1.z = c1.z + vec.z*a;
		return 1;
	}
	return 0;
}


float collision::pointdistance(vector3d c1, vector3d c2)
{
	vector3d vec(c2.x - c1.x, c2.y - c1.y, c2.z - c1.z);
	return (vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}