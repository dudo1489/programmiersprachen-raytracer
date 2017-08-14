#ifndef HIT_HPP
#define HIT_HPP

#include "material.hpp"
#include "ray.hpp"


struct Hit 
{
    Hit();
    Hit(bool hit, float distance, glm::vec3 const& intersect, glm::vec3 normal, Shape const& shape);




    bool hit_;
    float distance_;
    glm::vec3 intersect_;
    glm::vec3 normal_;
    Shape shape_;

}