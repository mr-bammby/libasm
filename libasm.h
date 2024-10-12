typedef struct s_list
{
  void *data;
  struct s_list *next;
} t_list;

int ft_strlen(const char* str);
char* ft_strcpy(char* dest, const char* src);
int ft_strcmp (const char* str1, const char* str2);
int ft_write(int fd, const void *buf, unsigned int count);
int ft_read(int fd, const void *buf, unsigned int count);
char *ft_strdup(char *src);
int ft_atoi_base(char *src, char *base);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);