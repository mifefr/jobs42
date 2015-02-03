#include "push_swap.c"

t_pile	*swap_a(t_pile *origin)
{
	t_pile	*ret;

	ret = origin;
	origin = origin->next;
	origin->next = ret;
	origin->next->next = ret->next->next;
	return (origin);
}