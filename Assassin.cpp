#include <iostream>
#include "Assassin.hpp"
using namespace std;

namespace coup{
     

    Assassin::Assassin(Game& game, string name): Player(game, move(name)){
         this->player_role = "Assassin";
         this->last_couped = this;
    }
    void Assassin::coup(Player &player) {
        is_my_turn();
        if(this->coins()<3){
             throw runtime_error("havan't enough money");
        }
        this->last_couped = &player; //save this player name, if Assassin will be block
        player.is_active=false;
        this->last_action = "coup";
        
    }
     void Assassin::blocked(){
     this->game->add_player(this->last_couped);
    }
    
    }