/*
 * PointLight.cpp
 *
 *
 */
#include "PointLight.h"



namespace rt
{

  class PointLight : public LightSource
  {
    //
    // PointLight constructor
    //
    PointLight::PointLight(Vec3f is, Vec3f id, Vec3f pos):LightSource(is, id, pos)
    {
      this->is = is;
      this->id = id;
      this->pos = pos;
    }


    void printLightSource()
    {
      printf("I am a point light at position %d!\n", this->pos);
      printf("is: %d, id: %d\n", this->is, this->id);
    }

    //
    // Pointlight destructor
    //
    PointLight::~PointLight()
    {
      // REMEMBER TO DELETE DYNAMICALLY ALLOCATED MEMORY!!
    }

  };

} //namespace rt
