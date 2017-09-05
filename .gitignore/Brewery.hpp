/******************************************************************************************
** Program name: Brewery.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the Brewery class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#ifndef BREWERY_HPP
#define BREWERY_HPP
#include "Location.hpp"

class Brewery: public Location
{
	public:
		Brewery(Character* player);
		void special();
		virtual ~Brewery();
};

#endif