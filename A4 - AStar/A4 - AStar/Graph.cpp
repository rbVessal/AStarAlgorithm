#include "stdafx.h"
#include "Graph.h"

#define EDGE_COST 1

//Default constructor
template <class GraphTemplateType>
Graph<GraphTemplateType>::Graph(void)
{
	// Assume that if a graph exists, it must be at least 1x1
	rows = 1;
	cols = 1;
	initBoard();
}

//Parameterized constructor
template <class GraphTemplateType>
Graph<GraphTemplateType>::Graph(int r, int c)
{
	rows = r;
	cols = c;
	initBoard();
}

//Copy constructor
template <class GraphTemplateType>
Graph<GraphTemplateType>::Graph(const Graph<GraphTemplateType>& other)
{
	rows = other.rows;
	cols = other.cols;
}

//Copy assignment constructor
template <class GraphTemplateType>
const Graph<GraphTemplateType>& Graph<GraphTemplateType>::operator=(const Graph<GraphTemplateType>& other)
{
	if(this != &other)
	{
		rows = other.rows;
		cols = other.cols;
	}
	return *this;
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
			grid[i][j] = new Node<char>(i, j, '.');
		}
	}
}

// An overload of the findPath function that takes coordinates
template <class GraphTemplateType>
vector<Node<char>*> Graph<GraphTemplateType>::findPath(int x1, int y1, int x2, int y2)
{
	Node<char>* startNode = grid[x1][y1];
	Node<char>* endNode = grid[x2][y2];

	vector<Node<char>*> path = findPath(startNode, endNode);
	//Node<char>* goal = findPath(startNode, endNode);

	// Highlight the path
	for(size_t i=0; i < path.size(); i++)
	{
		//Starting point
		if(i == 0)
		{
			path[i]->setDisplayData('S');
		}
		//Goal
		else if(i == path.size() - 1)
		{
			path[i]->setDisplayData('G');
		}
		//Path from starting point to goal
		else
		{
			path[i]->setDisplayData('X');
		}
		
	}

	//return goal;
	return path;
}




// A* ALGORITHM
// Pseudo-code reference: http://heyes-jones.com/pseudocode.php
// see also: http://www.policyalmanac.org/games/aStarTutorial.htm
template <class GraphTemplateType>
//Node<char>* Graph<GraphTemplateType>::findPath(Node<char>* start, Node<char>* destination)
vector<Node<char>*> Graph<GraphTemplateType>::findPath(Node<char>* start, Node<char>* destination)
{
	
	vector<Node<char>*> open_list; // Potential adjacent nodes that can become part of the new path between start node and end node
	//vector<Node<char>*>open_vector_list;
	vector<Node<char>*> closed_list; // Nodes that are part of the start and end node including the end node

	//Store the start node into the open vector list
	start->g = 0;
	start->h = heuristicDistance(start, destination);
	open_list.push_back(start);

	// while open list is not empty
	while(open_list.size() > 0)
	{
		sortList(open_list);
		// Get the node off the open list with the lowest f and make it the current node
		Node<char>* current = open_list.back(); // Top is lowest f
		//cout << "current node: " << current << endl;
		//cout << " current size "<<open_list.size() <<endl;
		//cout << " " << current->x << " "  << current->y <<endl;
		open_list.pop_back();

		// add current to closed list
		closed_list.push_back(current);

		// If current is same as goal, break from loop
		if(current == destination)
		{
			//return current;
			break;
		}

		// generate each successor that can come after current
		vector<Node<char>*> successors = getAllNeighbors(current);
		
		// for each successor of current node, do the following
		while(successors.size() > 0)
		{
			//Get each successor from the back of the vector list of neighbors to the current node
			Node<char>* successor = successors.back();
			successors.pop_back();

			// if successor is on the CLOSED list, then ignore it
			if(isInVector(closed_list, successor))
			{
				continue;
			}
			// Check to see if the successor is not in the open list
			else if(!(isInPriorityQueue(open_list, successor)))
			{
				// add successor to open list
				//open_vector_list.push_back(successor);
				open_list.push_back(successor);
				//open_vector_list.pop_back();
				//Calculate the F, G, and H costs of this successor
				// set the cost (g) of successor to be the cost of current plus the cost to get to successor from current
				successor->g = current->g + EDGE_COST; // cost from current to successor is always 1
				// set h to be the estimated distance to goal (using heuristic function)
				successor->h = heuristicDistance(successor, destination);
			}
			//If the successor is in the open list
			else
			{
				//Check to see if G cost of the successor node is better
				if(successor->g < current->g)
				{
					//If the G cost is lower, then change the parent of the successor to the current node
					//successor->parent = current;
					//Recalculate the G and F scores of the successor
					successor->g = current->g + EDGE_COST;
					//Resort the open list by F score - optional
					sortList(open_list);
				}

			}
			
		}

		
	}
	
	return closed_list; // return the closed list
}

