#include <iostream>
using namespace std;

class procesor {
    int l_watkow;
    int l_rdzeni;

public:
    procesor(int, int); //konstruktor
    void wysw_param();
};

procesor::procesor (int a, int b) {
l_watkow = a;
l_rdzeni = b;
}
void procesor::wysw_param() {
cout << "\nProcesor posiada " << l_watkow << " watkow";
cout << "\nProcesor posiada " << l_rdzeni << " rdzeni";
}
int main() {
procesor i5(4,4);
procesor i7(8,4);
cout << "Program przechowuje i wyswietla informacje na temat "
<< "procesorow\n";
cout << "\n\ti5\n";
i5.wysw_param();
cout << endl;
cout << "\n\ti7\n";
i7.wysw_param();
cout << endl;
return 0;
}