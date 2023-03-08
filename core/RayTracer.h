/*
 * RayTracer.h
 *
 */
#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include "math/geometry.h"

#include "Camera.h"
#include "Scene.h"
#include "RayHitStructs.h"

namespace rt
{
/*
 * Raytracer class declaration
 */
class RayTracer 
{
public:

	RayTracer();

	static Vec3f* render(Camera* camera, Scene* scene, int nbounces);
	static Vec3f* tonemap(Vec3f* pixelbuffer, int width, int height);

private:
	static Vec3f shootRay(Ray ray, Scene* scene, int nbounces);
	static bool shootShadowRay(Hit* hit, Scene* scene);
	static Vec3f getDiffuseRGB(Hit* hit, Scene* scene);
	static Vec3f getSpecularRGB(Hit* hit, Scene* scene, Vec3f v);
};

} //namespace rt



#endif /* RAYTRACER_H_ */

