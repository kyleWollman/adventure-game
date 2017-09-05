/******************************************************************************************
** Program name: BucketFactory.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the source file for the BucketFactory class. It is derived from the 
**		Location base class. It takes a pointer to a Character object for its 
**		itialization and overwrites the special function.
*******************************************************************************************/

#include "BucketFactory.hpp"

/******************************************************************************************
** Description: The constructor takes a pointer to a Character as its paramter. It initializes
**		its name and player data members through the Location class. It initializes
**		one of its items array members to "Bucket" and its action data 
**		member to "Build a bucket". 
*******************************************************************************************/

BucketFactory::BucketFactory(Character* player) : Location("Bucket Factory", player)
{
	items[0] = "Bucket";
	
	action = "Build a bucket.";
}

/******************************************************************************************
** Description: BucketFactory::special searches the player's inventory for "Bucket". If they
**		already have one they are not allowed to get another one. If not they are
**		prompted to build one. They have to choose the color, what the handle is 
**		is made from, and the material that the bucket is made of by inputting 
**		strings for the varoius parameters. Once they are done building their bucket
**		"Bucket" is added to their inventory.
*******************************************************************************************/

void BucketFactory::special()
{
	if(player -> getInventorySize() == 4)
	{
		std::cout << "It looks like you are carrying all that you can hold. You better drop something"
			  << "\nbefore you can " << action << std::endl;
	}

	else if(player -> searchInventory("Bucket"))
	{
		std::cout << "I hope you enjoy your bucket. See you another time." << std::endl;
	}
	
	else
	{
		std::string color, handle, material;
		
		std::cin.clear();
		std::cin.ignore();
		
		std::cout << "Welcome to Build a Bucket, where you get to design and build your own custom bucket."
			  << "\nFor this process to work, you must free your mind and let your creative juices flow."
			  << "\nFirst we need to know what color you would like your bucket to be?" << std::endl;

		std::cin >> color;
		
		std::cout << "\nOh, excellent choice. I can see that you are naturally gifted for this sort of thing."
			  << "\nNext I need to know what you would like to use for the handle of the bucket."
			  << "\nTraditionally handles are something curved like a rainbow, but you can use whatever you like."
			  << std::endl;
				  
		std::cin >> handle;
		
		std::cout << "\nWow! I did not see that coming. Great idea!"
			  << "\nFinally tell us what material you want the bucket to be made out of. You're only limited by your imagination."
			  << std::endl;
				  
		std::cin >> material;
		
		std::cout << "\n\nAlright. We're all done. And here is your " << color << " bucket, with a " << handle << " for a handle."
			  << "\nMade from the finest " << material << ". Enjoy now. Happy bucketing!" << std::endl;

		player -> addToInventory(items[0]);
		items[0] = " ";
	}
}			

/******************************************************************************************
** Description: The destructor deletes BucketFactory objects going out of scope.
*******************************************************************************************/

BucketFactory::~BucketFactory() {}
