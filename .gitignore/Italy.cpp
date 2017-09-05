/******************************************************************************************
** Program name: Italy.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the Italy class object. It is derived from
**		the Destination class. It takes a pointer to a Character for its 
**		initialization. 
*******************************************************************************************/

#include "Italy.hpp"

/******************************************************************************************
** Description: The constructor sets the name of this class to "Italy", sets the Character
**		pointer to player, and sets the data member key to "Italian Stamp" to be
**		used as a search parameter in the menu function.
*******************************************************************************************/

Italy::Italy(Character* player) : Destination("Italy", player)
{
	key = "Italian Stamp";
}

/******************************************************************************************
** Description: The destructor deletes Italy objects going out of scope.
*******************************************************************************************/

Italy::~Italy() {}