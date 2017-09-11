#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "ray.hpp"



class Sphere: public Shape
{
    glm::vec3 center_;
    float radius_;

public:
    Sphere();
    Sphere(glm::vec3 const& center, float radius);
    Sphere(glm::vec3 const& center, float radius, Material const& material, std::string const& name);
   ~Sphere() override;

    glm::vec3 const& get_center() const;
    float get_radius() const;

    float area() const override;
    float volume() const override;

    std::ostream& print(std::ostream& os) const override;

   
    Hit intersect(Ray const& ray) override;
    glm::vec3 calculate_normale(Hit const& hit) const override;


};

#endif