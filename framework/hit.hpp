#ifndef HIT_HPP
#define HIT_HPP

#include "material.hpp"
#include "ray.hpp"
#include "shape.hpp"

class Shape;

struct Hit 
{
    Hit();
    Hit(bool hit, float distance, glm::vec3 const& intersect, glm::vec3 normal, const Shape* shape);

    


    bool hit_;
    float distance_;
    glm::vec3 intersect_;
    glm::vec3 normal_;
    Shape* shape_;

};

#endif