#pragma once

#include <iostream>

template<typename t> void
PrintArray(t* arr, long long arr_size)
{
	for (size_t i = 0; i < arr_size; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
};

template<typename t> void
PrintBinaryTree(t* arr, long long arr_size)
{

}