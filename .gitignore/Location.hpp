/******************************************************************************************
** Program name: Location.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the location class object. It is derived from
**		the Space base class. It takes a string and a pointer to a Character object
**		as its initialzation parameters. It has a string as a protected data member, 
**		which is initialized by classes derived from the Location class.
*******************************************************************************************/

#ifndef LOCATION_HPP
#define LOCATION_HPP
#include "Space.hpp"

class Location: public Space
{
	protected:
	std::string action;
	
	public:
	Location(std::string name, Character* player);
	int menu();
	void special();
	virtual ~Location();
};

#endif
	