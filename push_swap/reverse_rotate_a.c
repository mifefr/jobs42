#include "push_swap.h"

void	reverse_rotate_a.c(t_pile *pile)
{
	t_pile	*pilebeg;

	pilebeg = pile;
	while (pile->next != NULL)
		pile = pile->next;
	pile->prev->next = NULL;
	pile->prev = NULL;
	pile->next = pilebeg;
	pile->next->prev = pile;
}