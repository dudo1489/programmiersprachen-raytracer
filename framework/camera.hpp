#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include "ray.hpp"
#include <glm/vec3.hpp>
#include <glm/glm.hpp>




struct Camera 
{



    Camera();
    Camera(std::string const& name, glm::vec3 const& position, float fov_x);
    Camera(std::string const& name, glm::vec3 const& position, glm::vec3 const& view, float fov_x,glm::vec3 direction, glm::vec3 upVector);
    glm::mat4 transformCam() const;

    //Ray calc_eye_ray(int x,int y, int height, int width);


    std::string name_;
    glm::vec3 direction_;
    glm::vec3 upVector_;
    glm::vec3 position_;
    glm::vec3 view_;
    float fov_x_;


};

#endif