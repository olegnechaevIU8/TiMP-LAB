#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
vector<int> tree;

void add() {
	int a, b;
	cin >> a;
	if (tree.size() == 0)
		tree.insert(tree.begin(), a);
	else {
		for (b = 0; b < tree.size(); b++)
			if (a <= tree[b])
			{
				tree.insert(tree.begin() + b, a);
				break;
			}
		if (b == tree.size())
			tree.push_back(a);

	}
}

int main()
{
	char command[4];
	int N;
	cin >> N;
	for (int b = 0; b <= N; b++) {
		scanf_s("%s", &command);
		switch (command[0]) {
		case 'add':
			add();
			break;
		case 'get':
			cout << tree[0] << endl;
			break;
		case 'del':
			tree.erase(tree.begin());
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}