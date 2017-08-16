#include "box.hpp"
#include <cmath>


Box::~Box(){}


Box::Box():
    Shape{{}, "Box"},
    min_{glm::vec3{0.0f}},
    max_{glm::vec3{1.0f}}
    {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max):
    Shape{{}, "Box"},
    min_{min},
    max_{max}
    {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max, Material const& mat, std::string const& name):
    Shape{mat, name},
    min_{min},
    max_{max}
    {}


glm::vec3 const& Box::get_min() const
{
    return min_;
}

glm::vec3 const& Box::get_max() const
{
    return max_;
}

float Box::area() const
{
    float x = fabs(max_.x - min_.x);
    float y = fabs(max_.y - min_.y);
    float z = fabs(max_.z - min_.z);
    return (x*y*2 + x*z*2 + y*z*2);
}

float Box::volume() const
{
    float volume = (max_.x-min_.x)*(max_.y-min_.y)*(max_.z-min_.z);
    return fabs(volume);
}

std::ostream& Box::print(std::ostream& os) const
{
    os<<"Min: ("<<min_.x<<", "<<min_.y<<", "<<min_.z<<") \n"
    <<"Max: ("<<max_.x<<", "<<max_.y<<", "<<max_.z<<")";
    return os;
}
/*
//bool intersect läuft
bool Box::intersect(Ray const& ray ,float& t)
{
    
    float tfar;
    float tnear;

    float tfarx;
    float tnearx;
    float tfary;
    float tneary;
    float tfarz;
    float tnearz;


    float tx1 = (min_.x-ray.origin.x)/ray.direction.x;
    float tx2 = (max_.x-ray.origin.x)/ray.direction.x;
 
    tfarx=std::max(tx1, tx2);
    tnearx=std::min(tx1, tx2);

    float ty1 = (min_.y-ray.origin.y)/ray.direction.y;
    float ty2 = (max_.y-ray.origin.y)/ray.direction.y;
  
    tfary=std::max(ty1, ty2);
    tneary=std::min(ty1, ty2);

    float tz1 = (min_.z-ray.origin.z)/ray.direction.z;
    float tz2 = (max_.z-ray.origin.z)/ray.direction.z;

    tfarz=std::max(tz1, tz2);
    tnearz=std::min(tz1, tz2);

    tfar=std::max(tfarx, tfary);
    tnear=std::min(tnearx, tneary);

   if(tfar<tnear)
   {
        return false;
   }
 
   tfar=std::min(tfar, tfarz);
   tnear=std::max(tnear, tnearz);

   if((tfar<0) || (tfar<tnear))
   {
       return false;
   }

   return true;
}

*/

Hit Box::intersect(Ray const& ray ,float& t)
{   
    Hit box_hit;

    box_hit.shape_ = this;

    float tfar;
    float tnear;

    float tfarx;
    float tnearx;
    float tfary;
    float tneary;
    float tfarz;
    float tnearz;


    float tx1 = (min_.x-ray.origin.x)/ray.direction.x;
    float tx2 = (max_.x-ray.origin.x)/ray.direction.x;
 
    tfarx=std::max(tx1, tx2);
    tnearx=std::min(tx1, tx2);

    float ty1 = (min_.y-ray.origin.y)/ray.direction.y;
    float ty2 = (max_.y-ray.origin.y)/ray.direction.y;
  
    tfary=std::max(ty1, ty2);
    tneary=std::min(ty1, ty2);

    float tz1 = (min_.z-ray.origin.z)/ray.direction.z;
    float tz2 = (max_.z-ray.origin.z)/ray.direction.z;

    tfarz=std::max(tz1, tz2);
    tnearz=std::min(tz1, tz2);

    tfar=std::max(tfarx, tfary);
    tnear=std::min(tnearx, tneary);

    box_hit.distance_ = sqrt(ray.direction.x*ray.direction.x+ray.direction.y*ray.direction.y+ray.direction.z*ray.direction.z);

    box_hit.intersect_ = glm::vec3{tnear*ray.direction.x, tnear*ray.direction.y, tnear*ray.direction.z}+ray.origin;

   if(tfar<tnear)
   {
    box_hit.hit_ = false;
    return box_hit;

   }
 
   tfar=std::min(tfar, tfarz);
   tnear=std::max(tnear, tnearz);

   if((tfar<0) || (tfar<tnear))
   {
        box_hit.hit_ = false;
        return box_hit;

   }

   box_hit.hit_ = true;
   
   return box_hit;
}
