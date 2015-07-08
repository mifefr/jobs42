/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 21:49:28 by abruyere          #+#    #+#             */
/*   Updated: 2015/05/26 19:13:09 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <ctype.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "includes/libfts.h"

////////* COLOR */////////
#define RED "\033[31m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[00m"

# define SIGN 1

# define USE_FT_ISALPHA
# define USE_FT_ISDIGIT
# define USE_FT_ISALNUM
# define USE_FT_ISASCII
# define USE_FT_ISPRINT
# define USE_FT_TOUPPER
# define USE_FT_TOLOWER
# define USE_FT_BZERO
# define USE_FT_STRCAT
# define USE_FT_PUTS
# define USE_FT_STRLEN
# define USE_FT_MEMSET
# define USE_FT_MEMCPY
# define USE_FT_STRDUP

////////* BONUS */////////
//# define USE_FT_PUTCHAR
//# define USE_FT_PUTSTR
//# define USE_FT_ISUPPER
//# define USE_FT_ISLOWER
//# define USE_FT_STRNEW

int    printf_result(int my_func, int system_func);
int    printf_result_str(char *my_str, char *sys_str);
char   *test_str_printf(char *string, int fdp, int (*function)(int, const char *, ...));
char   *test_str_printf_c(int c, int fdp, int (*function)(int, const char *, ...));
int		ft_tolower(int c);

#ifdef USE_FT_STRDUP
int     test_strdup(void)
{
    int     i;
    char   *c;

	c = "AbC";
    i = 0;
    printf(CYAN"\n[ft_strdup]:\n"RESET);
    i += printf_result_str(ft_strdup("aaaaa"), "aaaaa");
    printf("#test1: Basic\n");
    i += printf_result_str(ft_strdup(""), "");
    printf("#test2: Basic\n");
    i += printf_result_str(ft_strdup(c), c);
    printf("#test3: Basic\n");
    if (i == 3)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_STRNEW
int test1(void)
{
    char    *str;
    char    *t;
    int i;

    i = 0;
    str = ft_strnew(100);
    t = malloc(101);
    bzero(t, 101);
    i += printf_result(memcmp(str, t, 101), 00);
    printf("#test1: Basic\n");
    return (i);

}

int test2(void)
{
    int i;

    i = 0;
    i += printf_result_str(ft_strnew(0), NULL);
    printf("#test2: 0\n");
    return (i);
}

int test3(void)
{
    int i;
    char *str;

    i = 0;
    str = ft_strnew(2147483647);
    memset(str, 'a', 2147483647);
    i += printf_result(strlen(str), 2147483647);
    printf("#test3: int max\n");
    return (i);
}

int     test_strnew(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_strnew]:\n"RESET);
    i += test1() + test2() + test3();
    if (i == 3)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_STRCAT
int    test_strcat(void)
{
    int i;
    char *dest;

    i = 0;
    dest = (char *)malloc(sizeof(char) * 9);
    printf(CYAN"\n[ft_strcat]:\n"RESET);
    bzero(dest, 9);
    ft_strcat(dest, "");
    ft_strcat(dest, "Bon");
    ft_strcat(dest, "j");
    ft_strcat(dest, "our.");
    ft_strcat(dest, "");
    i += printf_result(strcmp(dest, "Bonjour."), 0);
    printf("#test1: Multi test\n");
    if (i == 1)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_PUTS
char    *test_str_puts(char *string, int (*function)(const char *))
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    readbuffer[strlen(string)];

        pipe(fd);
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                close(fd[0]);
                dup2(fd[1], 1);
                close(fd[1]);
                      // write(fd[1], string, (strlen(string)));
                function(string);
                exit(0);
        }
        else
        {
                close(fd[1]); /* close the unused read side */
                 dup2(fd[0], 0); /* connect the write side with stdout */
                close(fd[0]);
                nbytes = read(0, readbuffer, strlen(string));
                readbuffer[nbytes] = 0;
                return (strdup(readbuffer));
        }
        return(NULL);
}

