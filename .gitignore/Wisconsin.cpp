/******************************************************************************************
** Program name: Wisconsin.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the Wisconsin class object. It is derived from
**		the Destination class. It takes a pointer to a Character for its 
**		initialization. 
*******************************************************************************************/

#include "Wisconsin.hpp"

/******************************************************************************************
** Description: The constructor sets the name of this class to "Wisconsin", sets the Character
**		pointer to player, and sets the data member key to "Wisconsin Stamp" to be
**		used as a search parameter in the menu function.
*******************************************************************************************/

Wisconsin::Wisconsin(Character* player) : Destination("Wisconsin", player)
{
	key = "Wisconsin Stamp";
}

/******************************************************************************************
** Description: The destructor deletes Wisconsin objects going out of scope.
*******************************************************************************************/

Wisconsin::~Wisconsin() 
{}
