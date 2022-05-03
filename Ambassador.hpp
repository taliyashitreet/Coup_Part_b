#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Ambassador: public Player{
        public:
            Ambassador(Game& game, string name);
            void transfer(Player &from_player, Player &to_player); //convey coin from one player to other
            static void block(Player &player); // block player from theft
            ~Ambassador(){}
            
    };
}