/******************************************************************************************
** Program name: finalMain.cpp
** Author: Kyle Wollman
** Date: 03/21/2017
** Description: This is the client function for the final project. It prints out a short 
**		introduction to the game describing the goal, gets the user's name, clears
**		the screen and creates a Game class object will controls the rest of the 
**		game play.
*******************************************************************************************/

#include <iostream>
#include <string>
#include "Game.hpp"

int main()
{
	std::cout << "Welcome to Shopping Trip!" 
		  << "\nYou will be visiting many locations to hunt down the items you need."
		  << "\nOnce an item has been safely put away back at home, it will be crossed off the list."
		  << "\nBe sure to get all the items back home before the portal gun runs out of battery."
		  << "\nOtherwise you'll be stuck with no way to get home. Happy travels." << std::endl;
	
	std::string name;
	
	std::cout << "\n\nPlease enter your name." << std::endl;
	std::getline(std::cin, name);
	
	std::cout << std::string(75, '\n');
	
	std::cout << "\nYou are minding your own business when your mom asks you to get some"
		  << "\ngroceries for her. It's only four items. Milk, pasta, beer, and ice."
		  << "\nIt won't take long, she promises."
		  << std::endl;
				
	Game game = Game(name);
	
	return 0;
}
