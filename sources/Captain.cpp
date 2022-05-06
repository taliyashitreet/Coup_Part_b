#include <iostream>
#include "Captain.hpp"
using namespace std;

namespace coup
{
    Captain::Captain(Game &game, string name) : Player(game, move(name))
    {
        this->plyer_role = "Captain";
        this->last_steal = this;
        this->Isteal = 2;
    }

    void Captain::block(Player &player)
    {
        if (player.role() != "Captain")
        {
            throw runtime_error("Captain can block only Captain");
        }
        if (player.last_action != "steal")
        {
            throw runtime_error("You missed the block option");
        }
        player.blocked();
    }
    void Captain::steal(Player &player)
    {
        is_my_turn();
        coins_10();
        if (player.coins() == 0 )
        {
            throw runtime_error("doesnt have engoth money");
        }
        if (player.coins() >=2){
        this->coins_count += 2;
        player.coins_count -= 2;
        this->Isteal =2;

        } else {
        this->coins_count += 1;
        player.coins_count -= 1; 
        this->Isteal =1;
        }
        
        this->game->t += 1; // next turn
        this->last_action = "steal";
        this->last_steal = &player;

    }
    void Captain::blocked()
    {
        if (this->last_action != "steal"  && this->last_action != "foreign_aid")
        {
            throw invalid_argument("you cant block this action");
        }
        this->coins_count -= 2;
        this->last_steal->coins_count+=this->Isteal;
    }
}