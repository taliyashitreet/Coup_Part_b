#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Duke: public Player{
        public:
            Duke(Game& game, string name);
            void tax(); //A tax of three coins from the cash register
            static void block(Player &player); // block foreign_aid
            ~Duke(){}
    };
}