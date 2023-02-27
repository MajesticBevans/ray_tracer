/*
 * RayTracer.cpp
 *
 */
#include "RayTracer.h"


namespace rt{

class RayTracer
{

/**
 * Performs ray tracing to render a photorealistic scene
 *
 * @param camera the camera viewing the scene
 * @param scene the scene to render, including objects and lightsources
 * @param nbounces the number of bounces to consider for raytracing
 *
 * @return a pixel buffer containing pixel values in linear RGB format
 */
Vec3f* RayTracer::render(Camera* camera, Scene* scene, int nbounces)
{

	Vec3f* pixelbuffer=new Vec3f[camera->getWidth()*camera->getHeight()];

	scene->printScene();

	return pixelbuffer;

}

/**
 * Tonemaps the rendered image (conversion of linear RGB values [0-1] to low dynamic range [0-255]
 *
 * @param pixelbuffer the array of size width*height containing linear RGB pixel values
 *
 * @return the tonemapped image
 */
Vec3f* RayTracer::tonemap(Vec3f* pixelbuffer){

	pixelbuffer->x = fmodf((pixelbuffer->x * 255.0F),threshold);
	pixelbuffer->y = fmodf((pixelbuffer->y * 255.0F),threshold);
	pixelbuffer->z = fmodf((pixelbuffer->z * 255.0F),threshold);

	return pixelbuffer;
}

private:
	const float threshold = (float)200;
};



} //namespace rt


