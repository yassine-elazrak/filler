/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:37:41 by yelazrak          #+#    #+#             */
/*   Updated: 2019/08/01 21:35:00 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"
#include <stdio.h>

 char  *ft_reverse(char *str)
 {
     int i;
     int j;
     char tmp;

     i = 0;
     j = ft_strlen(str) - 1;
     while (i < j)
     {
         tmp = str[i];
         str[i] = str[j];
         str[j] = tmp;
         i++;
         j--;
     }
     return (str);
 }


char *ft_sum(char *dst, char *srcs)
{
    int sum;
    int len;
    int i;
    int s_a;
    int s_b;
    int rest = 0;
    char *str;
    char *a;
    char *b;

    i = -1;
    a = ft_strdup(dst);
    b = ft_strdup(srcs);
    s_a  = ft_strlen(a);
    s_b = ft_strlen(b);
    len =  (s_a >=  s_b) ?  s_a :  s_b;
    str = ft_strnew(len + 1);
    a = ft_reverse(a);
    b = ft_reverse(b);
    char aa;
    char bb;
    while (++i < len)
    {
        if(i < s_a)
            aa = a[i];
        else
            aa = '0';
         if(i < s_b)
            bb = b[i];
        else
            bb = '0';
        sum = (aa - '0') + (bb - '0') + rest;
        str[i] = (sum % 10)  + '0';
        rest = sum / 10;
    }
    str[i]  = rest + '0';
      while (i > 0 && str[i] == '0')
            s tr[i] = '\0';
    return (ft_reverse(str));
}

char *ft_produt_2_char(char *dst, char b)
{
    char *str;
    int s_a;
    int prd;
    int rest  = 0;
    int i;
    char aa;
    char *a  = ft_strdup(dst);

    i = -1;
    s_a = ft_strlen(a);
    str = ft_strnew(s_a + 1);
    a = ft_reverse(a);
     while (++i <= s_a)
     {
        if(i < s_a)
            aa = a[i];
        else
            aa = '0';
         prd = ((aa - '0') * (b - '0')) + rest;
         str[i] = (prd % 10) + '0';
         rest = prd / 10;    
     }
      
     while (--i > 0 && str[i] == '0')
            str[i] = '\0';
    free(a);
      return (ft_reverse(str));
}

char *ft_strjoin_00(char *dst, int i)
{
    char *rst;
    char *str;

    str = ft_strdup(dst);
    while (i > 0)
    {
          rst = ft_strjoin(str, "0");
          free(str);
          str = rst;
        i--;
    }
     free(dst);
    return (str);
}

char *ft_produt(char *dst, char *s)
{
    int i;
    char *rest;
    char *tmp;
    char  *tmp_2;
    char *srcs ;

    i = 0;
    srcs = ft_strdup(s);
    srcs = ft_reverse(srcs);
    rest = ft_strjoin_00( ft_strnew(0),1);     
    while (srcs[i])
    {
        tmp_2 = rest;
       
        tmp = ft_produt_2_char(dst,srcs[i]);
        tmp = ft_strjoin_00(tmp,i);
        rest = ft_sum(rest,tmp);
        free(tmp);
        free(tmp_2);
        i++;
    }
    ft_strdel(&srcs);
    return (rest);
}


char *ft_power(char *str, long n)
{
    char *dst;
    char *tmp;

    if (n == 0)
        return (ft_strdup("1"));
    dst = ft_strdup(str);
    while (--n > 0)
    {
        tmp = dst;
        dst  = ft_produt(dst,str);
        ft_strdel(&tmp);
    }
    return (dst);
}

// int main()
// {
//     char *s;

//   s = ft_power(ft_strdup("123456789"), 123);
//  // s = ft_sum(ft_strdup("1111111101"),ft_strdup("9876543120"));
//   //s = ft_produt(ft_strdup("123456789"), ft_strdup("123456789"));
//     printf("%s\n", s);
// }