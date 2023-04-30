#include <iostream>

int main() {
int a;
int *b;
a = 11;
std::cout << "a = " << a;
std::cout << std::endl;
b = &a;
std::cout <<" value of a variable pointed by b is equal " << *b;
std::cout << std::endl;
std::cout << b;
std::cout << std::endl;
*b = 14;
std::cout << "a = " << a;
std::cout << std::endl;
return 0;
}
