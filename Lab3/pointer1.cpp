#include <iostream>
using namespace std;
int main() {
int a;
int *b;
a = 11;
cout << "a = " << a;
cout << endl;
b = &a; /*in this line a pointer is connected to a variable
address*/
cout <<"b="<<b<<std::endl<<" value of a variable pointed by b is equal "
<< *b;
cout << endl;
*b = 14;
cout << "a = " << a;
cout << endl;
return 0;
}