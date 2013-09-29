#include "stdafx.h"
#include "Graph.h"

Graph::Graph(void)
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

vector<Node> Graph::findPath(Node* start, Node* destination)
{
	vector<Node> path_list; // store all of the nodes in the path


	return path_list; // return a vector of all the nodes it takes to get to destination
}

Graph::~Graph(void)
{
	// Deallocate 2D array
}
