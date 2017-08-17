#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray
{
    glm::vec3 origin;
    glm::vec3 direction;

    Ray():
    origin{glm::vec3{0.0}},
    direction{glm::vec3{-1.0}}
    {}

    Ray(glm::vec3 origin, glm::vec3 direction):
    origin{origin},
    direction{direction}
    {}

    Ray& transformRay(glm::mat4 const& mat);
    
    

};

Ray transformRay(glm::mat4 const& mat, Ray& ray);
#endif