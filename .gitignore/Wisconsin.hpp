/******************************************************************************************
** Program name: Wisconsin.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the Wisconsin class object. It is derived from
**		the Destination class. It takes a pointer to a Character for its 
**		initialization. 
*******************************************************************************************/

#ifndef WISCONSIN_HPP
#define WISCONSIN_HPP
#include "Destination.hpp"

class Wisconsin: public Destination
{
	public:
	Wisconsin(Character* player);
	virtual ~Wisconsin();
};

#endif