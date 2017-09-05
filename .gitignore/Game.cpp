/******************************************************************************************
** Program name: Game.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the Game class object. It has a pointer to a
**		Character object which represents the player, and 16 pointers to Space class
**		objects which represent the current location, and the different spaces that 
**		the player could enter. 
*******************************************************************************************/

#include "Game.hpp"
#include <iostream>

/******************************************************************************************
** Description: The constructor takes a string as its parameter and uses it to initialize
**		the Character object player. It then initializes the 17 Space pointers with
**		the appropriate classes. It then calls the play function to play the game.
*******************************************************************************************/

Game::Game(std::string name)
{
	player = new Character(name);
	home = new Home(player);
	kitchen = new Kitchen(player);
	pta = new PortalTransitAuthority(player);
	wisconsin = new Wisconsin(player);
	dairyFarm = new DairyFarm(player);
	wheatFarm = new WheatFarm(player);
	italy = new Italy(player);
	pastaShop = new PastaShop(player);
	ferrariDealer = new FerrariDealer(player);
	germany = new Germany(player);
	brewery = new Brewery(player);
	bucketFactory = new BucketFactory(player);
	northPole = new NorthPole(player);
	iceCastle = new IceCastle(player);
	yeastFactory = new YeastFactory(player);
	
	home -> setSpaces(kitchen, 0);
	home -> setSpaces(pta, 1);
	kitchen -> setSpaces(home, 0);
	pta -> setSpaces(wisconsin, 0);
	pta -> setSpaces(italy, 1);
	pta -> setSpaces(germany, 2);
	pta -> setSpaces(northPole, 3);
	pta -> setSpaces(home, 4);
	wisconsin -> setSpaces(dairyFarm, 0);
	wisconsin -> setSpaces(wheatFarm, 1); 
	wisconsin -> setSpaces(pta, 2);
	dairyFarm -> setSpaces(pta, 1);
	wheatFarm -> setSpaces(pta, 1);
	italy -> setSpaces(pastaShop, 0);
	italy -> setSpaces(ferrariDealer, 1);
	italy -> setSpaces(pta, 2);
	pastaShop -> setSpaces(pta, 1);
	ferrariDealer -> setSpaces(pta, 1);
	germany -> setSpaces(brewery, 0);
	germany -> setSpaces(bucketFactory, 1);
	germany -> setSpaces(pta, 2);
	brewery -> setSpaces(pta, 1);
	bucketFactory -> setSpaces(pta, 1);
	northPole -> setSpaces(iceCastle, 0);
	northPole -> setSpaces(yeastFactory, 1);
	northPole -> setSpaces(pta, 2);
	iceCastle -> setSpaces(pta, 1);
	yeastFactory -> setSpaces(pta, 1);
	
	location = home;

	play();
}

/******************************************************************************************
** Description: Game::play creates an int for a variable nextLocation. This int controls
**		which object's functions are called at which times. The Space object's menu
**		funciton returns an int, so play assigns that int to nextLocation. If it 
**		is a 5, the Space's special function will be called. If it is a 6, the
**		Space's dropItem function will be called. If it is a 7 the Space's 
**		printDroppedItems function will be called, and if it is 0 through 4
**		location pointer will switch to the approriate Space object and call that
**		object's menu function. It continues this as long as nextLocation isn't -1,
**		and the player's portal gun hasn't run out of battery power, and the player
**		hasn't completed the shopping list. Once the do/while loop is exited the 
**		lose function is called if the portal gun's battery ran out, the win funciton
**		is called if the player completed the list, or the program exits if the player
**		chose to quit. 
*******************************************************************************************/

void Game::play()
{
	int nextLocation;

	nextLocation = location -> menu();
	do
	{
		location -> clearScreen();
		
		if(nextLocation == 5)
		{
			location -> special();
			nextLocation = location -> menu();
		}
		
		else if(nextLocation == 6)
		{
			location -> dropItem();
			nextLocation = location -> menu();
		}
		
		else if(nextLocation == 7)
		{
			location -> printDroppedItems();
			nextLocation = location -> menu();
		}
		
		else if(nextLocation == 8)
		{
			location -> pickUpDroppedItem();
			nextLocation = location -> menu();
		}
	
		else if(nextLocation < 5 && nextLocation > -1)
		{
			location = location -> getSpace(nextLocation);
			nextLocation = location -> menu();
		}
		
	}while(nextLocation != -1 && player -> getBatteryLife() > 0 && player -> getShoppingListSize() > 0);
	
	if(player -> getBatteryLife() <= 0)
	{
		lose();
	}
	
	else if(player -> getShoppingListSize() <= 0)
	{
		win();
	}
		
}

/******************************************************************************************
** Description: Game::lose clears the screen and prints out the message that the player's
**		portal gun has run out of battery power.
*******************************************************************************************/
void Game::lose()
{
	location -> clearScreen();
	
	std::cout << "It looks like the portal gun ran out of batteries." 
		  << "\nYou're stuck here forever. Sorry. Better luck next time." << std::endl;
}

/******************************************************************************************
** Description: Game::win clears the screen and prints out the message that the player has
**		completed the shopping list and won the game.
*******************************************************************************************/
void Game::win()
{
	location -> clearScreen();
	
	std::cout << "Congratulations! You got everything on the list! And there's still time for a nap." << std::endl;
}

/******************************************************************************************
** Description: The destructor deletes all of the pointers to Space objects and the pointer
**		to a Character object and sets them to NULL.
*******************************************************************************************/

Game::~Game() 
{
	delete player;
	player = NULL;
	
	delete home;
	home = NULL;
	
	delete kitchen;
	kitchen = NULL;
	
	delete pta;
	pta = NULL;
	
	delete wisconsin;
	wisconsin = NULL;
	
	delete dairyFarm;
	dairyFarm = NULL;
	
	delete wheatFarm;
	wheatFarm = NULL;
	
	delete italy;
	italy = NULL;
	
	delete pastaShop;
	pastaShop = NULL;
	
	delete ferrariDealer;
	ferrariDealer = NULL;
	
	delete germany;
	germany = NULL;
	
	delete brewery;
	brewery = NULL;
	
	delete bucketFactory;
	bucketFactory = NULL;
	
	delete northPole;
	northPole = NULL;
	
	delete iceCastle;
	iceCastle = NULL;
	
	delete yeastFactory;
	yeastFactory = NULL;
}
