#ifndef _NODE_
#define _NODE_

#include <iostream>
using namespace std;

// Templates used for the ambiguity of an "object" on the grid
// The T* object member in this class is that object.
// Everything is in the header file to avoid linker problems with templates.

template <class TemplateDataType>
class Node
{
public:
	// Big Three / Constructors
	Node(void);
	Node(int row, int col, TemplateDataType* displayData);
	Node(const Node&);
	const Node& operator=(const Node&);
	~Node(void);

	void print();

private:
	// Attributes
	TemplateDataType* displayData;
	int x;
	int y;
	
};
#endif