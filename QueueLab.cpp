#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class queue
{
	queue* Next;
	string Data;
public:
	queue() : Next(nullptr), Data("") {};
	void push(string data);
	void get();
	void pop();
	~queue() { if (Next != nullptr) delete Next; }
}Queue;

void queue::push(string data)
{
	if (Next == nullptr)
		if (Data != "")
			Next = new queue();
		else
		{
			Data = data;
			return;
		}
	Next->push(Data);
	Data = data;
}

void queue::get()
{
	if (Next == nullptr)
	{
		cout << Data << endl;
		return;
	}
	Next->get();
}

void queue::pop()
{
	if (Next == nullptr)
	{
		Data = "";
		return;
	}
	else
		Next->pop();
}



int main()
{
	size_t n;       //Number of commands
	string line;    //Command name
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> line;
		if (line == "add")
		{
			cin >> line;
			Queue.push(line);
		}
		else if (line == "get")
			Queue.get();
		else if (line == "del")
			Queue.pop();
		else
			return 1;

	}
	system("pause");
	return 0;
}

