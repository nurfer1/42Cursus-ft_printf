#include"ft_printf.h"

void	ft_putstr(char *s, int *x)
{
	if (!s)
	{
		ft_putstr("(null)", x);
		return ;
	}
	while (*s)
		*x += write(1, s++, 1);
}

void	ft_putunbr(unsigned int n, int *x)
{
	char	s[10];
	int		i;

	i = 0;
	if (n == 0)
		*x += write(1, "0", 1);
	while (n)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	while (i--)
		*x += write(1, s + i, 1);
}

void	ft_putchar(char a, int *x)
{
	*x += write(1, &a, 1);
}

void	ft_putnbr(int n, int *x)
{
	char	s[10];
	int		i;
	long	nbr;

	nbr = n;
	i = 0;
	if (nbr == 0)
		*x += write(1, "0", 1);
	if (nbr < 0)
	{
		nbr *= -1;
		*x += write(1, "-", 1);
	}
	while (nbr)
	{
		s[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	while (i--)
		*x += write(1, s + i, 1);
}
