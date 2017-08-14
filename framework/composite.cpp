#include "composite.hpp"


Composite::Composite():
    Shape{{}, "default composite"},
    shape_{}
    {}

Composite::Composite(std::string const& name):
    Shape{{}, name},
    shape_{}
    {}

 Composite::~Composite()
    {} 

void Composite::add_shape(std::shared_ptr<Shape> const& shape)
    {
        shape_.push_back(shape);
    }

 void Composite::set_name(std::string const name)
    {
        name_=name;
    } 

    float Composite::area() const
    {
        float result = 0;
        for(auto const& shape : shape_)
        {
            result = shape -> area();
        }
    }

float Composite::volume() const
    {
        float result = 0;
        for(auto const& shape : shape_)
        {
            result = shape -> volume();
        }
    }   

std::ostream& Composite::print(std::ostream& os)
    {
         for(auto const& shape : shape_)
        {
            shape ->print(os);
            os << "\n";
        }
        return os; 
    }


Hit Composite::intersect(Ray const& ray ,float& t)
{
    Hit hitFar;
    Hit hitClose;
    for (auto const& shape : shape_)
    {
        hitFar = shape -> intersect(ray, t);
        if(hitFar.distance_<hitClose.distance_)
        {
            hitClose=hitFar;
        }
        return hitClose; 
    }
}
  