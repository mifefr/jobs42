#include "push_swap.h"

void	rotate_b.c(t_pile *pile)
{
	t_pile	*pilebeg;
	t_pile	*pileend;

	pileend = pile;
	pileend->next = NULL;
	pile->next->prev = NULL;
	pilebeg = pile->next;
	while (pile->next != NULL)
		pile = pile->next;
	pile->next = pileend;
	pile = pilebeg;
}