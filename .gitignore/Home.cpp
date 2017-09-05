/******************************************************************************************
** Program name: Home.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for Home class objects. It is dervied from the Space
**		class. It has a Constructor, a special function that allows players to look
**		around the space, and a menu function that gives them the options to look 
**		around, put away groceries, open a portal, or quit the game.
*******************************************************************************************/

#include "Home.hpp"
#include <iostream>
#include <string>

/******************************************************************************************
** Description: The constructor takes a pointer to a Character object and sets the player
**		to point to that as well as setting its name to "Home" via the Space class.
**		It also initializes 2 items in its items array.
*******************************************************************************************/

Home::Home(Character* player): Space("Home", player)
{
	//initialize objects
	items[0] = "Portal Gun";
	items[1] = "Passport";
}

/******************************************************************************************
** Description: Home::menu give the user the option to look around the space, which sends
**		them to Home's special function, put groceries away, which sends them to a 
**		Kitchen object, open and enter a portal, which sends them to a 
**		PortalTransitAuthority object, or quit which ends the game.
*******************************************************************************************/

int Home::menu()
{
	int choice;
	
	do
	{
		std::cout << "\nYou are at home." << std::endl;
		std::cout << "\nWhat would you like to do?"
			  << "\n1. Look around."
			  << "\n2. Put groceries away."
			  << "\n3. Open and enter a portal."
			  << "\n4. Quit" << std::endl;
				  
		std::cin >> choice;
		verify(&choice);
		
		if(choice == 1)
		{
			return 5;
		}
		
		else if(choice == 2)
		{
			return 0;
		}
		
		else if(choice == 3)
		{
			player -> usePortal();
			return 1;
		}
		
		else if(choice == 4)
		{
			return -1;
		}

	}while(choice < 1 || choice > 4);
}

/******************************************************************************************
** Description: Home::special() prints out the items in Home's items array and allows the 
**		user the option to add them to the player's inventory. Once the user enters
**		the special function they must continue until both items are added to their
**		inventory. If the user has already picked up both items a message will them.
*******************************************************************************************/

void Home::special()
{
	if(items[0] == "empty" && items[1] == "empty")
	{
		std::cout << "\nThere's nothing else to pick up here." << std::endl;
	}
	
	else
	{
	
		std::cout << "\nOn the table in front of you, you see the following items:";
		
		if(items[0] != "empty")
		{
			std::cout << "\n\n" << items[0];
		}
		
		if(items[1] != "empty")
		{
			std::cout << "\n" << items[1];
		}
		
		int pick;
		
		do
		{	
			std::cout << "\n\nWhat would you like to do?";
			
			if(items[0] != "empty")
			{
				std::cout << "\n1. Pick up " << items[0];
			}
			
			if(items[1] != "empty")
			{
				std::cout << "\n2. Pick up " << items[1] << std::endl;
			}
		
			
			std::cin >> pick;
			verify(&pick);
			
			if(pick == 1)
			{
				player -> addToInventory(items[0]);
				items[0] = "empty";
				std::cout << "\nMaybe this portal gun could make shopping a little easier" << std::endl;
			}
			
			else if(pick == 2)
			{
				player -> addToInventory(items[1]);
				items[1] = "empty";
			}
		}while(items[0] != "empty" || items[1] != "empty" || pick < 1 || pick > 2);
	}
}

/******************************************************************************************
** Description: The destructor deletes Home objects that are going out of scope. 
*******************************************************************************************/

Home::~Home() 
{}
