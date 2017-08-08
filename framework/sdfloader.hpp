#ifndef SDFLOADER_HPP
#define SDFLOADER_HPP
#include <string>
#include "scene.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "color.hpp"
#include "material.hpp"
#include <ifstream>
#include <iostream>
#include "scene.hpp"


class SDFloader
{
    static Scene load(std::string const& inpath);
}