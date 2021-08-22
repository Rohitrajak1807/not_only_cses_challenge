#include <iostream>
#include <BST.hpp>

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
