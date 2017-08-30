#include "box.hpp"
#include <cmath>


//Box::~Box(){}


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
    Box boxhit;
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

Hit Box::intersect(Ray const& ray)
{   
    Hit box_hit;

    box_hit.shape_ = this;

    Ray temp_ray;
    temp_ray.direction = glm::normalize(ray.direction);
    temp_ray.origin = ray.origin;

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

    box_hit.distance_ = sqrt(ray.direction.x*ray.direction.x+ray.direction.y*ray.direction.y+ray.direction.z*ray.direction.z); //Normierung des 

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
/*

Hit Box::intersect(Ray const& inray){
  float hit_x = 0.0;
  float hit_y = 0.0;
  float hit_z = 0.0;
  float dis = 0.0;
  Hit boxhit;
  Ray ray;
  ray.direction = glm::normalize(inray.direction);
  ray.origin = inray.origin;


  glm::vec3 hitvec{glm::vec3{0.0}};

  if(ray.origin.x <= min_.x || (ray.origin.x > min_.x && ray.origin.x < max_.x && ray.direction.x < 0))
  {
    hitvec.x = min_.x;  
  }
  else if(ray.origin.x >= max_.x || (ray.origin.x > min_.x && ray.origin.x < max_.x && ray.direction.x > 0))
  {
    hitvec.x = max_.x;  
  }

  if(ray.origin.y <= min_.y || (ray.origin.y > min_.y && ray.origin.y < max_.y && ray.direction.y < 0))
  {
    hitvec.y = min_.y;  
  }
  else if(ray.origin.y >= max_.y || (ray.origin.y > min_.y && ray.origin.y < max_.y && ray.direction.y > 0))
  {
    hitvec.y = max_.y;  
  }

  if(ray.origin.z <= min_.z || (ray.origin.z > min_.z && ray.origin.z < max_.z && ray.direction.z < 0))
  {
    hitvec.z = min_.z;  
  }
  else if(ray.origin.z >= max_.z || (ray.origin.z > min_.z && ray.origin.z < max_.z && ray.direction.z > 0))
  {
    hitvec.z = max_.z;  
  }

  dis = (hitvec.x - ray.origin.x)/ray.direction.x;
  hit_y = ray.origin.y + dis*ray.direction.y;
  hit_z = ray.origin.z + dis*ray.direction.z;;
  
  if(hit_y >= min_.y && hit_y <= max_.y && hit_z >= min_.z && hit_z <= max_.z && dis >= 0){
    boxhit.hit_ = true;
    boxhit.distance_ = dis;
    boxhit.intersect_ = ray.origin + ray.direction * boxhit.distance_;
    if(hitvec.x == min_.x){
      boxhit.normal_ = glm::vec3{-1.0,0.0,0.0};
      }
    else{
      boxhit.normal_ = glm::vec3{1.0,0.0,0.0};
    }
    boxhit.shape_ = this;
    return boxhit;
  }

  dis = (hitvec.y - ray.origin.y)/ray.direction.y;
  hit_x = ray.origin.x + dis*ray.direction.x;
  hit_z = ray.origin.z + dis*ray.direction.z;;
  
  if(hit_x >= min_.x && hit_x <= max_.x && hit_z >= min_.z && hit_z <= max_.z && dis >= 0){
    boxhit.hit_ = true;
    boxhit.distance_ = dis;
    boxhit.intersect_ = ray.origin + ray.direction * boxhit.distance_;
    if(hitvec.y == min_.y){
      boxhit.normal_ = glm::vec3{0.0,-1.0,0.0};
      }
    else{
      boxhit.normal_ = glm::vec3{0.0,1.0,0.0};
    }
    boxhit.shape_ = this;    
    return boxhit;
  }

  dis = (hitvec.z - ray.origin.z)/ray.direction.z;
  hit_x = ray.origin.x + dis*ray.direction.x;
  hit_y = ray.origin.y + dis*ray.direction.y;;
  
  if(hit_x >= min_.x && hit_x <= max_.x && hit_y >= min_.y && hit_y <= max_.y && dis >= 0){
    boxhit.hit_ = true;
    boxhit.distance_ = dis;
    boxhit.intersect_ = ray.origin + ray.direction * boxhit.distance_;
    if(hitvec.z == min_.z){
      boxhit.normal_ = glm::vec3{0.0,0.0,-1.0};
      }
    else{
      boxhit.normal_ = glm::vec3{0.0,0.0,1.0};
    }
    boxhit.shape_ = this;
    return boxhit;
  }

  boxhit.hit_ = false;
  return boxhit;
}
*/
