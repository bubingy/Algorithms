#include <iostream>
#include <string>
#include "IsBinarySearchTree.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	int tree_sequence[15] = {21, 14, 28, 11, 18, 25, 32, 5, 12, 15, 19, 23, 27, 30, 37};
	bool result = tree::IsBinarySearchTree(tree_sequence, 15, -1);
	cout << result << endl;
}