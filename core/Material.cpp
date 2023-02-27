/*
 * Material.cpp
 *
 */
#include "Material.h"


namespace rt
{
class Material
{
public:
    Material::Material(){};

    Material::Material(Value& specs)
    {
        this->ks = specs["ks"].GetFloat();
        this->kd = specs["kd"].GetFloat();
        this->usingKr = specs.HasMember("kr");
        this->kr = this->usingKr ? specs["kr"].GetFloat() : (float)0;
        this->specular = specs["specularexponent"].GetFloat();
        this->diffuse = Vec3f(specs["diffusecolor"]);
        this->usingPath = specs.HasMember("tPath");
        if (!this->usingPath) { return; }
        this->tPath = specs["tPath"].GetString();
        this->tWidth = specs["tWidth"].GetInt();
        this->tHeight = specs["tHeight"].GetInt();
    }

    Material::Material(float ks, float kd, float specular, Vec3f diffuse)
    {
        this->ks = ks;
        this->kd = kd;
        this->specular = specular;
        this->diffuse = diffuse;
        this->usingPath = false;
        this->usingKr = false;
    }

    Material::Material(float ks, float kd, float kr, float specular, Vec3f diffuse)
    {
        this->ks = ks;
        this->kd = kd;
        this->kr = kr;
        this->specular = specular;
        this->diffuse = diffuse;
        this->usingPath = false;
        this->usingKr = true;
    }

    Material::Material(float ks, float kd, float specular, Vec3f diffuse, std::string tPath, int tWidth, int tHeight)
    {
        this->ks = ks;
        this->kd = kd;
        this->specular = specular;
        this->diffuse = diffuse;
        this->tPath = tPath;
        this->tWidth = tWidth;
        this->tHeight = tHeight;
        this->usingPath = true;
        this->usingKr = false;
    }

    Material::Material(float ks, float kd, float kr, float specular, Vec3f diffuse, std::string tPath, int tWidth, int tHeight)
    {
        this->ks = ks;
        this->kd = kd;
        this->kr = kr;
        this->specular = specular;
        this->diffuse = diffuse;
        this->tPath = tPath;
        this->tWidth = tWidth;
        this->tHeight = tHeight;
        this->usingPath = true;
        this->usingKr = true;
    }

private:
    float ks, kd, kr;
    float specular;
    Vec3f diffuse;
    std::string tPath;
    int tWidth;
    int tHeight;
    bool usingPath;
    bool usingKr;
};





} //namespace rt


