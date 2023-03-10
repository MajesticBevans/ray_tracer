/*
 * Pinhole.h
 *
 *
 */

#ifndef PINHOLE_H_
#define PINHOLE_H_

#include "core/Camera.h"

namespace rt{

class Pinhole:public Camera{
public:

	//
	// Constructors
	//
	Pinhole(int width, int height, int fov, Vec3f pos, Vec3f lookat, Vec3f up);

	//
	//Destructor
	//
	~Pinhole(){};

	//
	// print function (implementing abstract function of base class)
	//
	void printCamera();

	Vec3f getPixelPos(float u, float v);

	//
	// Getters and Setters
	//

	float getImageHeight();
	float getImageWidth();
	float getDistanceToPlane();
	Vec3f getRight();
	Vec3f getImageCentre();
	Vec3f getImageTopLeft();

private:
	float image_height;
	float image_width;
	float distanceToPlane;
	Vec3f right;
	Vec3f image_centre;
	Vec3f image_top_left;
};



} //namespace rt




#endif /* PINHOLE_H_ */
