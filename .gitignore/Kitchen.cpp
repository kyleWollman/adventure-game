/******************************************************************************************
** Program name: Kitchen.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the Kitchen class objects. Kitchen is derived
**		from the base class Space. It takes a pointer to a Character object as its
**		parameter. 
*******************************************************************************************/

#include "Kitchen.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character for its parameter and uses
**		Space class to initiazlise its name and player data members. 
*******************************************************************************************/

Kitchen::Kitchen(Character* player) : Space("Kitchen", player)
{}

/******************************************************************************************
** Description: Kitchen::menu seaches the player's inventory for the items listed on the 
**		grocery list. If none of them are found a message is displayed saying so, 
**		and control returns to Home. If one of the objects is found it is removed
**		from the player's inventory and also removed from the shopping list. Control
**		then returns to Home
*******************************************************************************************/

int Kitchen::menu()
{
	if(!player -> searchInventory("Milk") && !player -> searchInventory("Pasta") && !player -> searchInventory("Beer")
		&& !player -> searchInventory("Ice"))
	{
		std::cout << "It looks like you don't have anything on the list. You better keep looking." << std::endl;
		
		//pause to let the user see the message before returning to Home
		std::cout << "Press <ENTER> to continue" << std::endl;
		
		std::string enter;
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, enter);
		
		return 0;
	}
	
	else
	{
		player -> removeFromShoppingList(player -> removeFromInventory());
	
		return 0;
	}
}

void Kitchen::special() {}

/******************************************************************************************
** Description: The destructor deletes Kitchen objects that are going out of scope.
*******************************************************************************************/
Kitchen::~Kitchen() {}
