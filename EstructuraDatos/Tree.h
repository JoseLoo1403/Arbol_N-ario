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

void PrintNodeInfo(Node n)
{
	cout << "Dato: " << n.Data << endl;
	cout << "Hijos: ";

	for (auto x : n.Children)
	{
		cout << x.Data << ",";
	}
}

void SearchNode(Node root, int SearchingData)
{
	if (root.Data == SearchingData)
	{
		PrintNodeInfo(root);
	}

	if (root.Children.size() != 0)
	{
		for (auto x : root.Children)
		{
			SearchNode(x, SearchingData);
		}
	}
}

//Menu helpers

void MainMenu()
{
	system("cls");
	cout << "Que desea hacer?" << endl;
	cout << "1.Generar arbol de forma aleatoria" << endl;
	cout << "2.Agregar nodo" << endl;
	cout << "3.Buscar nodo" << endl;
	cout << "4.Eliminar nodo" << endl;
}

bool CountinueHelper()
{
	int res;
	cout << "Desea continuar? 1.Si  0.No" << endl;
	cin >> res;

	if (res == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}