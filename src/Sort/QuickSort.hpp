#pragma once

#include "SortUtils.hpp"

namespace quicksort {
	/// <summary>
	/// Partition given array into two parts.
	/// Target of partitions is, given an array and 
	/// an element x of array as pivot,
	/// put x at its correct position in sorted array and 
	/// put all smaller elements (smaller than x) before x, 
	/// and put all greater elements (greater than x) after x.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="l_iter">left iterator.</param>
	/// <param name="r_iter">right iterator.</param>
	/// <param name="reverse">set true will sort the array descending.</param>
	/// <returns>index of pivot after adjusting.</returns>
	template<typename t> long long
	Partition(t* arr, long long l_iter, long long r_iter, bool reverse)
	{
		assert(l_iter <= r_iter);
		long long pivot_idx = l_iter;
		t pivot = arr[l_iter];

		while (l_iter < r_iter)
		{
			if (reverse)
			{
				while (l_iter < r_iter && arr[r_iter] <= pivot) r_iter--;
				while (l_iter < r_iter && arr[l_iter] >= pivot) l_iter++;
			}
			else
			{
				while (l_iter < r_iter && arr[r_iter] >= pivot) r_iter--;
				while (l_iter < r_iter && arr[l_iter] <= pivot) l_iter++;
			}
			
			if (l_iter < r_iter) sortutils::Swap(arr + l_iter, arr + r_iter);
		}
		sortutils::Swap(arr + pivot_idx, arr + r_iter);
		return r_iter;
	};

	/// <summary>
	/// Overload Partition
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="arr_size">size of array.</param>
	/// <param name="reverse">set true will sort the array descending.</param>
	/// <returns></returns>
	template<typename t> long long
	Partition(t* arr, long long arr_size, bool reverse)
	{
		return Partition(arr, 0, arr_size - 1, reverse);
	}

	/// <summary>
	/// Perform quicksort.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="l_iter">left iterator.</param>
	/// <param name="r_iter">right iterator.</param>
	/// <param name="reverse">set true will sort the array descending.</param>
	template<typename t> void
	Sort(t* arr, long long l_iter, long long r_iter, bool reverse)
	{
		if (l_iter >= r_iter) return;

		long long pivot_idx = quicksort::Partition(arr, l_iter, r_iter, reverse);
		Sort(arr, l_iter, pivot_idx - 1, reverse);
		Sort(arr, pivot_idx + 1, r_iter, reverse);
	};

	/// <summary>
	/// Overload Sort.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="arr_size">size of array.</param>
	/// <param name="reverse">set true will sort the array descending.</param>
	template<typename t> void
	Sort(t* arr, long long arr_size, bool reverse)
	{
		Sort(arr, 0, arr_size - 1; , reverse);
	};
}
