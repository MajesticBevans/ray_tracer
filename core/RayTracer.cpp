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

		for (int j = 0; j < camera->getHeight(); ++j)
		{
			for (int i = 0; i < camera->getWidth(); ++i)
			{
				float u = (float)i / (float)(camera->getWidth() - 1);
				float v = (float)j / (float)(camera->getHeight() - 1);
				Vec3f pixelPos = camera->getPixelPos(u, v);
				//printf("(%f, %f, %f)\n", pixelPos.x, pixelPos.y, pixelPos.z);
				Vec3f direction = (pixelPos - camera->getPos()).normalize();
				pixelbuffer[j * camera->getWidth() + i] = shootRay(Ray(camera->getPos(), direction, RayType::PRIMARY, 0), scene, nbounces);
			}
		}

		return pixelbuffer;

	}

	Vec3f RayTracer::shootRay(Ray ray, Scene* scene, int nbounces)
	{
		Vec3f* closestHitPoint = new Vec3f();
		Hit* closestHit = new Hit();

		for (auto shape : scene->getShapes())
		{
			Hit h = shape->intersect(ray);

			if (h.isHit && (!closestHit->isHit || ray.origin.distanceTo(h.point) < ray.origin.distanceTo(closestHit->point)))
			{
				*closestHit = h;
				*closestHitPoint = h.point;
			}
		}

		if (!closestHit->isHit)
		{
			delete closestHit;
			delete closestHitPoint;
			return scene->getBackgroundColour();
		}

		Vec3f diffuse = getDiffuseRGB(closestHit, scene);

		return diffuse;
	}

	Vec3f RayTracer::getDiffuseRGB(Hit* hit, Scene* scene)
	{
		Vec3f returnColour = Vec3f();

		for (auto lightSource : scene->getLights())
		{
			Vec3f l = (lightSource->getPos() - hit->point).normalize();
			returnColour += hit->material->getDiffuse() * lightSource->getId() * l.dotProduct(hit->normal);
		}
		return returnColour;
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


