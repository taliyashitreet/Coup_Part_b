#pragma once
#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;

namespace coup{
    class Player;
    class Game{
        public:
        Game();
            vector<Player*> _players;
            unsigned int t; //turn
            vector<string> active_players(); //The names of the players currently active in the game
            string turn(); // the player whose turn it is
            vector<string> players();
            string winner();
            void add_player(Player *player);
    };
}