int    test_puts(void)
{
    int i;
    char buf[10000];
    int     out;
    int     p[2];
    int     ret;

    i = 0;
    printf(CYAN"\n[ft_puts]:\n"RESET);
    out = dup(1);
    pipe(p);
    dup2(p[1], 1);
    ft_puts("aaa");
    ft_puts(NULL);
    dup2(out, 1);
    ret = read(p[0], buf, 10000);
    buf[ret] = 0;
    close(p[0]);
    close(p[1]);
    close(out);
    i += printf_result_str(buf, "aaa\n(null)\n");
    printf("#test1: null\n");
    i += printf_result_str(test_str_puts("", ft_puts), test_str_puts("", puts));
    printf("#test2: nothing\n");
    i += printf_result_str(test_str_puts("Bon\\0jour", ft_puts), test_str_puts("Bon\\0jour", puts));
    printf("#test1: \\0\n");
    if (i == 3)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_PUTCHAR
char    *test_str_putchar(int c, void (*function)(char))
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    readbuffer[1];

        pipe(fd);
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                close(fd[0]);
                dup2(fd[1], 1);
                close(fd[1]);
                      // write(fd[1], string, (strlen(string)));
                function(c);
                exit(0);
        }
        else
        {
                close(fd[1]); /* close the unused read side */
                dup2(fd[0], 0); /* connect the write side with stdout */
                close(fd[0]);
                nbytes = read(0, readbuffer, 1);
                readbuffer[nbytes] = 0;
                return (strdup(readbuffer));
        }
        return(NULL);
}

int    test_putchar(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_putchar]:\n"RESET);
    i += printf_result_str(test_str_putchar('B', ft_putchar), "B");
    printf("#test1: basic test\n");
    i += printf_result_str(test_str_putchar(' ', ft_putchar), " ");
    printf("#test2: nothing\n");
    i += printf_result_str(test_str_putchar('\n', ft_putchar), "\n");
    printf("#test1: \\0\n");
    if (i == 3)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_STRLEN
int     test_million_chars_string(void)
{
    int test_len = 1000 * 1000;
    char str[test_len];

    memset(str, 'a', test_len);
    str[test_len - 1] = '\0';
    return (printf_result(ft_strlen(str), strlen(str)));
}

int    test_strlen(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_strlen]:\n"RESET);
    i += printf_result(ft_strlen("Bonjour"), strlen("Bonjour"));
    printf("#test1: basic test\n");
    i += printf_result(ft_strlen(""), strlen(""));
    printf("#test2: none\n");
    i += printf_result(ft_strlen("\0"), strlen("\0"));
    printf("#test3: \\0 \n");
    i += test_million_chars_string();
    printf("#test4:  \n");
    if (i == 4)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_PUTSTR
char    *test_str_fd(char *string, void (*function)(const char *))
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    readbuffer[strlen(string)];

        pipe(fd);
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                close(fd[0]);
                dup2(fd[1], 1);
                close(fd[1]);
                      // write(fd[1], string, (strlen(string)));
                function(string);
                exit(0);
        }
        else
        {
                close(fd[1]); /* close the unused read side */
                 dup2(fd[0], 0); /* connect the write side with stdout */
                close(fd[0]);
                nbytes = read(0, readbuffer, strlen(string));
                readbuffer[nbytes] = 0;
                return (strdup(readbuffer));
        }
        return(NULL);
}

int     test_putstr(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_putstr]:\n"RESET);
    i += printf_result_str(test_str_fd("Bonjour", ft_putstr), "Bonjour");
    printf("#test1: basic test\n");
    i += printf_result_str(test_str_fd("", ft_putstr), "");
    printf("#test2: nothing\n");
    i += printf_result_str(test_str_fd("Bon\\0jour", ft_putstr), "Bon\\0jour");
    printf("#test1: \\0\n");
    if (i == 3)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_MEMSET
