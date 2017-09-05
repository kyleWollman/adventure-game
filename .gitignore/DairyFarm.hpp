/******************************************************************************************
** Program name: DairyFarm.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the DairyFarm class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#ifndef DAIRYFARM_HPP
#define DAIRYFARM_HPP
#include "Location.hpp"

class DairyFarm: public Location
{
	public:
	DairyFarm(Character* player);
	void special();
	virtual ~DairyFarm();
};

#endif