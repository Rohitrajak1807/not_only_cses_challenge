#include <iostream>
#include <BST.hpp>
#include <memory>
#include <algorithm>


// Write a function that takes in a Binary Tree and inverts it.
// In other words, the function should swap every left node in the tree for its corresponding right node.
// Each BinaryTree node has an integer value, a left child node and a right child node.
// Children nodes can either be BinaryTree nodes themselves or null.
// Clem would be proud

//  Sample Input:
//  tree  =    1
//  	    /     \
//  	   2       3
//  	 /   \   /   \
//      4     5 6     7
//    /   \
//   8     9
//  Sample Output:
//        1
//     /     \
//    3       2
//  /   \   /   \
// 7     6 5     4
//             /   \
//            9     8

template<typename T>
void invert_tree(BST<T> &tree);

template<typename T>
void invert(Node<T> *curr_node);


template<typename T>
void inorder_view(BST<T> &tree);

template<typename T>
void inorder_view(const std::unique_ptr<Node<T>> &curr_node);

int main() {
	BST<int32_t> bst(1);
	bst.get_root()->left = std::make_unique<Node<int32_t>>(2);
	bst.get_root()->left->left = std::make_unique<Node<int32_t>>(4);
	bst.get_root()->left->left->left = std::make_unique<Node<int32_t>>(8);
	bst.get_root()->left->left->right = std::make_unique<Node<int32_t>>(9);

	bst.get_root()->left->right = std::make_unique<Node<int32_t>>(5);

	bst.get_root()->right = std::make_unique<Node<int32_t>>(3);
	bst.get_root()->right->right = std::make_unique<Node<int32_t>>(7);
	bst.get_root()->right->left = std::make_unique<Node<int32_t>>(6);
	inorder_view(bst);
	invert_tree(bst);
	std::cout << "\n-----------------------------------\n";
	inorder_view(bst);
	return 0;
}

template<typename T>
void invert_tree(BST<T> &tree) {
	Node<T> *root = tree.get_root().get();
	invert(root);
}

template<typename T>
void invert(Node<T> *curr_node) {
	if (curr_node == nullptr)
		return;
	std::swap(curr_node->left, curr_node->right);
	invert(curr_node->left.get());
	invert(curr_node->right.get());
}

template<typename T>
void inorder_view(BST<T> &tree) {
	inorder_view(tree.get_root());
}

template<typename T>
void inorder_view(const std::unique_ptr<Node<T>> &curr_node) {
	if (curr_node == nullptr)
		return;
	inorder_view(curr_node->left);
	std::cout << curr_node->value << '\n';
	inorder_view(curr_node->right);
}
