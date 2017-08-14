#include "hit.hpp"

Hit::Hit():
    hit_{false},
    distance_{9999999},
    intersect_{999, 999, 999},
    normal_{999, 999, 999},
    sphere_{nullptr}
    {}


Hit::Hit(bool hit, float distance, glm::vec3 const& intersect, glm::vec3 const& normal, Sphere const& sphere):
    hit_{hit},
    distance_{distance},
    intersect_{intersect},
    normal_{normal},
    sphere_{sphere}
    {}

