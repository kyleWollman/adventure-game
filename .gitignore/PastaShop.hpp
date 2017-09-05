/******************************************************************************************
** Program name: PastaShop.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the PastaShop class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#ifndef PASTASHOP_HPP
#define PASTASHOP_HPP
#include "Location.hpp"

class PastaShop: public Location
{
	public:
		PastaShop(Character* player);
		void special();
		virtual ~PastaShop();
};

#endif
		