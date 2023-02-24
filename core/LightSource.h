/*
 * LightSource.h
 *
 */

#ifndef LIGHTSOURCE_H_
#define LIGHTSOURCE_H_

#include "math/geometry.h"
#include "rapidjson/document.h"

using namespace rapidjson;

namespace rt{

class LightSource
{
public:

    //
	// Constructors
	//
    LightSource() {};
    LightSource(Vec3f* is, Vec3f* id):
    is(is), id(id){};


    //
    // Destructor
    //
    virtual ~LightSource();

    //
	// factory function : returns lightsource instance dynamically based on lightsource specifications
	//
    static LightSource* createLightSource(Value& lightSourceSpecs);

    //
	// print function (to be implemented by the subclasses )
	//
	virtual void printLightSource()=0;

    //
    // Getters and Setters
    //
    Vec3f* getIs() const { return is; }
    Vec3f* getId() const { return id; }
    
protected:
    Vec3f* is;
    Vec3f* id;

};

} //namespace rt



#endif /* LIGHTSOURCE_H_ */
