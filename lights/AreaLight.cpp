/*
 * AreaLight.cpp
 *
 *
 */
#include "AreaLight.h"

namespace rt
{
  //
  // AreaLight constructors
  //
  AreaLight::AreaLight(Vec3f is, Vec3f id, Vec3f pos):LightSource(is, id, pos)
  {
    this->is = is;
    this->id = id;
    this->pos = pos;
  }

  //
  // AreaLight destructor
  //
  AreaLight::~AreaLight()
  {
    // REMEMBER TO DELETE DYNAMICALLY ALLOCATED MEMORY!!
  }

  void AreaLight::printLightSource()
  {
    printf("I am an area light at position (%f, %f, %f)!\n", this->pos.x, this->pos.y, this->pos.z);
    printf("is: (%f, %f, %f), id: (%f, %f, %f)\n",
          this->is.x, this->is.y,  this->is.z,
          this->id.x, this->id.y, this->id.z);
  }
  
} //namespace rt
