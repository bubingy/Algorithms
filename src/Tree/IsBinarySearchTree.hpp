#pragma once

#include "GetExtremumElementFromTree.hpp"

namespace tree
{
	/// <summary>
	/// Verify if the given tree is a binary search tree.
	/// </summary>
	/// <typeparam name="t">int, float, double or any other type supporting compare operation.</typeparam>
	/// <param name="tree_sequence">tree stored in array.</param>
	/// <param name="tree_size">size of tree.</param>
	/// <param name="null_value">specify the value of null.</param>
	/// <returns>Return 1 if the given tree is a binary search tree, otherwise return 0.</returns>
	template <typename t> bool
	IsBinarySearchTree(t* tree_sequence, size_t tree_size, t null_value)
	{
		for (size_t index = 0; index < tree_size; index++)
		{
			size_t left_child_index = 2 * index + 1;
			// skip leaf node
			if (left_child_index >= tree_size) break;
			// skip null node
			if (tree_sequence[index] == null_value) continue;

			// verify if maximum element of left sub tree is less than the root
			t max_element_of_left_child = GetMaxElementOfTree(
				tree_sequence, left_child_index, tree_size, null_value
			);
			if (max_element_of_left_child != null_value
				&& max_element_of_left_child > tree_sequence[index]) return false;

			size_t right_child_index = 2 * index + 2;
			// if the node only have left child
			if (right_child_index >= tree_size) break;

			// verify if minimum element of right sub tree is larger than the root
			t min_element_of_right_child = GetMinElementOfTree(
				tree_sequence, right_child_index, tree_size, null_value
			);
			if (min_element_of_right_child != null_value
				&& min_element_of_right_child < tree_sequence[index]) return false;
		}
		return true;
	}
}