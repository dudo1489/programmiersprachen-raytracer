#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray
{

    Ray():
    origin{glm::vec3{0.0}},
    direction{glm::vec3{-1.0}}
    {}

    Ray(glm::vec3 const& origin, glm::vec3 const& direction):
    origin{origin},
    direction{glm::normalize(direction)}
    {}

    Ray& transformRay(glm::mat4 const& mat);

    friend Ray transformRay(glm::mat4x4 const& transform_inv, Ray const& ray);
    
    glm::vec3 origin;
    glm::vec3 direction;
    glm::vec3 inv_direction;

};

    Ray transformRay(glm::mat4 const& mat, Ray& ray);
#endif