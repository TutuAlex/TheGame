#pragma once
#include<SDL.h>



#include<GL\glew.h>
#include<GL\GL.h>
#include<SDL_image.h>


#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#include"vector3d.h"

#ifndef OBJLOADER_H
#define OBJLOADER_H


//This structure is used to store every property of a face
struct face {
	int facenum;    //the number of the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it), it's used for the normal vectors
	bool four;              //.boolean for deciting if a face is a triangle or a quad. if true, than it's a quad else it's a triangle
	int faces[4];   //indexes for every vertex, which makes the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it)
	int texcoord[4];        //indexes for every texture coorinate that is in the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it)
	int mat;                                        //the index for the material, which is used by the face
	face(int facen, int f1, int f2, int f3, int t1, int t2, int t3, int material);        //constuctor for triangle
	face(int facen, int f1, int f2, int f3, int f4, int t1, int t2, int t3, int t4, int material);  //constructor for quad
};

//this is a structure, which contain one material
struct material {
	std::string name;       //the name of the material
	float alpha, ns, ni;      //some property, alpha, shininess, and another one which is not used, but is necessairy to read the file. 
	float dif[3], amb[3], spec[3];    //the color property (diffuse, ambient, specular)
	int illum;      //illum - we do not use it atm
	int texture;    //the id for the texture, if there is no texture then return -1
	material(const char* na, float al, float n, float ni2, float* d, float* a, float* s, int i, int t); // constructor for the material
};

//texture coorinate (UV vector3d), 
struct texcoord {
	float u, v;
	texcoord(float a, float b); //constructor
};

//the main class for the object loader
class objloader {
	std::vector<std::string*> coord;        //every line of code from the obj file
	std::vector<vector3d*> vertex;        //all vertexes
	std::vector<face*> faces;               //all faces
	std::vector<vector3d*> normals;       //all normal vectors
	std::vector<unsigned int> texture;      //the id for all the textures (so we can delete the textures after use it)
	std::vector<unsigned int> lists;        //the id for all lists (so we can delete the lists after use it)
	std::vector<material*> materials;       //all materials
	
	std::vector<texcoord*> texturevector3d; //all texture coorinate (UV vector3d)
	std::vector<vector3d*> vertexnormals;
	bool ismaterial, isnormals, istexture, isvertexnormal;    
	unsigned int loadTexture(const char* filename); //private load texture function
	void clean();   //free all of the used memory

	void smoothnormals();


public:
	objloader();      //constructor
	~objloader();   //deconstruct the textures and lists
	int load(const char* filename); //the main model load function
};



#endif