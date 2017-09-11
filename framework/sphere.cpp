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

Hit Sphere::intersect(Ray const& rayman)
{
    Hit sphere_hit;
    Ray ray;

    ray = transformRay(world_transform_inv_, rayman);
    
    sphere_hit.normal_ = glm::normalize(glm::vec3(glm::transpose(get_transform_inv_())*glm::vec4(sphere_hit.normal_, 0.0)));
    sphere_hit.hit_ = glm::intersectRaySphere(ray.origin, ray.direction, center_, radius_, sphere_hit.intersect_, sphere_hit.normal_);
    /* if(glm::distance(sphere_hit.intersect_ - 0.001f * ray.direction, center_) < radius_)
    {
        sphere_hit.normal_ = - sphere_hit.normal_;
    } */
    
        if(sphere_hit.hit_)
        {
            sphere_hit.distance_ = glm::distance(ray.origin, sphere_hit.intersect_);
            sphere_hit.shape_ = this;
        }

        return sphere_hit;
    }

glm::vec3 Sphere::calculate_normale(Hit const& hit)const
{}
    