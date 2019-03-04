// W19_CST126_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "session.h"
#include <iostream>

// schedule source: http://west.paxsite.com/schedule

int main()
{
	session paxWest0("Experiences Creating Tabletop RPGs", "Chris Pramas", 60);
	session paxWest1("PAX Storytime Session", "Ion Hazzikostas", 60);
	session paxWest2("Twitch Town Hall", "Erin Wayne", 60);
	session paxWest3("Gaming While Other", "JC Lau", 60);
	session paxWest4("I Agree, Internet's Biggest Lie", "Ryan Black", 60);
	session paxWest5("Tabletop->PC: BATTLETECH Dev Story", "Jordan Weisman", 60);
	session paxWest6("Villains Vs Heroes: Moral High Gnd", "Anthony Bean", 60);
	session paxWest7("Game Jobs You Never Knew Existed", "Glenn White", 60);
	session paxWest8("Behind Sound: Game Audio Deep Dive", "Akash Thakkar", 60);
	session paxWest9("The Improvised Postmortem", "Pat Baer", 60);

	session paxWestArray[]{ paxWest0 , paxWest1 , paxWest2 , paxWest3 , paxWest4 , paxWest5 , paxWest6 , paxWest7 , paxWest8 , paxWest9 };

	List paxWestList;
	for (int i{}; i != 10; i++)
	{
		paxWestList.addSession(&(paxWestArray[i]));
	}

	paxWestList.printList();

	std::string finding{ "Y" }, lookingFor{};
	while (finding == "Y" || finding == "y")
	{
		std::cout << std::endl << "Which speaker would you like to find? ";
		getline(std::cin, lookingFor); 

		std::cout << std::endl;

		paxWestList.findSession(lookingFor);

		std::cout << "Do you want to find another? (enter Y to continue) ";
		std::cin >> finding;

		std::cin.get();
	}
}


