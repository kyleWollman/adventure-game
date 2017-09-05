/******************************************************************************************
** Program name: DairyFarm.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the DairyFarm class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#include "DairyFarm.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character as its paramter. It initializes
**		its name and player data members through the Location class. It initializes
**		one of its items array members to Milk and its action data member to "Milk 
**		a cow". 
*******************************************************************************************/

DairyFarm::DairyFarm(Character* player) : Location("Dairy Farm", player)
{
	items[0] = "Milk";
	
	action = "Milk a cow.";
}

/******************************************************************************************
** Description: DairyFarm::special searches the player's inventory for "Bucket". If it 
**		doesn't find it the player will be sent away with nothing. It it does find
**		"Bucket" the Bucket will be replaced by Milk in the player's inventory. If
**		the player has already milked a cow, they are told that they can't do it again.
*******************************************************************************************/

void DairyFarm::special() 
{
	
	if(!player -> searchInventory("Bucket"))
	{
		std::cout << "You see a field of cows eating grass, and remember that milk is on your shopping list."
			  << "\nThis is your chance to cross it off. You walk up to one of the cows, reach down and start to milk it."
			  << "\nThe milk sprays all over your shoes and makes a puddle on the ground. It's going to be hard to get the milk"
			  << "\nhome like this. Maybe you can find a bucket to make this task easier." << std::endl;
	}
	
	else if(player -> searchInventory("Bucket"))
	{
		std::cout << "You see a field of cows eating grass, and slowly walk up to one of them."
			  << "\nYou pull out the bucket that you got in Germany and slide it underneath one of the cows."
			  << "\nShe's so distracted chewing a mouthful of grass that she doesn't even notice"
			  << "\nas you start to fill your bucket with the freshest milk you've ever seen!"
			  << "\nThis is your first time milking a cow so you spill a litte, but it's nothing to cry about."
			  << "\nAs the bucket starts to get full, you realize that you better get it back home so it doesn't spoil."
			  << "\nAnother item to cross off the list!" << std::endl;
				  
		player -> replace("Bucket", items[0]);
		items[0] = " ";
	}
	
	else if(items[0] == " ")
	{
		std::cout << "The ladies are tired from all the milking. You won't find anything more to drink here. Sorry." << std::endl;
	}
}

/******************************************************************************************
** Description: The destructor deletes DairyFarm objects going out of scope.
*******************************************************************************************/

DairyFarm::~DairyFarm() 
{}
