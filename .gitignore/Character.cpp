/******************************************************************************************
** Program name: Character.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the Character class. Character represents the 
**		player in the game. It has 3 arrays, a shoppingList, inventory, and Passport
**		array each of size 4 that hold strings. It also has a battery array that 
**		represents the Portal Gun's battery life. Character has various functions for
**		manipulating or retrieving the data in these arrays.
*******************************************************************************************/

#include "Character.hpp"
#include <iostream>
#include "verify.hpp"

/******************************************************************************************
** Description: The constructor takes a string as its parameter. It sets the data member name
**		equal to that string. It fills the passport and inventory arrays with the 
**		empty string " ", and the battery array with the char '|' representing the 
**		power indicator lines on the portal gun.
*******************************************************************************************/

Character::Character(std::string name)
{
	this -> name = name;
	
	for(int i = 0; i < 4; i++)
	{
		passport[i] = " ";
	}
	
	for(int i = 0; i < inventoryCapacity; i++)
	{
		inventory[i] = " ";
	}
	
	for(int i = 0; i < batteryLife; i++)
	{
		battery[i] = '|';
	}
}

/******************************************************************************************
** Description: Character::getName() returns the Character's name to the calling function.
*******************************************************************************************/

std::string Character::getName()
{
	return name;
}

//inventory funcitons

/******************************************************************************************
** Description: Character::addToInventory searches the inventory for the first empty spot.
**		If there isn't one then the user is told they need to drop an item before 
**		they can add another item. If an empty spot is found the item recieved 
**		as the function parameter is added to that empty spot. 
*******************************************************************************************/

void Character::addToInventory(std::string item)
{
	int empty = 0;
	while(inventory[empty] != " " && empty < inventoryCapacity)
	{
		empty++;
	}
	
	if(empty == inventoryCapacity)
	{
		std::cout << "Looks like you are holding all that you can carry. Better drop something." << std::endl;
	}
	
	else
	{
		inventory[empty] = item;
		inventorySize++;
	}
}

/******************************************************************************************
** Description: Character::getInventorySize returns the current inventory size.
*******************************************************************************************/

int Character::getInventorySize()
{
	return inventorySize;
}

/******************************************************************************************
** Description: Character::removeFromInventory removes an item from the inventory array.
**		If the array is "empty" then the user is told such. Otherwise the user
**		enters the item number that they want to remove. If that item is in the 
**		first or second spot, they are not allowed to remove it because doing so
**		would make finishing the game impossible. If they choose another item, 
**		it is removed and returned to the calling function.
*******************************************************************************************/

std::string Character::removeFromInventory()
{
	if(inventorySize == 0)
	{
		std::cout << "Your inventory is emtpy" << std::endl;
		return " ";
	}
	
	else
	{
		int drop = -1;
		while(drop < 0 || drop > inventorySize)
		{
			std::cout << "Enter the item number from the inventory that you wish to drop." << std::endl;
			std::cin >> drop;
			verify(&drop);
		}
		
		drop--;
		
		if(drop == 0 || drop == 1)
		{
			std::cout << "If you drop that, you won't be able to complete the shopping trip. You better hold onto it." << std::endl;
			return " ";
		}
		
		else
		{
			std::string temp = inventory[drop];
			
			for(int i = drop; i < inventorySize - 1; i++)
			{
				inventory[i] = inventory[i + 1];
			}
			
			inventory[inventorySize - 1] = " ";
			
			inventorySize -= 1;
		
			return temp;
		}
	}
}

/******************************************************************************************
** Description: Character::searchInventory takes a string as its parameter. If the string 
**		matches an item in the inventory array it returns true, otherwise it 
**		returns false to the calling function.
*******************************************************************************************/

bool Character::searchInventory(std::string item)
{
	bool found = false;
	
	for(int i = 0; i < inventorySize; i++)
	{
		if(inventory[i] == item)
		{
			found = true;
		}
	}
	
	return found;
}

/******************************************************************************************
** Description: Character::replace takes two strings as its parameters. It searches the 
**		inventory array for the first string to get its position in the array. Once
**		that has been found, it replaces it with the second string. 
*******************************************************************************************/

