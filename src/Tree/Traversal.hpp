#pragma once

#include <list>
#include "Node.hpp"

namespace tree {
	template <typename T> void
		PreOrder(BinaryTreeNode<T>* root, std::list<T>* output_sequence)
	{
		if (root)
		{
			output_sequence->push_back(root->data); 
			PreOrder(root->leftchild, output_sequence);
			PreOrder(root->rightchild, output_sequence);
		}	
	}

	template <typename T> void
		InOrder(BinaryTreeNode<T>* root, std::list<T>* output_sequence)
	{
		if (root)
		{
			InOrder(root->leftchild, output_sequence);
			output_sequence->push_back(root->data);
			InOrder(root->rightchild, output_sequence);
		}
	}

	template <typename T> void
		PostOrder(BinaryTreeNode<T>* root, std::list<T>* output_sequence)
	{
		if (root)
		{
			PostOrder(root->leftchild, output_sequence);
			PostOrder(root->rightchild, output_sequence);
			output_sequence->push_back(root->data);
		}
	}
}