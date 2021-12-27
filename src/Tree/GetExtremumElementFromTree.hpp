namespace tree
{
	/// <summary>
	/// Get maximum element of a binary tree.
	/// </summary>
	/// <typeparam name="t">int, float, double or any other type supporting compare operation.</typeparam>
	/// <param name="tree_sequence">tree stored in array.</param>
	/// <param name="root_index">root index of a tree(or subtree)</param>
	/// <param name="tree_size">size of tree.</param>
	/// <param name="null_value">specify the value of null.</param>
	/// <returns>maximum element of a binary tree.</returns>
	template <typename t> t
	GetMaxElementOfTree(t* tree_sequence, size_t root_index, size_t tree_size, t null_value)
	{
		if (tree_sequence[root_index] == null_value) return null_value;
		
		size_t left_child_index = 2 * root_index + 1;
		// return leaf node directly
		if (left_child_index >= tree_size) return tree_sequence[root_index];

		// initialize max value
		t max_value = tree_sequence[root_index];

		t max_element_of_left_child = GetMaxElementOfTree(
			tree_sequence, left_child_index, tree_size, null_value
		);
		if (max_element_of_left_child != null_value && max_element_of_left_child > max_value)
			max_value = max_element_of_left_child;

		size_t right_child_index = 2 * root_index + 2;
		// if the tree don't have right child
		if (right_child_index >= tree_size) return max_value;

		t max_element_of_right_child = GetMaxElementOfTree(
			tree_sequence, right_child_index, tree_size, null_value
		);
		if (max_element_of_right_child != null_value && max_element_of_right_child > max_value)
			max_value = max_element_of_right_child;
		return max_value;
	}

	/// <summary>
	/// Get minimum element of a binary tree.
	/// </summary>
	/// <typeparam name="t">int, float, double or any other type supporting compare operation.</typeparam>
	/// <param name="tree_sequence">tree stored in array.</param>
	/// <param name="root_index">root index of a tree(or subtree)</param>
	/// <param name="tree_size">size of tree.</param>
	/// <param name="null_value">specify the value of null.</param>
	/// <returns>minimum element of a binary tree.</returns>
	template <typename t> t
	GetMinElementOfTree(t* tree_sequence, size_t root_index, size_t tree_size, t null_value)
	{
		if (tree_sequence[root_index] == null_value) return null_value;

		size_t left_child_index = 2 * root_index + 1;
		// return leaf node directly
		if (left_child_index >= tree_size) return tree_sequence[root_index];

		// initialize max value
		t min_value = tree_sequence[root_index];

		t min_element_of_left_child = GetMinElementOfTree(
			tree_sequence, left_child_index, tree_size, null_value
		);
		if (min_element_of_left_child != null_value && min_element_of_left_child < min_value)
			min_value = min_element_of_left_child;

		size_t right_child_index = 2 * root_index + 2;
		// if the tree don't have right child
		if (right_child_index >= tree_size) return min_value;

		t min_element_of_right_child = GetMinElementOfTree(
			tree_sequence, right_child_index, tree_size, null_value
		);
		if (min_element_of_right_child != null_value && min_element_of_right_child < min_value)
			min_value = min_element_of_right_child;
		return min_value;
	}
}