
#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Assassin: public Player{
        public:
            Player *last_couped;
            Assassin(Game& game, string name);
            void coup(Player &player) ; //coup another player with only 3 coins
            void blocked();
            ~Assassin(){}
    };
}