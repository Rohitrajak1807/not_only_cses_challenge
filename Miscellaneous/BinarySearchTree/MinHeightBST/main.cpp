#include <iostream>
#include <BST.hpp>

#define NLOGN 0
#define LINEAR 1


// Write a function that takes in a non-empty sorted array of distinct integers, constructs a BST from the integers,
// and returns the root of the BST. The function should minimize the height of the BST. You've been provided with a BST
// class that you'll have to use to construct the BST.
// Each BST node has an integer value, a left child node, and a right child node.
// A node is said to be a valid BST node if and only if it satisfies the BST property:
// its value is strictly greater than the values of every node to its left;
// its value is less than or equal to the values of every node to its right;
// and its children nodes are either valid BST nodes themselves or null.
// Sample Input
// array = [1, 2, 5, 7, 10, 13, 14, 15, 22]
// Sample Output
//         10
//       /     \
//      2      14
//    /   \   /   \
//   1     5 13   15
//          \       \
//           7      22

template<typename T>
bool is_in_bound(std::vector<T> &v, size_t idx);

template<typename T>
BST<T> construct_min_h_bst(std::vector<T> &v);

# if NLOGN == 1

template<typename T>
void construct_min_h_bst(std::vector<T> &v, BST<T> &bst, size_t start, size_t end);

#endif

#if LINEAR == 1

template<typename T>
void construct_min_h_bst(std::vector<T> &v, std::unique_ptr<Node<T>> &curr_node, size_t start, size_t end);

#endif

int main() {
	std::vector<int32_t> v = {1, 2, 5, 7, 10, 13, 14, 15, 22};
	BST<int32_t> bst = construct_min_h_bst(v);
	return 0;
}

template<typename T>
bool is_in_bound(std::vector<T> &v, size_t idx) {
	return (idx < v.size()) and (idx >= 0UL);
}

template<typename T>
BST<T> construct_min_h_bst(std::vector<T> &v) {
	BST<T> bst;
#if NLOGN == 1
	construct_min_h_bst(v, bst, 0, v.size() - 1);
#endif
#if LINEAR == 1
	std::unique_ptr<Node<T>> &root = bst.get_root();
	construct_min_h_bst(v, root, 0, v.size() - 1);
#endif
	return bst;
}


#if NLOGN == 1

template<typename T>
void construct_min_h_bst(std::vector<T> &v, BST<T> &bst, size_t start, size_t end) {
	if (!is_in_bound(v, start) or !is_in_bound(v, end) or (end < start))
		return;
	size_t mid = (start + end) / 2;
	T &value = v[mid];
	if (bst.get_root() == nullptr)
		bst = BST(value);
	else
		bst.insert(value);
	construct_min_h_bst(v, bst, start, mid - 1);
	construct_min_h_bst(v, bst, mid + 1, end);
}

#endif

# if LINEAR == 1

template<typename T>
void construct_min_h_bst(std::vector<T> &v, std::unique_ptr<Node<T>> &curr_node, size_t start, size_t end) {
	if (!is_in_bound(v, start) or !is_in_bound(v, end) or (end < start))
		return;
	size_t mid = (start + end) / 2;
	T &value = v[mid];
	if (curr_node == nullptr)
		curr_node = std::make_unique<Node<T>>(value);
	else {
		if (value < curr_node->value)
			curr_node->left = std::make_unique<Node<T>>(value);
		else
			curr_node->right = std::make_unique<Node<T>>(value);
	}
	construct_min_h_bst(v, curr_node->left, start, mid - 1);
	construct_min_h_bst(v, curr_node->right, mid + 1, end);
}

# endif
