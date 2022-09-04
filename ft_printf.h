#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include<unistd.h>
# include<stdio.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *s, int *x);
void	ft_putchar(char a, int *x);
void	ft_putnbr(int n, int *x);
void	ft_putunbr(unsigned int n, int *x);

#endif
