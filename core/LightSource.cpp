/*
 * LightSource.cpp
 *
 */
#include "LightSource.h"

#include "lights/PointLight.h"
#include "lights/AreaLight.h"

namespace rt{

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

        std::string type=lightSourceSpecs["type"].GetString();
        Value& isJson = lightSourceSpecs["is"];
        Value& idJson = lightSourceSpecs["id"];

        if (!lightSourceSpecs["is"].IsArray() || !lightSourceSpecs["id"].IsArray() ||
            isJson.Size() != 3 || idJson.Size() != 3) 
        {
            std::cerr<<"Is/Id values not input correctly"<<std::endl;
            exit(-1);
        }

        float isX, isY, isZ, idX, idY, idZ;
        isX = isJson[0].GetFloat();
        isY = isJson[1].GetFloat();
        isZ = isJson[2].GetFloat();
        idX = idJson[0].GetFloat();
        idY = idJson[0].GetFloat();
        idZ = idJson[0].GetFloat();

        Vec3f* is = new Vec3f(isX, isY, isZ);
        Vec3f* id = new Vec3f(idX, idY, idZ);
        

        //return camera object based on camera specs
        if (type.compare("pointlight")==0)
        {
            return new PointLight(is, id);
        }
        else if (type.compare("arealight")==0)
        {
            return new AreaLight(is, id);
        }

        return 0;
    }

} //namespace rt

