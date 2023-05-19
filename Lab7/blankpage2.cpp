#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class RPGCharacter {
public:
    string name;
    string classType;
    int level;
    int health;
    int attack;
    int defense;
    int strength;
    int dexterity;
    int endurance;
    int intelligence;
    int charisma;

    RPGCharacter(string n, int l, string c, int h, int a, int d, int s, int dex, int end, int intel, int cha) :
        name(n), level(l), classType(c), health(h), attack(a), defense(d), strength(s), dexterity(dex),
        endurance(end), intelligence(intel), charisma(cha) {}
};

void createNewCharacter();
RPGCharacter loadCharacter();
int main() {
    string name, classType;
    int level, health, attack, defense, strength, dexterity, endurance, intelligence, charisma;

    RPGCharacter character(name, level, classType, health, attack, defense, strength, dexterity, endurance, intelligence, charisma);



    int choice;
    do {
        cout << "Select an option:" << endl;
        cout << "1. Create new character" << endl;
        cout << "2. Load character" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
           
            break;
        case 2:
           loadCharacter();
        
            break;
        case 3:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 3);
    return 0;
}


RPGCharacter loadCharacter() {
    string filename;
    cout << "Enter character name to load: " << endl;
    cin >> filename;
    fstream file;
    file.open(filename, ios::in);

    if (!file) {
        cerr << "Error: unable to open file " << filename << endl;
        exit(0);
    }

    string name, classType;
    int level, health, attack, defense, strength, dexterity, endurance, intelligence, charisma;

    getline(file, name);
    getline(file, classType);
    file >> level >> health >> attack >> defense >> strength >> dexterity >> endurance >> intelligence >> charisma;

    RPGCharacter character(name, level, classType, health, attack, defense, strength, dexterity, endurance, intelligence, charisma);

    file.close();

    cout << "Character loaded successfully." << endl;
    std::cout<<"workie"<<std::endl;

    return character;

}