#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

class Skill {
    public:
        std::string skillName;
        std::string skillType;
        int damage;
        int Try;
        int MaxTry;
};
class Pokemon {
    public:
        std::string pokemonName;
        std::string pokemonType;
        int Hp;

        Skill skill[4];

        std::string usedSkill;
};

//Declare Functions
void selectPokemon(Pokemon& myPokemon, Pokemon& battlePokemon);
Pokemon allocatePokemon(int chosen);
void battle(Pokemon& myPokemon, Pokemon& battlePokemon);
void battleInterface(Pokemon& myPokemon, Pokemon& battlePokemon, bool myturn, int& chosenSkill);
std::string generateString(int count);
int intLength(int& input);
void pokemonInfo(Pokemon myPokemon, Pokemon battlePokemon, bool myturn);
void latestSkill(Pokemon myPokemon, Pokemon battlePokemon);
void skillSet(int num, Pokemon myPokemon, Pokemon battlePokemon);
int checkingSkills(std::string skill, std::string type);

//Main Function
int main() {
    Pokemon myPokemon;
    Pokemon battlePokemon;
    
    //Select Pokemon
    selectPokemon(myPokemon, battlePokemon);
    //Battle Page
    battle(myPokemon, battlePokemon);
};

void selectPokemon(Pokemon& myPokemon, Pokemon& battlePokemon) {
    bool chosenPokemon = false;
    int selectMine;
    int selectYours;
    
    //Choosing my Pokemon.
    cout << "Choose a Pokemon(0~4): ";
    cin >> selectMine;
    //Allocate myPokemon elements.
    myPokemon = allocatePokemon(selectMine);
    //Choosing opponent's Pokemon.
    while(!chosenPokemon) {
        cout << "Choose a Pokemon(0~4): ";
        cin >> selectYours;
        //Check whether battlePokemon is same as myPokemon.
        if (selectMine == selectYours) {
            cout << "You have to choose Pokemons different from each other." << std::endl;
        } 
        else {
            battlePokemon = allocatePokemon(selectYours);
            //Exit loop when it is different.
            chosenPokemon = true;
        }
    }
};

Pokemon allocatePokemon(int chosen) {
     switch(chosen) {
        case 0:
            return {"Pikachu", "Electric", 35,
            {{"Tackle", "Normal", 4, 5, 5},
            {"Grass Knot", "Grass", 8, 5, 5},
            {"Thunderbolt", "Electric", 10, 5, 5},
            {"Megabolt", "Electric", 15, 3, 3}}, "-"}; 
        case 1:
            return {"Dratini", "Water", 41,
            {{"Wrap", "Normal", 4, 10, 10},
            {"Aqua Tail", "Water", 3, 5, 5},
            {"Water Pulse", "Water", 3, 5, 5},
            {"Hyper Beam", "Normal", 20, 1, 1}}, "-"};
        case 2:
            return {"Eevee", "Normal", 55,
            {{"Tackle", "Normal", 4, 5, 5},
            {"Sand Attack", "Ground", 8, 3, 3},
            {"Bite", "Normal", 12, 3, 3},
            {"Rain Dance", "Water", 15, 1, 1}}, "-"};   
        case 3:
            return {"Charmander", "Fire", 39,
            {{"Tackle", "Normal", 4, 5, 5},
            {"Flamethrower", "Fire", 11, 5, 5},
            {"Dig", "Ground", 7, 5, 5},
            {"Heat Wave", "Fire", 14, 5, 5}}, "-"};   
        case 4:
            return {"Palkia", "Water", 90,
            {{"Hydro Pump", "Water", 12, 10, 10},
            {"Earth Power", "Ground", 15, 10, 10},
            {"Surf", "Water", 13, 10, 10},
            {"Spatial Rend", "Normal", 30, 10 ,10}}, "-"};
        default:
            return {"Unknown", "None", 0,
            {{"None", "None", 0, 0, 0},
            {"None", "None", 0, 0, 0},
            {"None", "None", 0, 0, 0},
            {"None", "None", 0, 0, 0}}, "-"};
    }
};

