// A4 - AStar.cpp : Defines the entry point for the console application.
// Rebecca Vessal and Jennifer Stanton

#include "stdafx.h"
#include <stdlib.h>
#include <string>

#include "Graph.cpp"

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "A* Demonstration" << endl;
	cout << "All valid input is 0-8" << endl;

	Graph<char>* graph = new Graph<char>(9, 9);

	// Do stuff here
	graph->print();

	int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
	string response;

	while(x1 <0 || x1 > 8)
	{
		cout << "Enter start x:" << endl;
		getline(cin, response);
		x1 = atoi(response.c_str());
	}

	while(y1 <0 || y1 > 8)
	{
		cout << "Enter start y:" << endl;
		getline(cin, response);
		y1 = atoi(response.c_str());
	}

	while(x2 <0 || x2 > 8)
	{
		cout << "Enter end x:" << endl;
		getline(cin, response);
		x2 = atoi(response.c_str());
	}

	while(y2 <0 || y2 > 8)
	{
		cout << "Enter end y:" << endl;
		getline(cin, response);
		y2 = atoi(response.c_str());
	}

	graph->findPath(x1, y1, x2, y2);
	cout << endl;
	graph->print();

	delete graph;

	system("pause");
	return 0;
}
