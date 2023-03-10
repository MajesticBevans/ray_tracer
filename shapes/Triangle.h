/*
 * Triangle.h
 *
 *
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "math/geometry.h"
#include "core/RayHitStructs.h"
#include "core/Shape.h"

namespace rt{

class Triangle: public Shape
{

public:

	//
	// Constructors
	//
	Triangle();
	Triangle(Vec3f v0, Vec3f v1, Vec3f v2, Material* material);
    Triangle(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Material* material);

	~Triangle();


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
	Vec3f vertices[3];
	Vec3f edges[3];
	Vec3f normal;
	float d;
	bool clockwise;
	bool linear;
	Material* material;
};



} //namespace rt




#endif /* TRIANGLE_H_ */
