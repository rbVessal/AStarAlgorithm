#pragma once
#ifndef _GRAPH_
#define _GRAPH_

#include "Node.h"
#include <vector>
#include <queue>

class Graph
{
public:
	// Big Three / Constructors
	Graph(void);
	Graph(int, int);
	Graph(const Graph&);
	const Graph& operator=(const Graph&);
	~Graph(void);

	// Functions
	void initBoard();
	void print();
	Node* findPath(Node*, Node*); // A* algorithm that takes start and end node
	Node* findPath(int, int, int, int); // an overload of the function that takes coordinates
	float heuristicDistance(const Node*, const Node*); // Distance between two nodes
	vector<Node*> getAllNeighbors(const Node*);
	bool isInPriorityQueue(priority_queue<Node*>, const Node*);
	bool isInVector(vector<Node*>, const Node*);
	void removeFromPQ(priority_queue<Node*>*, const Node*);
	void removeFromVector(vector<Node*>*, const Node*);

private:
	// Attributes
	Node*** grid; // 2D Grid of node pointers
	int rows;
	int cols;
};
#endif