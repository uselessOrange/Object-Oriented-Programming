#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<cstdlib>
#include "my_rand.cpp"

//std::

using namespace std;



class RPGCharacter {
public:
    std::string Name;
    std::string Perk;
    int Strength;
    int Perception;
    int Endurance;
    int Charisma;
    int Intelligence;
    int Agility;
    int Luck;
    int Experience;
    int Level;
    virtual ~RPGCharacter(){};
    virtual void Battle(){};
};

class Hero: public RPGCharacter {
    public:

        Hero(){

            Name="Name";
            Perk="Perk";
            Experience=1;
            Level=1;
            Strength=1;
            Perception=1;
            Endurance=1;
            Charisma=1;
            Intelligence=1;
            Agility=1;
            Luck=1;
        }
        void setValue(string name,int experience,int level, int strength, int perception,
         int endurance, int charisma, int intelligence, int agility, int luck,string perk) {
        Name = name;
        Experience=experience;
        Level=level;
        Strength = strength;
        Perception = perception;
        Endurance = endurance;
        Charisma = charisma;
        Intelligence = intelligence;
        Agility = agility;
        Luck = luck;
        Perk = perk;
    }
};


class Monster: public RPGCharacter {
    public:

        Monster(){
            void my_rand(int*,int,int,int);
            Name="monster";
            Perk="none";


            int length=8;
            int randomNumberVector[length];
            my_rand(randomNumberVector,length,0,9);
            
            Strength=randomNumberVector[0];
            Perception=randomNumberVector[1];
            Endurance=randomNumberVector[2];
            Charisma=randomNumberVector[3];
            Intelligence=randomNumberVector[4];
            Agility=randomNumberVector[5];
            Luck=randomNumberVector[6];
            Level=randomNumberVector[7];
            Experience=0;
        }
        void ChangeName(std::string monsterName){
            Name=monsterName;
        }
        ~Monster(){};
};


class Chem_Addict : public Hero {
    public:
    void chooseClass(Hero& obj,string name){
        obj.setValue(name,1,1,4,4,3,4,4,4,4,"Chem Addict");
    }
};

class Brotherhood_of_Steel_Knight : public Hero {
    public:
    void chooseClass(Hero& obj,string name){
        obj.setValue(name,1,1,6,5,6,4,3,6,4,"Brotherhood of Steel Knight");
    }
};

class Enclave_Energy_Riffleman : public Hero {
    public:
    void chooseClass(Hero& obj,string name){
        obj.setValue(name,1,1,5,6,6,3,4,7,4,"Eclave Energy Riffleman");
    }
};

class Raider_Scout : public Hero {
    public:
    void chooseClass(Hero& obj,string name){
        obj.setValue(name,1,1,6,7,4,3,3,6,5,"Raider Scout");
    }
};



void createNewCharacter(Hero& character) {
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

            
            character.setValue(Name,1,1,Strength,Perception,Endurance,Charisma,Intelligence,Agility,Luck,Perk);
            
            cout << "New character created!" << endl;
            saveCharacter(character,Name,Perk,Strength,
            Perception,Endurance,Charisma,Intelligence,Agility,Luck);
    }    
    else if (choice==2){
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

void loadCharacter(Hero& character) {
    string filename;
    cout << "Enter character name to load: " << endl;
    cin >> filename;
    filename += ".txt";
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
    int Experience;
    int Level;
    getline(file, Name);
    getline(file, Perk);
    file >> Strength >> Perception >> Endurance >> Charisma >> Intelligence >> Agility >> Luck >> Experience >> Level;


    file.close();

    cout << "Character loaded successfully." << endl;

    cout << "Character name: "<<Name<<endl;
    cout << "Character Perk: "<<Perk<<endl;
    cout << "Character Experience: "<<Experience<<endl;
    cout << "Character Level: "<<Level<<endl;
    cout << "Character Strength: "<<Strength<<endl;
    cout << "Character Perception: "<<Perception<<endl;
    cout << "Character Endurance: "<<Endurance<<endl;
    cout << "Character Charisma: "<<Charisma<<endl;
    cout << "Character Intelligence: "<<Intelligence<<endl;
    cout << "Character Agility: "<<Agility<<endl;
    cout << "Character Luck: "<<Luck<<endl;

    character.setValue(Name,Experience,Level,Strength,Perception,Endurance,
    Charisma,Intelligence,Agility,Luck,Perk);

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
                file << character.Experience << endl;
                file << character.Level << endl;
                
                file.close();
                cout << "Character saved to file!" << endl;
            }
            else {
                cout << "Error opening file." << endl;
            }
            }




template <typename Character>
class Battle {
public:
    void operator()(Character& monster, Character& hero) {
        int statsCombined(Character obj);
        int monsterPower;
        int heroPower;
        monsterPower = statsCombined(monster);
        heroPower = statsCombined(hero);
        int outcome = heroPower - monsterPower;
        if (outcome > 0) {
            hero.Experience = hero.Experience + monster.Level;
            hero.Level = hero.Level + 1;
            std::cout << "Hero has won!" << std::endl;
        } else if (outcome < 0) {
            hero.Experience = 1;
            hero.Level = 1;
            std::cout << "Hero has lost!" << std::endl;
        } else {
            std::cout << "I took an arrow to the knee" << std::endl;
        }
    }
};


/*
void Battle(RPGCharacter& monster,RPGCharacter& hero){
    int statsCombined(RPGCharacter obj);
    int monsterPower;
    int heroPower;
    monsterPower=statsCombined(monster);
    heroPower=statsCombined(hero);
    int outcome;
    outcome=heroPower-monsterPower;
    if (outcome>0){
        hero.Experience=hero.Experience+monster.Level;
        hero.Level=hero.Level+1;
        std::cout<<"Hero has won!"<<std::endl;
    }
    else if (outcome<0){
        hero.Experience=1;
        hero.Level=1;
        std::cout<<"Hero has lost!"<<std::endl;
    }
    else {
        std::cout<<"I took an arrow to the knee"<<std::endl;
    }
};
*/
int statsCombined(RPGCharacter obj){
    int characterPower=obj.Strength+obj.Perception
    +obj.Endurance+obj.Charisma+obj.Intelligence+obj.Agility
    +obj.Luck+obj.Experience+obj.Level;

    return characterPower;
};

void showStats(RPGCharacter obj){
    cout << "Character name: "<<obj.Name<<endl;
    cout << "Character Perk: "<<obj.Perk<<endl;
    cout << "Character Experience: "<<obj.Experience<<endl;
    cout << "Character Level: "<<obj.Level<<endl;
    cout << "Character Strength: "<<obj.Strength<<endl;
    cout << "Character Perception: "<<obj.Perception<<endl;
    cout << "Character Endurance: "<<obj.Endurance<<endl;
    cout << "Character Charisma: "<<obj.Charisma<<endl;
    cout << "Character Intelligence: "<<obj.Intelligence<<endl;
    cout << "Character Agility: "<<obj.Agility<<endl;
    cout << "Character Luck: "<<obj.Luck<<endl;
}

int selectionMenu(){
        int choice;

        cout << "Select an option:" << endl;
        cout << "1. Create new character" << endl;
        cout << "2. Load character" << endl;
        cout << "3. Create a monster" << endl;
        cout << "4. Battle" << endl;
        cout << "5. Show stats" << endl;
        cout << "6. Quit" << endl;
        cin >> choice;
        cin.ignore();
        return choice;
}

void WelcomeScreen(){
    std::ifstream inputFile("falloutBoy.txt"); // Replace "example.txt" with the path to your text file
    if (!inputFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;

    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "hello" << std::endl;
    inputFile.close();

}