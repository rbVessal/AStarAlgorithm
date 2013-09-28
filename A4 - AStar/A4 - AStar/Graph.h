#pragma once
#ifndef _GRAPH_
#define _GRAPH_

#include "Node.h"

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

private:
	// Attributes
	Node** grid; // 2D Grid of nodes
};
#endif