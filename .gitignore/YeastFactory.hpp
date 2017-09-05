/******************************************************************************************
** Program name: YeastFactory.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the YeastFactory class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#ifndef YEASTFACTORY_HPP
#define YEASTFACTORY_HPP
#include "Location.hpp"

class YeastFactory: public Location
{
	public:
		YeastFactory(Character* player);
		void special();
		virtual ~YeastFactory();
};

#endif