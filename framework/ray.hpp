#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray
{
    glm::vec3 origin;
    glm::vec3 direction;
    glm::vec3 inv_direction;

    Ray():
    origin{glm::vec3{0.0}},
    direction{glm::vec3{-1.0}}
    {}

    Ray(glm::vec3 origin, glm::vec3 direction):
    origin{origin},
    direction{direction}
    {}

    Ray& transformRay(glm::mat4 const& mat);

    /*friend Ray transformRay(glm::mat4x4 const& trans_mat_inv, Ray const& Ray)
    {
        Ray newray;
        glm::vec3 origin(trans_mat_inv*glm::vec4(newray.origin,1));
        glm::vec3 direction(trans_mat_inv*glm::vec4(newray.direction,0));
        glm::vec3 inv_direction(glm::vec3{1.0/direction.x, 1.0/direction.y, 1.0/direction.z});

        newray.origin = origin;
        newray.direction = direction;
        newray.inv_direction = inv_direction;
        return newray;
    } */
    
    

};

    Ray transformRay(glm::mat4 const& mat, Ray& ray);
#endif