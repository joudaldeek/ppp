#include "push_swap.h"

float compute_disorder(t_stack *a)
{
	 t_stack *i;
	 t_stack *j;
	 long mistakes; 
	 long total_pairs;

	 mistakes = 0;
	 total_pairs = 0;
	 i = 1;
	 while (i)
	 {
		 j = i ->next;
		 while (j)
		 {
			 total_pairs++;
			 if(i -> value > j -> value)
				 mistakes++;
			 j = j -> next;
		 }
		 i = i -> next;
	 }
	 if(total_pairs == 0)
		 return(0);
	 return((float)mistakes/ (float)total_pairs);
}

int sorted (t_stack *a)
{
	t_node *tmp;

	if(a -> size < 2)
		return (1);
	tmp = a->head;
	while (tmp -> next)
	{
		if(tmp ->value > tmp -> next -> value)
			return(0);
		tmp = tmp ->next;
	}
	retur(1);
}

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
