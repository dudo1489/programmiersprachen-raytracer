#include "shape.hpp"


Shape::Shape():
    material_{},
    name_{"Shape"}
    {}


 Shape::Shape(String const& name):
    material_{},
    name_{name}
    {} 

Shape::Shape(Material const& mat, String const& name):
    material_{mat},
    name_{name}
 //  { std::cout<<"constructor shape"<<"\n";}
    {}

Shape::~Shape() 
    {}

Material const& Shape::get_material() const
 {
     return material_;
 }

String const& Shape::get_name() const
{
    return name_;
}

std::ostream& Shape::print(std::ostream& os) const
{
    os<<"Name: "<<name_<<"\n"<<"Material: "<<material_<<"\n";
    return os; 
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
    return s.print(os);
}