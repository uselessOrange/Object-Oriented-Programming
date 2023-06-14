#include <iostream>
#include <fstream>
#include <string>
#include "Lab9_Func&Class.cpp"
using namespace std;







void createNewCharacter();
Monster createNewMonster(string);
RPGCharacter loadCharacter();

int main() {
    int choice;
    std::ifstream inputFile("falloutBoy.txt"); // Replace "example.txt" with the path to your text file
    if (!inputFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "hello" << std::endl;
    inputFile.close();
    
    do {
        cout << "Select an option:" << endl;
        cout << "1. Create new character" << endl;
        cout << "2. Load character" << endl;
        cout << "3. Create a monster" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;
        cin.ignore();
        string monsterName;
        Monster obj;

        switch (choice) {
        case 1:
            createNewCharacter();
            break;
        case 2:
            loadCharacter();
            break;
        case 3:
            
            cout << "Enter monster name: ";
            getline(cin, monsterName);
            obj.createNewMonster(monsterName);
            break;            
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 4);
    return 0;
}