int    test_memset(void)
{
    int i;
    char str[] = "destination";
    int src = 46;

    i = 0;
    printf(CYAN"\n[ft_memset]:\n"RESET);
    i += printf_result_str((void *)ft_memset(str, src, 7), (void *)memset(str, src, 7));
    printf("#test1: basic test\n");
    i += printf_result_str((void *)ft_memset(str, src, 0), (void *)memset(str, src, 0));
    printf("#test2: n == 0\n");
    i += printf_result_str((void *)ft_memset(str, src, 10), (void *)memset(str, src, 10));
    printf("#test3: n > src\n");
    if (i == 3)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_MEMCPY
int    test_memcpy(void)
{
    int i;
    char str[] = "destination";
    char src[] = "source";

    i = 0;
    printf(CYAN"\n[ft_memcpy]:\n"RESET);
    i += printf_result_str((void *)ft_memcpy(str, src, 7), (void *)memcpy(str, src, 7));
    printf("#test1: basic test\n");
    i += printf_result_str((void *)ft_memcpy(str, src, 0), (void *)memcpy(str, src, 0));
    printf("#test2: n == 0\n");
    i += printf_result_str((void *)ft_memcpy(str, src, 10), (void *)memcpy(str, src, 10));
    printf("#test3: n > src\n");
    if (i == 3)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_BZERO
int     test_bzero(void)
{
    int i;
    char str[] = "Bonjour patrick";
    char str2[] = "Bonjour patrick";
    char zero_in_str[] = "Bonj0ur patrick";
    char zero_in_str2[] = "Bonj0ur patrick";

    i = 0;
    printf(CYAN"\n[ft_bzero]:\n"RESET);
    ft_bzero((void *)str, 15);
    bzero((void *)str2, 15);
    i += printf_result_str(str, str2);
    printf("#test1: basic test\n");
    ft_bzero((void *)str, 0);
    bzero((void *)str2, 0);
    i += printf_result_str(str, str2);
    printf("#test2: n == 0\n");
    ft_bzero((void *)str, 30);
    bzero((void *)str2, 30);
    i += printf_result_str(str, str2);
    printf("#test3: n > str\n");
    ft_bzero((void *)zero_in_str, 8);
    bzero((void *)zero_in_str2, 8);
    i += printf_result_str(zero_in_str, zero_in_str2);
    printf("#test4: zero in str\n");
    if (i == 4)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_TOLOWER
int     test_tolower(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_tolower]:\n"RESET);
    i += printf_result(ft_tolower(65), tolower(65));
    printf("#test1: lower cara\n");
    i += printf_result(ft_tolower(90), tolower(90));
    printf("#test2: lower cara 2\n");
    i += printf_result(ft_tolower(97), tolower(97));
    printf("#test3: toupper cara\n");
    i += printf_result(ft_tolower(122), tolower(122));
    printf("#test4: toupper cara 2\n");
    i += printf_result(ft_tolower(123), tolower(123));
    printf("#test5: no alpha\n");
    i += printf_result(ft_tolower(96), tolower(96));
    printf("#test6: no alpha 2\n");
    i += printf_result(ft_tolower(91), tolower(91));
    printf("#test7: no alpha 3\n");
    i += printf_result(ft_tolower(64), tolower(64));
    printf("#test8: no alpha 4\n");
    i += printf_result(ft_tolower(53), tolower(53));
    printf("#test9: no alpha 5\n");
    i += printf_result(ft_tolower('\n'), tolower('\n'));
    printf("#test10: back n\n");
    if (i == 10)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_TOUPPER
int     test_toupper(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_toupper]:\n"RESET);
    i += printf_result(ft_toupper(65), toupper(65));
    printf("#test1: lower cara\n");
    i += printf_result(ft_toupper(90), toupper(90));
    printf("#test2: lower cara 2\n");
    i += printf_result(ft_toupper(97), toupper(97));
    printf("#test3: toupper cara\n");
    i += printf_result(ft_toupper(122), toupper(122));
    printf("#test4: toupper cara 2\n");
    i += printf_result(ft_toupper(123), toupper(123));
    printf("#test5: no alpha\n");
    i += printf_result(ft_toupper(96), toupper(96));
    printf("#test6: no alpha 2\n");
    i += printf_result(ft_toupper(91), toupper(91));
    printf("#test7: no alpha 3\n");
    i += printf_result(ft_toupper(64), toupper(64));
    printf("#test8: no alpha 4\n");
    i += printf_result(ft_toupper(53), toupper(53));
    printf("#test9: no alpha 5\n");
    i += printf_result(ft_toupper('\n'), toupper('\n'));
    printf("#test10: back n\n");
    if (i == 10)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_ISPRINT
int     test_isprint(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_isprint]:\n"RESET);
    i += printf_result(ft_isprint(39), isprint(39));
    printf("#test1: print cara\n");
    i += printf_result(ft_isprint(126), isprint(126));
    printf("#test2: print cara 2\n");
    i += printf_result(ft_isprint(0), isprint(0));
    printf("#test3: first print cara\n");
    i += printf_result(ft_isprint(126), isprint(126));
    printf("#test4: last print cara\n");
    i += printf_result(ft_isprint(128), isprint(128));
    printf("#test5: no ascii\n");
    i += printf_result(ft_isprint(31), isprint(31));
    printf("#test6: no ascii 2\n");
    i += printf_result(ft_isprint(0), isprint(0));
    printf("#test7: no ascii 3\n");
    i += printf_result(ft_isprint('\n'), isprint('\n'));
    printf("#test8: back n\n");
    if (i == 8)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_ISASCII
int     test_isascii(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_isascii]:\n"RESET);
    i += printf_result(ft_isascii(61), isascii(61));
    printf("#test1: alpha\n");
    i += printf_result(ft_isascii('z'), isascii('z'));
    printf("#test2: alpha 2\n");
    i += printf_result(ft_isascii(0), isascii(0));
    printf("#test3: first cara\n");
    i += printf_result(ft_isascii(127), isascii(127));
    printf("#test4: last print cara\n");
    i += printf_result(ft_isascii(177), isascii(177));
    printf("#test5: last cara\n");
    i += printf_result(ft_isascii(178), isascii(178));
    printf("#test6: no ascii\n");
    i += printf_result(ft_isascii(128), isascii(128));
    printf("#test7: alpha 3\n");
    i += printf_result(ft_isascii(-1), isascii(-1));
    printf("#test8: no ascii 2\n");
    if (i == 8)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_ISALNUM
int     test_isalnum(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_isalnum]:\n"RESET);
    i += printf_result(ft_isalnum('a'), isalnum('a'));
    printf("#test1: alpha\n");
    i += printf_result(ft_isalnum('z'), isalnum('z'));
    printf("#test2: alpha 2\n");
    i += printf_result(ft_isalnum('A'), isalnum('A'));
    printf("#test3: alpha 3\n");
    i += printf_result(ft_isalnum('Z'), isalnum('Z'));
    printf("#test4: alpha 4\n");
    i += printf_result(ft_isalnum('9'), isalnum('9'));
    printf("#test5: digi\n");
    i += printf_result(ft_isalnum('0'), isalnum('0'));
    printf("#test6: digit 2\n");
    i += printf_result(ft_isalnum('\n'), isalnum('\n'));
    printf("#test7: backslash n\n");
    i += printf_result(ft_isalnum('\0'), isalnum('\0'));
    printf("#test8: backslash 0\n");
    if (i == 8)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_ISLOWER
int     test_islower(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_islower]:\n"RESET);
    i += printf_result(ft_islower('a'), 1);
    printf("#test1: min\n");
    i += printf_result(ft_islower('z'), 1);
    printf("#test2: min 2\n");
    i += printf_result(ft_islower('A'), 0);
    printf("#test3: maj\n");
    i += printf_result(ft_islower('Z'), 0);
    printf("#test4: maj 2\n");
    i += printf_result(ft_islower('\n'), 0);
    printf("#test5: backslash n\n");
    i += printf_result(ft_islower('\0'), 0);
    printf("#test6: backslash 0\n");
    if (i == 6)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_ISUPPER
int     test_isupper(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_isupper]:\n"RESET);
    i += printf_result(ft_isupper('a'), 0);
    printf("#test1: min\n");
    i += printf_result(ft_isupper('z'), 0);
    printf("#test2: min 2\n");
    i += printf_result(ft_isupper('A'), 1);
    printf("#test3: maj\n");
    i += printf_result(ft_isupper('Z'), 1);
    printf("#test4: maj 2\n");
    i += printf_result(ft_isupper('\n'), 0);
    printf("#test5: backslash n\n");
    i += printf_result(ft_isupper('\0'), 0);
    printf("#test6: backslash 0\n");
    if (i == 6)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_ISALPHA
int     test_isalpha(void)
{
    int i;

    i = 0;
    printf(CYAN"\n[ft_isalpha]:\n"RESET);
    i += printf_result(ft_isalpha('a'), isalpha('a'));
    printf("#test1: alpha\n");
    i += printf_result(ft_isalpha('z'), isalpha('z'));
    printf("#test2: alpha 2\n");
    i += printf_result(ft_isalpha('A'), isalpha('A'));
    printf("#test3: alpha maj\n");
    i += printf_result(ft_isalpha('Z'), isalpha('Z'));
    printf("#test4: alpha maj 2\n");
    i += printf_result(ft_isalpha('\n'), isalpha('\n'));
    printf("#test5: backslash n\n");
    i += printf_result(ft_isalpha('\0'), isalpha('\0'));
    printf("#test6: backslash 0\n");
    if (i == 6)
        return (1);
    return (0);
}
#endif

#ifdef USE_FT_ISDIGIT
int     test_isdigit(void)
{
    int i;

    i = 0;
    printf(CYAN"\n\n[ft_isdigit]:\n"RESET);
    i += printf_result(ft_isdigit('0'), isdigit('0'));
    printf("#test1: digit\n");
    i += printf_result(ft_isdigit('a'), isdigit('a'));
    printf("#test2: no digit\n");
    i += printf_result(ft_isdigit('\n'), isdigit('\n'));
    printf("#test3: backslash n\n");
    i += printf_result(ft_isdigit('\0'), isdigit('\0'));
    printf("#test4: backslash 0\n");
    if (i == 4)
        return (1);
    return (0);
}
#endif

char    *test_str_printf_c(int c, int fdp, int (*function)(int, const char *, ...))
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    readbuffer[1];

        pipe(fd);
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                close(fd[0]);
                dup2(fd[1], fdp);
                close(fd[1]);
                      // write(fd[1], string, (strlen(string)));
                function(fdp, "%c", c);
                exit(0);
        }
        else
        {
                close(fd[1]); /* close the unused read side */
                 dup2(fd[0], 0); /* connect the write side with stdout */
                close(fd[0]);
                nbytes = read(0, readbuffer, 1);
                readbuffer[nbytes] = 0;
                // printf("%s\n", readbuffer);
                return (strdup(readbuffer));
        }
        return(NULL);
}

char    *test_str_printf(char *string, int fdp, int (*function)(int, const char *, ...))
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    readbuffer[strlen(string)];

        pipe(fd);
        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                close(fd[0]);
                dup2(fd[1], fdp);
                close(fd[1]);
                      // write(fd[1], string, (strlen(string)));
                function(fdp, "%s", string);
                exit(0);
        }
        else
        {
                close(fd[1]); /* close the unused read side */
                 dup2(fd[0], 0); /* connect the write side with stdout */
                close(fd[0]);
                nbytes = read(0, readbuffer, strlen(string));
                readbuffer[nbytes] = 0;
                // printf("%s\n", readbuffer);
                return (strdup(readbuffer));
        }
        return(NULL);
}

