#include "sort.h"

void swap(int *x, int *y);
void quick_sort_rec(int *array, int start, int end, size_t size);
int partition(int *array, int start, int end, size_t size);


/**
 * quick_sort - orts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * swap - swaps two values
 * @x: the first value to swap with y.
 * @y: the second value to swap with x.
 * Return: Nothing
 */

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * quick_sort_rec - Sorts an integer array using the Quick Sort algorithm.
 *
 * @array: Pointer to the integer array to be sorted.
 * @start: The starting index of the current sub-array to be sorted.
 * @end: The ending index of the current sub-array to be sorted.
 * @size: The total number of elements in the array.
 *
 * Return: Nothing
 */

void quick_sort_rec(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start >= end)
		return;

	pivot_index = partition(array, start, end, size);
	quick_sort_rec(array, start, pivot_index - 1, size);
	quick_sort_rec(array, pivot_index + 1, end, size);
}

/**
 * partition - Rearranges elements in the array around a pivot value.
 *
 * @array: Pointer to the integer array to be partitioned.
 * @start: The starting index of the partitioning range.
 * @end: The ending index of the partitioning range.
 * @size: The total number of elements in the array.
 *
 * Return: The index where the pivot element is placed after partitioning.
 */

int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start, j;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			i++;
			print_array(array, size);
		}
	}
	swap(&array[i], &array[end]);
	print_array(array, size);

	return (i);
}
