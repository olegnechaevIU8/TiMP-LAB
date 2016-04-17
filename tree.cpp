#include "stdafx.h"
#include <iostream>
using namespace std;

void rev(int i, int* a, int N)
{
	for (int z = 0; z<N; z++)
		if (a[z] == i)
		{
			rev(z, a, N);
		}
	if (i != -1) cout << i;
}

void sym(int i, int* a, int N)
{
	int x = 0;
	for (int z = 0; z<N; z++)
		if (a[z] == i)
		{
			sym(z, a, N);
			if ((i != -1) && (!x)) cout << i;
			x++;
		}
	if (x == 0) cout << i;
}

void dir(int i, int* a, int N)
{
	for (int z = 0; z<N; z++)
		if (a[z] == i)
		{
			cout << z;
			dir(z, a, N);
		}
}

int main()
{
	int N; cin >> N;
	int* tree = new int[N];
	
	for (int i = 0; i<N; i++) cin >> tree[i];

	dir(-1, tree, N); cout << endl;
	rev(-1, tree, N); cout << endl;
	sym(-1, tree, N); cout << endl;

	delete[] tree;
	
	system("pause");
	return 0;
}