#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class RPGCharacter {
public:
    string Name;
    string Perk;
    int Strength;
    int Perception;
    int Endurance;
    int Charisma;
    int Intelligence;
    int Agility;
    int Luck;

    RPGCharacter(string name, int strength, int perception,
         int endurance, int charisma, int intelligence, int agility, int luck,string perk) :
        Name(name), Strength(strength), Perception(perception), Endurance(endurance), Charisma(charisma), Intelligence(intelligence), Agility(agility), Luck(luck),
        Perk(perk) {}
};

void createNewCharacter();
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
        cout << "3. Quit" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            createNewCharacter();
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

void createNewCharacter() {
    string Name;
    string Perk;
    int Strength;
    int Perception;
    int Endurance;
    int Charisma;
    int Intelligence;
    int Agility;
    int Luck;

    cout << "Enter character name: ";
    getline(cin, Name);
    cout << "Enter character Perk: ";
    getline(cin, Perk);
    cout << "Enter character Strength: ";
    cin >> Strength;
    cout << "Enter character Perception: ";
    cin >> Perception;
    cout << "Enter character Endurance: ";
    cin >> Endurance;
    cout << "Enter character Charisma: ";
    cin >> Charisma;
    cout << "Enter character Intelligence: ";
    cin >> Intelligence;
    cout << "Enter character Agility: ";
    cin >> Agility;
    cout << "Enter character Luck: ";
    cin >> Luck;


    RPGCharacter character(Name,Strength,Perception,Endurance,Charisma,Intelligence,Agility,Luck,Perk);

    cout << "New character created!" << endl;
    string filename=character.Name;
    filename += ".txt";
    fstream file;
    file.open(filename, ios::out);
    if (file.is_open()) {
        file << character.Name << endl;
        file << character.Perk << endl;
        file << character.Strength << endl;
        file << character.Perception << endl;
        file << character.Endurance << endl;
        file << character.Charisma << endl;
        file << character.Intelligence << endl;
        file << character.Agility << endl;
        file << character.Luck << endl;

        file.close();
        cout << "Character saved to file!" << endl;
    }
    else {
        cout << "Error opening file." << endl;
    }
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

    string Name;
    string Perk;
    int Strength;
    int Perception;
    int Endurance;
    int Charisma;
    int Intelligence;
    int Agility;
    int Luck;

    getline(file, Name);
    getline(file, Perk);
    file >> Strength >> Perception >> Endurance >> Charisma >> Intelligence >> Agility >> Luck;

    RPGCharacter character(Name,Strength,Perception,Endurance,Charisma,Intelligence,Agility,Luck,Perk);
    file.close();

    cout << "Character loaded successfully." << endl;

    cout << "Character name: "<<Name<<endl;
    cout << "Character Perk: "<<Perk<<endl;
    cout << "Character Strength: "<<Strength<<endl;
    cout << "Character Perception: "<<Perception<<endl;
    cout << "Character Endurance: "<<Endurance<<endl;
    cout << "Character Charisma: "<<Charisma<<endl;
    cout << "Character Intelligence: "<<Intelligence<<endl;
    cout << "Character Agility: "<<Agility<<endl;
    cout << "Character Luck: "<<Luck<<endl;


    return character;
}