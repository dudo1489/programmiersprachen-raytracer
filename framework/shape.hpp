#ifndef SHAPE_HPP
#define SHAPE_HPP
#define GLM_FORCE_RADIANS

#include "material.hpp"
#include <string>
#include "ray.hpp"
#include "hit.hpp"
#include <memory>
#include <glm/glm.hpp>
#include "glm/gtx/transform.hpp"
#include "glm/gtc/matrix_transform.hpp"

typedef std::string String;

struct Hit;

class Shape
{
protected:
    Material material_;
    String name_;
    glm::mat4 world_transform_;
    glm::mat4 world_transform_inv_;
    
    glm::mat4 translation_;
    glm::mat4 scale_;
    glm::mat4 rotation_;

 public:
    
    virtual float area() const = 0;
    virtual float volume() const = 0;

    Shape();
    virtual ~Shape();
    Shape(String const& name);
    Shape(Material const& mat, String const& name);
    

    Material const& get_material();
    String const& get_name() const;
    glm::mat4 get_transform_() const;
    glm::mat4 get_transform_inv_() const;
    

    void scale(glm::vec3 const& scale_vec);
    void transform(glm::vec3 const& transale_vec);
    void rotate(float angle, glm::vec3 rotate_vec);

    virtual std::ostream& print(std::ostream& os) const;

 
    virtual Hit intersect(Ray const& ray) = 0;
    virtual glm::vec3 calculate_normale(Hit const& hit) const = 0;



};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif