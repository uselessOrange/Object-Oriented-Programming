#include <iostream>
#include <fstream>
#include <string>
#include "Lab12_Func&Class.cpp"
//#include "Lab12.hpp"

//using namespace std;
//std::









int main() {
    int choice;
    Monster monster;
    Hero hero;
    string monsterName;
    Battle<RPGCharacter> battle;

    WelcomeScreen();
    do {

        choice=selectionMenu();
        Monster monsterNew;
        switch (choice) {
        case 1:
            createNewCharacter(hero);
            break;
        case 2:
            loadCharacter(hero);
            break;
        case 3:
            cout << "Enter monster name: ";
            getline(cin, monsterName);
            monsterNew.ChangeName(monsterName);
            monster=monsterNew;
            break;
        case 4:
            //Battle(monster,hero); 
            battle(monster, hero);   
            break;      
        case 5:
            showStats(monster);
            showStats(hero);
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}

