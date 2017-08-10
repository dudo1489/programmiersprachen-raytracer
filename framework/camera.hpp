#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/vec3.hpp>
#include <string>
#include "scene.hpp"

struct Camera 
{

std::string name_;
glm::vec3 position_;
glm::vec3 view_;
float fov_x_;



    Camera():
        name_{"default"},
        position_{0.0, 0.0, 0.0},
        view_{0.0, 0.0, -1.0},
        fov_x_{45.0}
        {}

    Camera(std::string const& name, glm::vec3 const& position, float fov_x):
        name_{name},
        position_{position},
        view_{position},//muss nóch für die z achse einen negativeren wert bekommen als position
        fov_x_{fov_x}
        {}

    Camera(std::string const& name, glm::vec3 const& position, glm::vec3 const& view, float fov_x):
        name_{name},
        position_{position},
        view_{view},
        fov_x_{fov_x}
        {}


};

#endif