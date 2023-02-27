/*
 * AreaLight.cpp
 *
 *
 */
#include "AreaLight.h"




namespace rt{

  class AreaLight : public LightSource
  {
    //
    // PointLight constructor
    //
    AreaLight::AreaLight(Vec3f is, Vec3f id, Vec3f pos):LightSource(is, id, pos)
    {
      this->is = is;
      this->id = id;
      this->pos = pos;
    }

    void printLightSource()
    {
      printf("I am an area light at position %d!\n", this->pos);
      printf("is: %d, id: %d\n", this->is, this->id);
    }

    //
    // Pointlight destructor
    //
    AreaLight::~AreaLight()
    {
      // REMEMBER TO DELETE DYNAMICALLY ALLOCATED MEMORY!!

    }

  };




} //namespace rt
