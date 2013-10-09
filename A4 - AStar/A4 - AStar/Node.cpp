#include "stdafx.h"
#include "Node.h"

//Members of template class
// see http://msdn.microsoft.com/en-us/library/5zcs50e1.aspx
//Difference between class and typename in templates
// see http://stackoverflow.com/questions/2023977/c-difference-of-keywords-typename-and-class-in-templates

//Default constructor
template <class TemplateDataType>
Node<TemplateDataType>::Node(void)
{
	displayData = ' ';
}

//Parameterized constructor
template <class TemplateDataType>
Node<TemplateDataType>::Node(int row, int col, TemplateDataType displayData)
{
	x = row;
	y = col;
	this->displayData = displayData;
}

//Copy constructor
template <class TemplateDataType>
Node<TemplateDataType>::Node(const Node<TemplateDataType>& other)
{
	x = other.x;
	y = other.y;
	g = other.g;
	h = other.h;
	displayData = other.displayData;

}

//Copy assignment constructor
template <class TemplateDataType>
const Node<TemplateDataType>& Node<TemplateDataType>::operator=(const Node<TemplateDataType>& other)
{
	if(this != &other)
	{
		x = other.x;
		y = other.y;
		g = other.g;
		h = other.h;
		displayData = other.displayData;
	}
	return *this;
}

//Getters and setters
template <class TemplateDataType>
int Node<TemplateDataType>::getX() const
{
	return x;
}

template <class TemplateDataType>
int Node<TemplateDataType>::getY() const
{
	return y;
}

template <class TemplateDataType>
float Node<TemplateDataType>::getF() const
{
	return g + h;
}

template <class TemplateDataType>
TemplateDataType Node<TemplateDataType>::getDisplayData() const
{
	return displayData;
}

template <class TemplateDataType>
void Node<TemplateDataType>::setDisplayData(TemplateDataType displayData)
{
	this->displayData = displayData;
}

//Destructor
template <class TemplateDataType>
Node<TemplateDataType>::~Node(void)
{
	x = 0;
	y = 0;
}

//Print out the character of the node
template <class TemplateDataType>
void Node<TemplateDataType>::print()
{
	cout << displayData;
}


//Explicit template specialization of int
//as template member functions
//see: http://publib.boulder.ibm.com/infocenter/lnxpcomp/v8v101/index.jsp?topic=%2Fcom.ibm.xlcpp8l.doc%2Flanguage%2Fref%2Fexplicit_specialization.htm
//Default constructor
Node<int>::Node(void)
{
	displayData = ' ';
}

//Parameterized constructor
Node<int>::Node(int row, int col, char displayData)
{
	x = row;
	y = col;
	this->displayData = displayData;
}

//Copy constructor
Node<int>::Node(const Node<int>& other)
{
	x = other.x;
	y = other.y;
	g = other.g;
	h = other.h;
	displayData = other.displayData;

}

//Copy assignment constructor
const Node<int>& Node<int>::operator=(const Node<int>& other)
{
	if(this != &other)
	{
		x = other.x;
		y = other.y;
		g = other.g;
		h = other.h;
		displayData = other.displayData;
	}
	return *this;
}

//Getters and setters
int Node<int>::getX() const
{
	return x;
}

int Node<int>::getY() const
{
	return y;
}

float Node<int>::getF() const
{
	return g + h;
}

char Node<int>::getDisplayData() const
{
	return displayData;
}

void Node<int>::setDisplayData(char displayData)
{
	this->displayData = displayData;
}

//Destructor
Node<int>::~Node(void)
{
	x = 0;
	y = 0;
}

//Print out the character of the node
void Node<int>::print()
{
	cout << displayData;
}