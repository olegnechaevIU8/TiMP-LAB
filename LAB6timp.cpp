#include "stdafx.h"
#include <cmath>
#include <iostream>

using namespace std;

bool* bv;
unsigned int N, M;
unsigned int* min;
unsigned int** dist;

void Algorythm(void);

int main() 
{
	bv = new bool[N];
	min = new unsigned int[N];
	dist = new unsigned int*[N];
	unsigned int a, b, c, d;
	cin >> N >> a;
	cin >> M;

	for (unsigned int i = 0; i < N; i++) 
	{
		bv[i] = false; min[i] = INT_MAX;
		dist[i] = new unsigned int[N];
		for (unsigned int j = 0; j < N; j++) 
		{
			dist[i][j] = INT_MAX;
		}
	}
	for (unsigned int i = 0; i < a; i++) 
	{
		cin >> b >> c >> d;
		dist[b][c] = d;
	}
	for (unsigned int i = 0; i < a; i++) 
	{
		min[i] = dist[M][i];
		if (i == M) {
			min[i] = 0;
		}
	}

	Algorythm();

	for (unsigned int i = 0; i < N; i++) 
	{
		cout << min[i] << " ";
	}
	system("pause");
	return 0;
}

void Algorythm() 
{
	while (true) 
	{
		unsigned int min_d = INT_MAX, min_index = INT_MAX; bool bva = true;
		for (unsigned int i = 0; i < N; i++) 
		{
			if (!bv[i]) 
			{
				bva = false;
				if (min[i] < min_d) 
				{
					min_d = min[i];
					min_index = i;
				}
			}
		}

		if (bva) 
		{
			return;
		}
		bv[min_index] = true;

		for (unsigned int i = 0; i < N; i++) 
		{
			min[i] = fmin(dist[min_index][i] + min_d, min[i]);

		}
	}
}