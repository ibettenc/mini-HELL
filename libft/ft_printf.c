/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:00:51 by niguilbe          #+#    #+#             */
/*   Updated: 2025/08/25 12:32:34 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_valid_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int	print_format(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_printptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_printuns(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_printnbr_base(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	len;
	size_t	i;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && (!str[i + 1] || !is_valid_format(str[i + 1])))
		{
			write (1, "OG printf doesn't compile\n", 27);
			va_end(args);
			return (-1);
		}
		if (str[i] == '%')
			len += print_format(str[++i], args);
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int	main(void)
{

	ft_printf("%%\n");                
	ft_printf("%d\n", -42);           
	ft_printf("%u\n", -1);            
	ft_printf("%x\n", 255);           
	ft_printf("%p\n", NULL);          
	ft_printf("%q\n");                
	ft_printf("Hello %\n");           

	int ret_ft;
	int ret_std;

	void *ptr = NULL;
	int a = printf("OG : %p\n", ptr);
	int b = ft_printf("FT : %p\n", ptr);
	printf("OG returned : %d\n", a);
	ft_printf("FT returned : %d\n", b);

	int x = 42;
	
	int test = printf("OG : %p\n", &x);
	int test2 = ft_printf("FT : %p\n", &x);
	printf("OG returned : %d\n", test);
	ft_printf("FT returned : %d\n", test2);

	char *s = "Hello";
	printf("OG : %p\n", s);
	ft_printf("FT : %p\n", s);

	ft_printf("Zero : %u\n", 0);
	ft_printf("Max : %u\n", 4294967295u);

	ft_printf("Hex min : %x\n", 0);
	ft_printf("Hex max : %x\n", 4294967295u);
	ft_printf("HEX MAX : %X\n", 4294967295u); 

	ft_printf("Min int : %d\n", -2147483648);
	ft_printf("Max int : %i\n", 2147483647);

	char *t = NULL;
	ft_printf("String : %s\n", t);

	ret_ft = ft_printf("Hello world\n");
	ret_std = printf("Hello world\n");
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("Char: %c, String: %s, Pointer: %p\n",
	 'A', "test", &ret_ft);
	ret_std = printf("Char: %c, String: %s, Pointer: %p\n",
	 'A', "test", &ret_ft);
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("Percent %% sign\n");
	ret_std = printf("Percent %% sign\n");
	printf("ft_printf returned: %d, printf returned: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("Invalid format: %q\n");
	printf("ft_printf returned: %d (should be -1)\n\n", ret_ft);


	ret_ft = ft_printf("Ends with percent %");
	printf("ft_printf returned: %d (should be -1)\n\n", ret_ft);

	ret_ft = ft_printf("%");
	printf("ft_printf returned: %d (should be -1)\n\n", ret_ft);


	int ret1, ret2;
	ret1 = ft_printf("Coucou Hibou\n");
	ret2 = printf("Coucou Hibou\n");
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("%c\n", 'A');
	ret2 = printf("%c\n", 'A');
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("%s\n", "Coucou");
	ret2 = printf("%s\n", "Coucou");
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("%d\n", 123456);
	ret2 = printf("%d\n", 123456);
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("%u\n", 1234567899U);
	ret2 = printf("%u\n", 1234567899U);
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("%x\n", 255);
	ret2 = printf("%x\n", 255);
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("%X\n", 255);
	ret2 = printf("%X\n", 255);
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("%     d");
	ret2 = printf("%%\n");
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);
	
	ret1 = ft_printf(" %p %p\n ", (void *)0, (void *)0);
	ret2 = printf(" %p %p\n ", (void *)0, (void *)0);
	printf("ft_printf: %d | printf: %d\n\n", ret1, ret2);

	return (0);
}
*/