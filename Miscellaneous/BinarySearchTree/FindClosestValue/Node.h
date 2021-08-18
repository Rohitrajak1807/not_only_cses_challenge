//
// Created on 8/14/21.
//

#ifndef FINDCLOSESTVALUE_NODE_H
#define FINDCLOSESTVALUE_NODE_H

#include <cstdint>

class Node {
public:
	int32_t value;
	Node *left;
	Node *right;
	explicit Node(int32_t value);
	static void inorder_view(Node *root);
	static void preorder_view(Node *root);
	static void post_order_view(Node * root);
};


#endif //FINDCLOSESTVALUE_NODE_H
