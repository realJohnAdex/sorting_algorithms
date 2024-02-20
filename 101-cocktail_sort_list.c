#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (*list == NULL || a == NULL || b == NULL)
		return;

	if (a->prev != NULL)
		a->prev->next = b;
	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	b->next = a;
	a->prev = b;

	if (a->prev == NULL)
		*list = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using Cocktail shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *ptr;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (ptr = *list; ptr->next != NULL; ptr = ptr->next)
		{
			if (ptr->n > ptr->next->n)
			{
				swap_nodes(list, ptr, ptr->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (; ptr->prev != NULL; ptr = ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				swap_nodes(list, ptr->prev, ptr);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
