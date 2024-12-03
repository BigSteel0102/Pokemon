#include <iostream>
#include <vector>

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

        Skill skill_0;
        Skill skill_1;
        Skill skill_2;
        Skill skill_3;
};

void selectPokemon(Pokemon& myPokemon, Pokemon& battlePokemon);
Pokemon allocatePokemon(int chosen);
void battle(Pokemon& myPokemon, Pokemon& battlePokemon);

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
    std::cout << "Choose a Pokemon(0~4): ";
    std::cin >> selectMine;
    //Allocate myPokemon elements.
    myPokemon = allocatePokemon(selectMine);
    //Choosing opponent's Pokemon.
    while(!chosenPokemon) {
        std::cout << "Choose a Pokemon(0~4): ";
        std::cin >> selectYours;
        //Check whether battlePokemon is same as myPokemon.
        if (selectMine == selectYours) {
            std::cout << "You have to choose Pokemons different from each other." << std::endl;
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
            {"Tackle", "Normal", 4, 5},
            {"Grass Knot", "Grass", 8, 5},
            {"Thunderbolt", "Electric", 10, 5},
            {"Megabolt", "Electric", 15, 3}}; 
        case 1:
            return {"Dratini", "Water", 41,
            {"Wrap", "Normal", 4, 10},
            {"Aqua Tail", "Water", 3, 5},
            {"Water Pulse", "Water", 3, 5},
            {"Hyper Beam", "Normal", 20, 1}};
        case 2:
            return {"Eevee", "Normal", 55,
            {"Tackle", "Normal", 4, 5},
            {"Sand Attack", "Ground", 8, 3},
            {"Bite", "Normal", 12, 3},
            {"Rain Dance", "Water", 15, 1}};   
        case 3:
            return {"Charmander", "Fire", 39,
            {"Tackle", "Normal", 4, 5},
            {"Flamethrower", "Fire", 11, 5},
            {"Dig", "Ground", 7, 5},
            {"Heat Wave", "Fire", 14, 5}};   
        case 4:
            return {"Palkia", "Water", 90,
            {"Hydro Pump", "Water", 12, 10},
            {"Earth Power", "Ground", 15, 10},
            {"Surf", "Water", 13, 10},
            {"Spatial Rend", "Normal", 30, 10}};
        default:
            return {"Unknown", "None", 0,
            {"None", "None", 0, 0},
            {"None", "None", 0, 0},
            {"None", "None", 0, 0},
            {"None", "None", 0, 0}};
    }
};

