#include "doctest.h"
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include <vector>

using namespace coup;
using namespace std;

	

TEST_CASE("throws exeption"){
    Game game_1{};

    CHECK_THROWS(game_1.turn()); //no one turn
    CHECK_THROWS(game_1.winner()); // no one to win

	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	vector<string> players = game_1.players();
    duke.income();
   CHECK_THROWS(captain.income()); //not his turn
   CHECK_THROWS(contessa.income()); //not her turn
   assassin.foreign_aid();
   ambassador.transfer(assassin,captain);
   CHECK_THROWS(captain.steal(ambassador)); // ambassador desnt have any coins
   captain.income();
   contessa.foreign_aid();
   duke.tax();
   CHECK_THROWS(assassin.coup(contessa)); //there is 1 coin to assassin
   assassin.income();
   CHECK_THROWS(ambassador.block(assassin)); //assassin cant steal
   ambassador.transfer(captain,assassin);
   captain.steal(assassin); // captain cant steal from itself
   contessa.income();
   duke.income();
   assassin.income();
   ambassador.income();
   captain.income();
   CHECK_THROWS(ambassador.block(captain)); // pass the option
   CHECK_THROWS(contessa.block(assassin)); // assassin didnt coup
   CHECK_THROWS(contessa.block(captain)); // block only assassin
   contessa.income();
   CHECK_THROWS(duke.block(contessa)); // contessa didnt foreign_aid
   CHECK_THROWS(game_1.winner()); //no one to win
}
TEST_CASE("good input"){
    Game game{};
    vector<string> Players {"Moshe", "Yossi", "Meirav", "Reut", "Gilad"};
    Duke duke{game, "Moshe"};
	Assassin assassin{game, "Yossi"};
	Ambassador ambassador{game, "Meirav"};
	Captain captain{game, "Reut"};
	Contessa contessa{game, "Gilad"};
    CHECK(game.turn().compare("Moshe")==0);
    CHECK(game._players.size() == 5);
    vector<string> Players_active = game.active_players();
    for (size_t i = 0; i<game._players.size(); i++){
        CHECK(Players[i].compare(Players_active[i])==0);
    }
    duke.income();
     CHECK(game.turn().compare("Yossi")==0);
     CHECK(duke.coins() == 1);
     assassin.foreign_aid();
     CHECK(assassin.coins() ==2);
    Game game2{};
    Duke duke2{game2, "Moshe"};
	Assassin assassin2{game2, "Yossi"};
    duke2.tax();
    assassin2.income();
    duke2.tax();
    assassin2.income();
    duke2.income();
    assassin2.income();
    CHECK(duke2.coins() ==7);
    duke2.coup(assassin2); //Moshe have 7 coins
    CHECK(game2.winner().compare("Moshe")==0); 
    Game game3{}; //game number 3
    Ambassador ambassador3{game3, "Meirav"};
    Captain captain3{game3, "Reut"};
   
    for (size_t i = 1; i < 100; i++)
    {
        ambassador3.income();
        CHECK(size_t(ambassador3.coins())== i);
        captain3.income();
    }
    

}
