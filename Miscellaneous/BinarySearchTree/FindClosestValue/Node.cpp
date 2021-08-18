//
// Created on 8/14/21.
//

#include <iostream>
#include "Node.h"

Node::Node(int32_t value) : value(value), left(nullptr), right(nullptr) {}

void Node::inorder_view(Node *root) {
	if(root == nullptr) {
		return;
	}
	inorder_view(root->left);
	std::cout << root->value << '\n';
	inorder_view(root->right);
}

void Node::preorder_view(Node *root) {
	if(root == nullptr)
		return;
	std::cout << root->value << '\n';
	preorder_view(root->left);
	preorder_view(root->right);
}

void Node::post_order_view(Node *root) {
	if(root == nullptr)
		return;
	post_order_view(root->left);
	post_order_view(root->right);
	std::cout << root->value << '\n';
}
