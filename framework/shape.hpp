#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"
#include <string>
#include "ray.hpp"

typedef std::string String;

class Shape
{
    Color color_;
    String name_;

 public:
    virtual float area() const = 0;
    virtual float volume() const = 0;

    Shape();
    ~Shape();
    Shape(String const& name);
    Shape(Color const& color, String name);

    Color const& get_color() const;
    String const& get_name() const;

    virtual std::ostream& print(std::ostream& os) const;

    virtual bool intersect(Ray const& ray ,float& t) = 0;
            


};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif