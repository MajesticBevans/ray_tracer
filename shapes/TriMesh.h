/*
 * TriMesh.h
 *
 *
 */

#ifndef TRIMESH_H_
#define TRIMESH_H_

#include "math/geometry.h"
#include "core/RayHitStructs.h"
#include "core/Shape.h"

namespace rt{

class TriMesh: public Shape
{

public:

	//
	// Constructors
	//
	TriMesh();
	TriMesh(Vec3f v0, Vec3f v1, Vec3f v2, Material* material);
    TriMesh(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Material* material);

	~TriMesh();


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
};



} //namespace rt




#endif /* TRIMESH_H_ */