void battle(Pokemon& myPokemon, Pokemon& battlePokemon) {
    std::string myLatestSkill = "NONE";
    std::string yourLatestSkill = "NONE";
    int chosenSkill;
    bool myturn = true;
    if (myPokemon.Hp !=0 && battlePokemon.Hp !=0 && myturn) {
        std::cout << "+-------------------------------------------------------------+\n";
        std::cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |\n";
        std::cout << "+------------------------------+------------------------------+\n";
        std::cout << "| " << myPokemon.pokemonName << "(*)| "<< battlePokemon.pokemonName << "|\n";
        std::cout << "| Type: " << myPokemon.pokemonType << "| Type: "<< battlePokemon.pokemonType << "|\n";
        std::cout << "| HP: " << myPokemon.Hp << "| " << battlePokemon.Hp << "|\n";
        std::cout << "+------------------------------+------------------------------+\n";
        std::cout << "| Latest Skill: " << myLatestSkill << "| LatestSkill" << yourLatestSkill << "|\n";
        std::cout << "|                              |                              |\n";
        std::cout << "+------------------------------+------------------------------+\n";
        std::cout << "| (0) " << myPokemon.skill_0.skillName << "| (0) " << battlePokemon.skill_0.skillName << "|\n";
        std::cout << "| - Type: " << myPokemon.skill_0.skillType << "| - Type: " << battlePokemon.skill_0.skillType << "|\n";
        std::cout << "| - Damage: " << myPokemon.skill_0.damage << "| - Damage: " << battlePokemon.skill_0.damage << "|\n";
        std::cout << "| - Count: " << myPokemon.skill_0.maxTry << "| - Count: " << battlePokemon.skill_0.maxTry << "|\n";
        std::cout << "| (1) " << myPokemon.skill_1.skillName << "| (1) " << battlePokemon.skill_1.skillName << "|\n";
        std::cout << "| - Type: " << myPokemon.skill_1.skillType << "| - Type: " << battlePokemon.skill_1.skillType << "|\n";
        std::cout << "| - Damage: " << myPokemon.skill_1.damage << "| - Damage: " << battlePokemon.skill_1.damage << "|\n";
        std::cout << "| - Count: " << myPokemon.skill_1.maxTry << "| - Count: " << battlePokemon.skill_1.maxTry << "|\n";
        std::cout << "| (2) " << myPokemon.skill_2.skillName << "| (2) " << battlePokemon.skill_2.skillName << "|\n";
        std::cout << "| - Type: " << myPokemon.skill_2.skillType << "| - Type: " << battlePokemon.skill_2.skillType << "|\n";
        std::cout << "| - Damage: " << myPokemon.skill_2.damage << "| - Damage: " << battlePokemon.skill_2.damage << "|\n";
        std::cout << "| - Count: " << myPokemon.skill_2.maxTry << "| - Count: " << battlePokemon.skill_2.maxTry << "|\n";
        std::cout << "| (3) " << myPokemon.skill_3.skillName << "| (3) " << battlePokemon.skill_3.skillName << "|\n";
        std::cout << "| - Type: " << myPokemon.skill_3.skillType << "| - Type: " << battlePokemon.skill_3.skillType << "|\n";
        std::cout << "| - Damage: " << myPokemon.skill_3.damage << "| - Damage: " << battlePokemon.skill_3.damage << "|\n";
        std::cout << "| - Count: " << myPokemon.skill_3.maxTry << "| - Count: " << battlePokemon.skill_3.maxTry << "|\n";
        std::cout << "+------------------------------+------------------------------+\n";
        std::cout << "Choose a skill (0~3): ";
        std::cin >> chosenSkill;
        std::cout << chosenSkill;
    } else if (myPokemon.Hp !=0 && battlePokemon.Hp !=0 && !myturn) {
        std::cout << "+-------------------------------------------------------------+\n";
        std::cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |\n";
        std::cout << "+------------------------------+------------------------------+\n";
        std::cout << "| " << myPokemon.pokemonName << "| "<< battlePokemon.pokemonName << " (*) |\n";
        std::cout << "| Type: " << myPokemon.pokemonType << "| Type: "<< battlePokemon.pokemonType << "|\n";
        std::cout << "| HP: " << myPokemon.Hp << "| " << battlePokemon.Hp << "|\n";
        std::cout << "+------------------------------+------------------------------+\n";
        std::cout << "| Latest Skill: " << myLatestSkill << "| LatestSkill" << yourLatestSkill << "|\n";
        std::cout << "|                              |                              |\n";
        std::cout << "+------------------------------+------------------------------+\n";
        std::cout << "| (0) " << myPokemon.skill_0.skillName << "| (0) " << battlePokemon.skill_0.skillName << "|\n";
        std::cout << "| - Type: " << myPokemon.skill_0.skillType << "| - Type: " << battlePokemon.skill_0.skillType << "|\n";
        std::cout << "| - Damage: " << myPokemon.skill_0.damage << "| - Damage: " << battlePokemon.skill_0.damage << "|\n";
        std::cout << "| - Count: " << myPokemon.skill_0.maxTry << "| - Count: " << battlePokemon.skill_0.maxTry << "|\n";
        std::cout << "| (1) " << myPokemon.skill_1.skillName << "| (1) " << battlePokemon.skill_1.skillName << "|\n";
        std::cout << "| - Type: " << myPokemon.skill_1.skillType << "| - Type: " << battlePokemon.skill_1.skillType << "|\n";
        std::cout << "| - Damage: " << myPokemon.skill_1.damage << "| - Damage: " << battlePokemon.skill_1.damage << "|\n";
        std::cout << "| - Count: " << myPokemon.skill_1.maxTry << "| - Count: " << battlePokemon.skill_1.maxTry << "|\n";
        std::cout << "| (2) " << myPokemon.skill_2.skillName << "| (2) " << battlePokemon.skill_2.skillName << "|\n";
        std::cout << "| - Type: " << myPokemon.skill_2.skillType << "| - Type: " << battlePokemon.skill_2.skillType << "|\n";
        std::cout << "| - Damage: " << myPokemon.skill_2.damage << "| - Damage: " << battlePokemon.skill_2.damage << "|\n";
        std::cout << "| - Count: " << myPokemon.skill_2.maxTry << "| - Count: " << battlePokemon.skill_2.maxTry << "|\n";
        std::cout << "| (3) " << myPokemon.skill_3.skillName << "| (3) " << battlePokemon.skill_3.skillName << "|\n";
        std::cout << "| - Type: " << myPokemon.skill_3.skillType << "| - Type: " << battlePokemon.skill_3.skillType << "|\n";
        std::cout << "| - Damage: " << myPokemon.skill_3.damage << "| - Damage: " << battlePokemon.skill_3.damage << "|\n";
        std::cout << "| - Count: " << myPokemon.skill_3.maxTry << "| - Count: " << battlePokemon.skill_3.maxTry << "|\n";
        std::cout << "+------------------------------+------------------------------+\n";
        std::cout << "Choose a skill (0~3): ";
        std::cin >> chosenSkill;
        std::cout << chosenSkill;
    } else if (myPokemon.Hp == 0) {
        std::cout << "===============================================================";
        std::cout << "Match Result: " << myPokemon.pokemonName << " defeats " << battlePokemon.pokemonName << "\n";
    } else if (battlePokemon.Hp == 0) {
        std::cout << "===============================================================";
        std::cout << "Match Result: " << battlePokemon.pokemonName << " defeats " << myPokemon.pokemonName << "\n";
    }
} 
