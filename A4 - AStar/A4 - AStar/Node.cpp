#include "stdafx.h"
#include "Node.h"

//Members of template class
// see http://msdn.microsoft.com/en-us/library/5zcs50e1.aspx
//Difference between class and typename in templates
// see http://stackoverflow.com/questions/2023977/c-difference-of-keywords-typename-and-class-in-templates

//Big 3 of C++
template <class TemplateDataType>
Node<TemplateDataType>::Node(void)
{
	displayData = ' ';
}

template <class TemplateDataType>
Node<TemplateDataType>::Node(int row, int col, TemplateDataType* displayData)
{
	this->x = row;
	this->y = col;
	this->displayData = displayData;
}

template <class TemplateDataType>
Node<TemplateDataType>::~Node(void)
{
	x = 0;
	y = 0;
	delete displayData;
}

template <class TemplateDataType>
void Node<TemplateDataType>::print()
{
	cout << *displayData << endl;
}