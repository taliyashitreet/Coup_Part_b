#include <iostream>
#include "Assassin.hpp"
using namespace std;
unsigned int const coins_7 =7;
unsigned int const coins_3 =3;

namespace coup{
     

    Assassin::Assassin(Game& game, string name): Player(game, move(name)){
        this->plyer_role = "Assassin";
        this->last_couped = this;
        this->coup_coins = 3;
    }

    void Assassin::coup(Player &player) {
        is_my_turn();
        if(this->coins()<coins_3){
             throw runtime_error("havan't enough money");
        }
        vector<string> active = this->game->active_players();
        if(find(active.begin() , active.end() ,player.name) == active.end()){
            throw runtime_error("already out");
        }
        if (this->coins_count <coins_7){
            this->coins_count-=coins_3;
            this->coup_coins =coins_3;
        }
        else{
            this->coins_count-=coins_7;
            this->coup_coins =coins_7;
        }
        this->last_couped = &player; //save this player name, if Assassin will be block
        player.is_active=false;
        this->last_action = "coup";
        
        this->game->t+=1;
        
    }
     void Assassin::blocked(){
        if(this->coup_coins == coins_7){
            throw runtime_error("you can't block this action");
        }
        this->last_couped->is_active = true;
    }
    
    }