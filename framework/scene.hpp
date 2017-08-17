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
#include "composite.hpp"
#include "camera.hpp"




struct Scene
{
    
    std::map<std::string, Material> materials_;
    std::shared_ptr<Composite> composite_;
    std::vector<std::shared_ptr<Camera>> camera_;
    Color backgroundclr_;
    std::vector<std::shared_ptr<Light>> light_;
};

#endif 
