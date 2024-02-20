#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 * using the Insertion sort algorithm
 *
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			/* Swap nodes */
			if (prev->prev != NULL)
				prev->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;

			current->next = prev;
			prev->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);

			prev = current->prev;
		}

		current = next_node;
	}
}

