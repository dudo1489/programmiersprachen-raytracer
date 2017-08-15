#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"
#include <glm/vec3.hpp>
#include "ray.hpp"

class Box: public Shape
{
    glm::vec3 min_;
    glm::vec3 max_;

    public:
    Box();
    Box(glm::vec3 const& min, glm::vec3 const& max);
    Box(glm::vec3 const& min, glm::vec3 const& max, Material const& mat, std::string const& name);
    ~Box() override;
    glm::vec3 const& get_min() const;
    glm::vec3 const& get_max() const;
 //   bool intersect(Ray const& ray ,float& t) override;
    Hit intersect(Ray const& ray ,float& t) override;

    float area() const override;
    float volume() const override;

    std::ostream& print(std::ostream& os) const override;
};

#endif