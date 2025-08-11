#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the first integer in the list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next, *left, *right;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		next = curr->next;

		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			left = curr->prev;
			right = curr;

			left->next = right->next;

			if (right->next != NULL)
			{
				right->next->prev = left;
			}

			right->prev = left->prev;
			right->next = left;

			if (left->prev != NULL)
				left->prev->next = right;
			else
			{
				*list = right;
			}

			left->prev = right;
			print_list(*list);
		}

		curr = next;
	}
}
