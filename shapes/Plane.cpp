/*
 * Plane.cpp
 *
 *
 */

#include "Plane.h"

namespace rt
{
	//
	// Constructors
	//
	Plane::Plane(){};
	Plane::Plane(Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3, Material* material)
    {
        this->id = "";
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
        this->vertices[3] = v3;
        this->material = material;
    }
    Plane::Plane(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3, Material* material)
    {
        this->id = id;
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
        this->vertices[3] = v3;
        this->material = material;
    }

    //
    // Destructor
    //
	Plane::~Plane()
    {
        // DESTRUCTOR TO BE IMPLEMENTED
    }


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//
	Hit Plane::intersect(Ray ray)
    {
        return Hit();
    }

	void Plane::printShape()
	{
		printf("I am a Plane ");
		if (this->id.size() > 0) { printf("called %s \n", this->id.c_str()); }
		printf("with vertices: (%f, %f, %f), (%f, %f, %f), (%f, %f, %f), (%f, %f, %f)\n",
        this->vertices[0].x, this->vertices[0].y, this->vertices[0].z,
        this->vertices[1].x, this->vertices[1].y, this->vertices[1].z,
        this->vertices[2].x, this->vertices[2].y, this->vertices[2].z,
        this->vertices[3].x, this->vertices[3].y, this->vertices[3].z);
	}

	//
	// Getters and Setters
	//
    
	Vec3f* Plane::getVertices()
    {
        return this->vertices;
    }

    std::string Plane::getID()
    {
        return this->id;
    }
} //namespace rt
