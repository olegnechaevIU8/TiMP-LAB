#include "stdafx.h"
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

int num = 0;
class queue
{
public:
	int data;
	int n;
	queue* next;
	queue(int w, int a)
	{
		data = w;
		n = a;
		next = 0;
		num++;
	}
};

queue* ph = 0;
queue* pq = 0;

void add(int a, queue* b)
{
	if ((a == 0) && (ph == 0))
	{
		ph = b;
		return;
	}
	pq = ph;
	while (pq->n != (a - 1))
	{
		if (pq->next == 0) pq->next = new queue(0, pq->n + 1);
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
		queue* q;
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
	int n, l, h; string dev;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> dev;
		if (dev == "add")
		{
			cin >> h;
			queue* ls;
			ls = new queue(h, num);
			add(num - 1, ls);
		}
		if (dev == "get")
		{
			get(0);
		}
		if (dev == "del")
		{
			del(0);
		}
	}
	return 0;
}
