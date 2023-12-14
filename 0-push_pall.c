#include "monty.h"
#include <stdlib.h>

/**
 * push_pall - A function that adds node to the stack
 * @head: Input
 * @cnt: input
 * Return: void
*/

void push_pall(stack_t **head, unsigned int cnt)
{
	int push, pall, sl;

	push = 0;
	pall = 0;
	sl = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			pall++;
		for (; bus.arg[pall] != '\0'; pall++)
		{
			if (bus.arg[pall] > 57 || bus.arg[pall] < 48)
				sl = 1;
		}
		if (sl == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", cnt);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", cnt);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	push = atoi(bus.arg);
	if (bus.lifi == 0)
	addnode(head, push);
	else
		addqueue(head, push);
}
