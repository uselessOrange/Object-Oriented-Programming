#include <iostream>
using namespace std;

template <class T>
class numberOperations{
T var;
public:
numberOperations() { }
void print(){
cout << var<< endl;
}
void square(){
var = var*var;
}
void set();
};

int main(){
numberOperations<int> intVar;
numberOperations<double> doubleVar;

cout << "\t\t\tProgram calculates square of int and floatnumbers\n";
cout<<"Enter integer number:\n";
intVar.set();
intVar.print();
intVar.square();
intVar.print();
cout<<"Enter floating point number:\n";
doubleVar.set();
doubleVar.print();
doubleVar.square();
doubleVar.print();

return 0;
}

template <class T>
void numberOperations<T>::set(){
cin>>var;
}