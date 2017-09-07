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

Hit Sphere::intersect(Ray const& ray)
{
    float distance = INFINITY;
  // Hit intersect_hit;
 //   intersect_hit.hit_ = glm::intersectRaySphere(ray.origin, ray.direction, center_, radius_*radius_, distance);
  //  std::cout << "ray.origin: " << ray.origin.x<<"     " <<ray.origin.y<<"    "<< ray.origin.z <<"    "<< "\n";
   //  std::cout << "ray.direction: " << ray.direction.x<<"     "<< ray.direction.y<<"     "<< ray.direction.z <<"\n";

    bool hit = glm::intersectRaySphere(ray.origin, ray.direction, center_, radius_*radius_, distance);
    
    if (hit == true)
    {  
      glm::vec3 intersection_point = ray.origin + distance * ray.direction;
   //   std::cout<< "surfacepoints" << intersection_point.x <<"   "<<intersection_point.y<<"   "<<intersection_point.z<<"\n";
      
      glm::vec3 normalen_vec = glm::normalize(intersection_point - center_);
   //   std::cout<< "normalen_vec" << normalen_vec.x <<"   "<<normalen_vec.y<<"   "<<normalen_vec.z<<"\n";

   //   std::cout<< "distance vom hit "<<distance << "\n";

      return Hit{true, distance, intersection_point, normalen_vec, this};
    }

    return Hit{};
}

glm::vec3 Sphere::calculate_normale(Hit const& hit)const
{}
    