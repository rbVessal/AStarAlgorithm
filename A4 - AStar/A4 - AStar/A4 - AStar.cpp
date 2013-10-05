// A4 - AStar.cpp : Defines the entry point for the console application.
// Rebecca Vessal and Jennifer Stanton

#include "stdafx.h"
#include <stdlib.h>
#include "Graph.cpp"

// Overload < and > operators for Node comparison (used in priority queue)
/*bool operator< (const Node<char>& n1, const Node<char>& n2)
{
	// Returns inverse of f so that lower f = higher priority
	int f1 = static_cast<int>(n1.getF() * -1);
	int f2 = static_cast<int>(n2.getF() * -1);
	return f1 < f2;
}*/

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "A* Demonstration" << endl;

	Graph<char>* graph = new Graph<char>(9, 9);

	// Do stuff here
	graph->print();
	//graph->findPath(0, 0, 1, 0);
	//cout << endl;
	//graph->print();

	delete graph;

	system("pause");
	return 0;
}
