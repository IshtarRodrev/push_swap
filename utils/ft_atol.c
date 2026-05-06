#include <stdio.h>

long	ft_atol(char *str)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (str[0] == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}
#include <limits.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{	
		char	*str;
		long	nbr;
		int		i;

		str = argv[1];
		i = 0;
		while (str[i] != '\0')
		{
			i++;
			if (i > 11)
				return (1);
		}
		nbr = ft_atol(str);
		if (nbr <= INT_MAX || nbr >= INT_MIN)
			return (0);
		printf("%ld\n", nbr);
		return (1);
	}
}
