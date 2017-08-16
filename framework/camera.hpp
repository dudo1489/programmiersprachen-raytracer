#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include "ray.hpp"


struct Camera 
{



    Camera();
    Camera(std::string const& name, glm::vec3 const& position, float fov_x);
    Camera(std::string const& name, glm::vec3 const& position, glm::vec3 const& view, float fov_x);
    
    Ray cam_ray(int x, int y, int height, int width) const;

    std::string name_;
    glm::vec3 position_;
    glm::vec3 view_;
    float fov_x_;


};

#endif