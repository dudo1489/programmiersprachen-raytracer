#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP


class Composite : public Shape
{
    public:
    
    typedef std::shared_ptr<Shape> shape_pointer;
    
    Composite();
    Composite(std::string name);
    ~Composite();

    void add(shape_pointer const& shape);
    void set_name(std::string const name);

    private:
    std::string name_;
    std::vector<shape_pointer> shape_;
};

#endif 
