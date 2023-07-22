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
	size_t i, j;
	int tmp;
	bool didSwap = true;

	if (!array || size < 2)
		return;

	for (i = 0; i < size && didSwap; i++)
	{
		didSwap = false;
		for (j = 0; j < (size - 1 - i); j++)
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
	}
}
