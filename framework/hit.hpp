#ifndef HIT_HPP
#define HIT_HPP

#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include <glm/vec3.hpp>
#include <cmath>

class Shape;

struct Hit 
{
    Hit();
    Hit(bool hit, float distance, glm::vec3 const& intersect, glm::vec3 const& normal, Shape* const shape);
    Hit(Hit const& tmp_hit);

    Hit& operator =(Hit const& tmp_hit);



    bool hit_;
    float distance_;
    glm::vec3 intersect_;
    glm::vec3 normal_;
    Shape* shape_;

};

#endif