#include <iostream>
#include "BST.hpp"
#include <vector>


//  Write a BST class for a Binary Search Tree. The class should support:

//  		Inserting values with the insert method.

//  		Removing values with the remove method; this method should
//  		only remove the first instance of a given value.
//  		Searching for values with the contains method.

//  		Note that you can't remove values from a single-node tree. In other words,
//  		calling the remove method on a single-node tree should simply not
//  		do anything.

int main() {
	std::boolalpha(std::cout);
	std::vector<int32_t> v{23, 2, 11, 2, 5, -5, 6, 34, 8, 9, 42, 0};

	BST<int32_t> bst{v};
	BST<int32_t> bst2(50);
	bst2.insert(25);
	bst2.insert(75);
	bst2.insert(24);
	bst2.insert(30);
	bst2.insert(80);
	bst2.insert(100);
	BST<int32_t> bst3{};
	bst3.insert(100);
	bst3.insert(40);
	bst3.insert(400);
	bst3.insert(10);

	std::vector<int32_t> v2{23, 2, 11, 2, 5, 34, 8};
	BST<int32_t> bst4(v2.begin(), v2.end());

	std::cout << bst.contains(2)    << '\n'
	          << bst.contains(30)   << '\n'
	          << bst2.contains(100) << '\n'
	          << bst2.contains(50)  << '\n'
	          << bst3.contains(44)  << '\n';

	std::cout << (bst.remove_val(11) ? "removed" : "not found") << '\n';
	std::cout << (bst.remove_val(11) ? "removed" : "not found") << '\n';
	std::cout << bst.contains(11) << '\n';
	std::cout << bst.min()  << '\n';
	std::cout << bst2.min() << '\n';
	std::cout << bst3.min() << '\n';
	std::cout << bst.max()  << '\n';
	std::cout << bst2.max() << '\n';
	std::cout << bst3.max() << '\n';
	std::cout << bst4.min() << ", " << bst4.max() << '\n';
	return 0;
}
