#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers in ascending order
 * order using an insertion sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_element, *prev_element, *new, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	/* dance begins with 1st from house left following */
	prev_element = (*list);
	/* and next dancer to house right leading */
	current_element = (*list)->next;
	while (current_element)
	{
		new = current_element->next;
		while (prev_element && current_element->n < prev_element->n)
		{
			/* lead and follow swap positions */
			if (prev_element->prev)
				prev_element->prev->next = current_element;
			else
				/* if lead makes it to house left, now head */
				*list = current_element;
			if (current_element->next)
				current_element->next->prev = prev_element;
			temp = current_element->next;
			current_element->next = prev_element;
			current_element->prev = prev_element->prev;
			prev_element->next = temp;
			prev_element->prev = current_element;
			print_list(*list);
			/* compare next pair, flowing to house left */
			prev_element = current_element->prev;
		}
		/* lead sorted to left, new cycle starts @ right leading edge */
		current_element = new;
		if (current_element)
			prev_element = current_element->prev;
	}
}
