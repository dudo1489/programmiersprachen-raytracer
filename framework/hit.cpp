#include "hit.hpp"

Hit::Hit():
    hit_{false},
    distance_{INFINITY},
    intersect_{999, 999, 999},
    normal_{999, 999, 999},
    shape_{nullptr}
    {}


Hit::Hit(bool hit, float distance, glm::vec3 const& intersect, glm::vec3 const& normal, Shape* const shape):
    hit_{hit},
    distance_{distance},
    intersect_{intersect},
    normal_{normal},
    shape_{shape}
    {}

