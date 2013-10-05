// A4 - AStar.cpp : Defines the entry point for the console application.
// Rebecca Vessal and Jennifer Stanton

#include "stdafx.h"
#include <stdlib.h>
#include "Graph.cpp"

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
