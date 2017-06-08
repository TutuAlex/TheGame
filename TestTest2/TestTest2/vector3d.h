#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include<iostream>
#include<cmath>

using namespace std;

//the vector class (atm it just generates 3 floats that ive elements their position in the world)
class vector3d {



public:


	//constructors
	float x, y, z;
	vector3d();
	vector3d(float a, float b);
	vector3d(float a, float b, float c);









	// ALL THE FUNCTIONS BELLOW ARE COMMENTED OUT DUE TO INACTIVITY. THEY MIGTH BE USED IN FURTHER DEVELOPMENT


	/*

	//get length of the vector with Pythagoras Formula
	float length();

	//get the lentgh of the vector and divide x y z with it (so to define a direction)
  //  void normalize();


	//change x y and z coordinates of the vector
	//void change(float a , float b , float c);

	//overloaded function
	void change(vector3d& vec);

	//these functions are not used ATS mut will prove usefull in further devleopment
	void changeX(float a);
	void changeY(float a);
    void changeZ(float a);

	//this will add the curent x y z to the current vectors x y z 
//	vector3d operator+(const vector3d& vec2);

//	vector3d operator-(const vector3d& vec2);

	//vector3d operator*(float num);

//	vector3d operator/(float num);


	

//	vector3d& operator+=(const vector3d& vec2);

	//vector3d& operator-=(const vector3d& vec2);

//	vector3d& operator*=(float num);

//	vector3d& operator/=(float num);



//	bool operator==(const vector3d vec2);
//	bool operator!=(const vector3d vec2);


	
	//friend std::ostream& operator<<(std::ostream& out, const vector3d& vec);

	*/

};














#endif VECTOR3D_H
