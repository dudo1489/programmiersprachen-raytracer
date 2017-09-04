#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP
#include <vector>
#include <string>
#include <memory>
#include "shape.hpp"
#include <map>

//#include <ostream>


class Composite : public Shape
{
    public:
    
    Composite();
    Composite(std::string const& name);
    ~Composite(); 

    void add_shape(std::shared_ptr<Shape> const& shape);
    void set_name(std::string const name); 

    float area() const override;
    float volume() const override;    

    std::ostream& print(std::ostream& os) const override;    //mussten implementiert werden da Composite sonst virtuell
    Hit intersect(Ray const& ray)override;
    glm::vec3 calculate_normale(Hit const& hit) const override;



    private:

        std::string name_;
        std::vector<std::shared_ptr<Shape>> shape_;

};

#endif 
