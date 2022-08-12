#include <iostream>
#include "Traversal.hpp"
#include "Node.hpp"

using namespace std;
using namespace tree;

int main(int argc, char* argv[])
{
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>();
	root->data = 1;
	root->leftchild = new BinaryTreeNode<int>();
	root->leftchild->data = 2;
	root->rightchild = new BinaryTreeNode<int>();
	root->rightchild->data = 3;
	root->leftchild->leftchild = new BinaryTreeNode<int>();
	root->leftchild->leftchild->data = 4;
	root->leftchild->rightchild = new BinaryTreeNode<int>();
	root->leftchild->rightchild->data = 5;
	list<int>* output = new list<int>();

	PostOrder(root, output);

	for (auto item : *output)
	{
		cout << item << " ";
	}
	cout << endl;
}