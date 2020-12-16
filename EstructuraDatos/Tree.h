#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Node
{
public:
	int Data;
	list<Node> Children = list<Node>();

	Node(int dat)
	{
		Data = dat;
	}
};

void PrintPreorder(Node n)
{
	cout << n.Data << ",";

	if (n.Children.size() != 0)
	{
		for (auto x : n.Children)
		{
			PrintPreorder(x);
		}
	}
}

void PrintPosorder(Node n)
{
	if (n.Children.size() != 0)
	{
		for (auto x : n.Children)
		{
			PrintPosorder(x);
		}
	}

	cout << n.Data << ",";
}