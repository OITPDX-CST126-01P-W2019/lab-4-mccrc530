#pragma once
#include <string>
struct session
{
public:
	session();
	session(std::string const inputTitle, std::string const inputSpeaker, int inputLength);
	void printSession() const;
	std::string const getSpeaker() const;
	void printTitle() const;
	session * next;
private:
	std::string title;
	std::string speaker;
	int length;
};

class List
{
public:
	List();
	~List();
	void printList() const;
	void addSession(session * newSession);
	void findSession(std::string const speaker) const;
private:
	session * topList;
};