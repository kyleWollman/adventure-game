/******************************************************************************************
** Program name: Character.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the Character class. Character represents the 
**		player in the game. It has 3 arrays, a shoppingList, inventory, and Passport
**		array each of size 4 that hold strings. It also has a battery array that 
**		represents the Portal Gun's battery life. Character has various functions for
**		manipulating or retrieving the data in these arrays.
*******************************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>


class Character
{
	private: 
	
	std::string name;
	
	//shopping list
	std::string shoppingList[4] = {"Milk", "Pasta", "Beer", "Ice"};
	int shoppingListSize = 4;
	
	//inventory data
	std::string inventory[4];
	const int inventoryCapacity = 4;
	int inventorySize = 0;
	
	//passport data
	std::string passport[4];
	int stamps = 0;
	
	//portal data
	char battery[21];
	int batteryLife = 21;

	
	public:
	//constructor
	Character(std::string name);
	
	std::string getName();
	
	//inventory functions
	void addToInventory(std::string item);
	std::string removeFromInventory();
	void replace(std::string replace, std::string with);
	void printInventory();
	bool searchInventory(std::string item);
	int getInventorySize();
	
	//passport functions
	void addToPassport(std::string stamp);
	bool searchPassport(std::string stamp);
	
	//portal functions
	void printBattery();
	void usePortal();
	int getBatteryLife();
	
	//shoppinglist functions
	void printShoppingList();
	int getShoppingListSize();
	void removeFromShoppingList(std::string item);
	
	//destructor
	~Character();
};

#endif
