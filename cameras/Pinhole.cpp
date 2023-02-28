/*
 * Pinhole.cpp
 *
 *
 */
#include <iostream>
#include <cmath>

#include "Pinhole.h"

using namespace std;

namespace rt
{
	//
	// Pinhole constructor
	//
	Pinhole::Pinhole(int width, int height, int fov, Vec3f pos, Vec3f lookat, Vec3f up) : 
	Camera(width, height, fov, pos, lookat, up)
	{
		this->width = width;
		this->height = height;
		this->fov = fov;
		this->pos = pos;
		this->lookat = lookat.normalize();
		this->up = up.normalize();

		float aspect_ratio = (float)this->width / (float)this->height;
		float fov_radians = fov * (/*PI*/ acos(-1) / 180.0F);
		float focal_length = (this->pos.dotProduct(this->lookat) / 2.0F) / tan(fov_radians / 2.0F);

		image_height = 2.0F * tan(fov_radians / 2.0F);
		image_width = image_height * aspect_ratio;
		right = this->up.crossProduct(this->lookat).normalize();
		this->up = this->lookat.crossProduct(right).normalize(); // re-assign up vector to ensure orthogonal with lookat vector
		image_centre = this->pos + focal_length * this->lookat;
		image_bottom_left = this->image_centre - (image_width * right) / 2.0F - (image_height * this->up) / 2.0F;
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

	Vec3f Pinhole::getPixelPos(float u, float v)
	{
		return image_bottom_left + (u * image_width * right) + (v * image_height * up); 
	}

	float Pinhole::getImageHeight() { return image_height; }
	float Pinhole::getImageWidth() { return image_width; }
	Vec3f Pinhole::getRight() { return right; }
	Vec3f Pinhole::getImageCentre() { return image_centre; }
	Vec3f Pinhole::getImageBottomLeft() { return image_bottom_left; }

} //namespace rt

