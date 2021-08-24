#include <iostream>
#include <memory>
#include <vector>
#include <BST.hpp>


//  The distance between a node in a Binary Tree and the tree's root is called the
//  node's depth.
//  Write a function that takes in a Binary Tree and returns the sum of its nodes'
//  depths.
//  Each BinaryTree node has an integer value, a left child node, and a right child node. Children
//  nodes can either be BinaryTree nodes themselves or null.
//  Sample Input:
//  tree  =    1
//  		/     \
//  	   2       3
//  	 /   \   /   \
//      4     5 6     7
//    /   \
//   8     9
//  Sample Output:
//  16


template<typename T>
struct NodeDepths {
	const std::unique_ptr<Node<T>>& node;
	int32_t depth;

	NodeDepths(const std::unique_ptr<Node<T>>& node, int32_t depth) : node(node), depth(depth) {}
};

template<typename T>
int32_t node_depths(const BST<T>& bst);

template<typename T>
int32_t node_depths(const std::unique_ptr<Node<T>>& curr_node, int32_t curr_depth);

template<typename T>
int32_t node_depths_iter(const BST<T>& bst);

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

	std::cout << node_depths(bst) << '\n';
	std::cout << node_depths_iter(bst) << '\n';
	return 0;
}

template<typename T>
int32_t node_depths(const BST<T>& bst) {
	return node_depths(bst.get_root(), 0);
}

template<typename T>
int32_t node_depths(const std::unique_ptr<Node<T>>& curr_node, int32_t curr_depth) {
	if(curr_node == nullptr)
		return 0;
	int32_t left_depths = node_depths(curr_node->left, curr_depth + 1);
	int32_t right_depths = node_depths(curr_node->right, curr_depth + 1);
	return curr_depth + left_depths + right_depths;
}

template<typename T>
int32_t node_depths_iter(const BST<T>& bst) {
	const auto& root = bst.get_root();
	int32_t all_depths = 0;
	std::vector<NodeDepths<T>> stack;
	stack.emplace_back(root, 0);
	while(!stack.empty()) {
		auto[node, depth] = stack.back();
		stack.pop_back();
		if(node == nullptr) {
			continue;
		}
		all_depths += depth;
		stack.emplace_back(node->left, depth + 1);
		stack.emplace_back(node->right, depth + 1);
	}
	return all_depths;
}
