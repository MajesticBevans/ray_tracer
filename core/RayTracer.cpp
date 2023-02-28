/*
 * RayTracer.cpp
 *
 */
#include "RayTracer.h"


namespace rt
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

		Vec3f* pixelbuffer = new Vec3f[camera->getWidth()*camera->getHeight()];
		Ray* primaries = new Ray[camera->getWidth()*camera->getHeight()];

		for (int j = 0; j < camera->getHeight(); ++j)
		{
			for (int i = 0; i < camera->getWidth(); ++i)
			{
				float u = (float)i / (float)(camera->getWidth() - 1);
				float v = (float)j / (float)(camera->getHeight() - 1);
				Vec3f pixelPos = camera->getPixelPos(u, v);
				Vec3f direction = (pixelPos - camera->getPos()).normalize();
				primaries[j * camera->getWidth() + i] = Ray(camera->getPos(), direction, RayType::PRIMARY, 0);
			}
		}

		delete primaries;
		return pixelbuffer;

	}

	/**
	 * Tonemaps the rendered image (conversion of linear RGB values [0-1] to low dynamic range [0-255]
	 *
	 * @param pixelbuffer the array of size width*height containing linear RGB pixel values
	 *
	 * @return the tonemapped image
	 */
	Vec3f* RayTracer::tonemap(Vec3f* pixelbuffer)
	{
		pixelbuffer->x = pixelbuffer->x * 255.0F > 200.0F ? 200.0F : pixelbuffer->x * 255.0F;
		pixelbuffer->y = pixelbuffer->y * 255.0F > 200.0F ? 200.0F : pixelbuffer->y * 255.0F;
		pixelbuffer->z = pixelbuffer->z * 255.0F > 200.0F ? 200.0F : pixelbuffer->z * 255.0F;

		return pixelbuffer;
	}


} //namespace rt


