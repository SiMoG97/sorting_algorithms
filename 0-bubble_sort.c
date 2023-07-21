#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 *                  order using the Bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, unsortedIndex = size - 1;
	int tmp;
	bool didSwap = false;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		didSwap = false;
		for (j = 0; j < unsortedIndex; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				didSwap = true;
			}
		}
		if (!didSwap)
			break;

		unsortedIndex -= 1;
	}
}
