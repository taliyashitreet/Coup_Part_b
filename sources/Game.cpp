#include <iostream>
#include "Game.hpp"
using namespace std;
unsigned int const limitPlyers =6;

namespace coup{
    Game::Game(){
        this->t=0;
    }

    string Game::turn(){
        vector<string> active = this->active_players();
      if (active.empty()){
           throw runtime_error("their is no players in this game");
       }
       for (unsigned int i =0; i<active.size(); i++){
           string turn_now = this->_players[this->t%this->_players.size()]->name;
           if(find(active.begin() , active.end() , turn_now) == active.end()){
               this->t+=1;
           }
       }
       
       return this->_players[this->t%this->_players.size()]->name;
    }
    string Game::winner(){
        vector<string> active = this->active_players();
       if (active.size() != 1 || this->t ==0){
           throw runtime_error("their is no winner in this game right now");
       }
       return active[0];
    }
    vector<string> Game::active_players(){
        vector<string> ans;
        for(Player *p: this->_players){
            if(p->is_active){
                ans.push_back(p->name);
            }
        }
        return ans;
    }
    vector<string> Game::players(){
        return this->active_players();
    }
    void Game::add_player(Player *player){
        if(this->_players.size() == limitPlyers ){
            throw runtime_error("this game limited to 6 players");
        }
        this->_players.push_back(player);
    }
    
}

