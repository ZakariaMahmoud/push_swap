#include "push_swap.h"

int int_len(long number)
{
	int i;
	int len;

	len = 1;
	i = 10;
	if (number < 0)
	{
		len++;
		number *= -1;
	}
	while (number / i > 0)
	{
		i *= 10;
		len++;
	}	
	return (len);
}
void print_content(int n, int size, char *color)
{
	int n_len = int_len(n);
	printf("%s %d", color, n);
	while(n_len++ < size)
		printf(" ");
	printf("\e[0m");
}

void header_a_b(char *color)
{
	char *color_end = "\e[0m";
	printf("%s|---------------------------------------------------|%s\n", color, color_end);	
	printf("%s|%s         Stack A         %s|%s         Stack B         %s|%s\n", color, color_end, color, color_end, color, color_end);
	printf("%s|---------------------------------------------------|%s\n", color, color_end);
}

void header_one(char *color, char c)
{
	char *color_end = "\e[0m";
	printf("%s|-------------------------|%s\n", color, color_end);	
	printf("%s|%s         Stack %c         %s|%s\n", color, color_end,  c, color, color_end);
	printf("%s|-------------------------|%s\n", color, color_end);
}

void	print_one_stack(t_stack *stack, int debug, char stack_name)
{
	char *color_end = "\e[0m";
	char *color;

	if (stack_name == 'A')
		color = "\e[1;31m";
	else 
		color = "\e[1;32m";
	int top = 0;
	header_one(color, stack_name);
	while (stack)
	{
		printf("%s|%s", color, color_end);
		if(top == 0)
		{
			printf("\e[1;93m*%s", color_end);
			print_content(stack->content, 23, color);
			top++;
		}
		else
			print_content(stack->content, 24, color);
		printf("%s|%s\n", color, color_end);
		stack = stack->next;
	}
	printf("%s|-------------------------|%s\n", color, color_end);
	if (debug == 1)
			getchar();
	
}

void print_stack(t_stack *stack_a, t_stack *stack_b, int debug)
{
	debug = 0;
	if (!stack_a && stack_b)
		print_one_stack(stack_b, debug, 'B');
	else if (stack_a && !stack_b)
		print_one_stack(stack_a, debug, 'A');
	else 
	{
		char *color = "\e[1;34m";
		char *color_end = "\e[0m";
		int	a_len = ft_lstsize(stack_a);
		int	b_len = ft_lstsize(stack_b);
		int top = 0;
		t_stack *tmp_a = stack_a, *tmp_b = stack_b;
		header_a_b(color);
		if (a_len >= b_len)
		{
			while (tmp_a)
			{
				printf("%s|%s", color, color_end);
				if(top == 0)
				{
					printf("\e[1;93m*%s", color_end);
					print_content(tmp_a->content, 23, "\e[1;31m");
					top++;
				}
				else
					print_content(tmp_a->content, 24, "\e[1;31m");
				printf("%s|%s", color, color_end);
				if (a_len <= b_len)
				{
					if(top >=0)
					{
						printf("\e[1;93m*\e[0m");
						print_content(tmp_b->content, 23, "\e[1;32m");
						top = -1;
					}
					else
						print_content(tmp_b->content, 24, "\e[1;32m");
					printf("%s|%s", color, color_end);
					tmp_b = tmp_b->next;
				}
				else
					printf("                         %s|%s", color, color_end);
				printf("\n");
				tmp_a = tmp_a->next;
				a_len--;
			}
		}
		else
		{
			top = 0;
			while (tmp_b)
			{
				printf("%s|%s", color, color_end);
				if(top == 0)
				{
					printf("\e[1;93m*%s", color_end);
					print_content(tmp_b->content, 23, "\e[1;31m");
					top++;
				}
				else
					print_content(tmp_b->content, 24, "\e[1;31m");
				printf("%s|%s", color, color_end);
				if (b_len <= a_len)
				{
					if(top >=0)
					{
						printf("\e[1;93m*\e[0m");
						print_content(tmp_a->content, 23, "\e[1;32m");
						top = -1;
					}
					else
						print_content(tmp_a->content, 24, "\e[1;32m");
					printf("%s|%s", color, color_end);
					tmp_a = tmp_a->next;
				}
				else
					printf("                         %s|%s", color, color_end);
				printf("\n");
				tmp_b = tmp_b->next;
				b_len--;
			}
		}
		printf("%s|---------------------------------------------------|%s\n", color, color_end);
		if (debug == 1)
			getchar();
	}
}