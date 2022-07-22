#pragma once

namespace sort {
	template <typename T> void
		Merge(T* source_sequence, T* target_sequence, size_t low, size_t mid, size_t high)
	{
		size_t i = low, j = mid + 1, k = low;
		while (i <= mid && j <= high)
		{
			if (source_sequence[i] <= source_sequence[j])
				target_sequence[k++] = source_sequence[i++];
			else
				target_sequence[k++] = source_sequence[j++];
		}
		while (i <= mid) target_sequence[k++] = source_sequence[i++];
		while (j <= high) target_sequence[k++] = source_sequence[j++];
	};

	template <typename T> void
		MergeSort(T* source_sequence, T* target_sequence, size_t low, size_t high) 
	{
		if (low >= high)
		{
			target_sequence[low] = source_sequence[low];
			return;
		}
		size_t mid = (low + high) / 2;
		MergeSort(source_sequence, target_sequence, low, mid);
		MergeSort(source_sequence, target_sequence, mid + 1, high);
		Merge(source_sequence, target_sequence, low, mid, high);
	};

}
