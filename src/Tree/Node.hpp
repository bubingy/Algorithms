#pragma once

namespace tree {
	template <typename T> struct 
		BinaryTreeNode
	{
		BinaryTreeNode* parent;
		BinaryTreeNode* leftchild;
		BinaryTreeNode* rightchild;
		T data;
	};
}