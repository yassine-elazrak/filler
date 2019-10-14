#include <stdio.h>
#include <stdlib.h>


void	ft_printf(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		printf( "%d \n", tab[i]);
		i++;
	}
}


void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}


// void quick_sort(int *a, int left, int right) 
// {
// 	int i;
// 	int	j;
// 	int x; 
// 	int	y;

// 	i = left;
// 	j = right;
// 	x = a[(left + right) / 2];

// 	while(i <= j) 
// 	{
// 		while(a[i] < x && i < right)
// 			i++;
// 		while(a[j] > x && j > left)
// 			j--;
// 		if(i <= j) 
// 		{
// 		//	ft_swap(&a[i], &a)
// 			y = a[i];
// 			a[i] = a[j];
// 			a[j] = y;
// 			i++;
// 			j--;
// 		}
// 	}

// 	if(j > left) {
// 		quick_sort(a, left, j);
// 	}
// 	if(i < right) {
// 		quick_sort(a, i, right);
// 	}
// }


void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 

 
void ft_quicksort(int list[],int m,int n)
{
    int key;
	int i;
	int j;
    if( m < n)
    {
      
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);
        }
        swap(&list[m],&list[j]);
        ft_quicksort(list,m,j-1);
        ft_quicksort(list,j+1,n);
    }
}
void	ft_sort(int *tab, int left, int right)
{
	int key;
	int i;
	int j;


	i = 0;
	j = 0;
	if (left < right)
	{
		key = tab[left];
		i = left ;
		j = right;
		while (i <= j)
		{
			while ( key > tab[i] && i < right)
				i++;
			while (key < tab[j] && j > left) 
				j--;
			if (i < j)
				ft_swap(&tab[i], &tab[j]);
		}	
	ft_sort(tab,j+1,right);
		ft_sort(tab,left,j-1);
		
	}
}



int	main(int argc, char **argv)
{
	int i;
	int j;
	int tab[] = {1, 2, 5, 6, 9, 4, 0};

	i = 1;
	j = 7;
	// tab = (int *)malloc(sizeof(int) * (argc - 1));

	// while (argv[i])
	// {
	// 	tab[j] = atoi(argv[i]);
	// 	i++;
	// 	j++;
	// }
	ft_printf(tab, j);
	printf("\n ------------  \n");
	ft_quicksort(tab, 0, j );printf("\n ------------  \n");
	ft_printf(tab, j );
	return (0);
}

