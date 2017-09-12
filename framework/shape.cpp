#include "shape.hpp"


Shape::Shape():
    material_{},
    name_{"Shape"},
    world_transform_{glm::mat4(1.0f)},
    world_transform_inv_{glm::mat4(1.0f)},
    translation_{glm::mat4(1.0f)},
    scale_{glm::mat4(1.0f)},
    rotation_{glm::mat4(1.0f)}
    {}


 Shape::Shape(String const& name):
    material_{},
    name_{name},
    world_transform_{glm::mat4(1.0f)},
    world_transform_inv_{glm::mat4(1.0f)},
    translation_{glm::mat4(1.0f)},
    scale_{glm::mat4(1.0f)},
    rotation_{glm::mat4(1.0f)}
    {} 

  Shape::Shape(Material const& mat, String const& name):
    material_{mat},
    name_{name},
    world_transform_{glm::mat4(1.0f)},
    world_transform_inv_{glm::mat4(1.0f)},
    translation_{glm::mat4(1.0f)},
    scale_{glm::mat4(1.0f)},
    rotation_{glm::mat4(1.0f)}
 //  { std::cout<<"constructor shape"<<"\n";}
    {}  

/* Shape::Shape(std::shared_ptr<Material> mat, String const& name):
    material_{mat},
    name_{name}
    {} */

Shape::~Shape() 
    {}

Material const& Shape::get_material()
 {
     return material_;
 } 

/* std::shared_ptr<Material> Shape::get_material()
{
    return material_;
} */

String const& Shape::get_name() const
{
    return name_;
}

glm::mat4 Shape::get_transform_() const
{
    return world_transform_;
}

glm::mat4 Shape::get_transform_inv_() const
{
    return world_transform_inv_;
}

std::ostream& Shape::print(std::ostream& os) const
{
    os<<"Name: "<<name_<<"\n"<<"Material: "<<material_<<"\n";
    return os; 
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
    return s.print(os);
}

void Shape::scale(glm::vec3 const& scale_vec)
{   glm::mat4 S;
    S = glm::scale(glm::mat4(), scale_vec);   //siehe vorlesungsfolie seite 30 
    scale_ = S;     //direkt auf scale_ anwenden wirft speicherfehler
    world_transform_ = scale_ * rotation_ * translation_;
    world_transform_inv_ = glm::inverse(world_transform_);
}

void Shape::transform(glm::vec3 const& translate_vec)
{
    glm::mat4 T;
    T = glm::translate(glm::mat4(), translate_vec);
    translation_ = T;
    world_transform_ = translation_ * scale_ * rotation_;
    world_transform_inv_ = glm::inverse(world_transform_); 
}

void Shape::rotate(float angle, glm::vec3 rotate_vec)   //angle in grad angeben
{
    angle = angle * 0.01745329; //deg to rad;
    glm::mat4 R;
    R = glm::rotate(glm::mat4(), angle, rotate_vec);
    rotation_ = R;
    world_transform_ = rotation_ * scale_ * translation_;
    world_transform_inv_ = glm::inverse(world_transform_);


}