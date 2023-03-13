/*
 * Plane.cpp
 *
 *
 */

#include "shapes/Plane.h"

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

        normal = (v1 - v0).crossProduct(v2 - v0).normalize();
        d = -normal.dotProduct(v0);
    }
    Plane::Plane(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Vec3f v3, Material* material)
    {
        this->id = id;
        this->vertices[0] = v0;
        this->vertices[1] = v1;
        this->vertices[2] = v2;
        this->vertices[3] = v3;

        this->material = material;

        normal = ((v1 - v0).crossProduct(v2 - v0)).normalize();
        d = -normal.dotProduct(v0);
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
        float normalDotDirection = normal.dotProduct(ray.direction);
        
        // ray is parallel to plane, no intersection
        if (normalDotDirection == 0) { return Hit(); }

        float t = -(normal.dotProduct(ray.origin) + d) / normalDotDirection;

        // intersection is behind ray origin
        if (t < 0) { return Hit(); }

        Vec3f intersection = ray.origin + t * ray.direction;

        // check if intersection is inside the plane
        bool isInside = true;
        for (int i = 0; i < 4; i++)
        {
            Vec3f edge1 = vertices[(i + 1) % 4] - vertices[i];
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
