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
		this->material = material;

		vertices[0] = v0;
		vertices[1] = v1;
		vertices[2] = v2;

		normal = (v1 - v0).crossProduct(v2 - v0);

		if (normal.length() == 0.0f) 
		{
			printf("err: triangle '%s' is a line\n", id.c_str());
			linear = true;
			return;
		}

		normal = ((v1 - v0).crossProduct(v2 - v0)).normalize();
        d = -normal.dotProduct(v0);
    }

	Triangle::Triangle(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Material* material)
	{
		this->id = id;
		this->material = material;

		vertices[0] = v0;
		vertices[1] = v1;
		vertices[2] = v2;

		normal = (v1 - v0).crossProduct(v2 - v0);

		if (normal.length() == 0.0f) 
		{
			printf("err: triangle '%s' is a line\n", id.c_str());
			linear = true;
			return;
		}

		normal = ((v1 - v0).crossProduct(v2 - v0)).normalize();
        d = -normal.dotProduct(v0);
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
		float normalDotDirection = normal.dotProduct(ray.direction);
        
        // ray is parallel to plane, no intersection
        if (normalDotDirection == 0) { return Hit(); }

        float t = -(normal.dotProduct(ray.origin) + d) / normalDotDirection;

        // intersection with plane is behind ray origin
        if (t < 0) { return Hit(); }

        Vec3f intersection = ray.origin + t * ray.direction;

        // check if intersection is inside the triangle
        bool isInside = true;
        for (int i = 0; i < 3; i++)
        {
            Vec3f edge1 = vertices[(i + 1) % 3] - vertices[i];
            Vec3f edge2 = intersection - vertices[i];
            Vec3f crossProduct = edge1.crossProduct(edge2);

            if (normal.dotProduct(crossProduct) < 0)
            {
                isInside = false;
                break;
            }
        }

        if (!isInside) { return Hit(); }
        Vec3f tempNormal;
        if (normalDotDirection > 0)
        {
            tempNormal = normal * -1.0F;
        }
        else
        {
            tempNormal = Vec3f(normal);
        }

        return Hit(intersection, t, tempNormal.normalize(), material);
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
