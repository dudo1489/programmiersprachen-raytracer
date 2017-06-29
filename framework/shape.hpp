#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "material.hpp"
#include <string>

typedef std::string String;

class Shape
{
    Material material_;
    String name_;

 public:
    virtual float area() const = 0;
    virtual float volume() const = 0;

    Shape();
    ~Shape();
    Shape(String const& name);
    Shape(Material const& mat, String const& name);

    Material const& get_material() const;
    String const& get_name() const;

    virtual std::ostream& print(std::ostream& os) const;

};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif