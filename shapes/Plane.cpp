/*
 * Plane.cpp
 *
 *
 */

#include "Plane.h"

namespace rt{

class Plane: public Shape
{

public:

	//
	// Constructors
	//
	Plane(){};
	Plane(Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3, Material* material)
    {
        this->id = "";
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
        this->vertices[3] = v3;
    }
    Plane(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3, Material* material)
    {
        this->id = id;
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
        this->vertices[3] = v3;
    }

	~Plane();


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//
	Hit intersect(Ray ray);

	void printShape()
	{
		printf("I am a Plane ");
		if (this->id.size() > 0) { printf("called %d \n", this->id); }
		printf("with vertices: %d", this->vertices);
	}

	//
	// Getters and Setters
	//

	Vec3f* getVertices()
    {
        return this->vertices;
    }

    std::string getID()
    {
        return this->id;
    }

private:
    std::string id;
	Vec3f vertices[4];
};



} //namespace rt
