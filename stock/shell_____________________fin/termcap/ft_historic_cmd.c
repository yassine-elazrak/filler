/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_historic_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:21:23 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/27 16:46:46 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

// void	ft_search(t_historic **lst,char *cmd, t_init *init)
// {
// 	t_historic *new;
// 	t_historic  *tmp;

// 	tmp = *lst;
// 	(void)init;
// 	if (!(new = (t_historic *)malloc(sizeof(t_historic))))
// 		return ;
// 	new->cmd = ft_strdup(cmd);
// 	new->next = *lst;
// 	new->perv = NULL;
		

// 	if (*lst != NULL)
// 	{	
// 		while ((*lst)->perv)
// 				(*lst) = (*lst)->perv;
// 		(*lst)->perv  = new;
	
// 	}
	
// 	(*lst) = new;
// 	//init->tmp = (*lst);

// }


// void	ft_search_2(char *file,t_init **init)
// {
// 	t_envp *new;
// 	t_envp *tmp;

// 	tmp = (*init)->ls;
// 	if (!(new = malloc(sizeof(t_envp))))
// 		return ;
// 	new->data = ft_strdup(file);
// 	new->next = NULL;
// 	if ((*init)->ls)
// 	{
// 		(*init)->ls = new;
// 		return ;
// 	}
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp = new;
// 	return ;
// }



int	ft_read_file_of_path(char *cmd ,char *path,t_init *init)
{
	int i;
	char *str;
	DIR *dir;
	struct dirent *lst;

	i = 0;
	str = NULL;
	if (!(dir = opendir(path)))
			return (0);

	while ((lst = readdir(dir)))
	{
		if (ft_strncmp(lst->d_name, cmd, ft_strlen(cmd)) == 0)
			{
				i++;
				if (!i)
					str = ft_strdup(lst->d_name);
			}
	}
	
	closedir(dir);
}


void	ft_auto_comple(char *cmd, t_init *init, t_envp *env)
{
	char **array;
	int i;

	i = -1;
	if (!(array = ft_catpath(env)))
		return ;
	if (ft_read_file_of_path(cmd, ".", init))
	{
  
	}
	else
	{
		while (array[++i])
		{
			if (ft_read_file_of_path(cmd, array[i], init))
				break;
		}
		
	}
	ft_tabfree(&array);
}

char	*ft_complete(t_init *init)
{
	int end;
	int start;
	char *str;

	ft_string_cmd(8,init);
	end  = init->s_cursor;
	ft_string_cmd(7,init);
	start = init->s_cursor;
	str = ft_strsub(init->out_put,init->s_cursor + 1,end - start -1);
	ft_string_cmd(8,init);
	while (end > start + 1)
	{
		del_char_of_line(&init->out_put, init);
		end--;
	}
	//printf("|ss =|%s||\n",str);
	ft_cat_string_of_line(init, "59");
	return (NULL);
}

// void	ft_chang_cmd(char *str,t_init *init)
// {
// 	char *tmp;

// 	tmp = ft_strsub(init->out_put,0,14);
// 	free(init->out_put);
// 	//init->out_put = ft_strdup(tmp);
// 	// free(tmp);
// 	// tmp = init->out_put;
// 	init->out_put = ft_strjoin(tmp,str);
// 	free(tmp);
// 	// while (init->s_cursor > 14 )
// 	// {
// 	// 	init->s_cursor--;
// 	// 	tputs(tgetstr("le",NULL),1,my_putchar);
// 	// }
// 	// tputs(tgetstr("cd",NULL),1,my_putchar);
// 	init->s_col = ft_strlen(init->out_put);
// 	init->s_l = ft_strlen(init->out_put);

// 	//ft_putstr_fd(&init->out_put[14],1);
// 	 move_cursor_and_mangemant_fonction(str,init);
// }

void	ft_complete_cmd(char *str, t_init *init)
{
	ft_putstr_fd("\033[",1);
	ft_putnbr_fd(ft_strlen(&init->out_put[14]),1);
	ft_putstr_fd("D",1);
	tputs(tgetstr("cd",NULL),0,my_putchar);
	free(init->out_put);
	init->s_cursor = 14;
	init->s_l = 14;
	init->n_col = 0;
	init->n_row = 0;
	ft_name(&init->out_put);
  	ft_cat_of_line(str,init);
	ft_putstr_fd(&init->out_put[14],1);
}
// void	ft_cmp_in_put(char *input,t_init *init)
// {
// 	t_envp	*tmp;
// 	(void)input;
// 	// t_ls *lst;
// 	// int		i;

// 	// i = 0;
// 	tmp = init->ls;
// 	// while (lst)
// 	// {
// 	// 	if (ft_strncmp(input,lst->data,ft_strlen(input)) == 0)
// 	// 			ft_search_2(lst->data,&tmp);
// 	// 	lst = lst->next;
// 	// }
// 	// if (tmp->next == NULL)
// 	// 	ft_chang_cmd(tmp->data,init);
// 	// else
// 	// {
// 		while (tmp)
// 		{
// 			ft_putstr_fd(tmp->data,1);
// 			ft_putchar('\t');
// 			tmp = tmp->next;
// 		}
// 	//}
// 	//ft_free_lst(tmp);
// }
			
