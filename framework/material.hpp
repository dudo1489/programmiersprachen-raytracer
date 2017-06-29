#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include "color.hpp"

using namespace std;

struct Material
{
		string name_;

		Color ka_;
		Color kd_;
		Color ks_;

		float m_; // Reflection


		Material();
		Material(string const& name, Color const& ka, Color const& kd, Color const& ks, float m);


    friend ostream& operator<<(ostream& os, Material const& mat)
    {  
	    os << mat.name_ << '/' << mat.ka_ << '/' << mat.kd_ << '/' << mat.ks_ << '/' << mat.m_;  
	    return os;  
	}


};
	



#endif