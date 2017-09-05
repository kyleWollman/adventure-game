/******************************************************************************************
** Program name: BucketFactory.hpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the header file for the BucketFactory class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#ifndef BUCKETFACTORY_HPP
#define BUCKETFACTORY_HPP
#include "Location.hpp"

class BucketFactory: public Location
{
	public:
		BucketFactory(Character* player);
		void special();
		virtual ~BucketFactory();
};

#endif