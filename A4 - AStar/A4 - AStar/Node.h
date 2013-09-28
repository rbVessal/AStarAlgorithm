#pragma once
class Node
{
public:
	// Big Three / Constructors
	Node(void);
	Node(const Node&);
	const Node& operator=(const Node&);
	~Node(void);

private:
	// Attributes
	char displayData;
};

