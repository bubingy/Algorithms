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
	template<typename t> inline long long
	Partition(t* arr, long long l_iter, long long r_iter, bool reverse)
	{
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
QuickSort(t* arr, long long l_iter, long long r_iter, bool reverse)
{
	if (l_iter >= r_iter) return;

	long long pivot_idx = quicksort::Partition(arr, l_iter, r_iter, reverse);
	QuickSort(arr, l_iter, pivot_idx - 1, reverse);
	QuickSort(arr, pivot_idx + 1, r_iter, reverse);
};