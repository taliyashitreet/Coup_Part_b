#include <iostream>
#include "Player.hpp"
using namespace std;
unsigned int const coinsToCoup =7;

namespace coup{
    Player::Player(Game &game, string name){ 
         this->game =&game;
         this->game->add_player(this);
         this->name = move(name);
         this->coins_count = 0;
         this->is_active=true;
    }
    void Player::income(){
        is_my_turn();
        this->coins_count+=1;
        this->game->t+=1;
        this->last_action="income";
    }
    void Player::foreign_aid(){
        is_my_turn();
        this->coins_count+=2;
        this->game->t+=1;
        this->last_action ="foreign_aid";

    }
    void Player::is_my_turn() const{
        if(this->game->turn()!=this->name){
            throw runtime_error("Not Your Turn!");
        }
    }
    int Player::coins() const{
        return this->coins_count;
    }
    void Player::coup(Player &player){
        is_my_turn();
        if(this->coins_count <coinsToCoup){
            throw runtime_error("not enough money");
        }
        this->coins_count-=coinsToCoup;
        player.is_active=false;
        this->last_action ="coup";
    }
    Player::~Player(){}
    void Player::blocked(){}

}