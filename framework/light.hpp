#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <glm/vec3.hpp>
#include "color.hpp"
#include <string>
#include "scene.hpp"

struct Light 
{

std::string name_;
Color color_;
glm::vec3 point_;
float brightness_;



    Light():
        name_{"default"},
        point_{0.0},
        color_{0.0,0.0,0.0},
        brightness_{0.9}
        {std::cout << "Konstrukt def. light";}

    Light(std::string const& name, glm::vec3 const& point,Color color, float brightness):
        name_{name},
        point_{point},
        color_{color},
        brightness_{brightness}
        {std::cout << "Konstrukt light";}


};

#endif