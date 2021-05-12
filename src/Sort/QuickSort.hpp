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
		assert(l_iter <= r_iter);

		if (l_iter >= r_iter) return;

		long long pivot_idx = quicksort::Partition(arr, l_iter, r_iter, reverse);
		Sort(arr, l_iter, pivot_idx - 1, reverse);
		Sort(arr, pivot_idx + 1, r_iter, reverse);
	};

	/// <summary>
	/// Get k th smallest element in array.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="k">k th smallest element.</param>
	/// <param name="l_iter">left iterator.</param>
	/// <param name="r_iter">right iterator.</param>
	/// <returns>k th smallest element.</returns>
	template<typename t> t
	GetKthSmallest(t* arr, long long k, long long l_iter, long long r_iter)
	{
		assert(k >= l_iter && k <= r_iter);

		long long pivot_idx = quicksort::Partition(arr, l_iter, r_iter, false);

		if (pivot_idx == k-1) return arr[pivot_idx];
		if (pivot_idx > k-1) return GetKthSmallest(arr, k, l_iter, pivot_idx - 1);
		if (pivot_idx < k-1) return GetKthSmallest(arr, k, pivot_idx + 1, r_iter);
	};

	/// <summary>
	/// Get k th largest element in array.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="k">k th largest element.</param>
	/// <param name="l_iter">left iterator.</param>
	/// <param name="r_iter">right iterator.</param>
	/// <returns>k th largest element.</returns>
	template<typename t> t
	GetKthLargest(t* arr, long long k, long long l_iter, long long r_iter)
	{
		assert(k >= l_iter+1 && k <= r_iter + 1);

		long long pivot_idx = quicksort::Partition(arr, l_iter, r_iter, true);

		if (pivot_idx == k - 1) return arr[pivot_idx];
		if (pivot_idx > k - 1) return GetKthLargest(arr, k, l_iter, pivot_idx - 1);
		if (pivot_idx < k - 1) return GetKthLargest(arr, k, pivot_idx + 1, r_iter);
	};
}
