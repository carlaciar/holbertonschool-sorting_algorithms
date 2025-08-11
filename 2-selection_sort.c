#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: pointer to the first element of the array
 * @size: the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		/**
		 * find the index of the smallest element
		 * in the unsorted part
		 */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		/* swap if the smallest isn't already in position i */
		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;

			/* print array after each swap */
			print_array(array, size);
		}
	}
}
