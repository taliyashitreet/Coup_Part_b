#include <iostream>
#include "Ambassador.hpp"
#include "Player.hpp"
using namespace std;

namespace coup
{
    Ambassador::Ambassador(Game &game, string name) : Player(game, move(name))
    {
        this->player_role = "Ambassador";
    }
    void Ambassador::transfer(Player &from_player, Player &to_player)
    {
        is_my_turn();
        if (from_player.coins() <= 0)
        {
            throw runtime_error("doesnt have engoth money");
        }
        from_player.coins_count -= 1;
        this->last_action = "transfer";
        to_player.coins_count += 1;
        this->game->t += 1; // Next turn
    }

void coup::Ambassador::block(Player &player)
{
    if (player.player_role != "Captain")
    {
        throw runtime_error("Ambassador can block only Captain");
    }
    if (player.last_action != "steal")
    {
        throw runtime_error("You missed the block option");
    }
    player.blocked();
}
}