int    printf_result_str(char *my_str, char *sys_str)
{
    // printf("my: %s\nsys: %s", my_str, sys_str);
    usleep(50000);
    if (my_str == NULL && sys_str == NULL)
    {
        printf(GREEN"   [V]  "RESET);
        return (1);
    }
    else if ((my_str == NULL && sys_str != NULL) || (my_str != NULL && sys_str == NULL))
    {
        printf(RED"   [X]  "RESET);
        return (0);
    }
    if (strcmp(my_str, sys_str))
    {
        printf(RED"   [X]  "RESET);
        return (0);
    }
    else
    {
        printf(GREEN"   [V]  "RESET);
        return (1);
    }
}

int    printf_result(int my_func, int system_func)
{
    usleep(50000);
    // printf("\nmy func: %c\nysytem: %c\n", my_func, system_func);
    if (my_func == system_func)
    {
        printf(GREEN"   [V]  "RESET);
        return (1);
    }
    else
    {
        printf(RED"   [X]  "RESET);
        return (0);
    }
}

int     ft_fork(int (*function)(void))
{
    pid_t   pid;
    int     status;
    int     i;

    i = 0;
    pid = fork();
    if (pid == 0)
    {
        i = function();
		exit(0);
    }
    else
        waitpid(pid, &status, WUNTRACED);
    if (i)
        return (1);
    return (0);
}

