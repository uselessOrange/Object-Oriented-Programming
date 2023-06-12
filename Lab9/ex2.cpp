#include <iostream>
#include "ex2.hpp"
using namespace std;



int main() {
int b;
do {
if (b > 9) {
cout<<"Learn to read! the number supposed to be "
<<"from 0 to 9"<<endl;
}
cout << "Your knight is being created. "
<< "Enter a number from 0 to 9: "<<endl;
cin>>b;
} while (b>9);
knight r1(b);return 0;
}