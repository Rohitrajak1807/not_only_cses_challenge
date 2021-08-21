#include <iostream>
#include <BST.hpp>
#include <vector>


// Write a function that takes in a potentially invalid Binary Search Tree (BST) and returns a boolean representing
// whether the BST is valid.

// Each BST node has an integer value, a left child node, and a right child node.
// A node is said to be a valid BST node if and only if it satisfies the BST property:
// its value is strictly greater than the values of every node to its left;
// its value is less than or equal to the values of every node to its right;
// and its children nodes are either valid BST nodes themselves or null.


template<typename T>
bool validate_bst(const std::unique_ptr<Node<T>> &root);

template<typename T>
bool validate(const std::unique_ptr<Node<T>> &root, int32_t min = -INT32_MAX, int32_t max = INT32_MAX);

int main() {
	std::boolalpha(std::cout);
	std::vector<int32_t> v{100, 67, 54, 7, 0, 55, 99};
	BST<int32_t> bst{v};
	BST<int32_t> bst2(10);
	bst2.get_root()->left = std::make_unique<Node<int32_t>>(30);
	bst2.get_root()->right = std::make_unique<Node<int32_t>>(3);
	const std::unique_ptr<Node<int32_t>> &root = bst.get_root();
	std::cout << validate_bst(root) << '\n';
	std::cout << validate_bst(bst2.get_root()) << '\n';
	return 0;
}

template<typename T>
bool validate_bst(const std::unique_ptr<Node<T>> &root) {
	return validate(root, -INT32_MAX, INT32_MAX);
}


template<typename T>
bool validate(const std::unique_ptr<Node<T>> &root, int32_t min, int32_t max) {
	bool is_valid = true;
	if (root == nullptr)
		return is_valid;
	if (root->value < min or root->value >= max)
		is_valid = false;

	return is_valid and validate(root->left, min, root->value) and validate(root->right, root->value, max);
}