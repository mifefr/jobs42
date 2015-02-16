#include "push_swap.c"

int		exist(t_pile *apile)
{
	if ((apile) && (apile + 1)
		return (1);
	return (0);
}

int		is_order(t_pile *p)
{
	while (p->v < p->push)
		p++;
	if (p->push == NULL)
		return (1);

}

int		last(t_pile *apile)
{
	t_pile *begpile;
	int i;

	i = 0;
	begpile = apile;
	
	while (apile + 1)
	{
		apile++;
	}
	if (apile->v > apile->pop->v)
		i = 1;
	apile = begpile;
	return (i);
}