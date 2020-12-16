#include <iostream>
#include <list>
#include <iterator>
#include "Tree.h"

using namespace std;


//Global Variables

Node Root = Node(1);

void InsertNode(int data, int father, Node* node)
{
	if (Root.Data == NULL)
	{
		Root = Node(data);
		return;
	}

	if (node->Data == father)
	{
		node->Children.push_back(Node(data));
		cout << "Nuevo Nodo ingresado" << endl;
		return;
	}

	for (list<Node>::iterator i = node->Children.begin(); i != node->Children.end(); i++)
	{
		if (i->Data == father)
		{
			i->Children.push_back(Node(data));
			cout << "Nuevo Nodo ingresado" << endl;
			return;
		}
	}

	
	for (list<Node>::iterator i = node->Children.begin(); i != node->Children.end(); i++)
	{
		InsertNode(data,father,&*i);
	}
}


void PrintTree(Node n, string SpaceHelper)
{
	SpaceHelper = "   " + SpaceHelper;
	for (auto x : n.Children)
	{
		cout << SpaceHelper <<x.Data << endl;
		if (x.Children.size() > 0)
		{
			PrintTree(x,SpaceHelper);
		}
	}
}

int main()
{
	InsertNode(2, 1, &Root);
	InsertNode(3, 1, &Root);
	InsertNode(4, 1, &Root);
	InsertNode(5, 2, &Root);
	InsertNode(6, 2, &Root);

	cout <<"   " <<Root.Data << endl;
	PrintTree(Root, "|--");

	PrintPreorder(Root);
	cout << endl;
	PrintPosorder(Root);
}