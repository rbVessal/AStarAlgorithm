#include "stdafx.h"
#include "Graph.h"

template <class GraphTemplateType>
Graph<GraphTemplateType>::Graph(void)
{
	// Assume that if a graph exists, it must be at least 1x1
	rows = 1;
	cols = 1;
	initBoard();
}

template <class GraphTemplateType>
Graph<GraphTemplateType>::Graph(int r, int c)
{
	rows = r;
	cols = c;
	initBoard();
}

template <class GraphTemplateType>
void Graph<GraphTemplateType>::initBoard()
{
	// Allocate a 2D array
	grid = new Node<char>**[rows];

	for(int i=0; i<rows; i++)
	{
		grid[i] = new Node<char>*[cols];

		for(int j=0; j<cols; j++)
		{
			grid[i][j] = new Node<char>(i, j, ".");
		}
	}
}

template <class GraphTemplateType>
//template <typename GraphTemplateType>
vector<Node<char>> Graph<GraphTemplateType>::findPath(Node<char>* start, Node<char>* destination)
{
	vector<Node<char>> path_list; // store all of the nodes in the path


	return path_list; // return a vector of all the nodes it takes to get to destination
}

template <class GraphTemplateType>
void Graph<GraphTemplateType>::print()
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

template <class GraphTemplateType>
Graph<GraphTemplateType>::~Graph(void)
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
