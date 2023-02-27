/*
 * Triangle.cpp
 *
 *
 */

#include "Triangle.h"

namespace rt{

class Triangle: public Shape
{

public:

	//
	// Constructors
	//
	Triangle();
	Triangle(){};
	Triangle(Vec3f v0, Vec3f v1, Vec3f v2, Material* material)
    {
        this->id = "";
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
    }
    Triangle(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Material* material)
    {
        this->id = id;
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
    }

	~Triangle();


	//
	// Functions that need to be implemented, since Sphere is a subclass of Shape
	//
	Hit intersect(Ray ray);

	void printShape()
	{
		printf("I am a Triangle ");
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
