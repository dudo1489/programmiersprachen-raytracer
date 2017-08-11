#ifndef SCENE_HPP
#define SCENE_HPP

#include "material.hpp"
#include "shape.hpp"
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "light.hpp"
#include "camera.hpp"




struct Scene
{
    
    std::map<std::string, Material> materials_;
    //std::map<std::string, std::shared_ptr<Box>> box_;
    //std::map<std::string, std::shared_ptr<Sphere>> sphere_;
    std::map<std::string, std::shared_ptr<Shape>> shape_;
    //std::map<std::string, std::shared_ptr<Color>> color_;
    std::map<std::string, std::shared_ptr<Light>> light_;
    std::map<std::string, std::shared_ptr<Camera>> camera_;

};

#endif 
