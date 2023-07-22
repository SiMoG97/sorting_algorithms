#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                      in ascending order using the Insertion sort algorithm
 * @list: the list ot be sorted
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp, *prev;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		tmp = curr;
		prev = tmp->prev;

		while (prev && prev->n > curr->n)
		{
			prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = prev;

			tmp->next = prev;
			tmp->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = tmp;
			else
				*list = tmp;

			prev->prev = tmp;
			prev = tmp->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
