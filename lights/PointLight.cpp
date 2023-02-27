/*
 * PointLight.cpp
 *
 *
 */
#include "PointLight.h"

namespace rt
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


  void PointLight::printLightSource()
  {
    printf("I am a point light at position (%f, %f, %f)!\n", this->pos.x, this->pos.y, this->pos.z);
    printf("is: (%f, %f, %f), id: (%f, %f, %f)\n",
          this->is.x, this->is.y,  this->is.z,
          this->id.x, this->id.y, this->id.z);
  }

  //
  // Pointlight destructor
  //
  PointLight::~PointLight()
  {
    // REMEMBER TO DELETE DYNAMICALLY ALLOCATED MEMORY!!
  }

} //namespace rt
