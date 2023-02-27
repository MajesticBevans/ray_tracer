/*
 * TriMesh.cpp
 *
 *
 */

#include "TriMesh.h"

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

	void printShape()
    {
        printf("I am a TriMesh ");
		if (this->id.size() > 0) { printf("called %d \n", this->id); }
		printf("with vertices: %d", this->vertices);   
    }

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
