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

    // Friend class declaration
    friend class FriendClass;
};

class FriendClass {
  public:
    void setValue(MyClass& obj, int val) {
        obj.value = val;
    }
};

int main() {
  MyClass obj(42);
  obj.displayValue();

  FriendClass fc;
  fc.setValue(obj, 99);
  obj.displayValue();

  return 0;
}
