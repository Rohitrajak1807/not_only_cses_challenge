//
// Created on 8/19/21.
//

#ifndef BSTCONSTRUCTION_BST_HPP
#define BSTCONSTRUCTION_BST_HPP

#include <memory>
#include <vector>

template<typename T>
struct Node {
	T value;
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;

	explicit Node(T &val);

	explicit Node(T &&val);
};

template<typename T>
class BST {
public:
	BST();

	explicit BST(T val);

	explicit BST(std::vector<T> &arr);

	template<typename Input_It>
	BST(Input_It first, Input_It last);

	void insert(T &&value);

	void insert(T &value);

	bool contains(const T &target);

	bool remove_val(const T &target);

	const T &min() const;

	const T &max() const;

	const std::unique_ptr<Node<T>> &get_root_c() const;

	std::unique_ptr<Node<T>> &get_root();

private:
	std::unique_ptr<Node<T>> root;

	void insert(T &value, std::unique_ptr<Node<T>> &current_node);

	bool del(const T &target, std::unique_ptr<Node<T>> &current_node);

	void delete_node(std::unique_ptr<Node<T>> &current_node);

	T get_successor_value(std::unique_ptr<Node<T>> &current_node);

};


template<typename T>
Node<T>::Node(T &val) : value(val) {}

template<typename T>
Node<T>::Node(T &&val) : value(val) {}

template<typename T>
BST<T>::BST(): root(nullptr) {}

template<typename T>
BST<T>::BST(T val): root(std::make_unique<Node<T>>(val)) {}

template<typename T>
BST<T>::BST(std::vector<T> &arr) {
	for (auto &i: arr) BST::insert(i);
}

template<typename T>
void BST<T>::insert(T &value) {
	insert(value, root);
}

template<typename T>
void BST<T>::insert(T &&value) {
	insert(value, root);
}

template<typename T>
bool BST<T>::contains(const T &target) {
	bool does_contain = false;
	Node<T> *current = root.get();
	while (current != nullptr) {
		if (target == current->value) {
			does_contain = true;
			break;
		} else if (target <= current->value) current = current->left.get();
		else current = current->right.get();
	}
	return does_contain;
}

template<typename T>
bool BST<T>::remove_val(const T &target) {
	return del(target, root);
}

template<typename T>
void BST<T>::insert(T &value, std::unique_ptr<Node<T>> &current_node) {
	if (!current_node)
		current_node = std::make_unique<Node<T>>(value);
	else if (value <= current_node->value)
		insert(value, current_node->left);
	else
		insert(value, current_node->right);
}

template<typename T>
bool BST<T>::del(const T &target, std::unique_ptr<Node<T>> &current_node) {
	if (!current_node) return false;
	else if (current_node->value == target) {
		delete_node(current_node);
		return true;
	} else if (target <= current_node->value)
		del(target, current_node->left);
	else
		del(target, current_node->right);
}

template<typename T>
void BST<T>::delete_node(std::unique_ptr<Node<T>> &current_node) {
	if (!current_node->left)
		current_node = std::move(current_node->right);
	else if (!current_node->right)
		current_node = std::move(current_node->left);
	else {
		current_node->value = get_successor_value(current_node->right);
	}
}

template<typename T>
T BST<T>::get_successor_value(std::unique_ptr<Node<T>> &current_node) {
	if (!current_node->left) {
		T val = current_node->value;
		current_node = std::move(current_node->right);
		return val;
	}
	return get_successor_value(current_node->left);
}

template<typename T>
const T &BST<T>::min() const {
	auto current = root.get();
	while (current->left)
		current = current->left.get();
	return current->value;
}

template<typename T>
const T &BST<T>::max() const {
	auto current = root.get();
	while (current->right)
		current = current->right.get();
	return current->value;
}

template<typename T>
template<typename Input_It>
BST<T>::BST(Input_It first, Input_It last) {
	while (first != last)
		insert(*first++);
}

template<typename T>
const std::unique_ptr<Node<T>> &BST<T>::get_root_c() const {
	return root;
}

template<typename T>
std::unique_ptr<Node<T>> &BST<T>::get_root() {
	return root;
}

#endif //BSTCONSTRUCTION_BST_HPP
