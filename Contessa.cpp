#include <iostream>
#include "Contessa.hpp"
#include "Assassin.hpp"
using namespace std;

namespace coup{
    class Assassin;
    Contessa::Contessa(Game& game, string name): Player(game, move(name)){
         this->player_role = "Contessa";
}
void Contessa::block(Player &player){
    if(player.player_role!="Assassin"){
        throw runtime_error("Contessa can block only Assassin");
    }
    if(player.last_action!="coup"){
        throw runtime_error("You missed the block option");
    }
    player.blocked(); 
}
}
