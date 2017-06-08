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

#include "objloader.h"

#ifndef FUNCTION_H
#define FUNCTION_H



//create skybox functions
void drawSkybox(float size);
void initskybox();
void killskybox();

//load textures function (here used to load the textures for the skybox)
unsigned int loadTexture(const char* filename);






#endif