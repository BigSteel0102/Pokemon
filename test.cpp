#include <iostream>

class Pokemon {
    public:
        int ID;
        std::string pokemonType;
        int Hp;
};

void selectPokemon(std::string& myPokemon, std::string& battlePokemon);

int main() {
    std::string myPokemon;
    std::string battlePokemon;

    //Select Pokemon
    selectPokemon(myPokemon, battlePokemon);
};

void selectPokemon(std::string& myPokemon, std::string& battlePokemon) {
    bool chosenPokemon = false;
    int select;
    const std::string NAME[5] = {"Pikachu", "Dratini", "Eevee", "Charmander", "Palkia"};
    //Choosing my Pokemon
    std::cout << "Choose a Pokemon(0~4): ";
    std::cin >> select;
    myPokemon = NAME[select];
    //Choosing opponent's Pokemon
    while(!chosenPokemon) {
        std::cout << "Choose a Pokemon(0~4): ";
        std::cin >> select;
        battlePokemon = NAME[select];
        if (myPokemon == battlePokemon) {
            std::cout << "You have to choose Pokemons different from each other." << std::endl;
        } 
        else {
            chosenPokemon = true;
        }
    }
};