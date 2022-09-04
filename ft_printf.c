#include"ft_printf.h"

static void	ft_putptr(size_t n, char *l, int *x)
{
	char	s[16];
	int		i;

	*x += write(1, "0x", 2);
	if (n == 0)
	{
		ft_putstr("0", x);
		return ;
	}
	i = 0;
	while (n)
	{
		s[i++] = l[n % 16];
		n /= 16;
	}
	while (i--)
		*x += write(1, s + i, 1);
}

static void	ft_putinth(unsigned int n, char *l, int *x)
{
	char	s[16];
	int		i;

	i = 0;
	if (n == 0)
	{
		ft_putstr("0", x);
		return ;
	}
	while (n)
	{
		s[i++] = l[n % 16];
		n /= 16;
	}
	while (i--)
		*x += write(1, s + i, 1);
}

static int	ft_select(char a, va_list list, int *x)
{
	if (a == 'c')
		ft_putchar(va_arg(list, int), x);
	else if (a == 's')
		ft_putstr(va_arg(list, char *), x);
	else if (a == 'p')
		ft_putptr(va_arg(list, size_t), "0123456789abcdef", x);
	else if (a == 'd' || a == 'i')
		ft_putnbr(va_arg(list, int), x);
	else if (a == 'u')
		ft_putunbr(va_arg(list, unsigned int), x);
	else if (a == 'x')
		ft_putinth(va_arg(list, size_t), "0123456789abcdef", x);
	else if (a == 'X')
		ft_putinth(va_arg(list, size_t), "0123456789ABCDEF", x);
	else if (a == '%')
		*x += write(1, "%", 1);
	else
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		b;
	int		x;

	x = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			b = 0;
			while (*(++str) == ' ')
				b = 1;
			if (b)
				x += write(1, " ", 1);
			if (ft_select(*str, list, &x) == -1)
				x += write(1, "%", 1);
		}
		else
			x += write(1, str, 1);
		str++;
	}
	va_end(list);
	return (x);
}
/*
int main()
{
	ft_printf(" %p %p \n", 0);
	printf(" %p %p \n", 0);
}*/
