#pragma once

#include "QuickSort.hpp"
#include "SortUtils.hpp"

namespace orderstatistic {
	/// <summary>
	/// Partition given array into two parts.
	/// Target of _Partitions is, given an array and 
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
	/// <returns>index of pivot after adjusting.</returns>
	template<typename t> long long
	_Partition(t* arr, t pivot, long long l_iter, long long r_iter)
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
			
			while (l_iter < r_iter && arr[r_iter] >= pivot) r_iter--;
			while (l_iter < r_iter && arr[l_iter] <= pivot) l_iter++;
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
	_FindMedian(t* arr, long long l_iter, long long r_iter)
	{
		quicksort::Sort(arr, l_iter, r_iter, false);  // Sort the array
		return arr[(l_iter + r_iter) / 2];   // Return middle element
	};

	/// <summary>
	/// Get kth smallest element in given array.
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
			median[median_size] = _FindMedian(arr, l_iter + median_size * 5, l_iter + median_size * 5 + 4);
		if (median_size * 5 < arr_size) //For last group with less than 5 elements
		{
			median[median_size] = _FindMedian(arr, l_iter + median_size * 5, l_iter + median_size * 5 + arr_size % 5 - 1);
			median_size++;
		}

		// Find median of all medians using recursive call.
		// If median[] has only one element, then no need
		// of recursive call
		t medOfMed = (median_size == 1) ? median[median_size - 1] :
			GetKthSmallest(median, median_size / 2, 0, median_size - 1);

		// Partition the array around a random element and
		// get position of pivot element in sorted array
		long long pos = _Partition(arr, medOfMed, l_iter, r_iter);

		// If position is same as k
		if (pos - l_iter == k - 1)
			return arr[pos];
		if (pos - l_iter > k - 1)  // If position is more, recur for left
			return GetKthSmallest(arr, k, l_iter, pos - 1);

		// Else recur for right subarray
		return GetKthSmallest(arr, k - pos + l_iter - 1, pos + 1, r_iter);
	};

	/// <summary>
	/// Overload GetKthSmallest.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="k"></param>
	/// <param name="arr_size">size of array.</param>
	/// <returns>k th smallest element.</returns>
	template<typename t> t
	GetKthSmallest(t* arr, long long k, long long arr_size)
	{
		return GetKthSmallest(arr, k, 0, arr_size - 1);
	};

	/// <summary>
	/// Get median of given array.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="l_iter">left iterator.</param>
	/// <param name="r_iter">right iterator.</param>
	/// <returns>median element.</returns>
	template<typename t> double
	GetMedian(t* arr, long long l_iter, long long r_iter)
	{
		if ((r_iter - l_iter) % 2 == 0)
			return GetKthSmallest(arr, (r_iter + l_iter) / 2 + 1, l_iter, r_iter);
		else
		{
			t down_median = GetKthSmallest(arr, (r_iter + l_iter) / 2 + 1, l_iter, r_iter);
			t up_median = GetKthSmallest(arr, (r_iter + l_iter) / 2 + 2, l_iter, r_iter);
			if ((down_median + up_median) % 2 == 0) return (down_median + up_median) / 2;
			else return ((double)down_median + (double)up_median) / 2;
		}
	};

	/// <summary>
	/// Overload GetMedian.
	/// </summary>
	/// <typeparam name="t"></typeparam>
	/// <param name="arr">the given array.</param>
	/// <param name="arr_size">size of array.</param>
	/// <returns></returns>
	template<typename t> double
	GetMedian(t* arr, long long arr_size)
	{
		return GetMedian(arr, 0, arr_size - 1);
	};
}