

#pragma once
#include <algorithm>
#include <iostream>
#include "Game.hpp"
using namespace std;

namespace coup{
    class Game;
    class Player{
        public:
        Player(Game &game, string name); // constructor
            Game *game; 
            string name;
            int coins_count; //How many coins does he have
            string plyer_role;
            virtual string role(); // What is its role
            string last_action; //what is the last action of this player
            bool is_active; // return if this player is in the game
            virtual void blocked();
            void income(); // Take a coin from the pile
            void foreign_aid(); //Earns the player two coins
            virtual void coup(Player &player); //Which player he decided to dismiss
            int coins() const; //How many coins does a player have
            void is_my_turn() const; //throw exeption if player try to play not on his turn
            void coins_10() const; // if this player have 10 coins he need to do coup
            ~Player(); // distructor

    };
}