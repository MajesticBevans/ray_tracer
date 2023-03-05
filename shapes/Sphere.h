/*
 * Sphere.h
 *
 *
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "math/geometry.h"
#include "core/Shape.h"

namespace rt{

class Sphere: public Shape
{

public:

	//
	// Constructors
	//
	Sphere(Vec3f center, float radius, Material* material);
	Sphere(std::string id, Vec3f center, float radius, Material* material);

	~Sphere();


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//
	Hit intersect(Ray ray);

	void printShape();

	//
	// Getters and Setters
	//

	Vec3f getCenter()
	{
		return center;
	}

	float getRadius()
	{
		return radius;
	}

private:
	std::string id;
	Vec3f center;
	float radius;
};



} //namespace rt




#endif /* SPHERE_H_ */
