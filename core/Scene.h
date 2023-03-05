/*
 * Scene.h
 *
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <vector>

#include "rapidjson/document.h"

#include "LightSource.h"
#include "Shape.h"


using namespace rapidjson;

namespace rt{

class Scene {
public:

	Scene(){};

	void createScene(Value& scenespecs);

	void printScene();

	//
	// Getters and Setters
	//

	std::vector<LightSource*> getLights();
	std::vector<Shape*> getShapes();
	Vec3f getBackgroundColour();


private:

	std::vector<LightSource*> lightSources;
	std::vector<Shape*> shapes;
	Vec3f background_colour;
};

} //namespace rt



#endif /* SCENE_H_ */
