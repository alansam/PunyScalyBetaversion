
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class shape {
protected:
  double base;
  double height;

public:
  shape(double base_ = 0.0, double height_ = 0.0) :
    base { base_ }, height { height_ } {
    std::cout << "shape::shape() default ctor\n";
  }
  shape(shape const & that) {
    std::cout << "shape::shape() copy ctor\n";
    base   = that.base;
    height = that.height;
  }
  shape(shape && that) = default;
  shape & operator=(shape const & that) = default;
  virtual ~shape() = default;

  virtual double area(void) const = 0;
};

class triangle : public shape {
public:
  triangle(double base_ = 0.0, double height_ = 0.0)
    : shape(base_, height_) {
    std::cout << "triangle::triangle() default ctor\n";
  }
  triangle(triangle const & that) : shape(that) {
    std::cout << "triangle::triangle() copy ctor\n";
  }

  virtual double area(void) const {
    double area = base / 2 * height;
    return area;
  }
};

int main(int argc, char const * argv[]) {
  triangle * tt = new triangle(3.0, 5.0);

  auto shapes = std::vector<shape const *>();
  shapes.push_back(tt);
  shapes.push_back(new triangle(3.0, 5.0));

  for (shape const * sh : shapes) {
    std::cout << "area: " << sh->area() << '\n';
  }
  std::cout << std::endl;

  delete tt;

  return 0;
}
