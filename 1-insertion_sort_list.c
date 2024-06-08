#include "sort.h"
/**
 * swap_nodes - To swap node in a linked list
 * @list: double pointer to node
 * @node1: for storing variables
 * @node2: for storing variables
 *
 * Return: To return a swaped list
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
	{
		(*node1)->prev->next = node2;
	}
	else
		*list = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}








/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order
 * @list: a double pointer  tothe function
 *
 * Return: To return sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *compare, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		compare = current->prev;
		while (compare != NULL && current->n < compare->n)
		{
			swap_nodes(list, &compare, current);
			print_list((const listint_t *) *list);
		}
	}
}
