#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


typedef struct s_stack_node
{
    int nbr;
    int index;
    int push_cost;
    bool above median;
    bool cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}   t_stack_node;


//Handle errors

//Stack initiation
char ***split(char *s, char c);


//Stack utils

//Commands

//Algorithm



#endif