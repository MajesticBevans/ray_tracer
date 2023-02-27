/*
 * Pinhole.cpp
 *
 *
 */
#include <iostream>

#include "Pinhole.h"



namespace rt
{
	//
	// Pinhole constructor (example)
	//
	Pinhole::Pinhole(int width, int height, int fov, Vec3f pos):Camera(width, height, fov, pos)
	{
		this->width = width;
		this->height = height;
		this->fov = fov;
		this->pos = pos;
	}


	/**
	 * Prints camera data
	 * this function implements the abstract function of the base Camera class
	 */
	void Pinhole::printCamera()
	{
		printf("I am a pinhole camera at position (%f, %f, %f)\n", pos.x, pos.y, pos.z);
		printf("width: %dpx, height: %dpx, fov:%d \n", width, height, fov);
	}
} //namespace rt

