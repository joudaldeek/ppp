#include <stdio.h>
#include "push_swap.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int error()
{
	write(2,"error\n", 6);
	return(0);
}
void free_split(char **s)
{
	int i = 0;
	if(!s)
		return;
	while(s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int set_strategy(t_algo* algo, char* flag)
{
    if (algo->set)
        return (0);
    if (strcmp(flag, "--simple") == 0)
        algo->strategy = SIMPLE;
    else  if (strcmp(flag, "--medium") == 0)
        algo->strategy = MEDIUM;
    else  if (strcmp(flag, "--complex") == 0)
        algo->strategy = COMPLEX;
    else  if (strcmp(flag, "--adaptive") == 0)
        algo->strategy = ADAPTIVE;
    else
        return (-1);
    algo->set = 1;
    return (1);
}
t_algo parse_flags(int* argc, char*** argv)
{
    t_algo algo;
    int i;
    int j;
    algo.strategy = ADAPTIVE;
    algo.bench = 0;
    algo.set = 0;
    i = 1;
    while (i < *argc)
    {
        if (set_strategy(&algo, (*argv)[i]) > 0);
        else if (strcmp((*argv)[i], "--bench") == 0)
            algo.bench = 1;
        else
            break;
        j = i;
        while (j < *argc - 1)
        {
            (*argv)[j] = (*argv)[j + 1];
            j++;
        }
        (*argc)--;
    }
    return (algo);
}
void push_stack(t_stack* a, long num)
{
    t_node* new;

    new = malloc(sizeof(t_node));
    if (!new)
        return;
    new->value = num;
    new->index = -1;
    new->next = NULL;
    new->prev = NULL;

    if (a->size == 0)
    {
        a->head = new;
        a->tail = new;
    }
    else
    {
        new->next = a->head;
        a->head->prev = new;
        a->head = new;
    }
    a->size++;
}
int get_numbers(int argc, char** argv, t_stack* a)
{
    int i;
    int j;
    char** tmp;

    i = 1;
    while (i < argc)
    {
        tmp = ft_split(argv[i], ' ');
        if (!tmp || !tmp[0])
            return (0);
        j = 0;
        while (tmp[j])
        {
            if (!number(tmp[j]) || has_dup(ft_atoi(tmp[j]), a))
            {
                free_split(tmp);
                return (0);
            }
            if (ft_atoi(tmp[j]) < INT_MIN || ft_atoi(tmp[j]) > INT_MAX)
                return(0);
            push_stack(a, ft_atoi(tmp[j]));
            j++;
        }
        free_split(tmp);
        i++;
    }
    return (1);
}
void    init_stack(t_stack* s)
{
    s->head = NULL;
    s->tail = NULL;
    s->size = 0;
    s->bench = malloc(sizeof(t_bench));
    if (s->bench)
        memset(s->bench->counts, 0, sizeof(s->bench->counts));
}
void print_stack(t_stack* a)
{
    t_node* tmp = a->head;

    printf("Stack A (size = %d):\n", a->size);
    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}
void sort_p(int *p, int size)
{
	int i;
	int tmp;
	int swapped;
	
	while (n > 1)
	{
		swapped = 0;
		i = 0;
		while (i < n -1)
		{
			if(a[i] > a[i + 1])
			{
				tmp = a[i];
				a[i] = a[i + 1]; 
				a[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
		if(!swapped)
			break;
		n--;
	}
}


void set_index(t_node *node, int *p, int size)
{
	int i;
	while (node)
	{
		i = 0;
		while (i<size)
		{
			if(p[i] == node->value)
			{
				node->index = i;
				break;
			}
			i++;
		}
		node = node -> next;
	}
}
void indexing (t_stack *a)
{
	int *p;
	int i;
	t_node *tmp;

	i = 0;
	p = malloc (a->size *sizeof(int));
	tmp = a->head;
	while (tmp)
	{
		p[i] = tmp ->value;
		i++;
		tmp = tmp ->next;
	}
	sort_p(p, a->size);
	tmp = a->head;
	set_index(a->head, p, a->size);
	free(p);
}



int main(int argc, char** argv)
{
    t_stack a;
    t_stack b;
    t_algo algo;
    float disorder;

    init_stack(&a);
    init_stack(&b);
    
    if (argc < 2)
        return (0);
    algo = parse_flags(&argc, &argv);
    if (!get_numbers(argc, argv, &a))
        return (error());
    indexing(a);
    print_stack(&a);

    return (0);

}

