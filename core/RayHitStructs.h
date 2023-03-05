/*
 * RayHitStructs.h
 */
#ifndef CORE_RAYHITSTRUCTS_H_
#define CORE_RAYHITSTRUCTS_H_

#include "math/geometry.h"
#include "Material.h"

namespace rt
{

enum RayType {PRIMARY, SECONDARY, SHADOW};

struct Ray
{	
	RayType rayType; //type of ray
	Vec3f origin; //origin of ray
	Vec3f direction; //direction of ray
	int bounce; //number of bounces before this ray was created

	//
	// Ray constructors
	//

	Ray() {}

	Ray(Vec3f origin, Vec3f direction, RayType rayType, int bounce) : 
	origin(origin), direction(direction.normalize()), rayType(rayType), bounce(bounce) {}
};


struct Hit
{
	Vec3f point; //point where ray hits a shape
	float distance; //distance ray travelled before hit
	Vec3f normal; //normal at hit point
	Material* material; //material of the shape hit
	bool isHit;


	//
	// Hit constructors
	//

	Hit() { isHit = false; }
	
	Hit(Vec3f point, float distance, Vec3f normal, Material* material) :
	point(point), distance(distance), normal(normal), material(material) { isHit = true; }
};

}

#endif /* CORE_RAYHITSTRUCTS_H_ */
