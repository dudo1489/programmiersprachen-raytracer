#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include "color.hpp"

using namespace std;

struct Material
{
		string name;
		Color ka;
		Color kd;
		Color ks;
		float m;

    friend ostream& operator<<(ostream& os, const Material& mat);  

};


	ostream& operator<<(ostream& os, const Material& mat)  
	{  
	    os << mat.name << '/' << mat.ka << '/' << mat.kd << '/' << mat.ks << '/' << mat.m;  
	    return os;  
	}




#endif