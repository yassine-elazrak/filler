/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:46:40 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/01 21:31:19 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <float.h>
#include <stdio.h>

// int		main(void)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	// printf("\n--------------------------------------------------\n");
// 	// i = ft_printf("|%c|\n", 1);
// 	// i = ft_printf("--------------------------------------------------\n");
// 	// i = ft_printf("%s", "WwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqp");
// 	// printf("\n--------------------------------------------------\n");
// 	// j = printf("|%c|", 1);
// 	// printf("\n--------------------------------------------------\n");
// 	// j = printf("%s", "WwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqp");
// 	// i = ft_printf("%.5hhd|%-.5hhd|%+.5hhd|% .5hhd|%0.5hhd", (signed char)5555, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX);
// 	// printf("\n--------------------------------------------------\n");
// 	// j =    printf("%.5hhd|%-.5hhd|%+.5hhd|% .5hhd|%0.5hhd", (unsigned char)5555, (unsigned char)LLONG_MAX, (unsigned char)LLONG_MAX, (unsigned char)LLONG_MAX, (unsigned char)LLONG_MAX);
// 	i = ft_printf("%d",55);
// 	//ft_printf("\n------------------------------------------------\n");
// //	ft_printf("2 => |%d|%-d|%+d|% d|%0d|", 0, 0, 0, 0, 0);
// //	ft_printf("\n------------------------------------------------\n");
// //	i = ft_printf("1 => |%+0d|% 0d|%-+ 0d|", 0, 0, 0);
// //	ft_printf("\n------------------------------------------------\n");
// 	//j = 	printf("3. => |%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d", 0, 0, 0, 0, 0, 0, 0);
// //	printf("\n--------------------------------------------------\n");
// //	   printf("2 => |%d|%-d|%+d|% d|%0d|", 0, 0, 0, 0, 0);
// //	printf("\n--------------------------------------------------\n");
// //	j =    printf("1 => |%+0d|% 0d|%-+ 0d|", 0, 0, 0);
// 	//printf("\n--------------------------------------------------\n");
// 	//printf("mine => %d, sys => %d\n", i, j);
// 	return (0);
// }


void		ft_print_bits(long long int i, int n)
{
	n--;
	//ft_putendl("");
	while (n >= 0)
	{
		if ((i >> n) & 1)
			ft_putstr("1");
		else
		{
			ft_putstr("0");
		}
		n--;
	}
}

t_data		*ft_check(t_data *lst)
{
	printf("|%d|\n",lst->exp);
	if (lst->exp == 255 &&  lst->mantissa == 0)
	{
		ft_putendl("infiny");
		return (NULL);
	}
	else if(lst->exp == 255 &&  lst->mantissa != 0)
	{
			ft_putendl("NAN");
			return (NULL);
	}
	else if(lst->exp == 0 &&  lst->mantissa == 0)
	{
			ft_putendl("0");
			return (NULL);
	}
	else if(lst->exp == 0 &&  lst->mantissa != 0)
		lst->exp = -126;
	else
		lst->exp = lst->exp - 127;
	return (lst);
}



void			ft_put_vurgile(char *str,int j)
{
	int i;
	char *tmp;
	char *tmp_2;

	i = 0;
	// if (j < 0)
	// 	j = -j;
	i = ft_strlen(str);
	printf("i = %d,			j = %d\n\n",i,j);
	i = i - 63;
	if (i >= 0 && j>=0)
	{
		tmp = ft_strsub(str,0,i );
		tmp_2 = ft_strjoin(tmp,".");
		free(tmp);
	}
	else
	{
		i += j;
		tmp_2 = ft_strdup(".");
		tmp = ft_strjoin_00(ft_strnew(0),abs(i));
		printf(" i = %d  tmp = %s   str = %s\n",i, tmp,str);
		str = ft_strjoin(tmp, str);
		i  = 0;
	}
		
	
	//free(tmp);
	tmp = ft_strjoin(tmp_2,&str[i ]);//ft_putendl("hhjjhd");
	if (tmp[0] == '.')
		tmp = ft_strjoin("0",tmp);
	ft_putendl(tmp);

}


  void		ft_printf( long double nb)
  {
	  int i;
	  t_float list;
	  char *str;
	  char  *tmp;
	  char *tmp_2;
	  t_data *lst;
	  int pos = 0;
	  int a = 0;

	// if (!(lst = ft_check(&list.lst)))
	// 		return ;
	tmp = ft_strdup("5");
	tmp_2 = ft_strdup("10");
	list.f = nb;
	i = 0; 
	lst = &list.lst;
	lst->exp = lst->exp - 16383; 
	printf("exp  = = = %d\n",list.lst.exp);
	str = ft_strdup("0");
	while (++i < 64) 
	{
        if((list.lst.mantissa >>  (63 - i) ) & (1))
			str = ft_sum(str,ft_power(tmp, i));		
		if (i < 63)
			str = ft_strjoin_00(str,1); 
    }
	if (list.lst.as & 1)
		str = ft_strjoin("1",str);
	 tmp = lst->exp < 0 ?ft_strdup("5") : ft_strdup("2");
	str = ft_produt(str,ft_power(tmp,llabs(list.lst.exp)));
	printf("befor str %s \n",str);
	ft_put_vurgile(str,list.lst.exp);
  }

  int	main()
  {
	    t_float list;
		t_data lst;
		//printf("printf= = %.100lf",0.417654321);
			long double t = LDBL_MIN;
		printf("printf= = %.100Lf",(long double)t);
	  ft_printf((long double)t);
	  return 0;
  }
  