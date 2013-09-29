#pragma once
#ifndef _GRAPH_
#define _GRAPH_

#include "Node.h"
#include <vector>

class Graph
{
public:
	// Big Three / Constructors
	Graph(void);
	Graph(const Graph&);
	const Graph& operator=(const Graph&);
	~Graph(void);

	// Functions
	void print();
	vector<Node> findPath(Node*, Node*); // A* algorithm that takes start and end node
								// Returns the next node to take

private:
	// Attributes
	Node*** grid; // 2D Grid of node pointers
	int rows;
	int cols;
};
#endif