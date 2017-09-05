/******************************************************************************************
** Program name: FerrariDealer.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the FerrariDealer class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#ifndef FERRARIDEALER_HPP
#define FERRARIDEALER_HPP
#include "Location.hpp"

class FerrariDealer: public Location
{
	public:
		FerrariDealer(Character* player);
		void special();
		virtual ~FerrariDealer();
};

#endif