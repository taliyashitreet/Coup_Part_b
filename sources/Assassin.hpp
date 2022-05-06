
#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Assassin: public Player{
        public:
            int coup_coins; //if Assassin coouped with 7 coins he cant be block
            Player *last_couped; // if Assassin coup this player
            Assassin(Game& game, string name);
            void coup(Player &player) ; //coup another player with only 3 coins
            void blocked();
            ~Assassin(){}
    };
}