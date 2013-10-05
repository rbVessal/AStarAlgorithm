#ifndef _GRAPH_
#define _GRAPH_

#include "Node.cpp" //Need to include cpp file because of compile time with templates
#include <vector>
#include <queue>

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
	//Node<char>* findPath(Node<char>*, Node<char>*); // A* algorithm that takes start and end node
	//Node<char>* findPath(int, int, int, int); // an overload of the function that takes coordinates
	vector<Node<char>*> findPath(Node<char>*, Node<char>*); // A* algorithm that takes start and end node
	vector<Node<char>*> findPath(int, int, int, int); // an overload of the function that takes coordinates
	float heuristicDistance(const Node<char>*, const Node<char>*); // Distance between two nodes
	vector<Node<char>*> getAllNeighbors(const Node<char>*);
	bool isInPriorityQueue(priority_queue<Node<char>*>, const Node<char>*);
	bool isInVector(vector<Node<char>*>, const Node<char>*);
	void removeFromPQ(priority_queue<Node<char>*>*, const Node<char>*);
	void removeFromVector(vector<Node<char>*>*, const Node<char>*);

private:
	// Attributes
	Node<char>*** grid; // 2D Grid of node pointers
	int rows;
	int cols;
};
#endif