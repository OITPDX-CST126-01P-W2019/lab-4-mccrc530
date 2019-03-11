#include "pch.h"
#include "session.h"
#include <iostream>
#include <iomanip>

session::session()
{
	title = "";
	speaker = "";
	length = 0;
	next = nullptr;
}
session::session(std::string const inputTitle, std::string const inputSpeaker, int const inputLength)
{
	title = inputTitle;
	speaker = inputSpeaker;
	length = inputLength;
	next = nullptr;
}
void session::printSession() const
{
	std::cout << std::setw(35) << title << std::setw(20) << speaker << " " << length << std::endl;
}

std::string const session::getSpeaker() const
{
	return speaker;
}

void session::printTitle() const
{
	std::cout << title << std::endl;
}

List::List()
{
	topList = nullptr;
}

List::~List()
{
	std::cout << std::endl << "~List" << std::endl;

	session * nextSession = topList;
	session * tempSession = topList;
	while (nextSession)
	{
		nextSession->printTitle();
		nextSession = nextSession->next;
		delete tempSession;
		tempSession = nextSession;
	}
}

void List::printList() const
{
	session * nextSession = topList;
	while (nextSession)
	{
		nextSession->printSession();
		nextSession = nextSession->next;
	}

}

void List::addSession(session * newSession)
{
	if (!topList)
	{
		topList = newSession;
	}

	else
	{
		if (newSession->getSpeaker() < topList->getSpeaker()) 
		{
			newSession->next = topList;
			topList = newSession;
		}

		else
		{
			session * nextSession = topList;
			session * prevSession = nullptr;
			while (nextSession && nextSession->getSpeaker() < newSession->getSpeaker())
			{
				prevSession = nextSession;
				nextSession = nextSession->next;
			}
			prevSession->next = newSession;
			newSession->next = nextSession;
		}
	}
}

void List::findSession(std::string const speaker) const
{
	session * nextSession = topList;
	while (nextSession && nextSession->getSpeaker() < speaker)
	{
		nextSession = nextSession->next;
	}
	if (nextSession && nextSession->getSpeaker() == speaker)
	{
		nextSession->printTitle();
	}
	else
	{
		std::cout << "Did not find speaker in list." << std::endl;
	}
}