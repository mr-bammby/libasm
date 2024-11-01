#ifndef _IG_LIBASM_BONUS_H_
#define _IG_LIBASM_BONUS_H_

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

int ft_atoi_base(char *src, char *base);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif /* _IG_LIBASM_BONUS_H_ */
