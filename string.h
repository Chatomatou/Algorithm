#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
 

typedef struct s_string
{
    char* data;
    int length;
}string;

extern string* string_create(void);
extern void string_destroy(string* str);
extern void string_concat(string* dst, string* src); 
extern void string_concat_c_str(string* dst, char* src);
extern string** string_split(string* str, char delimiter);
extern size_t string_length(string* str);
extern site_t string_length_c_str(char* str);
extern void string_replace(string* str, char find, char replace);
extern size_t string_count(string* str, char find);
extern bool string_contains(string* str, char find);
extern bool string_is_empty(string* str);
extern void string_set(string* str, char data);


#endif