void battle(Pokemon& myPokemon, Pokemon& battlePokemon) {
    int chosenSkill = 0;
    int damage = 0;
    bool myturn = true;

    while (myPokemon.Hp > 0 && battlePokemon.Hp > 0) {
        battleInterface(myPokemon, battlePokemon, myturn, chosenSkill);
        if (myturn) {
            if (myPokemon.skill[chosenSkill].Try != 0) {
                 if (checkingSkills(myPokemon.skill[chosenSkill].skillType, battlePokemon.pokemonType) == 0) {
                cout << myPokemon.pokemonName << " used " << myPokemon.skill[chosenSkill].skillName <<  "." << endl;
                cout << "It was not very effective." << endl;
                damage = myPokemon.skill[chosenSkill].damage - 3;
                } 
                else if (checkingSkills(myPokemon.skill[chosenSkill].skillType, battlePokemon.pokemonType) == 1) {
                    cout << myPokemon.pokemonName << " used " << myPokemon.skill[chosenSkill].skillName <<  "." << endl;
                    cout << "It was effective." << endl;
                    damage = myPokemon.skill[chosenSkill].damage;
                } 
                else if (checkingSkills(myPokemon.skill[chosenSkill].skillType, battlePokemon.pokemonType) == 2) {
                    cout << myPokemon.pokemonName << " used " << myPokemon.skill[chosenSkill].skillName <<  "." << endl;
                    cout << "It was super effective." << endl;
                    damage = myPokemon.skill[chosenSkill].damage + 5;
                }
                battlePokemon.Hp -= damage;
                myPokemon.skill[chosenSkill].Try -= 1;
                myPokemon.usedSkill = myPokemon.skill[chosenSkill].skillName;
                myturn = false;
            } 
            else if (myPokemon.skill[chosenSkill].Try == 0) {
                cout << myPokemon.pokemonName << "failed to perform " << myPokemon.skill[chosenSkill].skillName << endl;
                myturn = false;
            }
        }
        else {
            if (battlePokemon.skill[chosenSkill].Try != 0) {
                if (checkingSkills(battlePokemon.skill[chosenSkill].skillType, myPokemon.pokemonType) == 0) {
                cout << battlePokemon.pokemonName << " used " << battlePokemon.skill[chosenSkill].skillName <<  "." << endl;
                cout << "It was not very effective" << endl;
                damage = battlePokemon.skill[chosenSkill].damage - 3;
                } 
                else if (checkingSkills(battlePokemon.skill[chosenSkill].skillType, myPokemon.pokemonType) == 1) {
                    cout << battlePokemon.pokemonName << " used " << battlePokemon.skill[chosenSkill].skillName <<  "." << endl;
                    cout << "It was effective" << endl;
                    damage = battlePokemon.skill[chosenSkill].damage;
                } 
                else if (checkingSkills(battlePokemon.skill[chosenSkill].skillType, myPokemon.pokemonType) == 2) {
                    cout << battlePokemon.pokemonName << " used " << battlePokemon.skill[chosenSkill].skillName <<  "." << endl;
                    cout << "It was super effective" << endl;
                    damage = battlePokemon.skill[chosenSkill].damage + 5;
                }
                myPokemon.Hp -= damage;
                battlePokemon.skill[chosenSkill].Try -= 1;
                battlePokemon.usedSkill = battlePokemon.skill[chosenSkill].skillName;
                myturn = true;
            } 
            else if (battlePokemon.skill[chosenSkill].Try == 0) {
                cout << battlePokemon.pokemonName << "failed to perform " << battlePokemon.skill[chosenSkill].skillName << endl;
                myturn = true;
            }
        }
    }
    
    if (myPokemon.Hp <= 0) {
        cout << "===============================================================" << endl;
        cout << "Match Result: " << battlePokemon.pokemonName << " defeats " << myPokemon.pokemonName << endl;
    } else if (battlePokemon.Hp <= 0) {
        cout << "===============================================================" << endl;
        cout << "Match Result: " << myPokemon.pokemonName << " defeats " << battlePokemon.pokemonName << endl;
    }
} 

