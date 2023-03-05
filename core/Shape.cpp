/*
 * Shape.cpp
 *
 */
#include "Shape.h"

#include "shapes/Sphere.h"
#include "shapes/Plane.h"
#include "shapes/Triangle.h"
#include "shapes/BVH.h"
#include "shapes/TriMesh.h"



namespace rt
{

    Shape::Shape(){};
    Shape::~Shape(){};
    /**
     * Factory function that returns shape subclass based on shape specifications
     *
     * @param shapeSpecs shape specifications json object
     *
     * @return shape subclass instance
     *
     */
    Shape* Shape::createShape(Value& shapeSpecs)
    {
        //check if lightsource is defined

        if (!shapeSpecs.HasMember("type"))
        {
            std::cerr<<"Shape type not specified"<<std::endl;
            exit(-1);
        }

        if (!shapeSpecs.HasMember("material"))
        {
            std::cerr<<"Shape material not specified"<<std::endl;
            exit(-1);
        }

        std::string type = shapeSpecs["type"].GetString();      

        Material* material = new Material(shapeSpecs["material"]);

        //return shape object based on shape specs
        if (type.compare("sphere")==0)
        {
            Vec3f center = Vec3f(shapeSpecs["center"]);
            float radius = shapeSpecs["radius"].GetFloat();
            return shapeSpecs.HasMember("id") ? new Sphere(shapeSpecs["id"].GetString(), center, radius, material) 
            : new Sphere(center, radius, material);
        }
        else if (type.compare("plane")==0)
        {
            Vec3f v0 = Vec3f(shapeSpecs["v0"]);
            Vec3f v1 = Vec3f(shapeSpecs["v1"]);
            Vec3f v2 = Vec3f(shapeSpecs["v2"]);
            Vec3f v3 = Vec3f(shapeSpecs["v3"]);
            return shapeSpecs.HasMember("id") ? new Plane(shapeSpecs["id"].GetString(), v0, v1, v2, v3, material) 
            : new Plane(v0, v1, v2, v3, material);
        }
        else if (type.compare("triangle")==0)
        {
            Vec3f v0 = Vec3f(shapeSpecs["v0"]);
            Vec3f v1 = Vec3f(shapeSpecs["v1"]);
            Vec3f v2 = Vec3f(shapeSpecs["v2"]);
            return shapeSpecs.HasMember("id") ? new Triangle(shapeSpecs["id"].GetString(), v0, v1, v2, material) 
            : new Triangle(v0, v1, v2, material);
        }
        else if (type.compare("trianglemesh"))
        {

        }

        return 0;
    }

    Material* Shape::getMaterial() { return material; }



} //namespace rt

