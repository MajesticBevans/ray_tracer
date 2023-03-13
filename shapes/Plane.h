/*
 * Plane.h
 *
 *
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "math/geometry.h"
#include "core/RayHitStructs.h"
#include "core/Shape.h"

namespace rt{

class Plane: public Shape
{

public:

	//
	// Constructors
	//
	Plane();
	Plane(Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3, Material* material);
    Plane(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3, Material* material);

	~Plane();


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//
	
	Hit intersect(Ray ray);

	void printShape();

	//
	// Getters and Setters
	//

	Vec3f* getVertices();

    std::string getID();

private:
    std::string id;
	Vec3f vertices[4];
	Vec3f edges[4];
	Material* material;
	Vec3f normal;
	float d;
	bool linear;
};



} //namespace rt




#endif /* PLANE_H_ */
