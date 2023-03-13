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
		edges[0] = (v1 - v0);
		edges[1] = (v2 - v1);
		edges[2] = (v0 - v2);

		normal = edges[0].crossProduct(edges[2]);
		if (normal.length() == 0.0f) 
		{
			//printf("err: triangle '%s' is a line\n", id.c_str());
			linear = true;
			return;
		}

		Vec3f extraNormal = normal;
		extraNormal.normalize();

		Vec3f up(0.0f, 1.0f, 0.0f);
		Vec3f right(1.0f, 0.0f, 0.0f);

		Vec3f facing = extraNormal.crossProduct(up);

		if (facing.length() == 0.0f) 
		{
			facing = extraNormal.crossProduct(right);
		}

		if (facing.z > 0.0F)
		{
			clockwise = false;
			//printf("%s anti\n", id.c_str());
		}
		else
		{
			clockwise = true;
			//printf("%s clock\n", id.c_str());
		}

		d = -normal.dotProduct(vertices[0]);
    }

	Triangle::Triangle(std::string id, Vec3f v0, Vec3f v1, Vec3f v2, Material* material)
	{
		this->id = id;
		this->vertices[0] = v0;
		this->vertices[1] = v1;
		this->vertices[2] = v2;
		this->material = material;
		edges[0] = (v1 - v0);
		edges[1] = (v2 - v1);
		edges[2] = (v0 - v2);

		normal = edges[0].crossProduct(edges[2]);
		if (normal.length() == 0.0f) 
		{
			//printf("err: triangle '%s' is a line\n", id.c_str());
			linear = true;
			return;
		}

		Vec3f extraNormal = normal;
		extraNormal.normalize();

		Vec3f up(0.0f, 1.0f, 0.0f);
		Vec3f right(1.0f, 0.0f, 0.0f);

		Vec3f facing = extraNormal.crossProduct(up);

		if (facing.length() == 0.0f) 
		{
			facing = extraNormal.crossProduct(right);
		}

		if (facing.z > 0.0F)
		{
			clockwise = false;
			//printf("%s anti\n", id.c_str());
		}
		else
		{
			clockwise = true;
			//printf("%s clock\n", id.c_str());
		}

		d = -normal.dotProduct(vertices[0]);
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
		bool hitBack = false;
		// if triangle is a line, no intersection
		if (linear) { return Hit(); }
		float normalDotDirection = normal.dotProduct(ray.direction);

		// ray is parallel to triangle plane, no intersection
		if (normalDotDirection == 0) { return Hit(); }
		if (normalDotDirection > 0) 
		{ 
			hitBack = true; 
		}

		float t = (normal.dotProduct(ray.origin) + d) / normalDotDirection;

		// intersection is behind ray origin
		if (t < 0) { return Hit(); }

		Vec3f intersection = ray.origin + t * ray.direction;

		// check each edge
		int edgeCount = 0;
		for (int i = 0; i < 3; i++)
		{
			Vec3f vertToPoint = intersection - vertices[i];
			Vec3f perp = edges[i].crossProduct(vertToPoint);

			// intersection is on inside of edge
			if (normal.dotProduct(perp) <= 0) { edgeCount++; }
		}

		if (edgeCount == 3)
		{
			Vec3f tempNormal = hitBack ? -normal : normal;
			return Hit(intersection, t, tempNormal.normalize(), material);
		}
		else { return Hit(); }
		
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
