#include <iostream>

class MyClass {
  private:
    int value;

  public:
    // Constructor
    MyClass(int val) {
        value = val;
    }

    // Member function
    void displayValue() {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
  // Creating an object of MyClass using the constructor
  MyClass obj(42);

  // Calling a member function to display the value
  obj.displayValue();

  return 0;
}
