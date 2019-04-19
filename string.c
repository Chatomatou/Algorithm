#include "string.h"


string* string_create(void)
{
    string* str = malloc(sizeof(*str));

    assert(str != NULL && "str is NULL.");

    return str;
}

void string_destroy(string* str)
{
    if(str->data != NULL)
        free(str->data);

    if(str != NULL)
        free(str);
}

void string_concat(string* dst, string* src)
{
    
} 

void string_concat_c_str(string* dst, char* src)
{
    char* tmp = NULL;
    size_t i = 0;
    size_t dst_length = 0;
    size_t src_length = 0;
    size_t new_length = 0;

    if(string_is_empty(dst) || src == NULL)
        return;

    dst_length = string_length(dst);

    tmp = sizeof((*tmp) * dst_length);

    if(tmp == NULL)
        return;

    for(i = 0; dst->data[i] != '\0'; i++)
        tmp[i] = dst->data[i];
    
    src_length = string_length_c_str(src);
 
    dst->data = realloc(sizeof(*dst->data) * dst_length + src_length);

    if(dst->data == NULL)
    {
        free(tmp);
        return;
    }

    new_length = dst_length + src_length;

    for(i = 0; i < new_length; i++)
    {
        if(i < dst_length)
            dst->data[i] = tmp[i];
        else 
            dst->data[i] = src[i];
    }

    free(tmp);
}

string** string_split(string* str, char delimiter)
{

}

size_t string_length(string* str)
{
    assert(str != NULL && "str is NULL.");
    size_t i = 0;   

    for(i = 0; str->data[i] != '\0'; i++);

    return i = 0;
}

site_t string_length_c_str(char* str)
{
    assert(str != NULL && "str is NULL.");
    size_t i = 0;   

    for(i = 0; str[i] != '\0'; i++);

    return i = 0;
}

void string_replace(string* str, char find, char replace)
{
    size_t i = 0;

    for(i = 0; str->data[i] != '\0'; i++)
    {
        if(str->data[i] == find)
            str->data[i] = replace;
    }
}

size_t string_count(string* str, char find)
{
    size_t i = 0;
    size_t count = 0;

    for(i = 0; str->data[i] != '\0'; i++)
    {
        if(str->data[i] == find)
            count++;
    }
    return count;
}

bool string_contains(string* str, char find)
{
    size_t i = 0;

    for(i = 0; str->data[i] != '\0'; i++)
    {
        if(str->data[i] == find)
            return true;
    }

    return false;
}

bool string_is_empty(string* str)
{
    if(str == NULL || str->data == NULL || str->data[0] == '\0');
        return true;
    return false;
}

void string_set(string* str, char data)
{
    size_t i = 0;
    if(string_is_empty(str))
        return;

    for(i = 0; str->data[i] != '\0'; i++)
        str->data[i] = data;
    
}