#include "sort.h"

#define PRINT_AFTER_SWAP	1

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *  ascending order using the Insertion sort algorithm
 * @list: The head node of the list to be sorted
 *
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *comp, *temp;

	if (list == NULL)
		return;
	for (cur = (*list); cur != NULL; cur = cur->next)
	{
		if (cur->prev == NULL)
			continue;
		temp = NULL;
		for (comp = cur->prev; comp != NULL; comp = comp->prev)
		{
			if (cur->n < comp->n)
			{
				temp = cur;
				comp->next = cur->next;
				cur->prev = comp->prev;
				if (cur->next != NULL)
					cur->next->prev = comp;
				if (comp->prev != NULL)
					comp->prev->next = cur;
				else
					*list = cur;
				cur->next = comp;
				comp->prev = cur;
				#if PRINT_AFTER_SWAP
				print_list(*list);
				#endif
			}
		}
		if (temp != NULL)
			cur = temp;
	}
}
