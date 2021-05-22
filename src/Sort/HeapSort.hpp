#pragma once

#include "SortUtils.hpp"

namespace heapsort {
	/// <summary>
	/// Compare two element when building binary heap.
	/// if is_max_heap is true, return result of a < b;
	/// else, return result of a > b.
	/// </summary>
	/// <typeparam name="t">Comparable type.</typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <param name="is_max_heap">whether it's a max heap.</param>
	/// <returns></returns>
	template<typename t> inline bool
	Compare(t& a, t& b, bool is_max_heap)
	{
		if (is_max_heap) return a < b;
		else return a > b;
	};

	/// <summary>
	/// Build a binary heap.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">an array.</param>
	/// <param name="arr_size">size of given array.</param>
	/// <param name="p_idx">index of root node of a subtree.</param>
	/// <param name="is_max_heap">decide whether it's a max heap.</param>
	template<typename t> void
	BuildBinHeap(t* arr,
				 long long arr_size,
				 long long p_idx,
				 bool is_max_heap)
	{
		assert(arr_size > 0);

		long long e_idx = p_idx; // index of extremum
		long long l_idx = 2 * p_idx + 1; // index of left child
		long long r_idx = 2 * p_idx + 2; // index of right child

		if (l_idx < arr_size && Compare(arr[e_idx], arr[l_idx], is_max_heap))
			e_idx = l_idx;

		if (r_idx < arr_size && Compare(arr[e_idx], arr[r_idx], is_max_heap))
			e_idx = r_idx;

		if (e_idx != p_idx)
		{
			sortutils::Swap(arr + p_idx, arr + e_idx);
			BuildBinHeap(arr, arr_size, e_idx, is_max_heap);
		}
	};

	/// <summary>
	/// perform heapsort.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">an array.</param>
	/// <param name="arr_size">size of given array.</param>
	/// <param name="reverse">set true will sort the array descending.</param>
	template<typename t> void
	Sort(t* arr, long long arr_size, bool reverse)
	{
		assert(arr_size > 0);

		// build a binary heap 
		bool is_max_heap = !reverse;
		for (long long i = arr_size / 2 - 1; i >= 0; i--)
			BuildBinHeap(arr, arr_size, i, is_max_heap);

		// heapsort
		for (long long i = arr_size - 1; i >= 0; i--)
		{
			sortutils::Swap(arr + 0, arr + i);
			BuildBinHeap(arr, i, 0, is_max_heap);
		}
	};
}

