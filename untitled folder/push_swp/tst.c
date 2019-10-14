#include <stdio.h>
void swap(int* a, int* b)
{
	static int i;

	i++;
	printf("static = = %d\n",i);
    int t = *a;
    *a = *b;
    *b = t;
}

 void		ft_printf(int *tab)
 {
	 int i;
	 i = 0;
	 while (i < 10)
	{
		printf("%d\n",tab[i]);
		i++;
	}
 }

void	ft_sort(int *tab, int left, int right)
{
	int key;
	int i;
	int j;


	i = 0;
	j = 0;
//printf("i  = %d			j=%d\n",left,right);
	if (left < right)
	{
		key = tab[left];
		i = left ;
		j = right;
		while (i < j)
		{
			while ( key > tab[i] && i < right)
				i++;
			while (key < tab[j] && j > left) 
				j--;
			if (i < j)
				swap(&tab[i], &tab[j]);
		}
		swap(&tab[j], &key);
		printf("--------------------------------\n");
		ft_printf(tab);
			printf("\n--------------------------------");
		ft_sort(tab,j+1,right);
		ft_sort(tab,left,j-1);
		
	}
}


// void	sswap(int **x, int **y)
// {
// 	int	*t;

// 	t = *x;
// 	*x = *y;
// 	*y = t;
// }

// void	ft_sort(int *a, int m, int n)
// {
// 	int		i;
// 	int		j;
// 	int	*key;

// 	if (m < n)
// 	{
// 		key = a[m];
// 		i = m + 1;
// 		j = n;
// 		while (i <= j)
// 		{
// 			while ((i <= n) && (a[i] <= key))
// 				i++;
// 			while ((j >= m) && (a[j] > key))
// 				j--;
// 			if (i < j)
// 				sswap(&a[i], &a[j]);
// 		}
// 		sswap(&a[m], &a[j]);
// 		ft_sort(a, m, (j - 1));
// 		ft_sort(a, (j + 1), n);
// 	}
// }


int main()
{
	int tab[10] = {1,5,6,4,2,9,3,7,8,0};
	int i;

	i = 0;
	ft_sort(tab,0,9);

	ft_printf(tab);
	return 0;
}


void	ft_lst_new(t_init **lst, int data)
{
	t_init *new;

	new = NULL;
	if (*lst == NULL)
	{
		if (!(*lst = (t_init *)malloc(sizeof(t_init))))
				return ;
		(*lst)->data = data;
		(*lst)->size = 1;
		(*lst)->next = NULL;
		(*lst)->end = NULL;
		return ;
	}
	if (!(new = (t_init *)malloc(sizeof(t_init))))
			return ;
	new->next = NULL;
	new->data = data;
	new->end = (*lst);
	new->size += 1;
	(*lst)->next = new;;
	(*lst) = (*lst)->next;
	return ;
}



