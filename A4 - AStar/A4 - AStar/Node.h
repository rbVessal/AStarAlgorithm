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
	Node(int row, int col, TemplateDataType displayData);
	Node(const Node<TemplateDataType>& other);
	const Node<TemplateDataType>& operator=(const Node<TemplateDataType>& other);
	~Node(void);


	// Overload < and > operators for Node comparison (used in priority queue)
	//Must make these functions non-member functions since an operator overload
	//member function only takes one parameter
	// see: http://www.velocityreviews.com/forums/t279133-overloading-operator.html
	bool operator< (const Node<TemplateDataType>& n1)
	{
		// Returns inverse of f so that lower f = higher priority
		int f1 = static_cast<int>(this->getF() * -1);
		int f2 = static_cast<int>(n1.getF() * -1);
		return f1 < f2;
	}

	bool operator> (const Node<TemplateDataType>& n1)
	{
		// Returns inverse of f so that lower f = higher priority
		int f1 = static_cast<int>(this->getF() * -1);
		int f2 = static_cast<int>(n1.getF() * -1);
		return f1 > f2;
	}

	void print();

	// Setters and getters
	int getX() const;
	int getY() const;
	float getF() const;

	void setDisplayData(TemplateDataType displayData);

	// Public attributes with temp values for algorithm
	float g;
	float h;
	Node* parent;

private:
	// Attributes
	TemplateDataType displayData;
	int x;
	int y;
};
#endif