void Character::replace(std::string replace, std::string with)
{
	int position;
	
	for(int i = 0; i < inventorySize; i++)
	{
		if(inventory[i] == replace)
		{
			position = i;
		}
	}
	
	inventory[position] = with;
}

/******************************************************************************************
** Description: Character::printInventory prints the items in the inventory array to the 
**		user's screen.
*******************************************************************************************/

void Character::printInventory()
{
	for(int i = 0; i < inventorySize; i++)
	{
		std::cout << i+1 << ". " << inventory[i] << " ";
	}
}

//passport functions

/******************************************************************************************
** Description: Character::addToPassport searches the passport array for the first empty 
**		spot. It then adds its parameter string to that spot in the array. 
*******************************************************************************************/

void Character::addToPassport(std::string stamp)
{
	int empty = 0;
	
	while(passport[empty] != " " && empty < 4)
	{
		empty++;
	}

	passport[empty] = stamp;

	stamps++;
}

/******************************************************************************************
** Description: Character::searchPassport takes a string as its parameter. If the string 
**		matches an item in the inventory array it returns true, otherwise it 
**		returns false to the calling function.
*******************************************************************************************/

bool Character::searchPassport(std::string stamp)
{
	bool found = false;
	
	for(int i = 0; i < stamps; i++)
	{
		if(passport[i] == stamp)
		{
			found = true;
		}
	}
	
	return found;
}

//portal functions

/******************************************************************************************
** Description: Character::printBattery prints the current amount of battery life left in 
**		the portal gun to the user's screen.
*******************************************************************************************/

void Character::printBattery()
{
	for(int i = 0; i < batteryLife; i++)
	{
		std::cout << battery[i] << " ";
	}
}

/******************************************************************************************
** Description: Character::usePortal decreases the batteryLife data member by one every time
**		it is called.
*******************************************************************************************/

void Character::usePortal()
{
	batteryLife--;
	
}

/******************************************************************************************
** Description: Character::getBatteryLife returns the current batteryLife to the calling 
**		function.
*******************************************************************************************/

int Character::getBatteryLife()
{
	return batteryLife;
}

//shoppingList functions

/******************************************************************************************
** Description: Character::printShoppingList prints the items in the shoppingList array to the 
**		user's screen.
*******************************************************************************************/

void Character::printShoppingList()
{
	for(int i = 0; i < shoppingListSize; i++)
	{
		std::cout << i+1 << ". " << shoppingList[i] << " ";
	}
}

/******************************************************************************************
** Description: Character::removeFromShoppingList removes an item from the shoppingList array.
**		If the array is "empty" then the user is told such. Otherwise it searches for
**		the position of the item to be removed and shifts the rest of the items 
**		behind it in the array forward one position. It then sets the last spot in 
**		the array to " " and decrements the shoppingListSize.
*******************************************************************************************/

void Character::removeFromShoppingList(std::string item)
{
	if(shoppingListSize == 0)
	{
		std::cout << "Shopping list is empty. You've got everything you needed." << std::endl;
	}
	
	else
	{
		int remove = -1;
		
		for(int i = 0; i < shoppingListSize; i++)
		{
			if(shoppingList[i] == item)
			{
				remove = i;
			}
		}
		
		if(remove == -1) //if the item is not on the list
		{
			std::cout << "\nThat's not an item on the shopping list." << std::endl;
		}
		
		else
		{
			for(int i = remove; i < shoppingListSize - 1; i++)
			{
				shoppingList[i] = shoppingList[i + 1];
			}
			
			shoppingList[shoppingListSize - 1] = " ";
			
			shoppingListSize -= 1;
		}
	}
}

/******************************************************************************************
** Description: Character::getShoppingListSize returns the current shoppingListSize to the 
**		calling function.
*******************************************************************************************/

int Character::getShoppingListSize()
{
	return shoppingListSize;
}

//destructor

/******************************************************************************************
** Description: The destructor deletes Character objects that are going out of scope. 
*******************************************************************************************/

Character::~Character() {}	
