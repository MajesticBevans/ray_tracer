/*
 * Material.cpp
 *
 */
#include "Material.h"


namespace rt
{

    Material::Material(){};

    Material::Material(Value& specs)
    {
        ks = specs["ks"].GetFloat();
        kd = specs["kd"].GetFloat();

        bool usingKr = specs.HasMember("kr");
        kr = usingKr ? specs["kr"].GetFloat() : (float)0;

        specular = specs["specularexponent"].GetFloat();
        diffuse = Vec3f(specs["diffusecolor"]).normalize();

        bool usingPath = specs.HasMember("tPath");
        if (!usingPath) { return; }

        tPath = specs["tPath"].GetString();
        tWidth = specs["tWidth"].GetInt();
        tHeight = specs["tHeight"].GetInt();
    }

    Material::Material(float ks, float kd, float specular, Vec3f diffuse)
    {
        this->ks = ks;
        this->kd = kd;
        this->specular = specular;
        this->diffuse = diffuse;

        kr = 0;
        tPath = "";
        tWidth = 0.0F;
        tHeight = 0.0F;
    }

    Material::Material(float ks, float kd, float kr, float specular, Vec3f diffuse)
    {
        this->ks = ks;
        this->kd = kd;
        this->kr = kr;
        this->specular = specular;
        this->diffuse = diffuse;

        tPath = "";
        tWidth = 0.0F;
        tHeight = 0.0F;
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

        kr = 0.0F;
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
    }

    float Material::getKs() { return ks; }
    float Material::getKd() { return kd; }
    float Material::getKr() { return kr; }
    float Material::getSpecular() { return specular; }
    Vec3f Material::getDiffuse() { return diffuse; }

} //namespace rt


