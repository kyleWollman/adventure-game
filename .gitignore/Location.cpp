/******************************************************************************************
** Program name: Location.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the location class object. It is derived from
**		the Space base class. It takes a string and a pointer to a Character object
**		as its initialzation parameters.
*******************************************************************************************/

#include "Location.hpp"

/******************************************************************************************
** Description: The constructor takes string and a pointer to a Character as its parameters
**		and uses them to initialize its name and player data members through the 
**		Space class.
*******************************************************************************************/

Location::Location(std::string name, Character* player) : Space(name, player)
{}

/******************************************************************************************
** Description: Location::menu displays a menu that gives the user the option to perform 
**		an action which is initialized by a derived class. It also gives them the 
**		option to return to a PortalTransitAuthority object, or call the class's
**		dropItem or printDroppedItems function. 
*******************************************************************************************/

int Location::menu()
{
	int choice;
	do
	{
		std::cout << "\n\nWelcome to the " << name << std::endl;
		std::cout << "\nWhat would you like to do?"
			  << "\n1. " << action
			  << "\n2. Open and enter a portal."
			  << "\n3. Remove items from inventory."
			  << "\n4. See what items you've dropped here."
			  << "\n5. Pick up a dropped item."
			  << "\n6. Quit." << std::endl;
				  
		std::cin >> choice;
		verify(&choice);
		
		if(choice == 1)
		{
			return 5;
		}
		
		else if(choice == 2)
		{
			player -> usePortal();
			return 1;
		}
		
		else if(choice == 3)
		{
			return 6;
		}
		
		else if(choice == 4)
		{
			return 7;
		}
		
		else if(choice == 5)
		{
			return 8;
		}

		else if(choice == 6)
		{
			return -1;
		}
		
	}while(choice < 1 || choice > 5);
	
}

/******************************************************************************************
** Description: Location::special is overwritten by classes derived from the Location class.
*******************************************************************************************/

void Location::special() {}

/******************************************************************************************
** Description: The destructor deletes Location items going out of scope. 
*******************************************************************************************/

Location::~Location() {}
