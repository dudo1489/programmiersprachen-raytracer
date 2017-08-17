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

Hit::Hit(Hit const& tmp_hit):

    hit_{tmp_hit.hit_},
    distance_{tmp_hit.distance_},
    intersect_{tmp_hit.intersect_},
    normal_{tmp_hit.normal_},
    shape_{tmp_hit.shape_}
    {}

Hit& Hit::operator = (Hit const& tmp_hit)
{
    if(this==&tmp_hit)
    {
        return *this;
    }

    hit_ = tmp_hit.hit_;
    distance_ = tmp_hit.distance_;
    intersect_ = tmp_hit.intersect_;
    normal_ = tmp_hit.normal_;
    shape_ = tmp_hit.shape_;
}