void battleInterface(Pokemon& myPokemon, Pokemon& battlePokemon, bool myturn, int& chosenSkill) {
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" << endl;
    cout << "+------------------------------+------------------------------+" << endl;
    pokemonInfo(myPokemon, battlePokemon, myturn);
    cout << "+------------------------------+------------------------------+" << endl;
    latestSkill(myPokemon, battlePokemon);
    cout << "+------------------------------+------------------------------+" << endl;
    skillSet(0, myPokemon, battlePokemon);
    skillSet(1, myPokemon, battlePokemon);
    skillSet(2, myPokemon, battlePokemon);
    skillSet(3, myPokemon, battlePokemon);
    cout << "+------------------------------+------------------------------+" << endl;
    cout << "Choose a skill (0~3): ";
    cin >> chosenSkill;
}

std::string generateString(int count) {
    return std::string(std::max(0, count), ' ');
}

int intLength(int& input) {
    return std::floor(std::log10(std::abs(input))) + 1;
}

void pokemonInfo(Pokemon myPokemon, Pokemon battlePokemon, bool myturn) {
    if (myturn) {

        cout << "| " << myPokemon.pokemonName << " (*)" << generateString(25 - myPokemon.pokemonName.length()) 
        << "| " << battlePokemon.pokemonName << generateString(29 - battlePokemon.pokemonName.length()) << "|" << endl;

        cout << "| Type: " << myPokemon.pokemonType << generateString(23 - myPokemon.pokemonType.length()) 
        << "| Type: " << battlePokemon.pokemonType << generateString(23 - battlePokemon.pokemonType.length()) << "|" << endl;

        cout << "| HP: " << myPokemon.Hp << generateString(25 - intLength(myPokemon.Hp))
        << "| HP: " << battlePokemon.Hp << generateString(25 - intLength(battlePokemon.Hp)) << "|"<< endl;

    } else {
        cout << "| " << myPokemon.pokemonName << generateString(29 - myPokemon.pokemonName.length()) 
        << "| " << battlePokemon.pokemonName << " (*)" << generateString(25 - battlePokemon.pokemonName.length()) << "|"<< endl;

        cout << "| Type: " << myPokemon.pokemonType << generateString(23 - myPokemon.pokemonType.length()) 
        << "| Type: " << battlePokemon.pokemonType << generateString(23 - battlePokemon.pokemonType.length()) << "|" << endl;

        cout << "| HP: " << myPokemon.Hp << generateString(25 - intLength(myPokemon.Hp))
        << "| HP: " << battlePokemon.Hp << generateString(25 - intLength(battlePokemon.Hp)) << "|"<< endl;
    }
}

void latestSkill(Pokemon myPokemon, Pokemon battlePokemon) {
    cout << "| Latest Skill: " << myPokemon.usedSkill << generateString(15 - myPokemon.usedSkill.length()) << "| Latest Skill: " << battlePokemon.usedSkill << generateString(15 - battlePokemon.usedSkill.length()) << "|" << endl; //60char -> 30char
    cout << "|" << generateString(30) << "|" << generateString(30) << "|" << endl;
}

