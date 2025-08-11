#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Pointer to array
 * @low: Starting index
 * @high: Ending index (pivot position)
 * @size: Total size of the array
 *
 * Return: Final index position of the pivot
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j;
	int tmp;
	
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	
	if (i != high)
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_rec - Recursive quick sort helper
 * @array: Pointer to array
 * @low: Starting index of partition
 * @high: Ending index of partition
 * @size: Total size of the array
 */
void quick_sort_rec(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, low, high, size);

		if (p > 0)
		{
			quick_sort_rec(array, low, p - 1, size);
		}
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick sort (Lomuto partition scheme)
 * @array: Pointer to array
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	
	quick_sort_rec(array, 0, size - 1, size);
}
