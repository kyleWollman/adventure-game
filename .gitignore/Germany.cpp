/******************************************************************************************
** Program name: Germany.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the Germany class object. It is derived from
**		the Destination class. It takes a pointer to a Character for its 
**		initialization. 
*******************************************************************************************/

#include "Germany.hpp"

/******************************************************************************************
** Description: The constructor sets the name of this class to "Germany", sets the Character
**		pointer to player, and sets the data member key to "German Stamp" to be
**		used as a search parameter in the menu function.
*******************************************************************************************/

Germany::Germany(Character* player) : Destination("Germany", player)
{
	key = "German Stamp";
}

/******************************************************************************************
** Description: The destructor deletes Germany objects going out of scope.
*******************************************************************************************/

Germany::~Germany() {}