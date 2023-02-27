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
    LightSource* createLightSource(Value& lightSourceSpecs)
    {
        //check if lightsource is defined

        if (!lightSourceSpecs.HasMember("type"))
        {
            std::cerr<<"Light source type not specified"<<std::endl;
            exit(-1);
        }

        std::string type = lightSourceSpecs["type"].GetString();
        Value& isJson = lightSourceSpecs["is"];
        Value& idJson = lightSourceSpecs["id"];
        Value& posJson = lightSourceSpecs["position"];


        Vec3f is = Vec3f(isJson);
        Vec3f id = Vec3f(idJson);
        Vec3f pos = Vec3f(posJson);
        

        //return camera object based on camera specs
        if (type.compare("pointlight")==0)
        {
            return new PointLight(is, id, pos);
        }
        else if (type.compare("arealight")==0)
        {
            return new AreaLight(is, id, pos);
        }

        return 0;
    }

} //namespace rt

