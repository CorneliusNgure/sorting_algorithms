#include <stdio.h>
#include "sort.h"

void swap_ahead(listint_t **head, listint_t **tail, listint_t **current);
void swap_behind(listint_t **head, listint_t **tail, listint_t **current);
void cocktail_sort_list(listint_t **head);

/**
 * swap_ahead - Swap a node in a listint_t doubly-linked list
 *              list of integers with the node ahead of it.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current swapping node of the
 * + cocktail shaker algo.
 */
void swap_ahead(listint_t **head, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*head = temp;
	temp->prev = (*current)->prev;
	(*current)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}

/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 *               list of integers with the node behind it.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the current swapping node of the
 * + cocktail shaker algo.
 */
void swap_behind(listint_t **head, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*current)->next;
	(*current)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*head = *current;
	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @head: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **head)
{
	listint_t *tail, *current;
	bool sorted = false;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (tail = *head; tail->next != NULL;)
		tail = tail->next;

	while (sorted == false)
	{
		sorted = true;
		for (current = *head; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_ahead(head, &tail, &current);
				print_list((const listint_t *)*head);
				sorted = false;
			}
		}
		for (current = current->prev; current != *head;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_behind(head, &tail, &current);
				print_list((const listint_t *)*head);
				sorted = false;
			}
		}
	}
}
