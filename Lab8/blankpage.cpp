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
        Name(name), Strength(strength), Perception(perception), 
        Endurance(endurance), Charisma(charisma), Intelligence(intelligence), Agility(agility), Luck(luck),
        Perk(perk) {}

    // Friend class declaration
    friend class FriendClass;

};

class FriendClass {
  public:
    void setValue(RPGCharacter& obj,string name, int strength, int perception,
         int endurance, int charisma, int intelligence, int agility, int luck,string perk) {
        obj.Name = name;
        obj.Strength = strength;
        obj.Perception = perception;
        obj.Endurance = endurance;
        obj.Charisma = charisma;
        obj.Intelligence = intelligence;
        obj.Agility = agility;
        obj.Luck = luck;
        obj.Perk = perk;
    }
    friend class Chem_Addict;
    friend class Brotherhood_of_Steel_Knight;
    friend class Enclave_Energy_Riffleman;
    friend class Raider_Scout;
};

class Chem_Addict {
    public:
    void chooseClass(RPGCharacter& obj,string name){
        FriendClass friendClass;
        friendClass.setValue(obj,name,4,4,3,4,4,4,4,"Chem Addict");
    }
};

class Brotherhood_of_Steel_Knight {
    public:
    void chooseClass(RPGCharacter& obj,string name){
        FriendClass friendClass;
        friendClass.setValue(obj,name,6,5,6,4,3,6,4,"Brotherhood of Steel Knight");
    }
};

class Enclave_Energy_Riffleman {
    public:
    void chooseClass(RPGCharacter& obj,string name){
        FriendClass friendClass;
        friendClass.setValue(obj,name,5,6,6,3,4,7,4,"Eclave Energy Riffleman");
    }
};

class Raider_Scout {
    public:
    void chooseClass(RPGCharacter& obj,string name){
        FriendClass friendClass;
        friendClass.setValue(obj,name,6,7,4,3,3,6,5,"Raider Scout");
    }
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
    std::cout<<"hello"<<std::endl;
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
    int choice;

void saveCharacter(RPGCharacter character,string Name,string Perk,int Strength,
int Perception,int Endurance,int Charisma,int Intelligence,int Agility,int Luck);



    cout<< "Would You like to create your own character or choose an existing class?"<<endl;
    cout<< "1. Create your own character"<<endl;
    cout<< "2. Choose an existing class"<<endl;
    cin >> choice;
    cin.ignore();

    if (choice==1) {

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
            saveCharacter(character,Name,Perk,Strength,
            Perception,Endurance,Charisma,Intelligence,Agility,Luck);
    }

    else if (choice==2){
        
        RPGCharacter character("Name",1,1,1,1,1,1,1,"Perk");
        Chem_Addict profession1;
        Brotherhood_of_Steel_Knight profession2;
        Enclave_Energy_Riffleman profession3;
        Raider_Scout profession4;
        int profession_choice;

        cout << "Enter character name: ";
        getline(cin, Name);

        cout << "Choose Profssion "<<endl;
        cout << "1. ChemAddict"<<endl;
        cout << "2. Brotherhoodof SteelKnight"<<endl;
        cout << "3. Enclave Energy Riffleman"<<endl;
        cout << "4. Raider Scout"<<endl;

        cin >> profession_choice;

        switch (profession_choice){
        case 1:
            profession1.chooseClass(character,Name);
            break;
        case 2:
            profession2.chooseClass(character,Name);
            break;
        case 3:
            profession3.chooseClass(character,Name);
            break;
        case 4:
            profession4.chooseClass(character,Name);
            break;
        }
        saveCharacter(character,character.Name,character.Perk,character.Strength,
        character.Perception,character.Endurance,character.Charisma,character.Intelligence,
        character.Agility,character.Luck);
        
    }
    else
    {
        cout<< "Invalid choice" <<std::endl;
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

void saveCharacter(RPGCharacter character,string Name,string Perk,int Strength,
int Perception,int Endurance,int Charisma,int Intelligence,int Agility,int Luck){
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