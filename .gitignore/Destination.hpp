/******************************************************************************************
** Program name: Destination.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the Destination class. It is derived from the 
**		the Space class. It has a protected data member called key, which it uses
**		as a search parameter for the special functions of classes derived from 
**		Destination. Destination objects are intialized with a string and a pointer
**		to a Character object. 
*******************************************************************************************/

#ifndef DESTINATION_HPP
#define DESTINATION_HPP
#include "Space.hpp"

class Destination: public Space
{
	protected:
		std::string key;
		
	public:
		Destination(std::string name, Character* player);
		int menu();
		void special();
		virtual ~Destination();
};

#endif