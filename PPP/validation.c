#include "push_swap.h"

int number(char* s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return(0);
		i++;
	}
	return (1);
}

int has_dup(long num, t_stack* a)
{
	t_node* tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;

	}
	return (0);
} 
