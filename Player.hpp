

#pragma once
#include <iostream>
#include "Game.hpp"
using namespace std;

namespace coup{
    class Game;
    class Player{
        public:
        Player(Game &game, string name);
            Game *game; 
            string name;
            int coins_count; //How many coins does he have
            string player_role; // What is its role
            string last_action; //what is the last action of this player
            bool is_active;
            virtual void blocked();
            void income(); // Take a coin from the pile
            void foreign_aid(); //Earns the player two coins
            virtual void coup(Player &player); //Which player he decided to dismiss
            int coins() const; //How many coins does a player have
            void is_my_turn() const;
            ~Player();

    };
}