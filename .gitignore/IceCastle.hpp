/******************************************************************************************
** Program name: IceCastle.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the IceCastle class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#ifndef ICECASTLE_HPP
#define ICECASTLE_HPP
#include "Location.hpp"

class IceCastle: public Location
{
	public:
		IceCastle(Character* player);
		void special();
		virtual ~IceCastle();
};

#endif