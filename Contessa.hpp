#include <iostream>
#include "Player.hpp"
using namespace std; 
namespace coup{
    class Contessa: public Player{
        public:
            Contessa(Game& game,string name);
            static void block(Player &player); // block Assassination
            ~Contessa(){}
    };
}