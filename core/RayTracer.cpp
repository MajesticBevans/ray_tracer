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
				shootRay(Ray(camera->getPos(), direction, RayType::PRIMARY), scene, 0.0F, nbounces);
			}
		}

		return pixelbuffer;

	}

	Vec3f RayTracer::shootRay(Ray ray, Scene* scene, float startDistance, int nbounces)
	{
		// Max bounces reached
		if (nbounces < 0) 
		{
			return scene->getBackgroundColour();
		}
		// Find the closest hit point
		Hit closestHit;
		bool hitSomething = false;
		for (auto shape : scene->getShapes())
		{
			Hit h = shape->intersect(ray);
			if (h.isHit && (!hitSomething || h.distance < closestHit.distance))
			{
				closestHit = h;
				hitSomething = true;
			}
		}

		std::vector<LightSource*> validLights = shootShadowRays(&closestHit, scene);
		// If no hit, return background color
		if (!hitSomething || validLights.size() == 0)
		{
			return scene->getBackgroundColour();
		}

		// Compute the diffuse and specular colors
		Material* mat = closestHit.material;
		Vec3f diffuse = getDiffuseRGB(&closestHit, validLights);
		Vec3f specular = getSpecularRGB(&closestHit, validLights, ray.direction);

		// Compute the reflection color by recursively shooting a new ray
		// in the reflected direction and averaging the results
		Vec3f reflection = Vec3f();

		if (mat->getKr() > 0)
		{
			Vec3f reflectedDir = reflect(ray.direction, closestHit.normal);
			Ray reflectedRay = Ray(closestHit.point + closestHit.normal * 0.001F, reflectedDir, RayType::SECONDARY);
			reflection = shootRay(reflectedRay, scene, closestHit.distance, nbounces - 1);
		}

		// Compute the total color as a weighted sum of the diffuse, specular,
		// and reflection colors, and return it
		Vec3f sumColour = diffuse * mat->getKd() + specular * mat->getKs() + reflection * mat->getKr();

		sumColour /= powf(startDistance + closestHit.distance, 0.05F);
		if (sumColour.x > 1.0F) { sumColour.x = 1.0F; }
		if (sumColour.y > 1.0F) { sumColour.y = 1.0F; }
		if (sumColour.z > 1.0F) {sumColour.z = 1.0F; }
		return sumColour;
	}

	std::vector<LightSource*> RayTracer::shootShadowRays(Hit* hit, Scene* scene)
	{
		std::vector<LightSource*> returnLights;

		// check each light source. If any not blocked, add to returnLights
		for (auto lightSource : scene->getLights())
		{
			Vec3f dir = lightSource->getPos() - hit->point;
			float distance = dir.length();

			Ray shadowRay = Ray(hit->point + hit->normal * 0.001F, dir.normalize(), RayType::SHADOW);

			bool inShadow = false;

			// check each shape. If one in way of light source, break and don't add
			// to return
			for (auto shape : scene->getShapes())
			{
				Hit shadowHit = shape->intersect(shadowRay);

				if (shadowHit.isHit && shadowHit.distance < distance)
				{
					// point in shadow
					inShadow = true;
					break;
				}
			}
			if (!inShadow) { returnLights.push_back(lightSource); }
		} 
		return returnLights;
	}


	Vec3f RayTracer::getDiffuseRGB(Hit* hit, std::vector<LightSource*> lights)
	{
		Vec3f returnColour = Vec3f();

		for (auto lightSource : lights)
		{
			Vec3f l = (lightSource->getPos() - hit->point).normalize();
			float dot_prod = fmaxf(l.dotProduct(hit->normal), 0.0F);
			Vec3f id = lightSource->getId().normalize();
			returnColour += hit->material->getDiffuse() * id * dot_prod;
		}

		return returnColour;
	}

	Vec3f RayTracer::getSpecularRGB(Hit* hit, std::vector<LightSource*> lights, Vec3f v)
	{
		Vec3f returnColour = Vec3f();

		for (auto lightSource : lights)
		{
			Vec3f is = lightSource->getIs().normalize();

			Vec3f l = (lightSource->getPos() - hit->point);
			Vec3f r = reflect(l, hit->normal);
			float dot_prod = fmax(r.dotProduct(v), 0.0F);
			
			returnColour += is * powf(dot_prod, hit->material->getSpecular()); 
		}
		return returnColour;
	}

	Vec3f RayTracer::reflect(Vec3f l, Vec3f n)
	{
		l.normalize();
		n.normalize();
		return (l - (2 * (n.dotProduct(l) * n)));
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
			pixelbuffer[i].x = powf(pixelbuffer[i].x, 1.1F) * 255.0F;
			pixelbuffer[i].y = powf(pixelbuffer[i].y, 1.1F) * 255.0F;	
			pixelbuffer[i].z = powf(pixelbuffer[i].z, 1.1F) * 255.0F;
		}
	
		return pixelbuffer;
	}
} //namespace rt


