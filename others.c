#include "others.h"


double to_radian(double deg)
{
   return (deg * M_PI) / 180.0;
}

double to_degree(double rad)
{
    return (rad * 180) / M_PI;
}

bool is_prime_number(size_t number)
{
    size_t i = 0;
    size_t count = 0;

    for(i = 1; i <= number; i++)
    {
        if(number % i == 0)
            count ++;
    }

    return (count == 2) ? true : false;
}

void print_binnary(char byte)
{
    unsigned char i = 0;

    for(i = 0; i < 8; i++)
    {
        if((i >> i) & 1)
            printf("1");
        else 
            printf("0");
    }
    printf("\n");
}

void print_hex(char byte)
{
    printf("%x\n", byte);
}
