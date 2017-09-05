/******************************************************************************************
** Program name: Game.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the Game class object. It has a pointer to a
**		Character object which represents the player, and 16 pointers to Space class
**		objects which represent the current location, and the different spaces that 
**		the player could enter. 
*******************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include "Character.hpp"
#include "Space.hpp"
#include "Home.hpp"
#include "Kitchen.hpp"
#include "PortalTransitAuthority.hpp"
#include "Wisconsin.hpp"
#include "DairyFarm.hpp"
#include "WheatFarm.hpp"
#include "Italy.hpp"
#include "PastaShop.hpp"
#include "FerrariDealer.hpp"
#include "Germany.hpp"
#include "Brewery.hpp"
#include "BucketFactory.hpp"
#include "NorthPole.hpp"
#include "IceCastle.hpp"
#include "YeastFactory.hpp"

class Game
{
	private:
	Character* player;
	Space* home;
	Space* kitchen;
	Space* pta;
	Space* wisconsin;
	Space* dairyFarm;
	Space* wheatFarm;
	Space* italy;
	Space* pastaShop;
	Space* ferrariDealer;
	Space* germany;
	Space* brewery;
	Space* bucketFactory;
	Space* northPole;
	Space* iceCastle;
	Space* yeastFactory;
	Space* location;
	
	public:
	Game(std::string name);
	void play();
	void lose();
	void win();
	~Game();
};

#endif
	