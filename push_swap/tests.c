#include "push_swap.c"

int		exist(t_pile *apile)
{
	if ((apile) && (apile + 1)
		return (1);
	return (0);
}

//si des chiffres sont egaux, retourne -1
int		isnt_same(t_pile *p)
{
	t_pile	*memp;
	t_pile	*verp;

	memp = p;
	while (p != NULL)
	{
		verp = p;
		while (verp->push != NULL)
		{
			verp = verp->push;
			if (verp->i == p->i)
				puterror("Les nombres ne sont pas tous différents.");
		}
		p = p->push;
	}
	p = memp;
	return(0);
}
//is_order renvoit -1 quand la liste est triée ou l'emplacement de l'echelon non classé.
int		is_order(t_pile *p)
{
	int	i;
	t_pile	*memp;

	memp = p;
	i = 0;
	while (p->v < p->push)
	{
		p++;
		i++;
	}
	if (p->push == NULL)
	{
		p = memp;
		return (-1);
	}
	p = memp;
	return(i);

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

int		long_pile(t_pile *p)
{
	t_pile	*memp;
	int		i;

	i = 0;
	memp = p;
	while (p != NULL)
	{
		p = p->push;
		i++;
	}
	p = memp;
	return(i);
}