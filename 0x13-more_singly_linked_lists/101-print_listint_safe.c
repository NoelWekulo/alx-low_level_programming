#include "lists.h"
#include <stdio.h>

/**
 * find_loop_length - Finds the number of nodes in the loop of a looped list.
 * @head: A pointer to the head of the list.
 * @intersection: The intersection point of the loop.
 *
 * Return: The number of nodes in the loop.
 */
size_t find_loop_length(const listint_t *head, const listint_t *intersection)
{
	size_t nodes = 1;
	const listint_t *temp = intersection;

	while (temp->next != intersection)
	{
		nodes++;
		temp = temp->next;
	}

	return (nodes);
}

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise, *hare;

	if (head == NULL || head->next == NULL)
		return (0);

	tortoise = head->next;
	hare = head->next->next;

	while (hare && hare->next)
	{
		if (tortoise == hare)
			return (find_loop_length(head, tortoise));

		tortoise = tortoise->next;
		hare = hare->next->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	size_t loop_length = looped_listint_len(head);
	const listint_t *intersection = head;

	if (loop_length == 0)
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			nodes++;
			head = head->next;
		}
	}
	else
	{
		while (head != intersection)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			nodes++;
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
		nodes++;

		while (loop_length > 1)
		{
			printf("[%p] %d\n", (void *)head->next, head->next->n);
			nodes++;
			head = head->next;
			loop_length--;
		}
	}

	return (nodes);
}
