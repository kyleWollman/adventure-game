/******************************************************************************************
** Program name: Germany.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the Germany class object. It is derived from
**		the Destination class. It takes a pointer to a Character for its 
**		initialization. 
*******************************************************************************************/

#ifndef GERMANY_HPP
#define GERMANY_HPP
#include "Destination.hpp"

class Germany: public Destination
{
	public:
	Germany(Character* player);
	virtual ~Germany();
};

#endif