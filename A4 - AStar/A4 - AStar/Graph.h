#ifndef _GRAPH_
#define _GRAPH_

#include "Node.cpp" //Need to include cpp file because of compile time with templates
#include <vector>

template <class GraphTemplateType> 
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
	vector<Node<char>*> findPath(Node<char>*, Node<char>*); // A* algorithm that takes start and end node
															// Returns the next node to take

private:
	// Attributes
	Node<char>*** grid; // 2D Grid of node pointers
	int rows;
	int cols;
};
#endif