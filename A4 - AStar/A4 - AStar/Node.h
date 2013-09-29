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
	Node(void){ displayData = ' '; }
	Node(int row, int col){ displayData = ' '; x = row; y = col; }
	Node(const Node&){}
	const Node& operator=(const Node&){}
	~Node(void){}

private:
	// Attributes
	char displayData;
	int x;
	int y;
	//T* object;
};
#endif