/*
 * Sphere.cpp
 *
 *
 */
#include "Sphere.h"


namespace rt
{

class Sphere: public Shape
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

	void printShape()
	{
		printf("I am a Sphere ");
		if (this->id.size() > 0) { printf("called %d ", this->id); }
		printf("at position %d!\n", this->center);
      	printf("radius: %d\n", this->radius);
	}

	private:
	std::string id;
	Vec3f center;
	float radius;
};
} //namespace rt


