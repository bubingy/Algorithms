#pragma once

namespace sort {
	template <typename T> inline void
		Swap(T& a, T& b)
	{
		T c = a;
		a = b;
		b = c;
	}

	template <typename T> void
		SimpleSelectionSort(T* sequence, size_t sequence_length)
	{
		T min_ele;
		size_t min_ele_index;
		for (size_t i = 0; i < sequence_length; i++)
		{
			min_ele = sequence[i];
			min_ele_index = i;
			for (size_t j = i; j < sequence_length; j++)
			{
				if (sequence[j] < min_ele)
				{
					min_ele = sequence[j];
					min_ele_index = j;
				}
			}
			Swap(sequence[i], sequence[min_ele_index]);
		}
	}

	template <typename T> inline void
		BuildHeap(T* sequence, size_t sequence_length, size_t parrent_index)
	{
		size_t max_index = parrent_index;
		size_t left_child_index = 2 * parrent_index + 1;
		size_t right_child_index = 2 * parrent_index + 2;

		if (left_child_index < sequence_length && sequence[left_child_index] > sequence[max_index])
			max_index = left_child_index;
		if (right_child_index < sequence_length && sequence[right_child_index] > sequence[max_index])
			max_index = right_child_index;

		if (max_index != parrent_index)
		{
			Swap(sequence[max_index], sequence[parrent_index]);
			BuildHeap(sequence, sequence_length, max_index);
		}
	}

	template <typename T> void
		HeapSort(T* sequence, size_t sequence_length)
	{
		for (size_t i = sequence_length / 2 - 1;  i != 0;  i--)
			BuildHeap(sequence, sequence_length, i);

		for (size_t i = sequence_length; i != 0; i--)
		{
			Swap(sequence[0], sequence[i]);
			BuildHeap(sequence, i, 0);
		}
	}
}
