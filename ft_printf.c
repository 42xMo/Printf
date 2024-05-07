/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:44:34 by mabdessm          #+#    #+#             */
/*   Updated: 2024/05/07 17:40:05 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				len += ft_putchar(va_arg(args, int));
			else if (str[i + 1] == 's')
				len += ft_putstr(va_arg(args, char *));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				len += ft_putnbr(va_arg(args, int));
			else if (str[i + 1] == 'u')
				len += ft_putunsigned(va_arg(args, unsigned int));
			else if (str[i + 1] == 'x')
				len += ft_putnbr_base(va_arg(args, unsigned long), \
				"0123456789abcdef");
			else if (str[i + 1] == 'X')
				len += ft_putnbr_base(va_arg(args, unsigned long), \
				"0123456789ABCDEF");
			else if (str[i + 1] == 'p')
			{
				len += ft_putstr("0x");
				len += ft_putnbr_base(va_arg(args, unsigned long), \
				"0123456789abcdef");
			}
			else if (str[i + 1] == '%')
				len += ft_putchar('%');
			++i;
		}
		else
			len += ft_putchar(str[i]);
		++i;
	}
	va_end(args);
	return (len);
}

/*#include <stdio.h>

int	main(void)
{
	int	i;
	
	i = 45;
	printf(" len : %i\n", ft_putchar('A'));
	printf(" len : %i\n", ft_putstr("ABCDEF"));
	printf(" len : %i\n", ft_putnbr(-7664567));
	printf(" len : %i\n", ft_putunsigned(3147487587));
	printf(" len : %i\n", ft_putnbr_base(565678, "0123456789ABCDEF"));
	printf(" len : %i\n", ft_putnbr_base(565678, "0123456789abcdef"));
	ft_printf(" len : %i\n", ft_putchar('A'));
	ft_printf(" len : %i\n", ft_putstr("ABCDEF"));
	ft_printf(" len : %i\n", ft_putnbr(-7664567));
	ft_printf(" len : %i\n", ft_putunsigned(3147487587));
	ft_printf(" len : %i\n", ft_putnbr_base(565678, "0123456789ABCDEF"));
	ft_printf(" len : %i\n", ft_putnbr_base(565678, "0123456789abcdef"));
	if (ft_printf("YOO\n%s_%d_%i_%c_%u_%x_%X_%%_%p\nHOO\n",\
		 "ABCD", i, -1245, 'B', 5678, 346578, 346578, &i) == \
		 printf("YOO\n%s_%d_%i_%c_%u_%x_%X_%%_%p\nHOO\n", "ABCD", \
		 i, -1245, 'B', 5678, 346578, 346578, &i))
		ft_printf("YOOHOO");
}*/
