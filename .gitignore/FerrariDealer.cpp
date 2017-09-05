/******************************************************************************************
** Program name: FerrariDealer.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the FerrariDealer class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#include "FerrariDealer.hpp"
#include <ctime>
#include <cstdlib>

/******************************************************************************************
** Description: The constructor takes a pointer to a Character as its paramter. It initializes
**		its name and player data members through the Location class. It initializes
**		one of its items array members to "Engine parts" and its action data 
**		member to "Search the warehouse". 
*******************************************************************************************/

FerrariDealer::FerrariDealer(Character * player) : Location("Ferrari Dealer", player)
{
	items[0] = "Engine parts";
	
	action = "Search the warehouse";
	
	unsigned seed = time(0);
	
	srand(seed);
}

/******************************************************************************************
** Description: FerrariDealer::special gives the user the option to search a box for the 
**		engine parts. It randomly generates a number giving the player a 1/3 chance
**		of finding the parts they need. If they find them they are added to the 
**		player's inventory. If they have already found the engine parts, they are
**		not allowed to get them again.  
*******************************************************************************************/

void FerrariDealer::special()
{
	if(player -> getInventorySize() == 4)
	{
		std::cout << "It looks like you are carrying all that you can hold. You better drop something"
			  << "\nbefore you can " << action << std::endl;
	}	

	else if(items[0] != " ")
	{
		std::cout << "You enter a warehouse with row after row of boxes. Santa's engine parts must be in here somewhere."
			  << std::endl;
		
		bool found = false;
		
		int pick, box;
		
		do
		{
			std::cout << "What would you like to do?"
				  << "\n1. Look in a box."
				  << "\n2. Give up." << std::endl;
			
			std::cin >> pick;	
			verify(&pick);
			
			if(pick == 1)
			{
				box = rand() % 3 + 1;
				
				if(box == 3)
				{
					found = true;
					
					std::cout << "\nYou found the parts! Santa will be so happy that he can make the rounds in record time now!" 
						  << std::endl;
					
					player -> addToInventory(items[0]);
					
					items[0] = " ";
				}
				
				else
				{
					std::cout << "\nNo parts in here. Keep trying, you'll find them eventually." << std::endl;
				}
			}
			
			else if(pick == 2)
			{
				std::cout << "\nSorry to see you give up. I guess there won't be any Christmas this year." << std::endl;
			}
			
		}while(!found || pick != 1);
	}
	
	else
	{
		std::cout << "You've already picked up the parts that you need. You won't find anything of interest here." << std::endl;
	}
	
}

/******************************************************************************************
** Description: The destructor deletes FerrariDealer objects going out of scope.
*******************************************************************************************/

FerrariDealer::~FerrariDealer() {}
