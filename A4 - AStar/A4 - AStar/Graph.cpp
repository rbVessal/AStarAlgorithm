#include "stdafx.h"
#include "Graph.h"

// Overload < and > operators for Node comparison (used in priority queue)
bool operator< (const Node& n1, const Node& n2)
{
	// Returns inverse of f so that lower f = higher priority
	int f1 = static_cast<int>(n1.getF() * -1);
	int f2 = static_cast<int>(n2.getF() * -1);
	return f1 < f2;
}

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

// An overload of the findPath function that takes coordinates
//vector<Node*> Graph::findPath(int x1, int y1, int x2, int y2)
Node* Graph::findPath(int x1, int y1, int x2, int y2)
{
	Node* startNode = grid[x1][y1];
	Node* endNode = grid[x2][y2];

	//vector<Node*> path = findPath(startNode, endNode);
	Node* goal = findPath(startNode, endNode);

	// Highlight the path
	/*for(int i=0; i < path.size(); i++)
	{
		path[i]->displayData = 'X';
	}*/

	
	Node* current = goal;
	while(current->getX() != x1 && current->getY() != y1)
	{
		current->displayData = 'X';
		current = current->parent;
	}
	//current->displayData = 'X';

	return goal;
}

// A* ALGORITHM
// Pseudo-code reference: http://heyes-jones.com/pseudocode.php
//vector<Node*> Graph::findPath(Node* start, Node* destination)
Node* Graph::findPath(Node* start, Node* destination)
{
	priority_queue<Node*> open_list; // Nodes not yet checked
	vector<Node*> closed_list; // Nodes previously checked

	open_list.push(start); // Put the starting node on the open list
	
	start->g = 0;
	start->h = heuristicDistance(start, destination);

	// while open list is not empty
	while(open_list.size() > 0)
	{
		// Get the node off the open list with the lowest f and make it the current node
		Node* current = open_list.top(); // Top is lowest f
		open_list.pop();

		// If current is same as goal, break from loop
		if(current == destination)
			return current;
			//break;

		// generate each successor that can come after current
		vector<Node*> successors = getAllNeighbors(current);
		
		// for each successor of current node, do the following
		while(successors.size() > 0)
		{
			Node* successor = successors.back();
			successors.pop_back();

			// set the cost (g) of successor to be the cost of current plus the cost to get to successor from current
			successor->g = current->g + 1; // cost from current to successor is always 1

			// find successor in open_list
			if(isInPriorityQueue(open_list, successor))
			{
				// if successor is on open list but the existing one is better or equal f, discard this successor and continue
				if(current->getF() < successor->getF())
				{
					continue;
				}
			}
			
			// if successor is on the CLOSED list but the existing one is as good or better then discard this successor and continue
			if(isInVector(closed_list, successor))
			{
				if(current->getF() < successor->getF())
				{
					continue;
				}
			}

			// remove successor from both open and closed
			removeFromPQ(&open_list, successor);
			removeFromVector(&closed_list, successor);

			// set parent of successor to current
			successor->parent = current;

			// set h to be the estimated distance to goal (using heuristic function)
			successor->h = heuristicDistance(successor, destination);

			// add successor to open list
			open_list.push(successor);
		}

		// add current to closed list
		closed_list.push_back(current);
	}

	//return closed_list; // return the closed list (is this correct?)
	return NULL;
}

float Graph::heuristicDistance(const Node* n1, const Node* n2)
{
	float distX = (n1->getX() - n2->getX()) * (n1->getX() - n2->getX());
	float distY = (n1->getY() - n2->getY()) * (n1->getY() - n2->getY());

	return sqrt(distX + distY);
}

// Returns true if the node is in the priority queue
bool Graph::isInPriorityQueue(priority_queue<Node*> pqueue, const Node* n)
{
	while(pqueue.size() > 0)
	{
		Node* current = pqueue.top();
		pqueue.pop();

		if(current == n)
			return true; 
	}

	return false;
}

bool Graph::isInVector(vector<Node*> vect, const Node* n)
{
	for(int i=0; i < vect.size(); i++)
	{
		Node* current = vect[i];

		if(current == n)
			return true;
	}
	return false;
}


void Graph::removeFromPQ(priority_queue<Node*>* pqueue, const Node* n)
{
	// Use a second pq to store popped items
	priority_queue<Node*> temporary;
	
	while(pqueue->size() > 0)
	{
		Node* current = pqueue->top();
		pqueue->pop();

		// Add to temporary list if it's not the one we're removing
		if(current != n)
		{
			temporary.push(current);
		}
	}

	// Fill the original back up
	while(temporary.size() > 0)
	{
		Node* current = temporary.top();
		temporary.pop();

		pqueue->push(current);
	}
}

void Graph::removeFromVector(vector<Node*>* vect, const Node* n)
{
	// Use a second vector to store popped items
	vector<Node*> temporary;
	
	while(vect->size() > 0)
	{
		Node* current = vect->back();
		vect->pop_back();

		// Add to temporary list if it's not the one we're removing
		if(current != n)
		{
			temporary.push_back(current);
		}
	}

	// Fill the original back up
	while(temporary.size() > 0)
	{
		Node* current = temporary.back();
		temporary.pop_back();

		vect->push_back(current);
	}
}

// Returns all in-bounds neighbors of a node
// TODO: define which neighbors are non-traversable (e.g., walls)
vector<Node*> Graph::getAllNeighbors(const Node* n)
{
	vector<Node*> neighbors;

	// x - 1
	if(n->getX() - 1 >= 0)
	{
		neighbors.push_back(grid[n->getX() - 1][n->getY()]);

		// x - 1, y - 1
		if(n->getY() - 1 >= 0)
			neighbors.push_back(grid[n->getX() - 1][n->getY() - 1]);

		// x - 1, y + 1
		if(n->getY() + 1 < cols)
			neighbors.push_back(grid[n->getX() - 1][n->getY() + 1]);
	}

	// x + 1
	if(n->getX() + 1 < rows)
	{
		neighbors.push_back(grid[n->getX() + 1][n->getY()]);

		// x + 1, y - 1
		if(n->getY() - 1 >= 0)
			neighbors.push_back(grid[n->getX() + 1][n->getY() - 1]);

		// x + 1, y + 1
		if(n->getY() + 1 < cols)
			neighbors.push_back(grid[n->getX() + 1][n->getY() + 1]);
	}

	// y - 1
	if(n->getY() - 1 >= 0)
		neighbors.push_back(grid[n->getX()][n->getY() - 1]);

	// y + 1
	if(n->getY() + 1 < cols)
		neighbors.push_back(grid[n->getX()][n->getY() + 1]);

	return neighbors;
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
