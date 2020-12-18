#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include "Tree.h"

using namespace std;

//Global Variables
vector<int>DataList;
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
		DataList.push_back(data);
		cout << "Nuevo Nodo ingresado" << endl;
		return;
	}

	for (list<Node>::iterator i = node->Children.begin(); i != node->Children.end(); i++)
	{
		if (i->Data == father)
		{
			i->Children.push_back(Node(data));
			DataList.push_back(data);
			cout << "Nuevo Nodo ingresado" << endl;
			return;
		}
	}
	
	for (list<Node>::iterator i = node->Children.begin(); i != node->Children.end(); i++)
	{
		InsertNode(data,father,&*i);
	}
}

void RemoveNode(int data, Node* n)
{
	for (list<Node>::iterator i = n->Children.begin(); i != n->Children.end(); i++)
	{
		if (i->Data == data)
		{
			for (auto l : n->Children)
			{
				if (l.Data == data)
				{
					DataList = RemoveChildrenFromDataList(DataList, l);
				}
			}
			n->Children.erase(i);			
			cout << "Nodo eliminado" << endl;
			return;
		}
		if (i->Children.size() > 0)
		{
			RemoveNode(data, &*i);
		}
	}
}


void PrintTree(Node n, string SpaceHelper)
{
	SpaceHelper = "|  " + SpaceHelper;
	for (auto x : n.Children)
	{
		cout << SpaceHelper <<x.Data << endl;
		if (x.Children.size() > 0)
		{
			PrintTree(x,SpaceHelper);
		}
	}
}

void LookForNode()
{
	int D;
	system("cls");
	cout << "Ingrese el dato del nodo que quiere buscar: " << endl;
	cin >> D;
	SearchNode(Root, D);
	system("PAUSE");
}

bool VerifytDuplicate(int N)
{
	for (auto x : DataList)
	{
		if (x == N)
		{
			return true;
		}
	}

	return false;
}

void RemoveNodeMenu()
{
	while (true)
	{
		system("cls");
		int DataToRemove;

		cout << "Ingrese el dato del nodo a eliminar: " << endl;
		cin >> DataToRemove;

		RemoveNode(DataToRemove, &Root);

		if (!CountinueHelper("Desea Eliminar otro nodo?"))
		{
			break;
		}
	}
}

void InsertNodeMenu()
{
	while (true)
	{
		//Insert Node
		system("cls");
		int _NewData;
		int Father;

		cout << "el dato del nodo: ";
		cin >> _NewData;

		if (!VerifytDuplicate(_NewData)) //Verify data
		{
			cout << endl;

			cout << "Ingrese el nodo padre: ";
			cin >> Father;

			InsertNode(_NewData, Father, &Root);
		}
		else
		{
			cout << "Este valor esta repetido" << endl;
		}

		if (!CountinueHelper("Desea agregar otro nodo?"))
		{
			break;
		}
	}
}

void GenerateTree() //Generate tree with random numbers
{
	int randomNumber;
	int randomFather;

	for (int i = 0; i < 50; i++)
	{
		randomNumber = 1 + (rand() % 100);
		randomFather = rand() % DataList.size();

		if (!VerifytDuplicate(randomNumber))
		{
			InsertNode(randomNumber,DataList[randomFather],&Root);
		}
	}
}

int main()
{
	DataList.push_back(1);
	bool verificador = true;
	int result;

	while (verificador)
	{
		MainMenu();
		cin >> result;

		switch (result)
		{
		case 1:
			GenerateTree();
			break;
		case 2:
			InsertNodeMenu();
			break;
		case 3:
			LookForNode();
			break;
		case 4:
			RemoveNodeMenu();
			break;
		case 5:
			cout << "   " << Root.Data << endl;
			PrintTree(Root,"|--");
			system("PAUSE");
			break;
		case 6:

			cout << "   " << Root.Data << endl;
			PrintTree(Root,"|--");

			cout << "Recorridos: " << endl;
			cout << endl;

			cout<<"In-order: ";
			PrintInOrder(Root);

			cout << endl;

			cout << "PosOrder: ";
			PrintPosorder(Root);

			cout << endl;

			cout << "PreOrder: ";
			PrintPreorder(Root);

			system("PAUSE");
			break;
		case 0:
			verificador = false;
			break;
		}
	}
}