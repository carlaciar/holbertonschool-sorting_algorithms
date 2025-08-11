#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: pointer to the first element of the array
 * @size: the size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	 /* Outer loop: controls the number of passes through the array */
	for (i = 0; i < size - 1; i++)
	{
		/**
		 * Inner loop: compares adjacent elements up to the
		 * unsorted part
		 */
		for (j = 0; j < size - 1 - i; j++)
		{
			/**
			 * If current element is greater than the next,
			 * swap them
			 */
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
