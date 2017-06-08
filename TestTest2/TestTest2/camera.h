#pragma once


#include<SDL.h>
#include <iostream>
#include<cmath>


#include<gl\glew.h>
#include<GL\GL.h>
#include<GL\GLU.h>

#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>

#include "vector3d.h"


class camera
{

	//all functions explained in .cpp

	vector3d loc;
	float camYaw;
	float camPitch;
	float speed;
	float mousespeed;
	bool mi;
	void lockCamera();
	void moveCamera(const float& dir);
	void moveCameraUp(const float& dir);
public:
	camera();
	camera(const vector3d& loc);
	camera(const vector3d& loc, const float& yaw, const float& pitch);
	camera(const vector3d& loc, const float& yaw, const float& pitch, const float& sp, const float& ms);
	void control();
	void update();

	vector3d getLocation();
	
	void setLocation(const vector3d& newcoord);
	
	void mouseIn();
	void mouseOut();



};

