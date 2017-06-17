#include "sphere.hpp"
#include <cmath>

Sphere::Sphere():
    Shape{"Sphere"},
    center_{glm::vec3{0.0f}},
    radius_{1}
    {}

Sphere::Sphere(glm::vec3 const& center, float radius):
    Shape{"Sphere"},
    center_{center},
    radius_{radius}
    {}

Sphere::Sphere(glm::vec3 const& center, float radius, Color const& color, String name):
    Shape{color, name},
    center_{center},
    radius_{radius}
    {}

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