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
		Vec3f originToCentre = (center - ray.origin).normalize();
		
		float distanceToPerpendicular = originToCentre.dotProduct(ray.direction);
		
		if (distanceToPerpendicular <= 0) { return Hit(); }
		
		float d2 = originToCentre.dotProduct(originToCentre) - distanceToPerpendicular * distanceToPerpendicular;
		
		if (d2 > radius * radius) { return Hit(); }
		
		float thc = sqrt(radius * radius - d2);
		float t0 = distanceToPerpendicular - thc;
		Vec3f intersectionPoint = ray.origin + ray.direction * t0;
		Vec3f normal = (intersectionPoint - center).normalize();
		
		return Hit(intersectionPoint, t0, normal, this->material);
	}

	void Sphere::printShape()
	{
		printf("I am a Sphere ");
		if (this->id.size() > 0) { printf("called %s ", this->id.c_str()); }
		printf("at position (%f, %f, %f)!\n", this->center.x, this->center.y, this->center.z);
		printf("radius: %f\n", this->radius);
	}

} //namespace rt


