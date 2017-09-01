#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "material.hpp"
#include <string>
#include "ray.hpp"
#include "hit.hpp"
#include <memory>
#include <glm/glm.hpp>

typedef std::string String;

struct Hit;

class Shape
{
    Material material_;
    String name_;
    glm::mat4 transform_;
    glm::mat4 transform_inv_;

 public:
    
    virtual float area() const = 0;
    virtual float volume() const = 0;

    Shape();
    virtual ~Shape();
    Shape(String const& name);
    Shape(Material const& mat, String const& name);
    //Shape(std::shared_ptr<Material> material, String const& name);

    Material const& get_material() const;
    String const& get_name() const;
    glm::mat4 get_transform_() const;
    glm::mat4 get_transform_inv_() const;
    //std::shared_ptr<Material> get_material();

    virtual std::ostream& print(std::ostream& os) const;

 //virtual bool intersect(Ray const& ray ,float& t) = 0;
    virtual Hit intersect(Ray const& ray) = 0;
    virtual glm::vec3 calculate_normale(Hit const& hit) const = 0;



};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif