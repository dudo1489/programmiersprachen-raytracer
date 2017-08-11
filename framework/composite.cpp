#include "composite.hpp"

Composite::Composite():
    name_("default"),
    shape_()
    {}

Composite::Composite(std::string name):
    name_(name),
    shape_()
    {}

Composite::~Composite()
    {}

Composite::add(shape_ const& shape)
    {
        shape_.push_back(shape);
    }

Composite::set_name(std::string const name)
    {
        name_=name;
    }
