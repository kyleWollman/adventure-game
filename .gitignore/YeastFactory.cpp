/******************************************************************************************
** Program name: YeastFactory.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the YeastFactory class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#include "YeastFactory.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character as its paramter. It initializes
**		its name and player data members through the Location class. It initializes
**		one of its items array members to "Yeast" and its action data 
**		member to "Get some yeast". 
*******************************************************************************************/

YeastFactory::YeastFactory(Character* player) : Location("Yeast Factory", player)
{
	items[0] = "Yeast";
	
	action = "Get some yeast.";
}

/******************************************************************************************
** Description: YeastFactory::special adds "Yeast" to the player's inventory. If they
**		already have some then they are not allowed to get anymore. 
*******************************************************************************************/

void YeastFactory::special()
{
	if(player -> getInventorySize() == 4)
	{
		std::cout << "It looks like you are carrying all that you can hold. You better drop something"
			  << "\nbefore you can " << action << std::endl;
	}
	
	
	else if(items[0] == " ")
	{
		std::cout << "You've already got enough yeast. Better not risk another trip." << std::endl;
	}
	else
	{
		
		std::cout << "\nYou enter a large door into what look like stables."
			  << "\nIn each pen is an actual reindeer. You see elves scurrying about."
			  << "\nThe elves are brushing the reindeer and keeping the hairs that fall off."
			  << "\nThey then collect the reindeer hair and grind it down into a fine powder."
			  << "\nThe powder is packaged and sold as yeast. That's right. Yeast is ground up reindeer hairs."
			  << "\nYou grab a bag of yeast before anyone sees you, and you're out the door." << std::endl;
		player -> addToInventory(items[0]);
		
		items[0] = " ";
	}
}

/******************************************************************************************
** Description: The destructor deletes YeastFactory objects going out of scope.
*******************************************************************************************/

YeastFactory::~YeastFactory() {}
