#include <iostream>
#include "Lab12_Func&Class.cpp"

int main(){
    Monster monster;
    Hero hero;

    Chem_Addict profession1;
    profession1.chooseClass(hero,"Mynam");

    int statsCombined(RPGCharacter);

    Battle(monster,hero);

    std::cout<<hero.Charisma<<std::endl;
    int out = statsCombined(monster);
    std::cout<<out<<std::endl;
    out = statsCombined(hero);  
    std::cout<<out<<std::endl;
    return 0;
}