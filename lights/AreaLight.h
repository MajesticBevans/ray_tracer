/*
 * AreaLight.h
 *
 *
 */

#ifndef AREALIGHT_H_
#define AREALIGHT_H_

#include "core/LightSource.h"

namespace rt{

class AreaLight:public LightSource{
    public:

    //
	// Constructors
	//
	AreaLight();
	AreaLight(Vec3f* is, Vec3f* id);

	//
	// Destructor
	//
	~AreaLight(){};

	//
	// print function (implementing abstract function of base class)
	//
	void printLightSource();


};



} //namespace rt




#endif /* AREALIGHT_H_ */
