#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	string lib;
	cin >> lib;

	HINSTANCE h = 0;

	void(*add) (int);
	void(*get) ();
	void(*del) ();

	if (lib == "LAB7Queue.dll") h = LoadLibrary(TEXT("LAB7Queue.dll"));
	if (lib == "LAB&PrQueue.dll") h = LoadLibrary(TEXT("LAB7PrQueue.dll"));
	else 
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) 
		{
			string command;
			cin >> command;
			if (command == "add") 
			{
				int n;
				cin >> n;
				add = (void(*) (int))GetProcAddress(h, "add");
				add(n);
			}
			if (command == "get") 
			{
				get = (void(*) ())GetProcAddress(h, "get");
				get();
			}
			if (command == "del") 
			{
				del = (void(*) ())GetProcAddress(h, "del");
				del();
			}
		}
	}

	FreeLibrary(h);

	return 0;
}