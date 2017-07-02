#include <iostream>
#include <fstream>
#include "color.hpp"
#include <map>
#include <sstream>
#include <string>
#include "material.hpp"



int main(void)
{
	std::ifstream Colorsource;
	Colorsource.open("farben_zum_einlesen.txt", std::ios_base::in);

	if(!Colorsource)
	std::cerr << "didn´t found <farben_zum_einlesen.txt>\n";
	else{
		std::ofstream Materialliste("materiallist.cpp");
		if (!Materialliste)
			std::cerr  << "can not open <materiallist.cpp>\n";
		else{
			std::string line_to_read;
			std::map<std::string, Material> materials;

			while (std::getline (Colorsource, line_to_read))
			{
				std::stringstream slicer;

				slicer << line_to_read;

				Material new_material;

				std::string not_used;

				slicer >> not_used;
				slicer >> not_used;
				slicer >> new_material.name_;
				//ambient
				slicer >> new_material.ka_.r;
				slicer >> new_material.ka_.g;
				slicer >> new_material.ka_.b;
				//diffuse
				slicer >> new_material.kd_.r;
				slicer >> new_material.kd_.g;
				slicer >> new_material.kd_.b;
				//specular
				slicer >> new_material.ks_.r;
				slicer >> new_material.ks_.g;
				slicer >> new_material.ks_.b;
				//m
				slicer >> new_material.m_;
			}
			
		}
	
	}

}



//  Material testmat(std::string {"testmaterial"}, Color{0.5f,1.0f,0.5f}, Color{0.8f,0.8f,0.4f}, Color{0.8f,0.9f,0.6f}, 0.6f);
