#include "pch.h"
#include "session.h"
#include <iostream>
#include <iomanip>

session::session()
{
	title[0] = '/0';
	speaker[0] = '/0';
	length = 0;
}
session::session(char const * inputTitle, char const * inputSpeaker, int const inputLength)
{
	for (int i{}; i != 35; i++)
	{
		title[i] = inputTitle[i];
		speaker[i] = inputSpeaker[i];
	}

	length = inputLength;
	next = nullptr;
}
void session::printSession() const
{
	std::cout << std::setw(35) << title << std::setw(35) << speaker << " " << length << std::endl;
}

char * const session::getSpeaker()
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
	std::cout << "~List" << std::endl;

	session * nextSession = topList;
	session * tempSession = topList;
	while (nextSession)
	{
		nextSession->printTitle();
		nextSession = nextSession->next;
		tempSession->next = nullptr;
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
		if (strcmp(newSession->getSpeaker(), topList->getSpeaker()) < 0) {
			newSession->next = topList;
			topList = newSession;
		}

		else
		{
			session * nextSession = topList;
			session * prevSession = nullptr;
			while (nextSession && strcmp(nextSession->getSpeaker(), newSession->getSpeaker()) < 0)
			{
				prevSession = nextSession;
				nextSession = nextSession->next;
			}
			prevSession->next = newSession;
			newSession->next = nextSession;
		}
	}
}

void List::findSession(char * speaker) const
{
	session * nextSession = topList;
	while (nextSession && strcmp(nextSession->getSpeaker(), speaker) < 0)
	{
		nextSession = nextSession->next;
	}
	if (nextSession && strcmp(nextSession->getSpeaker(), speaker) == 0)
	{
		nextSession->printTitle();
	}
	else
	{
		std::cout << "Did not find speaker in list." << std::endl;
	}
}