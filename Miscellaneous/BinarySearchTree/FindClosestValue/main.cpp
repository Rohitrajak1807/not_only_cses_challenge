#include <Node.h>
#include <array>
#include <iostream>

int32_t closest_value(Node *root, int32_t target);

int32_t get_closest_val(Node *root, int32_t target, int32_t closest);

int32_t closest_val_iter(Node *root, int32_t target);

int main() {
	std::array<Node, 9> nodes = {
			Node(10),
			Node(5),
			Node(15),
			Node(2),
			Node(5),
			Node(13),
			Node(22),
			Node(1),
			Node(14)
	};
	Node root = nodes[0];
	root.left = &nodes[1];
	root.right = &nodes[2];

	root.left->left = &nodes[3];
	root.left->right = &nodes[4];

	root.left->left->left = &nodes[7];

	root.right->left = &nodes[5];
	root.right->right = &nodes[6];
	root.right->left->right = &nodes[8];

	std::cout << closest_value(&root, 12) << '\n';
	std::cout << closest_val_iter(&root, 12) << '\n';
	return 0;
}

int32_t closest_value(Node *root, int32_t target) {
	int32_t closest = INT32_MAX;
	return get_closest_val(root, target, closest);
}

int32_t get_closest_val(Node *root, int32_t target, int32_t closest) {
	if (root == nullptr) {
		return closest;
	}
	if (std::abs(target - closest) > std::abs(target - root->value)) {
		closest = root->value;
	}
	if (target < root->value) {
		return get_closest_val(root->left, target, closest);
	} else if (target > root->value) {
		return get_closest_val(root->right, target, closest);
	} else {
		return closest;
	}
}

int32_t closest_val_iter(Node *root, int32_t target) {
	Node *current_node = root;
	int32_t closest = INT32_MAX;
	while (current_node != nullptr) {
		if (std::abs(target - closest) > std::abs(current_node->value - target)) {
			closest = current_node->value;
		}
		if (target < current_node->value) {
			current_node = current_node->left;
		} else if (target > current_node->value) {
			current_node = current_node->right;
		} else {
			break;
		}
	}
	return closest;
}
