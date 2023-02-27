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
		printf("I am a pinhole camera at position %d \n", pos);
		printf("width: %dpx, height: %dpx, fov:%d \n", width, height, fov);
	}

	//
	// Pinhold destructor
	//
	Pinhole::~Pinhole()
	{
		// REMEMBER TO DELETE DYNAMICALLY ALLOCATED MEMORY!!!!
	}
} //namespace rt

