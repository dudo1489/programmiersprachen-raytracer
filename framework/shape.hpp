#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "material.hpp"
#include <string>
#include "ray.hpp"
#include "hit.hpp"
#include <memory>

typedef std::string String;

struct Hit;

class Shape
{
    Material material_;
    String name_;

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

    //std::shared_ptr<Material> get_material();

    virtual std::ostream& print(std::ostream& os) const;

 //virtual bool intersect(Ray const& ray ,float& t) = 0;
   virtual Hit intersect(Ray const& ray) = 0;
            


};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif