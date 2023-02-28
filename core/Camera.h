/*
 * Camera.h
 *
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "math/geometry.h"
#include "rapidjson/document.h"


using namespace rapidjson;

namespace rt{

class Camera{ 
public:

	//
	// Constructors
	//
	Camera(){};
	Camera(int height, int width, int fov, Vec3f pos, Vec3f lookat, Vec3f up) : 
	height(height), width(width), fov(fov), pos(pos), lookat(lookat), up(up) {};

	//
	// Destructor
	//
	virtual ~Camera();


	//
	// factory function : returns camera instance dynamically based on camera specifications
	//
	static Camera* createCamera(Value& cameraSpecs);


	//
	// print function (to be implemented by the subclasses )
	//
	virtual void printCamera()=0;

	virtual Vec3f getPixelPos(float u, float v);



	//
	// other camera functions (to complete)
	//


	//
	// Getters and Setters
	//

	int getHeight() const 
	{
		return height;
	}

	int getWidth() const 
	{
		return width;
	}

	Vec3f getPos() const
	{
		return this->pos;
	}


protected:

	//
	//camera members
	//
	int height;
	int width;
	int fov; //field of view
	Vec3f pos;
	Vec3f lookat;
	Vec3f up;


};

} //namespace rt



#endif /* CAMERA_H_ */
