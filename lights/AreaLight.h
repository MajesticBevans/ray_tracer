/*
 * AreaLight.h
 *
 *
 */

#ifndef AREALIGHT_H_
#define AREALIGHT_H_

#include "core/LightSource.h"

namespace rt{

class AreaLight:public LightSource
{
public:

    //
	// Constructors
	//
	AreaLight(Vec3f is, Vec3f id, Vec3f pos);

	//
	// Destructor
	//
	~AreaLight();

	//
	// print function (implementing abstract function of base class)
	//
	void printLightSource();

private:
	Vec3f is;
	Vec3f id;
};



} //namespace rt




#endif /* AREALIGHT_H_ */
