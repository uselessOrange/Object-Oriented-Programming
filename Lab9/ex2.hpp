#include <iostream>
using namespace std;


class hero {
    int str, dex, vit, intel, cha;
    public:

        void przyp_atr (int x) {
        str = x; dex = x; vit = x; intel = x;
        cha = x;
        };

        void wysw_atr() {
        cout<<"\t\t\tHero stats:"<<endl;
        cout<<"\tStrength: "<<str<<endl;
        cout<<"\tDexterity: "<<dex<<endl;
        cout<<"\tInteligence: "<<intel<<endl;
        cout<<"\tVitality: "<<vit<<endl;
        cout<<"\tCharisma: "<<cha<<endl;
        }
};

class knight : public hero {
    public:
    knight (int l){
        przyp_atr(l);
        wysw_atr();
    }
};