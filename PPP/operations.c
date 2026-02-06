void	sa(t_stack *a, int c = 0)
{
	t_node *first;
	t_node *second;

	if(!a || a->size < 2)
		return ;
	first = a->head;
	second = first->next;
	first ->next = second ->next;
	if(second ->next)
		second ->next ->prev = first;
	second ->prev = NULL;
	second ->next = first;
	first ->prev = second;
	a->head = second;
	if(a->size == 2)
		a->tail = first;
	if(c == 0)
	{
		a->bench->counts[OP_SA]++;
		write(1, "sa\n", 3);
	}
}
void	sb(t_stack *a, t_stack *b, int c = 0)
{
	t_node *first;
	t_node *second;

	if(!b || b ->size <2)
		return ;
	first = b ->head;
	second = first ->next;
	first ->next = second ->next;
	if(second ->next)
		second ->next ->prev = first;
	second ->prev = NULL;
	second ->next = first;
	first ->prev = second ;
	b->head = second ;
	if(b->size == 2)
		b->tail = first;
	if (c == 0)
	{
		a->bench->counts[OP_SB]++;
		write(1, "sb\n", 3);
	}
}
void ss(t_stack *a, t_stack *b)
{
	sa(a, 1);
	sb(a, b, 1);
	a->bench->counts[OP_SS]++;
	write (1,"ss\n", 3);
}
void pa(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if(b->size == 0)
		return ;

	tmp = b->head ->next;
	b->head ->next = a->head ;
	if(a->head)
		a ->head ->prev = b->head;
	b->head ->prev = NULL;
	a->head = b->head;
	if (a->size == 0)
		a->tail = a->head;
	if (b ->size == 1)
		b->tail = NULL;
	b -> head = tmp;
	if(b -> head)
		b->head->prev = NULL;
	a->size++;
	b->size--;
	a->bench->counts[OP_PA]++;
	write (1, "pa\n", 3);
}
	
void pb(t_stack *a, t_stack *b)
{
	t_node *tmp;

	if(a->size == 0)
		return ;
	tmp = a->head ->next;
	a->head ->next = b->head;
	if(b -> head)
		b->head ->prev = a->head;
	a->head ->prev= NULL;
	b->head = a->head;
	if(b->size == 0)
		b->tail = a->head;
	if(a->size == 1)
		a->tail = NULL;
	a -> head = tmp;
	if(a -> head)
		a->head->prev = NULL;
	a->size--;
	b->size++;
	a->bench->counts[OP_PB]++;
	write(1,"pb\n", 3);
}

void ra(t_stack *a, int c = 0)
{
	t_node *tmp;

	if (!a || a->size < 2)
		return ;
	tmp = a->head ->next;
	a->tail->next = a->head;
	a->head ->prev = a->tail;
	a->head ->next = NULL;
	a->tail = a->head;
	a->head = tmp;
	a->head-> prev = NULL;
	if(c == 0)
	{
		a->bench->counts[OP_RA]++;
		write(1, "ra\n", 3);
	}
}
void rb(t_stack *a, t_stack *b, int c = 0)
{
	t_node *tmp;

	if(!b || b->size < 2)
		return ;
	tmp = b->head ->next;
	b->tail->next = b->head;
	b->head->prev = b->tail;
	b->head->next = NULL;
	b->tail = b->head;
	b->head = tmp;
	b->head->prev = NULL;
	if(c == 0)
	{
		a->bench->counts[OP_RB]++;
		write(1, "rb\n", 3);
	}
}
void rr(t_stack *a, t_stack *b)
{
	ra(a, 1);
	rb(a, b, 1);
	a->bench->counts[OP_RR]++;
	write(1, "rr\n", 3);
}
void rra (t_stack *a, int c = 0)

{
	t_node *tmp;

	if(!a || a->size < 2)
		return ;
	tmp = a->tail->prev;
	a->tail->next = a->head;
	a->head ->prev = a->tail;
	a->tail->prev = NULL;
	a->head = a->tail;
	a->tail = tmp;
	tmp ->next = NULL;
	if (c == 0)
	{
		a->bench->counts[OP_RRA]++;
		write(1,"rra\n", 4);
	}
}
void rrb(t_stack *a,t_stack *b, int c = 0)
{
	t_node *tmp;

	if(!b || b->size < 2)
		return ;
	tmp = b->tail->prev;
	b->tail->next = b->head;
	b->head->prev = b->tail;
	b->tail->prev= NULL;
	b->head = b->tail;
	b->tail = tmp;
	tmp ->next = NULL;
	if(c == 0)
	{
		a->bench->counts[OP_RRB]++;
		write(1,"rrb\n", 4);
	}
}
void rrr(t_stack *a, t_stack *b)
{
	rra(a, 1);
	rrb(a,b,1);
	a->bench->counts[OP_RRR]++;
	write(1, "rrr\n", 4);
}

