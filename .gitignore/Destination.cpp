/******************************************************************************************
** Program name: Destination.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the Destination class. It is derived from the 
**		the Space class. It has a protected data member called key, which it uses
**		as a search parameter for the special functions of classes derived from 
**		Destination. Destination objects are intialized with a string and a pointer
**		to a Character object. 
*******************************************************************************************/

#include "Destination.hpp"

/******************************************************************************************
** Description: The constructor takes a string and a pointer to a Character object as its 
**		parameters. It then uses Space to initialize the name and player data members.
*******************************************************************************************/

Destination::Destination(std::string name, Character* player) : Space(name, player)
{}


/******************************************************************************************
** Description: Destination::menu searches the player's inventory for the string contained
**		in key. If it's found, a menu is displayed. The menu displays the name of 
**		the Destination object, and gives the user the option to visit the other 
**		Spaces stored in the Destination object's spaces array. The user can also
**		visit a PortalTransitAuthority object. The menu returns the approriate
**		integer corresponding to the user's selection to the calling function. If
**		the search key is not found in the player's inventory a message is displayed
**		telling them so and they are sent back to the appropriate Space.
*******************************************************************************************/

int Destination::menu()
{
	if(player -> searchPassport(key))
	{
		std::cout << "Welcome to " << name << "!" << std::endl;
		int choice;
		do
		{
			std::cout << "\nWhat would you like to do?"
				  << "\n1. Visit the " << spaces[0] -> getName()
				  << "\n2. Visit the " << spaces[1] -> getName()
				  << "\n3. Open and enter a portal." << std::endl;
			
			std::cin >> choice;
			verify(&choice);
			
			if(choice == 1)
			{
				return 0;
			}
			
			else if(choice == 2)
			{
				return 1;
			}
			
			else if(choice == 3)
			{
				player -> usePortal();
				return 2;
			}
		}while(choice < 1 || choice > 3);
	}
	
	else
	{
		std::cout << "It looks like you're not authorized to be here. You best be on your way."
			  << "\nDon't come back without a stamp." << std::endl;
		
		//pause to let the user see the message before returning
		std::cout << "Press <ENTER> to continue" << std::endl;
		
		std::string enter;
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, enter);
	
		return 2;
	}
}

/******************************************************************************************
** Description: Destination::special is overwritten by derived classes.
*******************************************************************************************/
void Destination::special() {}

/******************************************************************************************
** Description: The destructor deletes Destination objects that are going out of scope.
*******************************************************************************************/
Destination::~Destination() {}
