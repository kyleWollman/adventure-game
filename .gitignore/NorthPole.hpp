/******************************************************************************************
** Program name: NorthPole.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the NorthPole class object. It is derived from
**		the Destination class. It takes a pointer to a Character for its 
**		initialization. 
*******************************************************************************************/

#ifndef NORTHPOLE_HPP
#define NORTHPOLE_HPP
#include "Destination.hpp"

class NorthPole: public Destination
{
	public:
	NorthPole(Character* player);
	virtual ~NorthPole();
};

#endif