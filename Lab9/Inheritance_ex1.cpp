#include <iostream>

// Base class
class Shape {
  protected:
    int width;
    int height;

  public:
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
};

// Derived class
class Rectangle : public Shape {
  public:
    int getArea() {
        return width * height;
    }
};

int main() {
  Rectangle rect;
  rect.setDimensions(5, 3);
  std::cout << "Area: " << rect.getArea() << std::endl;

  return 0;
}
