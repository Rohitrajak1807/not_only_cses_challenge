#include <iostream>
#include "BST.hpp"
#include <vector>

//template<typename T>
//struct Node {
//	T value;
//	std::unique_ptr<Node> left;
//	std::unique_ptr<Node> right;
//
//	explicit Node(T &val);
//};
//
//template<typename T>
//class BST {
//public:
//	BST();
//
//	explicit BST(T val);
//
//	explicit BST(std::vector<T> &arr);
//
//	void insert(T &value);
//
//	void insert(T &&value);
//
//	bool contains(const T &target);
//
//	bool remove_val(const T &target);
//
//private:
//	std::unique_ptr<Node<T>> root;
//
//	void insert(T &value, std::unique_ptr<Node<T>> &current_node);
//
//	bool del(const T &target, std::unique_ptr<Node<T>> &current_node);
//
//	void delete_node(std::unique_ptr<Node<T>> &current_node);
//
//	T get_successor_value(std::unique_ptr<Node<T>> &current_node);
//};


//template<typename T>
//Node<T>::Node(T &val) : value(val), left(nullptr), right(nullptr) {}
//
//template<typename T>
//BST<T>::BST(): root(nullptr) {}
//
//template<typename T>
//BST<T>::BST(T val): root(std::make_unique<Node<T>>(val)) {}
//
//template<typename T>
//BST<T>::BST(std::vector<T> &arr) {
//	for (auto &i : arr) BST::insert(i);
//}
//
//template<typename T>
//void BST<T>::insert(T &value) {
//	insert(value, root);
//}
//
//template<typename T>
//void BST<T>::insert(T &&value) {
//	insert(value, root);
//}
//
//template<typename T>
//bool BST<T>::contains(const T &target) {
//	bool does_contain = false;
//	Node<T> *current = root.get();
//	while (current != nullptr) {
//		if (target == current->value) {
//			does_contain = true;
//			break;
//		} else if (target <= current->value) current = current->left.get();
//		else current = current->right.get();
//	}
//	return does_contain;
//}
//
//template<typename T>
//bool BST<T>::remove_val(const T &target) {
//	return del(target, root);
//}
//
//template<typename T>
//void BST<T>::insert(T &value, std::unique_ptr<Node<T>> &current_node) {
//	if (!current_node)
//		current_node = std::make_unique<Node<T>>(value);
//	else if (value <= current_node->value)
//		insert(value, current_node->left);
//	else
//		insert(value, current_node->right);
//}
//
//template<typename T>
//bool BST<T>::del(const T &target, std::unique_ptr<Node<T>> &current_node) {
//	if (!current_node) return false;
//	else if (current_node->value == target) {
//		delete_node(current_node);
//		return true;
//	} else if (target <= current_node->value)
//		del(target, current_node->left);
//	else
//		del(target, current_node->right);
//}
//
//template<typename T>
//void BST<T>::delete_node(std::unique_ptr<Node<T>> &current_node) {
//	if (!current_node->left)
//		current_node = std::move(current_node->right);
//	else if (!current_node->right)
//		current_node = std::move(current_node->left);
//	else {
//		current_node->value = get_successor_value(current_node->right);
//	}
//}
//
//template<typename T>
//T BST<T>::get_successor_value(std::unique_ptr<Node<T>> &current_node) {
//	if (!current_node->left) {
//		T val = current_node->value;
//		current_node = std::move(current_node->right);
//		return val;
//	}
//	return get_successor_value(current_node->left);
//}



int main() {
	std::boolalpha(std::cout);
	std::vector<int32_t> v{23, 2, 11, 2, 5, -5, 6, 34, 8, 9, 42, 0};

	BST<int32_t> bst{v};
	BST<int32_t> bst2(50);
	bst2.insert(25);
	bst2.insert(75);
	bst2.insert(24);
	bst2.insert(30);
	bst2.insert(80);
	bst2.insert(100);
	BST<int32_t> bst3{};
	bst3.insert(100);
	bst3.insert(40);
	bst3.insert(400);
	bst3.insert(10);

	std::vector<int32_t> v2{23, 2, 11, 2, 5, 34, 8};
	BST<int32_t> bst4(v2.begin(), v2.end());

	std::cout << bst.contains(2) << '\n'
	          << bst.contains(30) << '\n'
	          << bst2.contains(100) << '\n'
	          << bst2.contains(50) << '\n'
	          << bst3.contains(44) << '\n';

	std::cout << (bst.remove_val(11) ? "removed" : "not found") << '\n';
	std::cout << (bst.remove_val(11) ? "removed" : "not found") << '\n';
	std::cout << bst.contains(11) << '\n';
	std::cout << bst.min() << '\n';
	std::cout << bst2.min() << '\n';
	std::cout << bst3.min() << '\n';
	std::cout << bst.max() << '\n';
	std::cout << bst2.max() << '\n';
	std::cout << bst3.max() << '\n';
	std::cout << bst4.min() << ", " << bst4.max() << '\n';
	return 0;
}
