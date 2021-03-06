#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP
#include <string>
#include "scene.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "color.hpp"
#include "material.hpp"
#include "light.hpp"
#include "composite.hpp"
#include "camera.hpp"
#include "shape.hpp"
#include "renderinfo.hpp"

#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include "scene.hpp"
#include <sstream>
#include <glm/vec3.hpp>
#include <memory>


class SDFloader
{

};

Scene load(std::string const& inpath);

#endif