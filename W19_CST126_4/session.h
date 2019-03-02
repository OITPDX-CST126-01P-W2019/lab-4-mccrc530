#pragma once

struct session
{
public:
	session();
	session(char const * inputTitle, char const * inputSpeaker, int inputLength);
	void printSession() const;
	char * const getSpeaker();
	void printTitle() const;
	session * next;
private:
	char title[35];
	char speaker[35];
	int length;
};

class List
{
public:
	List();
	~List();
	void printList() const;
	void addSession(session * newSession);
	void findSession(char * speaker) const;
private:
	session * topList;
};