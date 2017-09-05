/******************************************************************************************
** Program name: Kitchen.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the Kitchen class objects. Kitchen is derived
**		from the base class Space. It takes a pointer to a Character object as its
**		parameter. 
*******************************************************************************************/
#ifndef KITCHEN_HPP
#define KITCHEN_HPP
#include "Space.hpp"

class Kitchen: public Space
{
	public:
	Kitchen(Character* player);
	int menu();
	void special();
	virtual ~Kitchen();
};

#endif