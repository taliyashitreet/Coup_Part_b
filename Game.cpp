#include <iostream>
#include "Game.hpp"
using namespace std;

namespace coup{
    Game::Game(){
        this->t=0;
    }

    string Game::turn(){
       vector<string> active = this->active_players();
       if (active.empty()){
           throw runtime_error("their is no players in this game");
       }
       return active[this->t%active.size()];
    }
    string Game::winner(){
        vector<string> active = this->active_players();
       if (active.size() != 1){
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
        vector<string> ans;
        for(Player *p: this->_players){
            ans.push_back(p->name);
        }
        return ans;
    }
    void Game::add_player(Player *player){
        this->_players.push_back(player);
    }
    
}

