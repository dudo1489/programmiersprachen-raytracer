#include "ray.hpp"

Ray& Ray::transformRay(glm::mat4 const& mat)
{
    glm::vec4 a {origin, 1.0f};
    glm::vec4 b {direction, 0.0};
    glm::vec3 origin{mat * a};
    glm::vec3 direction {mat * b};
    
    return *this;
}

Ray transformRay(glm::mat4x4 const& transform_inv, Ray const& ray)
{
    
    glm::vec3 origin(transform_inv * glm::vec4(ray.origin, 1));
    glm::vec3 direction(transform_inv * glm::vec4(ray.direction, 0));
    
    Ray new_ray{origin, direction};
    return new_ray;
}

Ray transformRay(glm::mat4 const& mat, Ray& ray)
{
    return ray.transformRay(mat);

}

