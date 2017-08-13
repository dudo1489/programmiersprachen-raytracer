#include "camera.hpp"




    Camera::Camera():
        name_{"default"},
        position_{0.0, 0.0, 0.0},
        view_{0.0, 0.0, -1.0},
        fov_x_{45.0}
        {}

    Camera::Camera(std::string const& name, glm::vec3 const& position, float fov_x):
        name_{name},
        position_{position},
        view_{0.0, 0.0, -1.0},//muss nóch für die z achse einen negativeren wert bekommen als position
        fov_x_{fov_x}
        {}

    Camera::Camera(std::string const& name, glm::vec3 const& position, glm::vec3 const& view, float fov_x):
        name_{name},
        position_{position},
        view_{view},
        fov_x_{fov_x}
        {}