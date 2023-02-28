/*
 * RayHitStructs.h
 */

#ifndef CORE_RAYHITSTRUCTS_H_
#define CORE_RAYHITSTRUCTS_H_

#include "math/geometry.h"

namespace rt{

/*
 * Ray structure definition
 */
enum RayType {PRIMARY, SECONDARY, SHADOW};

struct Ray
{	
	//
	// Ray constructors
	//
	Ray() {}

	Ray(Vec3f origin, Vec3f direction, RayType rayType, int bounce) : 
	origin(origin), direction(direction.normalize()), rayType(rayType), bounce(bounce) {}

	RayType rayType; //type of ray
	Vec3f origin; //origin of ray
	Vec3f direction; //direction of ray
	int bounce; //number of bounces before this ray was created
};


struct Hit
{
	//
	// Hit constructors
	//
	Hit() {}
	
	Hit(Vec3f point, float distance, Vec3f normal, Shape* shape) :
	point(point), distance(distance), normal(normal), shape(shape) {}

	Vec3f point; //point where ray hits a shape
	float distance; //distance ray travelled before hit
	Vec3f normal; //normal at hit point
	Shape* shape; //shape that the ray hit
};

}

#endif /* CORE_RAYHITSTRUCTS_H_ */
