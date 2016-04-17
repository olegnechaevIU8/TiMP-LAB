#include "stdafx.h"
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

int num = 0;
class stack
{
public:
	int data;
	int n;
	stack* next;
	stack(int w, int a)
	{
		data = w;
		n = a;
		next = 0;
		num++;
	}
};

stack* ph = 0;
stack* pq = 0;

void add(int a, stack* b)
{
	if ((a == 0) && (ph == 0))
	{
		ph = b;
		return;
	}
	pq = ph;
	while (pq->n != (a - 1))
	{
		if (pq->next == 0) pq->next = new stack(0, pq->n + 1);
		else pq = pq->next;
	}
	b->next = pq->next;
	pq->next = b;
	pq = pq->next;
	while (pq->next != 0)
	{
		pq = pq->next;
		pq->n++;
	}

}

void get(int a)
{
	pq = ph;
	while (pq->n != a)
	{
		pq = pq->next;
	}
	cout << pq->data << endl;
}

void del(int a)
{
	pq = ph;
	if (a == 0)
	{
		ph = pq->next;
		pq = ph;
		pq->n--;
	}
	else
	{
		while (pq->n != a - 1)
		{
			pq = pq->next;
		}
		stack* q;
		q = pq->next;
		pq->next = q->next;
	}
	while (pq->next != 0)
	{
		pq = pq->next;
		pq->n--;
	}
	num--;
}

int main()
{
	int n;
	cin >> n;
	string com;
	int l, h;
	for (int i = 0; i < n; i++)
	{
		cin >> com;
		if (com == "add")
		{
			cin >> h;
			stack* ls;
			ls = new stack(h, num);
			add(num - 1, ls);
		}
		if (com == "get")
		{
			get(num - 1);
		}
		if (com == "del")
		{
			del(num - 1);
		}
	}
	system("pause");
	return 0;
}