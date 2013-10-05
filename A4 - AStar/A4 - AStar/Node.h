#pragma once
#ifndef _NODE_
#define _NODE_

#include <iostream>
using namespace std;

// Templates used for the ambiguity of an "object" on the grid
// The T* object member in this class is that object.
// Everything is in the header file to avoid linker problems with templates.
//template <typename T>
class Node
{
public:
	// Big Three / Constructors
	Node(void){ displayData = '.'; parent = NULL; }
	Node(int row, int col){ displayData = '.'; x = row; y = col; parent = NULL; }
	Node(const Node&){}
	const Node& operator=(const Node&){}
	~Node(void){}

	void print(){ cout << displayData; }

	// Setters and getters
	int getX() const{ return x; }
	int getY() const{ return y; }
	float getF() const{ return g + h; }

	// Public attributes with temp values for algorithm
	float g;
	float h;
	Node* parent;
	
	char displayData;

private:
	// Attributes
	
	int x;
	int y;
};
#endif