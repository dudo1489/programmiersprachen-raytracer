#include "camera.hpp"




    Camera::Camera():
        name_{"default"},
        position_{0.0, 0.0, 0.0},
        view_{0.0, 0.0, -1.0},
        fov_x_{45.0},
        direction_{0.0, 0.0, -1.0},
        upVector_{0.0, 0.0, 0.0}
        {}

    Camera::Camera(std::string const& name, glm::vec3 const& position, float fov_x):
        name_{name},
        position_{position},
        view_{0.0, 0.0, -1.0},//muss nóch für die z achse einen negativeren wert bekommen als position
        fov_x_{fov_x},
        direction_{0.0, 0.0, -1.0},
        upVector_{0.0, 0.0, 0.0}
        {}

    Camera::Camera(std::string const& name, glm::vec3 const& position, glm::vec3 const& view, float fov_x, glm::vec3 direction, glm::vec3 upVector):
        name_{name},
        position_{position},
        view_{view},
        fov_x_{fov_x},
        direction_{direction},
        upVector_{upVector}
        {}


    /* Ray Camera::calc_eye_ray(int x,int y, int height, int width)
    {
        glm::vec3 view{float(x)*1.0/float(width)-0.5, float(y) * 1.0/float(height)-0.5, -1.0*(0.5/tan(fov_x_/2))};
        Ray camRay{position_, view};
        auto transformedCam = transformCam();

        return camRay.transformRay(transformedCam);
    } */  

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
    
    }
