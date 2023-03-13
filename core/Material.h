/*
 * Material.h
 *
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "math/geometry.h"
#include "rapidjson/document.h"

namespace rt
{

class Material
{
public:

    //
    // Constructors
    //

    Material();
    Material(Value& specs);
    Material(float ks, float kd, float specular, Vec3f diffuse);
    Material(float ks, float kd, float kr, float specular, Vec3f diffuse);
    Material(float ks, float kd, float specular, Vec3f diffuse, std::string tPath, int tWidth, int tHeight);
    Material(float ks, float kd, float kr, float specular, Vec3f diffuse, std::string tPath, int tWidth, int tHeight);

    //
    // Destructor
    //
    ~Material(){};


    //
    // Getters and setters
    //

    float getKs();
    float getKd();
    float getKr();
    float getSpecular();
    Vec3f getDiffuse();



private:
    float ks, kd, kr;
    float specular;
    Vec3f diffuse;
    std::string tPath;
    int tWidth;
    int tHeight;
};


} //namespace rt



#endif /* MATERIAL_H_ */
