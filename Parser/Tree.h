#pragma once

namespace st
{
	typedef unsigned long id_t;

	static id_t current_id = 0;

	template<class T>
	class Tree_node_t
	{
	public:
		Tree_node_t();
		Tree_node_t(const T&);
		Tree_node_t(T&&);

		Tree_node_t<T>* parent;
		Tree_node_t<T>* first_child, * last_child;
		Tree_node_t<T>* prev_sibling, * next_sibling;

		id_t id_;
		id_t parrent_id_;

		T data;
	};

	template <class T, class tree_node_allocator = std::allocator<Tree_node_t<T>> >
	class Tree_t
	{
	protected:
		typedef tree_node_<T> tree_node;
	public:

	};

}