#include <iostream>
#include <BST.hpp>

// Write a function that takes in a Binary Tree and returns a list of its branch
// sums ordered from leftmost branch sum to rightmost branch sum.
// A branch sum is the sum of all values in a Binary Tree branch. A Binary Tree
// branch is a path of nodes in a tree that starts at the root node and ends at
// any leaf node.
// Each BinaryTree node has an integer value, a left child node, and a right child node. Children
// nodes can either be BinaryTree nodes themselves or null.
//
// Sample Input
// tree=
// 		           1
// 				/     \
//              2       3
//            /   \    /  \
//           4     5  6    7
//         /   \  /
//        8    9 10
//  Sample Output
//  [15, 16, 18, 10, 11]
// 15 == 1 + 2 + 4 + 8
// 16 == 1 + 2 + 4 + 9
// 18 == 1 + 2 + 5 + 10
// 10 == 1 + 3 + 6
// 11 == 1 + 3 + 7
template<typename T>
std::vector<int32_t> branch_sums(const std::unique_ptr<Node<T>>& root);

template<typename T>
void branch_sums(const std::unique_ptr<Node<T>>& root, std::vector<int32_t>& sums, int32_t sum);

int main() {
	BST<int32_t> bst(1);
	bst.get_root()->left = std::make_unique<Node<int32_t>>(2);
	bst.get_root()->left->left = std::make_unique<Node<int32_t>>(4);
	bst.get_root()->left->left->left = std::make_unique<Node<int32_t>>(8);
	bst.get_root()->left->left->right = std::make_unique<Node<int32_t>>(9);

	bst.get_root()->left->right = std::make_unique<Node<int32_t>>(5);
	bst.get_root()->left->right->left = std::make_unique<Node<int32_t>>(10);

	bst.get_root()->right = std::make_unique<Node<int32_t>>(3);
	bst.get_root()->right->left = std::make_unique<Node<int32_t>>(6);
	bst.get_root()->right->right = std::make_unique<Node<int32_t>>(7);

	auto &&res = branch_sums(bst.get_root());
	for(int32_t& i : res)
		std::cout << i << '\n';
	return 0;
}


template<typename T>
std::vector<int32_t> branch_sums(const std::unique_ptr<Node<T>>& root) {
	std::vector<int32_t> sums;
	branch_sums(root, sums, 0);
	return sums;
}

template<typename T>
void branch_sums(const std::unique_ptr<Node<T>>& root, std::vector<int32_t>& sums, int32_t sum) {
	if(root == nullptr)
		return;
	if(root->left == nullptr and root->right == nullptr) {
		sums.emplace_back(sum + root->value);
		return;
	}
	branch_sums(root->left, sums, sum + root->value);
	branch_sums(root->right, sums, sum + root->value);
}
