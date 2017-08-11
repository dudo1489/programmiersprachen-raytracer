#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP
#include <vector>
#include <string>
#include <memory>
#include "shape.hpp"
#include <map>

class Composite
{
    public:
    
    Composite();
    Composite(std::string const& name);
     ~Composite(); 

    void add_shape(std::shared_ptr<Shape> const& shape);
    void set_name(std::string const name); 

    float area() const;
    float volume() const;    

    std::ostream& print(std::ostream& os) const;

    bool intersect(Ray const& ray ,float& t);

    private:
    std::vector<std::shared_ptr<Shape>> shape_;
    std::string name_;
    
};

#endif 
