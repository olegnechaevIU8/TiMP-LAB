#include "stdafx.h"
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

class list
{
public:
	int data;
	int n;
	list* next;
	list(int w, int a)
	{
		data = w;
		n = a;
		next = 0;
	}
};

list* ph = 0;
list* pq = 0;


void add(int a, list* b)
{
	if ((a == 0) && (ph == 0))
	{
		ph = b;
		return;
	}

	if ((a != 0) && (ph == 0))
	{
		ph = new list(0, 0);
	}

	if ((a == 0) && (ph != 0))
	{
		pq = ph;
		ph = b;
		ph->next = pq;
		pq->n++;
		while (pq->next != 0)
		{
			pq = pq->next;
			pq->n++;
		}
		return;
	}

	pq = ph;
	while (pq->n != (a - 1))
	{
		if (pq->next == 0) pq->next = new list(0, pq->n + 1);
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
		list* q;
		q = pq->next;
		pq->next = q->next;
	}
	while (pq->next != 0)
	{
		pq = pq->next;
		pq->n--;
	}
}

int main()
{
	int n, l, h; string com;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> com;
		if (com == "add")
		{
			cin >> l;
			cin >> h;
			list* ls;
			ls = new list(h, l);
			add(l, ls);
		}
		if (com == "get")
		{
			cin >> l;
			get(l);
		}
		if (com == "del")
		{
			cin >> l;
			del(l);
		}
	}
	system("pause");
	return 0;
}