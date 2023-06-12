#include <iostream>


class MyClass {
  private:
    int data;

  public:
    MyClass(int d) : data(d) {}

    friend void friendFunction(MyClass obj);
};

void friendFunction(MyClass obj) {
  // Friend function can access private members of MyClass
  std::cout << "Friend function accessing data: " << obj.data << std::endl;
}

int main() {
  MyClass obj(42);
  friendFunction(obj);  // Invoking the friend function
  return 0;
}
