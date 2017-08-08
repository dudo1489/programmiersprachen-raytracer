#ifndef SCENE_HPP
#define SCENE_HPP

#include "material.hpp"
#include "shape.hpp"
#include <vector>
#include <map>



struct Scene
{
    
    std::map<std::string, std::shared_ptr<Material>> materials_;
    std::map<std::string, std::shared_ptr<Box>> box_;
    //std::map<std::string, std::shared_ptr<Sphere>> sphere_;
    std::map<std::string, std::shared_ptr<Shape>> shape_;
    //std::map<std::string, std::shared_ptr<Color>> color_;
};

#endif 
