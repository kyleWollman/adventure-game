/******************************************************************************************
** Program name: Home.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for Home class objects. It is dervied from the Space
**		class. It has a Constructor, a special function that allows players to look
**		around the space, and a menu function that gives them the options to look 
**		around, put away groceries, open a portal, or quit the game.
*******************************************************************************************/

#ifndef HOME_HPP
#define HOME_HPP
#include "Space.hpp"

class Home: public Space
{
	public:
	Home(Character* player);
	int menu();
	void special();
	virtual ~Home();
};

#endif