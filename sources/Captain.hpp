#include <iostream>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Captain: public Player{
        private:
        Player *last_steal;
        int Isteal;
        public:
            Captain(Game& game, string name);
            static void block(Player &player); // block another Captain steal
            void steal(Player &player); // steal 2 coins from other player
            void blocked();
            ~Captain(){}
    };
}