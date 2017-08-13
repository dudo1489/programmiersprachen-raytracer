#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>



struct Camera 
{



    Camera();
    Camera(std::string const& name, glm::vec3 const& position, float fov_x);
    Camera(std::string const& name, glm::vec3 const& position, glm::vec3 const& view, float fov_x);



    std::string name_;
    glm::vec3 position_;
    glm::vec3 view_;
    float fov_x_;


};

#endif