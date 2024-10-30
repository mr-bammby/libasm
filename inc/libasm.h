#ifndef _IG_LIBASM_H_
#define _IG_LIBASM_H_

typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

unsigned long ft_strlen(const char* str);
char* ft_strcpy(char* dest, const char* src);
int ft_strcmp (const char* str1, const char* str2);
long ft_write(int fd, const void *buf, unsigned long count);
long ft_read(int fd, void *buf, unsigned long count);
char *ft_strdup(const char *src);
int ft_atoi_base(char *src, char *base);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

#endif /* _IG_LIBASM_H_ */
