/******************************************************************************************
** Program name: PastaShop.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the PastaShop class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#include "PastaShop.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character as its paramter. It initializes
**		its name and player data members through the Location class. It initializes
**		one of its items array members to "Pasta" and its action data 
**		member to "Buy some pasta". 
*******************************************************************************************/

PastaShop::PastaShop(Character* player) : Location("Pasta Shop", player)
{
	items[0] = "Pasta";
	
	action = "Buy some pasta.";
}

/******************************************************************************************
** Description: PastaShop::special searches the player's inventory for "Bushel of wheat".
**		if it finds it, it replaces it in the inventory with Pasta. If it doens't 
**		find it, the player is sent away to find it, so that the Pasta can be made.
**		If the player already has Pasta in their inventory, they can't add it again.
*******************************************************************************************/

void PastaShop::special()
{
	if(items[0] == " ")
	{
		std::cout << "Please, I have no more pasta to give. I have children to feed. Come back another time."
			  << std::endl;
	}

	else if(player -> searchInventory("Bushel of wheat"))
	{
		std::cout << "You are greeted by a chef. \"Bonjourno! I'm a gonna make you the best pasta you've a ever tasted!"
			  << "\nHand me that wheat that you are holding and watch me work!\""
			  << "\nThe chef takes the wheat from you and turns it into flour, which he then turns into dough"
			  << "\nand cuts into strips of pasta. He bags everything up for you and sends you on your way."
			  << "\nOne more item to cross off the list." << std::endl;
				  
		player -> replace("Bushel of wheat", items[0]);
		items[0] = " ";
	}
	
	else if(!player -> searchInventory("Bushel of wheat"))
	{
		std::cout << "You are greeted by a chef. \"Bonjourno! I would love to make you a some tasty pasta," 
			  << "\nbut I'm all out of wheat. If you bring me a bushel of wheat I will make you all the"
			  << "\npasta you can carry.\"" << std::endl;
	}
	
	
}

/******************************************************************************************
** Description: The destructor deletes PastaShop objects going out of scope.
*******************************************************************************************/

PastaShop::~PastaShop() {}
