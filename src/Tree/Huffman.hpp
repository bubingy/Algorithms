#pragma once

#include <list>
#include "sort/SwapSort.hpp"
#include "Tree/Node.hpp"

namespace tree {

	template <typename T> BinaryTreeNode<T>*
		HuffmanTree(T* sequence, size_t sequence_size)
	{
		// sort input array
		T* tmp_sequence = new T[sequence_size];
		std::copy(sequence, sequence + sequence_size, tmp_sequence);
		sort::QuickSort(tmp_sequence, 0, sequence_size - 1);

		// convert array to list
		std::list<BinaryTreeNode<T>*> node_list;
		for (size_t i = 0; i < sequence_size; i++)
		{
			BinaryTreeNode<T>* node = new BinaryTreeNode<T>();
			node->data = tmp_sequence[i];
			node_list.push_back(node);
		}

		// construct huffman tree
		std::list<BinaryTreeNode<T>*>::iterator iter = node_list.begin();
		while (node_list.size() >= 2)
		{
			BinaryTreeNode<T>* left_child = *iter;
			iter++;
			node_list.pop_front();
			BinaryTreeNode<T>* right_child = *iter;
			iter++;
			node_list.pop_front();

			BinaryTreeNode<T>* tmp_node = new BinaryTreeNode<T>();
			tmp_node->data = left_child->data + right_child->data;
			tmp_node->leftchild = left_child;
			tmp_node->rightchild = right_child;

			for (iter = node_list.begin(); iter != node_list.end(); iter++)
				if ((*iter)->data > tmp_node->data) 
					break;
			
			node_list.insert(iter, tmp_node);
			iter = node_list.begin();
		}

		return *iter;
	}
}