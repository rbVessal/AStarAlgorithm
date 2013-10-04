#include "stdafx.h"
#include "Graph.h"

Graph::Graph(void)
{
	// Assume that if a graph exists, it must be at least 1x1
	rows = 1;
	cols = 1;
	initBoard();
}

Graph::Graph(int r, int c)
{
	rows = r;
	cols = c;
	initBoard();
}

void Graph::initBoard()
{
	// Allocate a 2D array
	grid = new Node**[rows];

	for(int i=0; i<rows; i++)
	{
		grid[i] = new Node*[cols];

		for(int j=0; j<cols; j++)
		{
			grid[i][j] = new Node(i, j);
		}
	}
}

// A* ALGORITHM
// Pseudo-code reference: http://heyes-jones.com/pseudocode.php
vector<Node*> Graph::findPath(Node* start, Node* destination)
{
	vector<Node*> path_list; // store all of the nodes in the path

	vector<Node*> open_list; // Nodes not yet checked
	vector<Node*> closed_list; // Nodes previously checked

	open_list.push_back(start); // Put the starting node on the open list

	// while open list is not empty
	//{
		// Get the node off the open list with the lowest f and make it the current node
		// If current is same as goal, end loop
		// generate each successor that can come after current
		// for each successor of current node
			// set the cost (g) of successor to be the cost of current plus the cost to get to successor from current
			// find successor in open_list
			// if successor is there but the existing one is better or equal f, discard this successor and continue
			// remove successor from both open and closed
			// set parent of successor to current
			// set h to be the estimated distasnce to goal (using heuristic function)
			// add successor to open list
	
		// current to closed list
	//}

	return path_list; // return a vector of all the nodes it takes to get to destination
}

void Graph::print()
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			grid[i][j]->print();
		}
		cout << endl;
	}
}

Graph::~Graph(void)
{
	// Deallocate 2D array
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			delete grid[i][j];
		}

		delete grid[i];
	}

	delete grid;
}
