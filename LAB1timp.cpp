#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void compare(string a, string b) {
	int i = 1;
	ifstream fs1(a);
	while (!fs1.eof()) 
	{
		ifstream fs2(b);
		string s1, s2;
		bool eq = false;
		
		getline(fs1, s1);
		while (!fs2.eof()) 
		{
			getline(fs2, s2);
			if (s1 == s2) 
			{
				eq = true;
			}
		}
		fs2.close();
		if (eq == false)
		{
			cout << a << " " << i << " " << s1 << endl;
			i++;
		}
	}
	fs1.close();
}

int main()
{
	string str1; cin >> str1;
	string str2; cin >> str2;
	
	compare(str1, str2); 
	compare(str2, str1);
	
	
	system("pause");
	return 0;
}
