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
	Node(int row, int col, char displayData);
	Node(const Node<TemplateDataType>& other);
	const Node<TemplateDataType>& operator=(const Node<TemplateDataType>& other);
	~Node(void);

	void print();

	// Setters and getters
	int getX() const;
	int getY() const;
	float getF() const;
	char getDisplayData() const;

	void setDisplayData(char displayData);

	// Public attributes with temp values for algorithm
	float g;
	float h;

private:
	// Attributes
	char displayData;
	int x;
	int y;
	
};

//Explicit specialization of Node with int
//see: http://msdn.microsoft.com/en-us/library/7y5ca42y.aspx
template<> class Node<int>
{
public:
	// Big Three / Constructors
	Node(void);
	Node(int row, int col, char displayData);
	Node(const Node<int>& other);
	const Node<int>& operator=(const Node<int>& other);
	~Node(void);

	void print();

	// Setters and getters
	int getX() const;
	int getY() const;
	float getF() const;
	char getDisplayData() const;

	void setDisplayData(char displayData);

	// Public attributes with temp values for algorithm
	float g;
	float h;

private:
	// Attributes
	char displayData;
	int x;
	int y;

};
#endif