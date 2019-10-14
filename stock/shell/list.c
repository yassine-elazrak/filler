#include "shell.h"

// new *alstnew(char *t)
// {
// 	new *new;


// 	if (!(new = (new*)malloc(sizeof(new))))
// 		return (NULL);
// 	new->t = ft_strdup(t);
// 	new->next = NULL;
// 	new->prev = NULL;
// 	return (new);
// }


// void	ft_allocation(new **alst,char *t)
// {
// 	new *tmp;
// 	new *new;
//tmp = *alst;


// void append(t_lst** head_ref, int new_data) 
// { 
//     /* 1. allocate node */
//     t_lst* new = (struct s_lst*)malloc(sizeof(struct s_lst)); 
  
//     t_lst* last = *head_ref; /* used in step 5*/
  
//     /* 2. put in the data  */
//     new->data = new_data; 
  
//     /* 3. This new node is going to be the last node, so 
//           make next of it as NULL*/
//     new->next = NULL; 
  
//     /* 4. If the Linked List is empty, then make the new 
//           node as head */
//     if (*head_ref == NULL) { 
//         new->prev = NULL; 
//         *head_ref = new; 
//         return; 
//     } 
  
//     /* 5. Else traverse till the last node */
//     while (last->next != NULL) 
//         last = last->next; 
  
//     /* 6. Change the next of last node */
//     last->next = new; 
  
//     /* 7. Make last node as previous of new node */
//     new->prev = last; 
  
//     return; 
// } 

// 	if (*alst)
// 	{
// 		while (tmp->next)
// 		{
// 			new = tmp;
// 			tmp = tmp->next;
// 		}
// 			ft_putendl("45355545");
// 		new = alstnew(t);
// 		new->prev = tmp;
// 		tmp->next = new;
		
// 	}
// 	else
// 	{
	
// 		//new = 
// 		//new->prev = NULL;
// 			ft_putendl("45355545");
// 		*alst = alstnew(t);
// 	}
	
// }
void ft_search(t_lst** head, char *new_data) 
{ 
	ft_putendl("45355545");
    t_lst* new;

	if(!(new = (t_lst*)malloc(sizeof(t_lst))))
		return ;
    t_lst* last = *head; 
    new->data = ft_strdup(new_data); 
    new->next = NULL; 
    if (*head == NULL) { 
        new->prev = NULL; 
        *head = new; 
        return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    new->prev = last; 
    last->next = new; 
    return; 
} 

int main()
{
	t_lst *alst;
	t_lst *lst;
	alst = NULL;

	 ft_search(&alst,"0123");
	 ft_search(&alst,"abcd");
	  
	
	alst=alst->next;
	lst=alst->prev;
	printf("%s		%s\n",alst->data,lst->data);
}