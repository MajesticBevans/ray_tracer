/*
 * Shape.h
 *
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "rapidjson/document.h"

#include "RayHitStructs.h"
#include "Material.h"

using namespace rapidjson;

namespace rt{

class Shape
{
public:

	//
	// Constructors
	//
	Shape();

	//
	// Destructor (must be overriden in subclass)
	//
	virtual ~Shape();

	//
	// Shape abstract methods (to be implemented by subclasses)
	//
	virtual Hit intersect(Ray)=0;

	static Shape* createShape(Value& shapeSpecs);

	virtual void printShape()=0;

	Material* getMaterial();


protected:

	Material* material;

};


} //namespace rt


#endif /* SHAPE_H_ */
