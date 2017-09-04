#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include "ray.hpp"
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <iostream>




struct Camera 
{



    Camera();
    Camera(std::string const& name, float fov_x, glm::vec3 const& position);
    Camera(std::string const& name, float fov_x, glm::vec3 const& position, glm::vec3 direction, glm::vec3 upVector);
    ~Camera();//glm::mat4 transformCam() const;

    //Ray calc_eye_ray(int x,int y, int height, int width);


    std::string name_;
    glm::vec3 direction_;
    glm::vec3 upVector_;
    glm::vec3 position_;
    float fov_x_;

   // Ray generate_ray(float x_position, float y_position, float distance) const;
    Ray generate_ray(int x,int y, int height, int width) const;
    glm::mat4 transformCam() const;

};

#endif