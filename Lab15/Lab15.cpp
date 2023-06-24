#include <iostream>
#include <fstream>
#include <string>
#include "Lab15_Func&Class.cpp"
//#include "Lab15.hpp"

//using namespace std;
//std::









int main() {
    int choice;
    Monster monster;
    Hero hero;
    string monsterName;
    Battle<RPGCharacter> battle;
    BattleHistory battle_history;
// Test bench
/*  

    battle_history.showBattleHistory();
    for (int i = 0; i < 6; i++)
    {
        battle_history.updateBattleHistroy(1);
        battle_history.updateBattleHistroy(-1);
    }
    battle_history.showBattleHistory();
*/
//end of test bench   
    



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
            battle(monster, hero, battle_history);   
            break;      
        case 5:
            std::cout<<">>>>>>"<<std::endl;
            showStats(monster);
            std::cout<<">>>>>>"<<std::endl;
            showStats(hero);
            std::cout<<">>>>>>"<<std::endl;
            battle_history.showBattleHistory();
            std::cout<<">>>>>>"<<std::endl;
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