void    ft_error(int c)
{
    (void)c;
    printf(RED"    [SEGFAULT]\n"RESET);
	exit(0);
}

void    ft_signal(int on)
{
	int i;

	i = 0;
	if (!on)
		return ;
	signal(SIGSEGV, ft_error);
}

int     main(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    j = 0;
    (void)av;
	ft_signal(SIGN);
	if (ac != 1)
		return (0);
    #ifdef USE_FT_ISLOWER
	i += test_islower();
    j += 1;
    #endif

    #ifdef USE_FT_ISUPPER
	i += test_isupper();
    j += 1;
    #endif

    #ifdef USE_FT_ISALPHA
	i += test_isalpha();
    j += 1;
    #endif

	#ifdef USE_FT_ISDIGIT
	i += test_isdigit();
    j += 1;
	#endif
	
    #ifdef USE_FT_ISALNUM
    i += test_isalnum();
    j += 1;   
    #endif

    #ifdef USE_FT_ISASCII
    i += test_isascii();
    j += 1;   
    #endif

    #ifdef USE_FT_ISPRINT
    i += test_isprint();
    j += 1;   
    #endif

    #ifdef USE_FT_TOUPPER
    i += test_toupper();
    j += 1;   
    #endif

    #ifdef USE_FT_TOLOWER
    i += test_tolower();
    j += 1;   
    #endif
	
	#ifdef USE_FT_BZERO
	i += ft_fork(test_bzero);
    j += 1;
	#endif

    #ifdef USE_FT_STRCAT
    i += test_strcat();
    j += 1;   
    #endif

    #ifdef USE_FT_PUTS
    i += test_puts();
    j += 1;   
    #endif

    #ifdef USE_FT_PUTCHAR
    i += test_putchar();
    j += 1;   
    #endif

    #ifdef USE_FT_STRLEN
    i += test_strlen();
    j += 1;   
    #endif

    #ifdef USE_FT_PUTSTR
    i += test_putstr();
    j += 1;   
    #endif

    #ifdef USE_FT_MEMSET
    i += test_memset();
    j += 1;   
    #endif

    #ifdef USE_FT_MEMCPY
    i += test_memcpy();
    j += 1;   
    #endif

	#ifdef USE_FT_STRNEW
	i += test_strnew();
    j += 1;
	#endif

    #ifdef USE_FT_STRDUP
    i += test_strdup();
    j += 1;   
    #endif

    if (i++ < (j / 2))
        printf(RED"\nScore: %d/%d        [YOU LOST]\n"RESET, i, j);
    else
        printf(GREEN"\nScore: %d/%d        [YOU WIN]\n"RESET, i, j);
}
