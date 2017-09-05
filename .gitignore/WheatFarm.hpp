/******************************************************************************************
** Program name: WheatFarm.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the WheatFarm class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#ifndef WHEATFARM_HPP
#define WHEATFARM_HPP
#include "Location.hpp"

class WheatFarm: public Location
{
	public:
	WheatFarm(Character* player);
	void special();
	virtual ~WheatFarm();
};

#endif