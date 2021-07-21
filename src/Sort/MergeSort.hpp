#pragma once

#include "SortUtils.hpp"

namespace mergesort {
	template <typename t> void
	Merge(t* array, size_t left, size_t mid, size_t right)
	{
		auto const subArrayOne = mid - left + 1;
		auto const subArrayTwo = right - mid;

		// Create temp arrays
		auto* leftArray = new t[subArrayOne];
		auto* rightArray = new t[subArrayTwo];

		for (size_t i = 0; i < subArrayOne; i++)
			leftArray[i] = array[left + i];
		for (size_t j = 0; j < subArrayTwo; j++)
			rightArray[j] = array[mid + 1 + j];

		size_t indexOfSubArrayOne = 0; // Initial index of first sub-array
		size_t indexOfSubArrayTwo = 0; // Initial index of second sub-array
		size_t indexOfMergedArray = left; // Initial index of merged array

		// Merge the temp arrays back into array[left..right]
		while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
			if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
				array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
			}
			else {
				array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
			}
			indexOfMergedArray++;
		}
		// Copy the remaining elements of
		// left[], if there are any
		while (indexOfSubArrayOne < subArrayOne) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}
		// Copy the remaining elements of
		// right[], if there are any
		while (indexOfSubArrayTwo < subArrayTwo) {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}
	};

	template <typename t> void
	MergeSort(t* array, size_t begin, size_t end) {
		if (begin >= end)
			return;

		size_t mid = begin + (end - begin) / 2;
		MergeSort(array, begin, mid);
		MergeSort(array, mid + 1, end);
		Merge(array, begin, mid, end);
	};

	template <typename t> void
	Sort(t* array, size_t array_size) {
		MergeSort(array, 0, array_size - 1);
	};
}
