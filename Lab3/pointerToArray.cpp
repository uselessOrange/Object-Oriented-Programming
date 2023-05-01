#include <iostream>
using namespace std;
int main() {
float tab[4] = {7.23, 12.46, 16.12, 23.28};
float *wsk;
wsk=tab;
cout << "Pierwszy pociag odjezdza o: "
<< *wsk << endl;
wsk=wsk+1;
cout << "Nastepny pociag odjezdza o: " << *wsk << endl;
wsk++;
cout << "Kolejny pociag odjezdza o: " << *wsk << endl;
wsk+=1;
cout << "Ostatni pociag odjezdza o: " << *wsk << endl;
return 0;
}