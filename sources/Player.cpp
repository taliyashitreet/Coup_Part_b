#include <iostream>
#include "Player.hpp"
using namespace std;
unsigned int const coinsToCoup =7;
unsigned int const limitCoins =10;

namespace coup{
    Player::Player(Game &game, string name){ 
         this->game =&game;
         if (this->game->t > 0){
            throw runtime_error("game already started");
        }
         this->game->add_player(this);
         this->name = move(name);
         this->coins_count = 0;
         this->is_active=true;
    }
    void Player::income(){
        is_my_turn();
        coins_10();
        this->coins_count+=1;
        this->game->t+=1;
        this->last_action="income";
    }
    void Player::foreign_aid(){
        is_my_turn();
        coins_10();
        this->coins_count+=2;
        this->game->t+=1;
        this->last_action ="foreign_aid";

    }
    void Player::is_my_turn() const{
         vector<string> active = this->game->active_players();
        if(find(active.begin() , active.end() ,this->name) == active.end()){
            throw runtime_error("you are out of the game");
        }
        if(this->game->turn()!=this->name){
            throw runtime_error("Not Your Turn!");
        }
        if (this->game->_players.size() < 2)
        {
            throw runtime_error("Not enough players!");
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
        vector<string> active = this->game->active_players();
        if(find(active.begin() , active.end() ,player.name) == active.end()){
            throw runtime_error("already out");
        }
        this->coins_count-=coinsToCoup;
        player.is_active=false;
        this->last_action ="coup";
        this->game->t+=1;
    }
    void Player::coins_10() const{
        if(this->coins_count >= limitCoins){
            throw runtime_error("you have to make coup");
        }
    }
    string Player::role(){
     return this->plyer_role;
    }
    Player::~Player(){}
    void Player::blocked(){
        is_my_turn();
        this->coins_count-=2; 

    }

}