void skillSet(int num, Pokemon myPokemon, Pokemon battlePokemon) {
    cout << "| (" << num << ") " << myPokemon.skill[num].skillName << generateString(25 - myPokemon.skill[num].skillName.length())
    << "| (" << num << ") " << battlePokemon.skill[num].skillName << generateString(25 - battlePokemon.skill[num].skillName.length()) << "|" << endl;

    cout << "|     - Type: " << myPokemon.skill[num].skillType << generateString(17 - myPokemon.skill[num].skillType.length())
    << "|     - Type: " << battlePokemon.skill[num].skillType << generateString(17 - battlePokemon.skill[num].skillType.length()) << "|" << endl;

    cout << "|     - Damage: " << myPokemon.skill[num].damage << generateString(15 - intLength(myPokemon.skill[num].damage))
    << "|     - Damage: " << battlePokemon.skill[num].damage << generateString(15 - intLength(battlePokemon.skill[num].damage)) << "|" << endl;
    
    if (myPokemon.skill[num].Try != 0 && battlePokemon.skill[num].Try != 0) {
        cout << "|     - Count: " << myPokemon.skill[num].Try << "(" << myPokemon.skill[num].MaxTry << ")" 
        << generateString(14 - intLength(myPokemon.skill[num].MaxTry) - intLength(myPokemon.skill[num].Try))
        << "|     - Count: " << battlePokemon.skill[num].Try << "(" << battlePokemon.skill[num].MaxTry << ")" 
        <<  generateString(14 - intLength(battlePokemon.skill[num].MaxTry) - intLength(battlePokemon.skill[num].Try)) << "|" << endl;
    } else if (myPokemon.skill[num].Try == 0 && battlePokemon.skill[num].Try != 0) {
        cout << "|     - Count: " << myPokemon.skill[num].Try << "(" << myPokemon.skill[num].MaxTry << ")" 
        << generateString(13 - intLength(myPokemon.skill[num].MaxTry))
        << "|     - Count: " << battlePokemon.skill[num].Try << "(" << battlePokemon.skill[num].MaxTry << ")" 
        <<  generateString(14 - intLength(battlePokemon.skill[num].MaxTry) - intLength(battlePokemon.skill[num].Try)) << "|" << endl;
    } else if (myPokemon.skill[num].Try != 0 && battlePokemon.skill[num].Try == 0) {
        cout << "|     - Count: " << myPokemon.skill[num].Try << "(" << myPokemon.skill[num].MaxTry << ")" 
        << generateString(14 - intLength(myPokemon.skill[num].MaxTry) - intLength(myPokemon.skill[num].Try))
        << "|     - Count: " << battlePokemon.skill[num].Try << "(" << battlePokemon.skill[num].MaxTry << ")" 
        <<  generateString(13 - intLength(battlePokemon.skill[num].MaxTry)) << "|" << endl;
    } else {
        cout << "|     - Count: " << myPokemon.skill[num].Try << "(" << myPokemon.skill[num].MaxTry << ")" 
        << generateString(13 - intLength(myPokemon.skill[num].MaxTry))
        << "|     - Count: " << battlePokemon.skill[num].Try << "(" << battlePokemon.skill[num].MaxTry << ")" 
        <<  generateString(13 - intLength(battlePokemon.skill[num].MaxTry)) << "|" << endl;
    }
    
}

int checkingSkills(std::string skill, std::string type) {
    if (skill == "Normal") {
        return 1;
    } else if (skill == "Ground") {
        if (type == "Electric") {
            return 2;
        } else if (type == "Grass") {
            return 0;
        } else if (type == "Fire") {
            return 2;
        } else {
            return 1;
        }
    } else if (skill == "Electric") {
        if (type == "Ground") {
            return 0;
        } else if (type == "Electric") {
            return 0;
        } else if (type == "Water") {
            return 2;
        } else if (type == "Grass") {
            return 0;
        } else {
            return 1;
        }
    } else if (skill == "Water") {
        if (type == "Ground") {
            return 2;
        } else if (type == "Water") {
            return 0;
        } else if (type == "Grass") {
            return 0;
        } else if (type == "Fire") {
            return 2;
        } else {
            return 1;
        }
    } else if (skill == "Grass") {
        if (type == "Ground") {
            return 0;
        } else if (type == "Water") {
            return 2;
        } else if (type == "Grass") {
            return 0;
        } else if (type == "Fire") {
            return 0;
        } else {
            return 1;
        }
    } else if (skill =="Fire") {
        if (type == "Water") {
            return 0;
        } else if (type == "Grass") {
            return 2;
        } else if (type == "Fire") {
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}
