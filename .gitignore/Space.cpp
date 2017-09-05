/******************************************************************************************
** Program name: Space.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for Space class objects. Space is an abstract class
**		that has an array of 5 pointers to Space class objects, an array of stringstream
**		a vector to hold strings of "dropped items" and a pointer to a Character, 
**		which represents the player using the space. Since Space is an abstract class
**		it cannot be instantiated, and can only be used by derived classes.
*******************************************************************************************/

#include "Space.hpp"

//constructor

/******************************************************************************************
** Description: The constructor initializes the name and player variables, and fills the
**		items array with empty strings and the spaces array with pointers to NULL.
*******************************************************************************************/

Space::Space(std::string name, Character* player)
{
	this -> name = name;
	
	this -> player = player;
	
	for(int i = 0; i < 4; i++)
	{
		items[i] = "empty";
	}
	
	for(int i = 0; i < 5; i++)
	{
		spaces[i] = NULL;
	}
}

//get functions

/******************************************************************************************
** Description: Space::getName() returns the name of the Space object
*******************************************************************************************/

std::string Space::getName()
{
	return name;
}

/******************************************************************************************
** Description: Space::getItemName takes an int as its paramter and returns the name of the
**		item stored in the items array at that subscript.
*******************************************************************************************/

std::string Space::getItemName(int itemNum)
{
	return items[itemNum];
}

/******************************************************************************************
** Description: Space::getSpace takes an int as its parameter and returns a pointer to the
**		Space object located in the spaces array at that subscript.
*******************************************************************************************/

Space* Space::getSpace(int subscript)
{
	return spaces[subscript];
}

//set function

/******************************************************************************************
** Description: Space::setSpaces takes a pointer to a Space object and an int as its paramters
		and sets the spaces array's subscript location to point to that Space object.
*******************************************************************************************/

void Space::setSpaces(Space* space, int subscript)
{
	spaces[subscript] = space;
}

//screen control functions

/******************************************************************************************
** Description: Space::printDroppedItems prints the strings in an Space objects droppedItems
**		vector. If the vector is emtpy, a message says so.
*******************************************************************************************/

void Space::printDroppedItems()
{
	if(droppedItems.size() == 0)
	{
		std::cout << "You haven't dropped anything here." << std::endl;
	}
	
	else
	{
		std::cout << "Here are the items that you have dropped here: " << std::endl;
		
		for(unsigned int i = 0; i < droppedItems.size(); i++)
		{
			std::cout << i+1 << ". " << droppedItems.at(i) << std::endl;
		}
	}
}

/******************************************************************************************
** Description: Space::clearScreen prints out 75 newline characters followed by the status
**		of the player's portal gun battery, inventory, and shopping list. It then 
**		prints 5 more newline characters, which is where the program output will start.
*******************************************************************************************/

void Space::clearScreen()
{
	std::cout << std::string(75,'\n');
	
	std::cout << "Portal Gun Battery: ";
	player -> printBattery();
	
	std::cout << "\nItems in inventory: ";
	player -> printInventory();
	
	std::cout << "\nShopping List: ";
	player -> printShoppingList();
	
	std::cout << std::string(5,'\n');
}

//misc functions

/******************************************************************************************
** Description: Space::special is a virtual function that will be overwritten by derived classes.
*******************************************************************************************/

void Space::special() {}

/******************************************************************************************
** Description: Space::dropItem removes an item from the player's inventory and adds it to
**		the space's droppedItems vector.
*******************************************************************************************/

void Space::dropItem()
{
	droppedItems.push_back(player -> removeFromInventory());
}

/******************************************************************************************
** Description: Space::pickUpDroppedItem allows a player to transfer an item from a Space'
**		droppedItems vector into their inventory array.
*******************************************************************************************/

void Space::pickUpDroppedItem()
{
	printDroppedItems();
	
	unsigned int drop;
	
	do
	{
		std::cout << "Please select the number of the item that you would like to pick up." << std::endl;
		std::cin >> drop;
		verify(&drop);
	}while(drop > droppedItems.size());
	
	drop--;
	
	player -> addToInventory(droppedItems.at(drop));
	
	droppedItems.erase(droppedItems.begin() + drop);
}

//destructor

/******************************************************************************************
** Description: The destructor deletes Space objects that are going out of scope. 
*******************************************************************************************/

Space::~Space () {}
