
#ifndef PUSH_SWAP_C

# define PUSH_SWAP_C

typedef	struct	s_pile
{
	int				v;
	struct s_list	*push;
	struct s_list	*pop;
}				t_pile;


int		ft_puterror(char *str);
void	rotate(t_pile *pile);
void	reverse_rotate(t_pile *pile);
t_pile	*swap(t_pile *origin);
void	push_a(t_pile	*pilea, t_pile *pileb);
void	push_b(t_pile	*pileb, t_pile *pilea);
int		processing(t_pile pa, t_pile pb);
int		long_pile(t_pile *p);

#endif