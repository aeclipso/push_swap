//
// Created by aeclipso on 9/12/20.
//

#include "pushswap.h"
/*
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


int	ft_longover(const char *str, int sign)
{
	int		i;
	
	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		i++;
	}
	if (i > 20 && sign == -1)
	{
		return (0);
	}
	else if (i > 20 && sign == 1)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

int					ft_atoi(const char *nptr)
{
	int				sign;
	long long int	nbr;
	
	sign = 1;
	nbr = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v'
		   || *nptr == '\f' || *nptr == '\r' || *nptr == '\n')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (ft_longover(nptr, sign) == 1)
	{
		while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
		{
			nbr = nbr * 10 + (*nptr - '0');
			nptr++;
		}
		return ((int)nbr * sign);
	}
	else
		return (ft_longover(nptr, sign));
}
*/

int					ft_atoi(const char *nptr)
{
	size_t			nbr;
	int				sign;
	
	sign = 1;
	nbr = 0;
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr)
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
	}
	if (sign == -1 && nbr > 2147483648)
		return (0);
	else if (sign == 1 && nbr > 2147483647)
		return (-1);
	else
		return (sign * nbr);
}


int main(int argc, char **argv)
{
	int kek = ft_atoi(argv[1]);
	int lol = atoi(argv[1]);
	printf("kek\t%i\n", kek);
	printf("lol\t%i\n", lol);
}