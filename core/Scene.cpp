/*
 * Scene.cpp
 *
 */
#include "Scene.h"
#include "LightSource.h"
#include "Shape.h"

namespace rt
{

/**
 * Parses json scene object to generate scene to render
 *
 * @param scenespecs the json scene specificatioon
 */
void Scene::createScene(Value& scenespecs)
{
	Value& lightSources = scenespecs["lightsources"];
	Value& shapes = scenespecs["shapes"];

	if (lightSources.Size() < 1)
	{
		std::cerr<<"err: No light sources specified in scene"<<std::endl;
        exit(-1);
	}
	if (shapes.Size() < 1)
	{
		std::cerr<<"err: No shapes specified in scene"<<std::endl;
        exit(-1);
	}

	for (SizeType i = 0; i < lightSources.Size(); i++)
	{
		this->lightSources.push_back(LightSource::createLightSource(lightSources[i]));
	}

	for (SizeType i = 0; i < shapes.Size(); i++)
	{
		this->shapes.push_back(Shape::createShape(shapes[i]));
	}
}

void Scene::printScene()
{
	for (auto lightSource : this->lightSources)
	{
		lightSource->printLightSource();
	}

	for (auto shape : this->shapes)
	{
		shape->printShape();
	}
}



} //namespace rt
