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
		BubbleSort(T* sequence, size_t sequence_length)
	{
		if (sequence_length <= 1) return;
		for (size_t i = 0; i < sequence_length-1; i++)
		{
			for (size_t j = 0; j < sequence_length - 1 - i; j++)
			{
				if (sequence[j] > sequence[j + 1])
					Swap(sequence[j], sequence[j + 1]);
			}
		}
	}

	template<typename T> inline long long
		Partition(T* arr, long long l_iter, long long r_iter, bool reverse)
	{
		long long pivot_idx = l_iter;
		T pivot = arr[l_iter];

		while (l_iter < r_iter)
		{
			while (l_iter < r_iter && arr[r_iter] >= pivot) r_iter--;
			while (l_iter < r_iter && arr[l_iter] <= pivot) l_iter++;
			
			if (l_iter < r_iter) Swap(arr[l_iter], arr[r_iter]);
		}
		Swap(arr[pivot_idx], arr[r_iter]);
		return r_iter;
	};

	template<typename T> void
	Sort(T* arr, long long l_iter, long long r_iter)
	{
		if (l_iter >= r_iter) return;

		long long pivot_idx = quicksort::Partition(arr, l_iter, r_iter);
		Sort(arr, l_iter, pivot_idx - 1);
		Sort(arr, pivot_idx + 1, r_iter);
	};

}
