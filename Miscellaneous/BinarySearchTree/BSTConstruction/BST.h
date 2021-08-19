//
// Created by ronin on 8/19/21.
//

#ifndef BSTCONSTRUCTION_BST_H
#define BSTCONSTRUCTION_BST_H
#include <memory>
#include <vector>

template<typename T>
struct Node {
	T value;
	std::unique_ptr <Node> left;
	std::unique_ptr <Node> right;

	explicit Node(T &val);
};

template<typename T>
class BST {
public:
	BST();

	explicit BST(T val);

	explicit BST(std::vector <T> &arr);

	void insert(T &value);

	void insert(T &&value);

	bool contains(const T &target);

	bool remove_val(const T &target);

private:
	std::unique_ptr <Node<T>> root;

	void insert(T &value, std::unique_ptr <Node<T>> &current_node);

	bool del(const T &target, std::unique_ptr <Node<T>> &current_node);

	void delete_node(std::unique_ptr <Node<T>> &current_node);

	T get_successor_value(std::unique_ptr <Node<T>> &current_node);
};

#endif //BSTCONSTRUCTION_BST_H
