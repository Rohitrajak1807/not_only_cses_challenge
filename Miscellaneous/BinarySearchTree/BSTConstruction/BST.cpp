//
// Created by ronin on 8/19/21.
//

#include "BST.h"

template<typename T>
Node<T>::Node(T &val) : value(val), left(nullptr), right(nullptr) {}

template<typename T>
BST<T>::BST(): root(nullptr) {}

template<typename T>
BST<T>::BST(T val): root(std::make_unique<Node<T>>(val)) {}

template<typename T>
BST<T>::BST(std::vector<T> &arr) {
	for (auto &i : arr) BST::insert(i);
}

template<typename T>
void BST<T>::insert(T &value) {
	_insert(value, root);
}

template<typename T>
void BST<T>::insert(T &&value) {
	_insert(value, root);
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
	return _del(target, root);
}

template<typename T>
void BST<T>::_insert(T &value, std::unique_ptr<Node<T>> &current_node) {
	if (!current_node)
		current_node = std::make_unique<Node<T>>(value);
	else if (value <= current_node->value)
		_insert(value, current_node->left);
	else
		_insert(value, current_node->right);
}

template<typename T>
bool BST<T>::_del(const T &target, std::unique_ptr<Node<T>> &current_node) {
	if (!current_node) return false;
	else if (current_node->value == target) {
		_delete_node(current_node);
		return true;
	} else if (target <= current_node->value)
		_del(target, current_node->left);
	else
		_del(target, current_node->right);
}

template<typename T>
void BST<T>::_delete_node(std::unique_ptr<Node<T>> &current_node) {
	if (!current_node->left)
		current_node = std::move(current_node->right);
	else if (!current_node->right)
		current_node = std::move(current_node->left);
	else {
		current_node->value = _get_successor_value(current_node->right);
	}
}

template<typename T>
T BST<T>::_get_successor_value(std::unique_ptr<Node<T>> &current_node) {
	if (!current_node->left) {
		T val = current_node->value;
		current_node = std::move(current_node->right);
		return val;
	}
	return _get_successor_value(current_node->left);
}
