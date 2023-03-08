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
				float distanceToPlane = camera->getPos().distanceTo(pixelPos);
				pixelbuffer[j * camera->getWidth() + i] = 
				shootRay(Ray(camera->getPos(), direction, RayType::PRIMARY, 0), scene, nbounces);
			}
		}

		return pixelbuffer;

	}

	Vec3f RayTracer::shootRay(Ray ray, Scene* scene, int nbounces)
	{
		Hit* closestHit = new Hit();

		for (auto shape : scene->getShapes())
		{
			Hit h = shape->intersect(ray);
			if (h.isHit && 
			(!closestHit->isHit || h.distance < closestHit->distance))
			{
				//printf("hit at (%f, %f, %f)\n", h.point.x, h.point.y, h.point.z);
				*closestHit = h;
			}
		}

		if (!closestHit->isHit)
		{
			delete closestHit;
			return scene->getBackgroundColour();
		}

		Vec3f finalColour = getDiffuseRGB(closestHit, scene) * closestHit->material->getKd() + 
							getSpecularRGB(closestHit, scene, ray.direction) * closestHit->material->getKs();
		delete closestHit;
		return finalColour;
	}

	Vec3f RayTracer::getDiffuseRGB(Hit* hit, Scene* scene)
	{
		Vec3f returnColour = Vec3f();

		for (auto lightSource : scene->getLights())
		{
			Vec3f l = (lightSource->getPos() - hit->point).normalize();
			float dot_prod = fmaxf(l.dotProduct(hit->normal), 0.0F);

			returnColour += (lightSource->getId() / 100.0F) * 
							fmaxf(dot_prod, 0.0F) *
							hit->material->getDiffuse();
		}

		return returnColour;
	}

	Vec3f RayTracer::getSpecularRGB(Hit* hit, Scene* scene, Vec3f v)
	{
		Vec3f returnColour = Vec3f();

		for (auto lightSource : scene->getLights())
		{
			Vec3f l = (lightSource->getPos() - hit->point).normalize();

			Vec3f r = (2 * (hit->normal.dotProduct(l)) * hit->normal) - l;

			returnColour += (lightSource->getIs() / 100.0F) * 
							(powf(fmaxf(r.normalize().dotProduct(v), 0.0F), hit->material->getSpecular())); 
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
	Vec3f* RayTracer::tonemap(Vec3f* pixelbuffer, int width, int height)
	{
		for (int i = 0; i < width * height; i++)
		{
			pixelbuffer[i] *= 255.0F;
			if (pixelbuffer[i].x > 100.0F)
			{
				//printf("(%f, %f, %f)\n", pixelbuffer[i].x, pixelbuffer[i].y, pixelbuffer[i].z);
			}
		}
	
		return pixelbuffer;
	}
} //namespace rt


