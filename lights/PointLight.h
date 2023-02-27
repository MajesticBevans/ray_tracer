/*
 * PointLight.h
 *
 *
 */

#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "core/LightSource.h"


namespace rt{

class PointLight: public LightSource{
    public:

    //
	// Constructors
	//
	PointLight();
	PointLight(Vec3f is, Vec3f id, Vec3f pos);

	//
	// Destructor
	//
	~PointLight(){};

	//
	// print function (implementing abstract function of base class)
	//
	void printLightSource();


};



} //namespace rt




#endif /* POINTLIGHT_H_ */
