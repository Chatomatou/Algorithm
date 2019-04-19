#ifndef OTHERS_H
#define OTHERS_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

extern double to_radian(double deg);
extern double to_degree(double rad);
extern bool is_prime_number(size_t number);
extern void print_binnary(char byte);
extern void print_hex(char byte);

#endif