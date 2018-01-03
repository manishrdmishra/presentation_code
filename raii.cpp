#include <iostream>

class Rectangle 
{
  public: 
    Rectangle(int *width = nullptr, int *height = nullptr)
      : width_{width}
    , height_{height}
    {}
    void setWidth(int *width) { width_ = width; }
    void setHeight(int *height) { height_ = height; }
    int area() { return (*width_) * (*height_) ; }

  private:
    int *width_;
    int *height_;
};

int main()
{
  Rectangle rect;
  int width = 4;
  int height = 5;
  rect.setWidth(&width);
  rect.setHeight(&height);
  std::cout<<"area : "<< rect.area() << std::endl ;
  return 0;
}
