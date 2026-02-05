#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_node
{
	int value;
	int index;
	struct s_node* next;
	struct s_node* prev;
}t_node;
typedef enum e_ops
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}t_ops;
typedef enum s_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}t_strategy;
typedef struct s_bench
{
	long counts[OP_COUNT];
}t_bench;

typedef struct s_stack
{
	t_node* head;
	t_node* tail;
	int size;
	t_bench* bench;
}t_stack;

typedef struct s_algo
{
	t_strategy strategy;
	int bench;
	int set;
}t_algo;
char	**ft_split(char const *s, char c);
int has_dup(long num, t_stack* a);
int number(char* s);
long ft_atoi(char *s);
#endif 
