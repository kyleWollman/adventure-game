/******************************************************************************************
** Program name: PortalTransitAuthority.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for PortalTransitAuthority class objects. It is 
**		dervied from the Space class. It has a constructor, a special function that
**		allows players to get their passport stamped and a menu function that lets
**		the user choose where to go next. 
*******************************************************************************************/

#ifndef PORTALTRANSITAUTHORITY_HPP
#define PORTALTRANSITAUTHORITY_HPP
#include "Space.hpp"

class PortalTransitAuthority: public Space
{
	public:
	PortalTransitAuthority(Character* player);
	void special();
	int menu();
	virtual ~PortalTransitAuthority();
};
#endif