#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (monty_file.arg)
	{
		if (monty_file.arg[0] == '-')
			j++;
		for (; monty_file.arg[j] != '\0'; j++)
		{
			if (monty_file.arg[j] > 57 || monty_file.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(monty_file.file);
			free(monty_file.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(monty_file.file);
		free(monty_file.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(monty_file.arg);
	if (monty_file.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
