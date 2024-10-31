#ifndef IG_LIBASM_TEST_
#define IG_LIBASM_TEST_

void test_strlen(unsigned long (*tested_fun)(const char *), unsigned long (*reference_fun)(const char *));
void test_strcmp(int (*tested_fun)(const char *, const char *), int (*reference_fun)(const char *, const char *));
void test_strcpy(char * (*tested_fun)(char *, const char *), char * (*reference_fun)(char *, const char *));
void test_write(long (*tested_fun)(int, const void *, unsigned long), long (*reference_fun)(int, const void *, unsigned long));
void test_read(long (*tested_fun)(int, void *, unsigned long), long (*reference_fun)(int, void *, unsigned long));
void test_strdup(char * (*tested_fun)(const char *), char  *(*reference_fun)(const char *));
void test_list_size(void);
void test_atoi_base(void);
void test_list_push_front(void);
void test_list_remove_if(void);
void test_list_sort(void);





#endif /* IG_LIBASM_TEST_ */