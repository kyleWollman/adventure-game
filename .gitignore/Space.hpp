/******************************************************************************************
** Program name: Space.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for Space class objects. Space is an abstract class
**		that has an array of 5 pointers to Space class objects, an array of stringstream
**		a vector to hold strings of "dropped items" and a pointer to a Character, 
**		which represents the player using the space. Since Space is an abstract class
**		it cannot be instantiated, and can only be used by derived classes.
*******************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <vector>
#include <iostream>
#include "Character.hpp"
#include "verify.hpp"


class Space
{
	protected:
		Space* spaces[5];
		Space* location;
		std::string name;
		std::string items[4];
		std::vector<std::string> droppedItems;
		Character* player;
	
	public:
		//constructor
		Space(std::string name, Character* player);
		
		//get functions
		std::string getName();
		std::string getItemName(int itemNum);
		Space* getSpace(int subscript);
		
		//set function
		void setSpaces(Space* space, int subscript);
		
		//screen control
		void printDroppedItems();
		void clearScreen();
		
		//misc functions
		virtual int menu() = 0;
		virtual void special();
		void dropItem();
		void pickUpDroppedItem();
	
		//destructor
		virtual ~Space();
};

#endif
	
		
		
		
