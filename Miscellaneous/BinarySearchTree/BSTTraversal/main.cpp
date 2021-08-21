#include <iostream>
#include <functional>
#include <BST.hpp>

template<typename T>
void inorder(const BST<T>& tree);

template<typename T>
void inorder(const std::unique_ptr<Node<T>>& root);

template<typename T>
void preorder(const BST<T>& tree);

template<typename T>
void preorder(const std::unique_ptr<Node<T>>& root);

template<typename T>
void postorder(const BST<T>& tree);

template<typename T>
void postorder(const std::unique_ptr<Node<T>>& root);

int main() {
	std::vector<int32_t> v1{50, 30, 80, 10, 5, 100, 70};
	std::vector<int32_t> v2{10, 30, 80, 7, 5, 1};
	BST<int32_t> t1{v1};
	BST<int32_t> t2{v2};

	inorder(t1);
	std::cout << "\n------------------------\n";
	preorder(t2);
	std::cout << "\n------------------------\n";
	postorder(t1);
	return 0;
}


template<typename T>
void inorder(const BST<T>& tree) {
	const std::unique_ptr<Node<T>>& root = tree.get_root();
	inorder(root);
}

template<typename T>
void inorder(const std::unique_ptr<Node<T>>& root) {
	if(root == nullptr)
		return;
	inorder(root->left);
	std::cout << root->value << '\n';
	inorder(root->right);
}

template<typename T>
void preorder(const BST<T>& tree) {
	const std::unique_ptr<Node<T>>& root = tree.get_root();
	preorder(root);
}

template<typename T>
void preorder(const std::unique_ptr<Node<T>>& root) {
	if(root == nullptr)
		return;
	std::cout << root->value << '\n';
	inorder(root->left);
	inorder(root->right);
}

template<typename T>
void postorder(const BST<T>& tree) {
	const std::unique_ptr<Node<T>>& root = tree.get_root();
	postorder(root);
}

template<typename T>
void postorder(const std::unique_ptr<Node<T>>& root) {
	if(root == nullptr)
		return;
	postorder(root->left);
	postorder(root->right);
	std::cout << root->value << '\n';
}