//Create a sorting function based on the lowest f using bubble sort
//see: http://www.cprogramming.com/tutorial/computersciencetheory/sorting1.html
template <class GraphTemplateType>
void Graph<GraphTemplateType>::sortList(vector<Node<char>*>&openList)
{
	for(int i = 0; i < openList.size()-1; i++)
	{
		
		for(int j = 0; j < openList.size()-1; j++)
		{
			Node<char>* temp = openList[j];
			Node<char>* temp2 = openList[j+1];
			if(temp->getF() < temp2->getF())
			{
				openList[j] = temp2;
				openList[j+1] = temp;
			}
			
		}
	}
}

// Use the distance formula as the heuristic
template <class GraphTemplateType>
float Graph<GraphTemplateType>::heuristicDistance(const Node<char>* n1, const Node<char>* n2)
{
	float distX = (n1->getX() - n2->getX()) * (n1->getX() - n2->getX());
	float distY = (n1->getY() - n2->getY()) * (n1->getY() - n2->getY());

	return sqrt(distX + distY);
}

// Returns true if the node is in the priority queue
template <class GraphTemplateType>
bool Graph<GraphTemplateType>::isInPriorityQueue(vector<Node<char>*> pqueue, const Node<char>* n)
{
	while(pqueue.size() > 0)
	{
		Node<char>* current = pqueue.front();
		pqueue.pop_back();

		if(current == n)
		{
			return true;
		}
	}

	return false;
}

template <class GraphTemplateType>
bool Graph<GraphTemplateType>::isInVector(vector<Node<char>*> vect, const Node<char>* n)
{
	for(size_t i=0; i < vect.size(); i++)
	{
		Node<char>* current = vect[i];

		if(current == n)
		{
			return true;
		}
	}
	return false;
}

// Returns all in-bounds neighbors of a node
// TODO: define which neighbors are non-traversable (e.g., walls)
template <class GraphTemplateType>
vector<Node<char>*> Graph<GraphTemplateType>::getAllNeighbors(const Node<char>* n)
{
	vector<Node<char>*> neighbors;

	// x - 1
	if(n->getX() - 1 >= 0)
	{
		neighbors.push_back(grid[n->getX() - 1][n->getY()]);

		// x - 1, y - 1
		if(n->getY() - 1 >= 0)
		{
			neighbors.push_back(grid[n->getX() - 1][n->getY() - 1]);
		}

		// x - 1, y + 1
		if(n->getY() + 1 < cols)
		{
			neighbors.push_back(grid[n->getX() - 1][n->getY() + 1]);
		}
	}

	// x + 1
	if(n->getX() + 1 < rows)
	{
		neighbors.push_back(grid[n->getX() + 1][n->getY()]);

		// x + 1, y - 1
		if(n->getY() - 1 >= 0)
		{
			neighbors.push_back(grid[n->getX() + 1][n->getY() - 1]);
		}

		// x + 1, y + 1
		if(n->getY() + 1 < cols)
		{
			neighbors.push_back(grid[n->getX() + 1][n->getY() + 1]);
		}
	}

	// y - 1
	if(n->getY() - 1 >= 0)
	{
		neighbors.push_back(grid[n->getX()][n->getY() - 1]);
	}

	// y + 1
	if(n->getY() + 1 < cols)
	{
		neighbors.push_back(grid[n->getX()][n->getY() + 1]);
	}

	return neighbors;
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
