/******************************************************************************************
** Program name: IceCastle.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the IceCastle class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#include "IceCastle.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character as its paramter. It initializes
**		its name and player data members through the Location class. It initializes
**		one of its items array members to "Ice" and its action data 
**		member to "Get some ice". 
*******************************************************************************************/

IceCastle::IceCastle(Character* player) : Location("Ice Castle", player)
{
	items[0] = "Ice";
	
	action = "Get some ice.";
}

/******************************************************************************************
** Description: IceCastle::special searches the player's inventory for "Engine parts". If
**		they are found they are replaced in the inventory with "Ice". If they are
**		not found the player is sent away to find them. If the player has already
**		got ice, they are not allowed to get anymore.  
*******************************************************************************************/
void IceCastle::special()
{
	
	if(player -> searchInventory("Engine parts"))
	{
		std::cout << "Ho ho ho! You've been a such a good delivery person."
			  << "\nI can't thank you enough for getting those parts for me."
			  << "\nThe reindeer need all the help they can get powering my sleigh."
			  << "\nThe Misses says it's because I eat too many cookies. But who doesn't love cookies!"
			  << "\nFor all your troubles I'll let you take all the ice you want."
			  << "\nJust remember, I'm always watching you. Safe travels!" << std::endl;
				  
		player -> replace("Engine parts", items[0]);
		
		items[0] = " ";
	}
	
	else if(!player -> searchInventory("Engine parts"))
	{
		std::cout << "You walk up to the Ice Castle and ring the door bell. A large man with a white beard answers."
			  << "\nAs your eyes adjust you realize that it is the King of the North. Santa Claus himself. He greets you."
			  << "\nHello there " << player -> getName() << "! Have you come to complain about the presents I brought you."
			  << "\nMore and more people are upset with my presents. People don't understand that I'll get sued for making"
			  << "\nyou an iPad, so I'm mostly limited to rocking horses for the good ones, and coal for the bad ones."
			  << "\nI see that your mom wants you to pick up some ice, and that's probably the real reason you came."
			  << "\nThere's still some ice left up here despite all those bad kids playing with their coal,"
			  << "\nbut I need you to pick up some engine parts for my sleigh from the Ferrari dealer in Italy."
			  << "\nBring me those and I'll get you your ice." << std::endl;
	}
	
	else if(items[0] == " ")
	{
		std::cout << "There's only so much ice left. Leave some for the polar bears!" << std::endl;
	}
	
}

/******************************************************************************************
** Description: The destructor deletes IceCastle objects going out of scope.
*******************************************************************************************/

IceCastle::~IceCastle() {}
