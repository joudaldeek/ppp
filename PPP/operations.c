void	sa(t_stack *a, int c = 0)
{
	t_node *first;
	t_node *second;

	if(!a || a->size < 2)
		return ;
	first = a->head;
	second = frist->next;
	first ->next = second ->next;
	if(second ->next)
		second ->next ->prev = first;
	second ->prev = NULL;
	second ->next = first;
	first ->prev = second;
	a->head = second;
	if(a->size == 2)
		a->tail = first;
	a->bench->count[OP_SA]++;
	if(c == 0)
		write(1, "sa\n", 3);
}
void	sb(t_stack *b, int c = 0)
{
	t_node *first;
	t_node *second;

	if(!b || b ->size <2)
		return ;
	first = b ->head;
	second = first ->next;
	frist ->next = second ->next;
	if(second ->next)
		second ->next ->prev = first;
	second ->prev = NULL;
	second ->next = first;
	first ->prev = second ;
	a->head = second ;
	if(a->size == 2)
		a->tail = first;
	a ->bench ->count [OP_SB]++;
	if (c == 0)
		write(1, "sb\n", 3);
}_stack *b, int c = 0)
{
	t_node *first;
	t_node *second;

	if(!b || b ->size <2)
		return ;
	first = b ->head;
	second = first ->next;
	frist ->next = second ->next;
	if(second ->next)
		second ->next ->prev = first;
	second ->prev = NULL;
	second ->next = first;
	first ->prev = second ;
	a->head = second ;
	if(a->size == 2)
		a->tail = first;
	a ->bench ->count [OP_SB]++;
	if (c == 0)
		write(1, "sb\n", 3);
}
void ss(t_stack *a, t_stack *b)
{
	sa(a, 1);
	sb(b, 1);
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
	if (b ->size == 1)
		b->tail = NULL;
	b -> head = tmp;
	a->size++;
	b->size--;
	a->bench->count[OP_PA]++;
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
	if(a->size == 1)
		a->tail = NULL;
	a -> head = tmp;
	a->size--;
	b->size++;
	a->bench->count[OP_PB]++;
	write(1,"pb\n", 3);
}
























