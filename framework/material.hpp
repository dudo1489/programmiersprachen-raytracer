#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include "color.hpp"

using namespace std;

struct Material
{
		string name_;

		Color ka_; //ambiente 
		Color kd_;	//difuse
		Color ks_;	//Reflection

		float m_; // ExponentReflection


		Material();
		Material(string const& name, Color const& ka, Color const& kd, Color const& ks, float m);


    friend ostream& operator<<(ostream& os, Material const& mat)
    {  
	    os 
	    << "name:"
	    << mat.name_ 
	    << "\n" 
	    << "ka:"
	    << mat.ka_ 
	    << "\n"
	    << "kd:"
	    << mat.kd_ 
	    << "\n" 
	    << "ks:"
	    << mat.ks_ 
	    << "\n" 
	    << "m:"
	    << mat.m_ 
	    << "\n" ;

	    return os;  
	}


};
	
#endif