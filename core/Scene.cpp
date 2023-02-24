/*
 * Scene.cpp
 *
 */
#include "Scene.h"




namespace rt{

/**
 * Parses json scene object to generate scene to render
 *
 * @param scenespecs the json scene specificatioon
 */
void Scene::createScene(Value& scenespecs)
{
	Value& lightsources = scenespecs["lightsources"];
	Value& shapes = scenespecs["shapes"];

	//----------parse json object to populate scene-----------

}



} //namespace rt
