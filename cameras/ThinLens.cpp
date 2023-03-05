/*
 * ThinLens.cpp
 *
 *
 */
#include <iostream>

#include "ThinLens.h"

namespace rt
{
	//
	// ThinLens constructors
	//
	
	ThinLens::ThinLens() {}

	ThinLens::ThinLens(int width, int height, int fov, Vec3f pos, Vec3f lookat, Vec3f up) :
	Camera(width, height, fov, pos, lookat, up)
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
	void ThinLens::printCamera()
	{
		printf("I am a thin lens camera at position (%f, %f, %f)\n", pos.x, pos.y, pos.z);
		printf("width: %dpx, height: %dpx, fov:%d \n", width, height, fov);
	}

	Vec3f ThinLens::getPixelPos(float u, float v) { return Vec3f(); }

} //namespace rt
