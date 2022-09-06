#include "main.h"

/**
 * create_first_node - the creation of the initial node
 * @head: pointer to head node
 * @str: str to be used to poplate first node details
 *
 * Return: pointer to first node or NULL
 */
list_t *create_first_node(path_t **head, char *name, char *val)
{
	path_t *first;
	char *n, *v;

	first = malloc(sizeof(path_t));
	n = strdup((char *)str);
	v = strdup((char *)str);
	if (first == NULL || n == NULL || v == NULL)
	{
		/*  Malloc test and strdup test*/
		unix_error("Malloc error");
	}

	first->name = n;
	first->val = v;
	first->next = NULL;
	head = first;
	return (head);
}

/**
 * find_tail - traverse a linked list and find
 * the first element in a linked list to point to
 * a null value
 * @c: pointer to the list head which is also used
 * in recursive calls as a pointer to the current element
 *
 * Return: pointer to the element we're looking for
 */
list_t *find_tail(const path_t *c)
{
	if (c == NULL)
	{
		printf("Haifai !!\n");
		return (NULL);
	}
	if (c->next == NULL)
	{
		return ((path_t *)c);
	}

	return (find_tail(c->next));
}

/**
 * add_node_end - add a node at the end of our linked list
 * @head: pointer to the pointer of our head node
 * @str: string used to populate new tail node
 *
 * Return: pointer to added node or NULL
 * Description: First we check if our head node points to a null
 * in which case we create a first node using the given information
 * and make the head of our node point to it
 * otherwise, we find the current tail node of our list
 * which is expected to point to a null as next
 * this tail node will now point to our new node and our current node will
 * point to a null since it's the new tail node of the linked list
 */
path_t *add_node_end(path_t **head, char *name, char *val)
{
	char *n, *v;
	path_t *new_tail, *current_tail;

	new_tail = malloc(sizeof(path_t));
	n = malloc(sizeof(char) * _strlen(name));
	v = malloc(sizeof(char) * _strlen(val));
	if (v == NULL || n == NULL || new_tail == NULL)
	{
		free(new_tail);
		free(n);
		free(v);
		unix_error("Malloc Error");
	}

	/**
	 * one pitfall is a head which points to NULL (empty linked list)
	 * so we check to see if it should be the first node 2 add
	 */
	if (*head == NULL)
	{
		/* create the first node if head is null */
		*head = create_first_node(*head, name, val);
		free(new_tail);
		return (*head);
	}
	/**
	 * create a new node once mem is ready, and it is confirmed
	 * that head node does not point to a NULL
	 */
	new_tail->name = n;
	new_tail->val = v;
	new_tail->next = NULL;

	/* find the current tail in our list with at least one node */
	current_tail = find_tail(*head);
	/* we then use this tail and set it's next to our new tail */
	current_tail->next = new_tail;
	return (new_tail);
}
