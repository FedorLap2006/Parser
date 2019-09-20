#include <iostream>
#include <string>

#include "Tree.h"

template<class T>
st::Tree_node_t<T>::Tree_node_t()
	: parent(0), first_child(0), last_child(0), prev_sibling(0), next_sibling(0), 
{
}

template<class T>
st::Tree_node_t<T>::Tree_node_t(const T& val)
	: parent(0), first_child(0), last_child(0), prev_sibling(0), next_sibling(0), data(val)
{
}

template<class T>
st::Tree_node_t<T>::Tree_node_t(T&& val)
	: parent(0), first_child(0), last_child(0), prev_sibling(0), next_sibling(0), data(val)
{
}