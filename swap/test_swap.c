#include <stdio.h>
#include "swap.h"

int main()
{

    int x = 42;
    int y = 14;
 
    printf("x is %i\t y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i\t y is %i\n", x, y);

    return 0;
}