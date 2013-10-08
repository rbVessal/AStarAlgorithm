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
	parent = NULL;
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