#include "camera.h"


//define pi
#ifndef M_PI
#define M_PI 3.1415926535
#endif

//camera constructors
camera::camera()
{
	loc.x = 0.0;
	loc.y = 0.0;
	loc.z = 0.0;
	camYaw = 0.0;
	camPitch = 0.0;
	speed = 0.2;
	mousespeed = 0.2;
	mi = false;
}
camera::camera(const vector3d& l)
{
	loc = l;
	camYaw = 0.0;
	camPitch = 0.0;
	speed = 0.3;
	mousespeed = 0.3;
	mi = false;
}
camera::camera(const vector3d& l, const float& yaw, const float& pitch)
{
	loc = l;
	camYaw = yaw;
	camPitch = pitch;
	speed = 0.3;
	mousespeed = 0.3;
	mi = false;
}
camera::camera(const vector3d& l, const float& yaw, const float& pitch, const float& sp, const float& ms)
{
	loc = l;
	camYaw = yaw;
	camPitch = pitch;
	speed = sp;
	mousespeed = ms;
	mi = false;
}



//locks camera so that we cannot move more than 90 degrees up or down
void camera::lockCamera()
{
	if (camPitch>90)
		camPitch = 90;
	if (camPitch<-90)
		camPitch = -90;
	if (camYaw<0.0)
		camYaw += 360.0;
	if (camYaw>360.0)
		camYaw -= 360;
}

//moves camera left and right
void camera::moveCamera(const float &dir)
{
	float rad = (camYaw + dir)*M_PI / 180.0;
	loc.x -= sin(rad)*speed;
	loc.z -= cos(rad)*speed;
}


//moves camera up and down
void camera::moveCameraUp(const float& dir)
{
	float rad = (camPitch + dir)*M_PI / 180.0;
	loc.y += sin(rad)*speed;
}


//control the camera
void camera::control()
{
	if (mi)
	{

		int MidX = 320;
		int MidY = 240;
		SDL_ShowCursor(SDL_DISABLE);
		int tmpx, tmpy;
		SDL_GetMouseState(&tmpx, &tmpy);
		camYaw += mousespeed*(MidX - tmpx);
		camPitch += mousespeed*(MidY - tmpy);
		lockCamera();
		SDL_WarpMouse(MidX, MidY);
		Uint8* state = SDL_GetKeyState(NULL);
		if (state[SDLK_w])
		{
			moveCamera(0.0);
		}
		else if (state[SDLK_s])
		{
			moveCamera(180.0);
		}
		if (state[SDLK_a])
			moveCamera(90.0);
		else if (state[SDLK_d])
			moveCamera(270);
	}

	glRotatef(-camPitch, 1.0, 0.0, 0.0);
	glRotatef(-camYaw, 0.0, 1.0, 0.0);
}


//updates the camera in relation to the world (negative values ued cause in reality the camera creates an illusion. when we "move", everything else moves in the opposite direction, and it appears that we re moving
void camera::update()
{
	glTranslatef(-loc.x, -loc.y, -loc.z);
}

//gets our location
vector3d camera::getLocation()
{
	return loc;
}

//checks if mouse is in window
void camera::mouseIn()
{
	mi = true;
}


//checks if mouse is not in window
void camera::mouseOut()
{
	mi = false;
}

//sets the cameras location (in case of collision)
void camera::setLocation(const vector3d& newcoord)
{
	loc = newcoord;
}