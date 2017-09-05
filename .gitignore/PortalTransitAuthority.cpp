/******************************************************************************************
** Program name: PortalTransitAuthority.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for PortalTransitAuthority class objects. It is 
**		dervied from the Space class. It has a constructor, a special function that
**		allows players to get their passport stamped and a menu function that lets
**		the user choose where to go next. 
*******************************************************************************************/

#include "PortalTransitAuthority.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character object and sets the player
**		to point to that as well as setting its name to "Portal Transit Authority" 
**		via the Space class. It also initializes all four items in the items array
**		with stamps to the Spaces that are in the spaces array. 
*******************************************************************************************/

PortalTransitAuthority::PortalTransitAuthority(Character* player) : Space("Portal Transit Authority", player)
{
	//intialize items
	items[0] = "Wisconsin Stamp";
	items[1] = "Italian Stamp";
	items[2] = "German Stamp";
	items[3] = "North Pole Stamp";
}

/******************************************************************************************
** Description: PortalTransitAuthority::special allows the user to collect Passport stamps.
**		A menu is displayed giving the user the choice of where to get a stamp for
**		and that stamp is added to their passport array. If they already have a 
**		stamp they are not allowed to add it again.	
*******************************************************************************************/


void PortalTransitAuthority::special() 
{
	
	std::cout << "In order to enter a location through a Portal you must have a stamp for that location."
		  << "\n\nWhere would you like a stamp to?"
		  << "\n1. Wisconsin."
		  << "\n2. Italy."
		  << "\n3. Germany."
		  << "\n4. North Pole." << std::endl;
	int choice;
	std::cin >> choice;
	verify(&choice);
	
	if(choice == 1)
		{
			if(items[0] == " ")
			{
				std::cout << "\nYou've already got that stamp. You can't double stamp a single stamp." << std::endl;
			}
			
			else
			{
				player -> addToPassport(items[0]);
				items[0] = " ";
				std::cout << "\nYou are now cleared for Portal travel to " << spaces[0] -> getName() << "." << std::endl;
			}
		}
		
		else if(choice == 2)
		{
			if(items[1] == " ")
			{
				std::cout << "\nYou've already got that stamp. You can't double stamp a single stamp." << std::endl;
			}
			
			else
			{
				player -> addToPassport(items[1]);
				items[1] = " ";
				std::cout << "\nYou are now cleared for Portal travel to " << spaces[1] -> getName() << "." << std::endl;
			}
		}
		
		else if(choice == 3)
		{
			if(items[2] == " ")
			{
				std::cout << "\nYou've already got that stamp. You can't double stamp a single stamp." << std::endl;
			}
			
			else
			{
				player -> addToPassport(items[2]);
				items[2] = " ";
				std::cout << "\nYou are now cleared for Portal travel to " << spaces[2] -> getName() << "." << std::endl;
			}
		}
		
		else if(choice == 4)
		{
			if(items[3] == " ")
			{
				std::cout << "\nYou've already got that stamp. You can't double stamp a single stamp." << std::endl;
			}
			
			else
			{
				player -> addToPassport(items[3]);
				items[3] = " ";
				std::cout << "\nYou are now cleared for Portal travel to " << spaces[3] -> getName() << "." << std::endl;
			}
		}
}

/******************************************************************************************
** Description: PortalTransitAuthority::menu searches the player's inventory for 
**		"Passport" and "Portal Gun". If both are found a menu is displayed that 
**		allows the player to choose to get their Passport stamped or to choose their
**		next travel location. If they don't have a Passport they are told they need
**		one, and if they don't have a Portal Gun they are told they need one. Menu
**		then returns the appropriate number back to the calling function in order to
**		continue the game.
*******************************************************************************************/

int PortalTransitAuthority::menu()
{
	
	if(player -> searchInventory("Portal Gun") && player -> searchInventory("Passport"))
	{
		int choice;
		
		do
		{
			
			std::cout << "\nWelcome to the Portal Transit Authority."
				  << "\nKeeping Portal travelers safe and happy for 50 years." << std::endl;
					  
			std::cout << "\n\n\nWhat would you like to do?"
				  << "\n1. Get your Passport stamped"
				  << "\n2. Go to Wisconsin."
				  << "\n3. Go to Italy."
				  << "\n4. Go to Germany."
				  << "\n5. Go to the North Pole."
				  << "\n6. Go back home" << std::endl;
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
				return 1;
			}
			
			else if(choice == 4)
			{
				return 2;
			}
			
			else if(choice == 5)
			{
				return 3; 
			}
			
			else if(choice == 6)
			{
				return 4;
			}
			
		}while(choice < 1 || choice > 6);
	}
	
	else if(!player -> searchInventory("Portal Gun"))
	{
		std::cout << "\nYou run as fast as you can at the wall, leaping through the air..."
			  << "\nTHUD. You slam into the wall and fall over backwards. There must be a better way you think to yourself."
			  << "\nPerhaps there's a Portal Gun somewhere around here." << std::endl;
				  
		return 4;
	}
	
	else if(!player -> searchInventory("Passport"))
	{
		std::cout << "\nSTOP. According to Portal Code 392.7 Subsection A, any traveler wishing"
			  << "\nto access a portal must have valid identification on their person at all times."
			  << "\nOur full spectrum body scanners indicate that you do not have any identification with you."
			  << "\nI cannot let you use any portals at this time, and must return you to where you came from."
			  << "\nGood Day!!!" << std::endl;
		
		return 4;
	}
	
	else
	{
		return 4;
	}
}

/******************************************************************************************
** Description: The destructor deletes PortalTransitAuthority objects that are going out of 
**		scope. 
*******************************************************************************************/

PortalTransitAuthority::~PortalTransitAuthority() 
{}

