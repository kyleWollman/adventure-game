/******************************************************************************************
** Program name: Italy.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the Italy class object. It is derived from
**		the Destination class. It takes a pointer to a Character for its 
**		initialization. 
*******************************************************************************************/

#ifndef ITALY_HPP
#define ITALY_HPP
#include "Destination.hpp"

class Italy: public Destination
{
	public:
	Italy(Character* player);
	virtual ~Italy();
};

#endif