#include "sphere.hpp"
#include <cmath>

Sphere::~Sphere()
{
   // std::cout<<"destructor sphere"<<"\n";
}

Sphere::Sphere():
    Shape{{}, "Sphere"},
    center_{glm::vec3{0.0f}},
    radius_{1}
    {}

Sphere::Sphere(glm::vec3 const& center, float radius):
    Shape{{}, "Sphere"},
    center_{center},
    radius_{radius}
    {}

Sphere::Sphere(glm::vec3 const& center, float radius, Material const& material, std::string const& name):
    Shape{material, name},
    center_{center},
    radius_{radius}
    {
   //     std::cout<<"constructor sphere"<<"\n";
    }
    
glm::vec3 const& Sphere::get_center() const
{
    return center_;
}

float Sphere::get_radius() const
{
    return radius_;
}

float Sphere::area() const
{
    return 4*M_PI*pow(radius_,2);
}

float Sphere::volume() const
{
    return fabs((4/3)*M_PI*pow(radius_,3));
}

std::ostream& Sphere::print(std::ostream& os) const
{
    os <<"Center: ("<<center_.x<<", "<<center_.y<<", "<<center_.z<<") \n"
    <<"Radius: "<<radius_<<"\n";
    return os;
}

Hit Sphere::intersect(Ray const& ray, float& distance)
{
    
   auto norm_direction = glm::normalize(ray.direction);
    auto result = glm::intersectRaySphere(ray.origin, norm_direction, center_, radius_ * radius_, distance);
    return result;
    
}