/*
 * LightSource.cpp
 *
 */
#include "LightSource.h"

#include "lights/PointLight.h"
#include "lights/AreaLight.h"

namespace rt
{
    LightSource::~LightSource(){};
    
    /**
     * Factory function that returns lightsource subclass based on lightsource specifications
     *
     * @param lightSourceSpecs lightsource specifications json object
     *
     * @return lightsource subclass instance
     *
     */
    LightSource* LightSource::createLightSource(Value& lightSourceSpecs)
    {

        if (!lightSourceSpecs.HasMember("type"))
        {
            std::cerr<<"Light source type not specified"<<std::endl;
		    exit(-1);
        }

        std::string type = lightSourceSpecs["type"].GetString();
        Vec3f is = Vec3f(lightSourceSpecs["is"]);
        Vec3f id = Vec3f(lightSourceSpecs["id"]);
        Vec3f pos = Vec3f(lightSourceSpecs["position"]);

        //return light source object based on specs
        if (type.compare("pointlight")==0)
        {
            return new PointLight(is, id, pos);
        }
        else
        {
            return new AreaLight(is, id, pos);
        }
    }

} //namespace rt

