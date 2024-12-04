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
        int maxTry;
};

class Pokemon {
    public:
        std::string pokemonName;
        std::string pokemonType;
        int Hp;

        Skill skill[4];

        std::string usedSkill;
};

void selectPokemon(Pokemon& myPokemon, Pokemon& battlePokemon);
Pokemon allocatePokemon(int chosen);
void battle(Pokemon& myPokemon, Pokemon& battlePokemon);
void pokemonInfo(Pokemon myPokemon, Pokemon battlePokemon, bool myturn);
void latestSkill(Pokemon myPokemon, Pokemon battlePokemon);
std::string generateString(int count);
void skillSet(int num, Pokemon myPokemon, Pokemon battlePokemon);

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
            {{"Tackle", "Normal", 4, 5},
            {"Grass Knot", "Grass", 8, 5},
            {"Thunderbolt", "Electric", 10, 5},
            {"Megabolt", "Electric", 15, 3}}, "-"}; 
        case 1:
            return {"Dratini", "Water", 41,
            {{"Wrap", "Normal", 4, 10},
            {"Aqua Tail", "Water", 3, 5},
            {"Water Pulse", "Water", 3, 5},
            {"Hyper Beam", "Normal", 20, 1}}, "-"};
        case 2:
            return {"Eevee", "Normal", 55,
            {{"Tackle", "Normal", 4, 5},
            {"Sand Attack", "Ground", 8, 3},
            {"Bite", "Normal", 12, 3},
            {"Rain Dance", "Water", 15, 1}}, "-"};   
        case 3:
            return {"Charmander", "Fire", 39,
            {{"Tackle", "Normal", 4, 5},
            {"Flamethrower", "Fire", 11, 5},
            {"Dig", "Ground", 7, 5},
            {"Heat Wave", "Fire", 14, 5}}, "-"};   
        case 4:
            return {"Palkia", "Water", 90,
            {{"Hydro Pump", "Water", 12, 10},
            {"Earth Power", "Ground", 15, 10},
            {"Surf", "Water", 13, 10},
            {"Spatial Rend", "Normal", 30, 10}}, "-"};
        default:
            return {"Unknown", "None", 0,
            {{"None", "None", 0, 0},
            {"None", "None", 0, 0},
            {"None", "None", 0, 0},
            {"None", "None", 0, 0}}, "-"};
    }
};

void battle(Pokemon& myPokemon, Pokemon& battlePokemon) {
    std::string myLatestSkill = "NONE";
    std::string yourLatestSkill = "NONE";
    int chosenSkill;
    bool myturn = true;

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

int intLength(int input) {
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

    cout << "| - Type: " << myPokemon.skill[num].skillType << generateString(21 - myPokemon.skill[num].skillType.length())
    << "| - Type: " << battlePokemon.skill[num].skillType << generateString(21 - battlePokemon.skill[num].skillType.length()) << "|" << endl;

    cout << "| - Damage: " << myPokemon.skill[num].damage << generateString(19 - intLength(myPokemon.skill[num].damage))
    << "| - Damage: " << battlePokemon.skill[num].damage << generateString(19 - intLength(battlePokemon.skill[num].damage)) << "|" << endl;

    cout << "| - Count: " << myPokemon.skill[num].maxTry << generateString(20 - intLength(myPokemon.skill[num].maxTry))
    << "| - Count: " << battlePokemon.skill[num].maxTry << generateString(20 - intLength(battlePokemon.skill[num].maxTry)) << "|" << endl;
}

