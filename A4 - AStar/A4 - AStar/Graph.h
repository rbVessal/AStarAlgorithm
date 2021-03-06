#ifndef _GRAPH_
#define _GRAPH_

#include "Node.cpp" //Need to include cpp file because of compile time with templates
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>

//Functor to be used for sorting the nodes based on lowest f value
//see: http://comsci.liu.edu/~jrodriguez/cs631sp08/c++priorityqueue.html
class CompareNodes
{
public:
	bool operator()(const Node<char>* n1, const Node<char>* n2) const
	{
		// Returns inverse of f so that lower f = higher priority
		int f1 = static_cast<int>(n2->getF() * -1);
		int f2 = static_cast<int>(n1->getF() * -1);

		return f1 < f2;
		
	}
};

template <class GraphTemplateType> 
class Graph
{
public:

	// Big Three / Constructors
	Graph(void);
	Graph(int, int);
	Graph(const Graph<GraphTemplateType>& other);
	const Graph<GraphTemplateType>& operator=(const Graph<GraphTemplateType>& other);
	~Graph(void);

	// Functions
	void initBoard();
	void print();
	vector<Node<char>*> findPath(Node<char>*, Node<char>*); // A* algorithm that takes start and end node
	vector<Node<char>*> findPath(int, int, int, int); // an overload of the function that takes coordinates
	
	

private:
	// Attributes
	Node<char>*** grid; // 2D Grid of node pointers
	int rows;
	int cols;

	float heuristicDistance(const Node<char>*, const Node<char>*); // Distance between two nodes
	vector<Node<char>*> getAllNeighbors(const Node<char>*);//Get adjacent nodes to the current node
	bool isInOpenList(vector<Node<char>*>, const Node<char>*);
	bool isInClosedList(vector<Node<char>*>, const Node<char>*);
	void sortList(vector<Node<char>*>&openList);
	void writeToFile();
};
#endif