/******************************************************************************************
** Program name: WheatFarm.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the WheatFarm class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#include "WheatFarm.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character as its paramter. It initializes
**		its name and player data members through the Location class. It initializes
**		one of its items array members to "Bushel of wheat" and its action data 
**		member to "Harvest some wheat". 
*******************************************************************************************/

WheatFarm::WheatFarm(Character* player) : Location("Wheat Farm", player)
{
	items[0] = "Bushel of wheat";
	
	action = "Harvest some wheat.";
}

/******************************************************************************************
** Description: WheatFarm::special adds "Bushel of wheat" to the player's inventory. 
*******************************************************************************************/

void WheatFarm::special() 
{
	if(player -> getInventorySize() == 4)
	{
		std::cout << "It looks like you are carrying all that you can hold. You better drop something"
			  << "\nbefore you can " << action << std::endl;
	}
	
	else
	{
		std::cout << "You see before you amber waves of grain. Wheat floods the horizon in all directions."
			  << "\nHopefully you don't have a gluten allergy. You pick up a scythe and start swinging."
		  	<< "\nBefore you know it you've got more wheat than you know what to do with." << std::endl;
	
		player -> addToInventory(items[0]);
	}
}

/******************************************************************************************
** Description: The destructor deletes WheatFarm objects going out of scope.
*******************************************************************************************/

WheatFarm::~WheatFarm() 
{}
