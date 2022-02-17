#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct Stack {
    int top;
    int *array;
} Stack;

int     ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif


//    1 2 3
// 1 3 2
//    2 1 3
// 2 3 1
//    3 1 2
//    3 2 1