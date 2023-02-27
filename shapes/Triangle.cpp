/*
 * Triangle.cpp
 *
 *
 */

#include "Triangle.h"

namespace rt
{
	//
	// Constructors
	//
	Triangle::Triangle(){}

	Triangle::Triangle(Vec3f v0, Vec3f v1, Vec3f v2, Material* material)
    {
        this->id = "";
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
		this->material = material;
    }

    Triangle::Triangle(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Material* material)
    {
        this->id = id;
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
		this->material = material;
    }

	Triangle::~Triangle()
	{
		// IMPLEMENT DESTRUCTOR
	}


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//
	Hit Triangle::intersect(Ray ray)
	{
		return Hit();
	}

	void Triangle::printShape()
	{
		printf("I am a Triangle ");
		if (this->id.size() > 0) { printf("called %s \n", this->id.c_str()); }
		printf("with vertices: (%f, %f, %f), (%f, %f, %f), (%f, %f, %f)",
		this->vertices[0].x, this->vertices[0].y, this->vertices[0].z,
        this->vertices[1].x, this->vertices[1].y, this->vertices[1].z,
        this->vertices[2].x, this->vertices[2].y, this->vertices[2].z);
	}

	//
	// Getters and Setters
	//

	Vec3f* Triangle::getVertices()
	{
		return this->vertices;
	}

    std::string Triangle::getID()
	{
		return this->id;
	}

} //namespace rt
