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

Hit Box::intersect(Ray const& rayman)
{

  Hit hitt{this};

//-------------
  Ray ray;
  ray.direction = glm::normalize(rayman.direction);
  ray.origin = rayman.origin;
//-------------
  ray = transformRay(world_transform_inv_, rayman);
 // Ray ray = transformRay(get_transform_inv_(), rayman);
  float tmin = -INFINITY, tmax = INFINITY;

  float t1 = (min_.x - ray.origin.x)/ray.direction.x;
  float t2 = (max_.x - ray.origin.x)/ray.direction.x;
  tmin = std::max(tmin,std::min(t1,t2));
  tmax = std::min(tmax,std::max(t1,t2));

  t1 = (min_.y - ray.origin.y)/ray.direction.y;
  t2 = (max_.y - ray.origin.y)/ray.direction.y;
  tmin = std::max(tmin,std::min(t1,t2));
  tmax = std::min(tmax,std::max(t1,t2));

  t1 = (min_.z - ray.origin.z)/ray.direction.z;
  t2 = (max_.z - ray.origin.z)/ray.direction.z;
  tmin = std::max(tmin,std::min(t1,t2));
  tmax = std::min(tmax,std::max(t1,t2));

  if (tmax > std::max(0.0f, tmin))
  {
    hitt.distance_ = sqrt(tmin*tmin*(
                      ray.direction.x*ray.direction.x +
                      ray.direction.y*ray.direction.y +
                      ray.direction.z*ray.direction.z ));
    
  //  hit.surface_pt = this->calc_surface_pt(ray, hit.distance);

    hitt.intersect_ = ray.origin + hitt.distance_ * ray.direction;


    hitt.hit_ = true;  
    hitt.normal_ = this->calculate_normale(hitt);
    hitt.intersect_ = glm::vec3(get_transform_()*glm::vec4(hitt.intersect_,1.0));
    hitt.normal_ = glm::normalize(glm::vec3(glm::transpose(get_transform_inv_())*glm::vec4(hitt.normal_, 0.0)));
  }
  return hitt;
}

glm::vec3 Box::calculate_normale(Hit const& hit) const
{
  auto surface_pt = hit.intersect_; 
  if(surface_pt.x == Approx(min_.x))
  {
    return glm::vec3{-1.0,0.0,0.0};
  }
  if(surface_pt.y == Approx(min_.y))
  {
    return glm::vec3{0.0,-1.0,0.0};
  }
  if(surface_pt.z == Approx(min_.z))
  {
    return glm::vec3{0.0,0.0,-1.0};
  }
  if(surface_pt.x == Approx(max_.x))
  {
    return glm::vec3{1.0,0.0,0.0};
  }
  if(surface_pt.y == Approx(max_.y))
  {
    return glm::vec3{0.0,1.0,0.0};
  }
  if(surface_pt.z == Approx(max_.z))
  {
    return glm::vec3{0.0,0.0,1.0};
  }
}

