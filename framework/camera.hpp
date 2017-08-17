#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include "ray.hpp"
<<<<<<< HEAD
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
=======
>>>>>>> 2c9fad5a9c3c599e4a93a106ade3b4557be155a9


struct Camera 
{



    Camera();
    Camera(std::string const& name, glm::vec3 const& position, float fov_x);
<<<<<<< HEAD
    Camera(std::string const& name, glm::vec3 const& position, glm::vec3 const& view, float fov_x,glm::vec3 direction, glm::vec3 upVector);
    glm::mat4 transformCam() const;

    //Ray calc_eye_ray(int x,int y, int height, int width);

=======
    Camera(std::string const& name, glm::vec3 const& position, glm::vec3 const& view, float fov_x);
    
    Ray cam_ray(int x, int y, int height, int width) const;
>>>>>>> 2c9fad5a9c3c599e4a93a106ade3b4557be155a9

    std::string name_;
    glm::vec3 direction_;
    glm::vec3 upVector_;
    glm::vec3 position_;
    glm::vec3 view_;
    float fov_x_;


};

#endif