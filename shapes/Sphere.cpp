/*
 * Sphere.cpp
 *
 *
 */
#include "Sphere.h"


namespace rt
{

	Sphere::Sphere(Vec3f center, float radius, Material* material)
	{
		this->id = "";
		this->center = center;
		this->radius = radius;
		this->material = material;
	}

	Sphere::Sphere(std::string id, Vec3f center, float radius, Material* material)
	{
		this->id = id;
		this->center = center;
		this->radius = radius;
		this->material = material;
	}

	Sphere::~Sphere()
	{
		// REMEMBER TO DELETE DYNAMICALLY ALLOCATED MEMORY
	}



	/**
	 * Computes whether a ray hit the specific instance of a sphere shape and returns the hit data
	 *
	 * @param ray cast ray to check for intersection with shape
	 *
	 * @return hit struct containing intersection information
	 *
	 */
	Hit Sphere::intersect(Ray ray)
	{

		Hit h;
		//-----------to be implemented -------------


		return h;

	}

	void Sphere::printShape()
	{
		printf("I am a Sphere ");
		if (this->id.size() > 0) { printf("called %s ", this->id.c_str()); }
		printf("at position (%f, %f, %f)!\n", this->center.x, this->center.y, this->center.z);
		printf("radius: %f\n", this->radius);
	}

} //namespace rt


