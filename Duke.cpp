#include <iostream>
#include "Duke.hpp"
using namespace std;

namespace coup{
     Duke::Duke(Game& game, string name): Player(game, move(name)){
         this->player_role = "Duke";
     }
            void Duke::tax(){
                is_my_turn();
                this->coins_count+=3;
                this->game->t+=1;
                this->last_action = "tax";
            } 
            void Duke::block(Player &player){
                if(player.last_action!="foreign_aid"){
                    throw runtime_error("you can't block this action");
                }
                player.coins_count-=2;

            } 
}