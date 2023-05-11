#include <iostream>
#include <string>

class Stock {
  public:
    std::string Product[5];
    int Quantity[5];
    float Price[5];

    void printInfo() {
      std::cout << "Name: " << Product[0] << std::endl;
      std::cout << "Age: " << Quantity[0] << std::endl;
      std::cout << "Height: " << Price[0] << std::endl;
    }
};

int main() {
  Stock person;
  for (int i = 0; i < 5; i++)
  {
    std::cin>>person.Product[0];
    std::cin>>person.Quantity[0];
    std::cin>>person.Price[0];
  }
  


  person.printInfo();

  return 0;
}
