#ifndef LIBFTS_H
# define LIBFTS_H

# include <stdlib.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
int		ft_puts(const char *s);
size_t	ft_strlen(const char *s);
int		ft_isupper(int c);
int		ft_islower(int c);
void	ft_putstr(const char *s);
void	ft_putchar(char c);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);

#endif