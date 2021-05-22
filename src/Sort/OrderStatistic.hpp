#pragma once

#include "QuickSort.hpp"
#include "SortUtils.hpp"

namespace orderstatistic {
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
	/// <param name="pivot">value of pivot.</param>
	/// <param name="l_iter">left iterator.</param>
	/// <param name="r_iter">right iterator.</param>
	/// <param name="reverse">set true will sort the array descending.</param>
	/// <returns>index of pivot after adjusting.</returns>
	template<typename t> long long
	Partition(t* arr, t pivot, long long l_iter, long long r_iter, bool reverse)
	{
		for (size_t i = l_iter; i <= r_iter; i++)
		{
			if (arr[i] == pivot)
			{
				sortutils::Swap(arr + l_iter, arr + i);
				break;
			}
		}

		long long pivot_idx = l_iter;
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
	/// Find median of an array with only five elements in it.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="l_iter">left iterator.</param>
	/// <param name="r_iter">right iterator.</param>
	/// <returns>median of this array.</returns>
	template<typename t> inline t
	FindMedian(t* arr, long long l_iter, long long r_iter)
	{
		quicksort::Sort(arr, l_iter, r_iter, false);  // Sort the array
		return arr[(l_iter + r_iter) / 2];   // Return middle element
	};

	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="k"></param>
	/// <param name="l_iter">left iterator.</param>
	/// <param name="r_iter">right iterator.</param>
	/// <returns>k th smallest element.</returns>
	template<typename t> t
	GetKthSmallest(t* arr, long long k, long long l_iter, long long r_iter)
	{
		long long arr_size = r_iter - l_iter + 1; // Number of elements in arr[l..r]

		// Divide arr[] in groups of size 5, calculate median
		// of every group and store it in median[] array.
		t* median = new t[(arr_size + 4) / 5];
		long long median_size;
		for (median_size = 0; median_size < arr_size / 5; median_size++)
			median[median_size] = FindMedian(arr, l_iter + median_size * 5, l_iter + median_size * 5 + 4);
		if (median_size * 5 < arr_size) //For last group with less than 5 elements
		{
			median[median_size] = FindMedian(arr, l_iter + median_size * 5, l_iter + median_size * 5 + arr_size % 5 - 1);
			median_size++;
		}

		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call
		t medOfMed = (median_size == 1) ? median[median_size - 1] :
			GetKthSmallest(median, median_size / 2, 0, median_size - 1);

		// Partition the array around a random element and
		// get position of pivot element in sorted array
		long long pos = Partition(arr, medOfMed, l_iter, r_iter, false);

		// If position is same as k
		if (pos - l_iter == k - 1)
			return arr[pos];
		if (pos - l_iter > k - 1)  // If position is more, recur for left
			return GetKthSmallest(arr, k, l_iter, pos - 1);

		// Else recur for right subarray
		return GetKthSmallest(arr, k - pos + l_iter - 1, pos + 1, r_iter);
	};
}