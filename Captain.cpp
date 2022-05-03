#include <iostream>
#include "Captain.hpp"
using namespace std;

namespace coup{
    Captain::Captain(Game& game, string name): Player(game, move(name)){
         this->player_role = "Captain";
    }
    void Captain::block(Player &player){
            if(player.player_role!="Captain"){
            throw runtime_error("Captain can block only Captain");
        }
        if(player.last_action!="steal"){
            throw runtime_error("You missed the block option");
        }
        player.blocked();
    }
    void Captain::steal(Player &player){
        is_my_turn();
        if(player.coins()<2){
            throw runtime_error("doesnt have engoth money");
        }
        this->coins_count+=2;
        this->game->t+=1;
        this->last_action ="steal";
    }
    void Captain::blocked(){
        if(this->last_action!="steal"|| this->last_action!="foreign_aid"){
            throw invalid_argument("you cant block this action");
        }
        this->coins_count-=2;
    }
}