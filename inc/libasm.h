#ifndef _IG_LIBASM_H_
#define _IG_LIBASM_H_

unsigned long ft_strlen(const char* str);
char* ft_strcpy(char* dest, const char* src);
int ft_strcmp (const char* str1, const char* str2);
long ft_write(int fd, const void *buf, unsigned long count);
long ft_read(int fd, void *buf, unsigned long count);
char *ft_strdup(const char *src);

#endif /* _IG_LIBASM_H_ */
