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
	Camera(int height, int width, int fov, Vec3f pos):height(height), width(width), fov(fov), pos(pos){};

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


};

} //namespace rt



#endif /* CAMERA_H_ */
