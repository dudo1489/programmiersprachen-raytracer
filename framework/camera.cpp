#include "camera.hpp"




    Camera::Camera():
        name_{"default"},
        position_{0.0, 0.0, 0.0},
        fov_x_{45.0},
        direction_{0.0, 0.0, -1.0},
        upVector_{0.0, 1.0, 0.0}
        {}

    Camera::Camera(std::string const& name, float fov_x, glm::vec3 const& position):
        name_{"name"},
        position_{position},
        fov_x_{fov_x},
        direction_{0.0, 0.0, -1.0},
        upVector_{0.0, 1.0, 0.0}
        {}

    Camera::Camera(std::string const& name, float fov_x, glm::vec3 const& position, glm::vec3 direction, glm::vec3 upVector):
        name_{name},
        position_{position}, 
        fov_x_{fov_x},
        direction_{direction},
        upVector_{upVector}
        {std::cout<<"Camera "<< name_<<" erstellt. Mit fov_x = "<<fov_x_<<" and Position: "<<position_.x<<" , "<<position_.y<<" , "<<position_.z<<" and direction_: "<<direction_.x<<" , "<<direction_.y<<" , "<<direction_.z<<" and upVector_: "<<upVector_.x<<" , "<<upVector_.y<<" , "<<upVector_.z<<"\n";}

    Camera::~Camera() {}
/*
    Ray Camera::generate_ray(float x_position, float y_position, float distance) const
    {

        Ray position_ray{position_, glm::vec3{x_position, y_position, -(distance)}};

        return position_ray;
    }

  */  
    Ray Camera::generate_ray(int x,int y, int height, int width) const
    {
        glm::vec3 view
                    { 
                        (float(x)/(float(width)))-0.5, 
                        (float(y)/(float(height)))-0.5, 
                        -1.0*(0.5/tan(fov_x_/2))
                    };
        Ray camRay{position_, view};
        auto transformedCam = transformCam();

        return camRay.transformRay(transformedCam);
    } 
    
     
    glm::mat4 Camera::transformCam() const
    {    
        glm::vec3 e = position_;
        glm::vec3 n = glm::normalize(direction_);
        glm::vec3 up = upVector_;

        glm::vec3 u = glm::normalize(glm::cross(n, up));
        glm::vec3 v = glm::normalize(glm::cross(u, n));

        glm::mat4 transformCam;
        transformCam[0] = glm::vec4 {u, 0.0f};   
        transformCam[1] = glm::vec4 {v, 0.0f};
        transformCam[2] = glm::vec4 {n * -1.0f, 0.0f};
        transformCam[3] = glm::vec4 {e, 1.0f};

        return transformCam;
    
    }
