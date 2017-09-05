/******************************************************************************************
** Program name: Brewery.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the Brewery class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#include "Brewery.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character as its paramter. It initializes
**		its name and player data members through the Location class. It initializes
**		one of its items array members to "Beer" and its action data 
**		member to "Brew some beer". 
*******************************************************************************************/

Brewery::Brewery(Character* player) : Location("Brewery", player)
{
	items[0] = "Beer";
	
	action = "Brew some beer.";
}

/******************************************************************************************
** Description: Brewery::special searches the player inventory for "Beer". If it is found, 
**		indicating that they have already got beer, they aren't allowed to get more.
**		It then searches the inventory for "Yeast". If it is found, it is repalced
**		in the inventory with "Beer". If "Yeast" is not found, the player is sent
**		of to find some "Yeast".  
*******************************************************************************************/

void Brewery::special()
{
	if(player -> searchInventory("Beer"))
	{
		std::cout << "Enjoy the beer friend. Please drink responsibly." << std::endl;
	}
	
	else if(player -> searchInventory("Yeast"))
	{
		std::cout << "You add the yeast to the wort and it starts turning the sugar into alcohol."
			  << "\nIn just a few short weeks. You'll have some delicious beer."
			  << "\nLuckily the brewmaster is so greatful for you picking up the yeast from the North Pole"
			  << "\nhe lets you take some beer that's finished home with you."
			  << "\nOne more item to cross off the list!" << std::endl;
				  
		player -> replace("Yeast", items[0]);
		items[0] = " ";
	}
	
	else if(!player -> searchInventory("Yeast"))
	{
		std::cout << "The brewmaster greets you as you enter the brewery. \"Guten tag! I can give you some beer,"
			  << "\nbut all of our yeast has died and I can't brew any beer without it. We use only the finest"
			  << "\nyeast from the North Pole. It's actually the secret ingredient that makes reindeer fly."
			  << "\nIf you bring me back a supply of yeast, I'll give you some of the best beer you've ever tasted.\""
			  << std::endl;
	}
}

/******************************************************************************************
** Description: The destructor deletes Brewery objects going out of scope.
*******************************************************************************************/

Brewery::~Brewery() {}
