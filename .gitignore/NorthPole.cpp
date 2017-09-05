/******************************************************************************************
** Program name: NorthPole.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for NorthPole class object. It is derived from
**		the Destination class. It takes a pointer to a Character for its 
**		initialization. 
*******************************************************************************************/

#include "NorthPole.hpp"

/******************************************************************************************
** Description: The constructor sets the name of this class to "North Pole", sets the Character
**		pointer to player, and sets the data member key to "North Pole Stamp" to be
**		used as a search parameter in the menu function.
*******************************************************************************************/

NorthPole::NorthPole(Character* player) : Destination("North Pole", player)
{
	key = "North Pole Stamp";
}

/******************************************************************************************
** Description: The destructor deletes NorthPole objects going out of scope.
*******************************************************************************************/

NorthPole::~NorthPole() {}