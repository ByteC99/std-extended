#include <stdio.h>
#include <stdlib.h>
#include "include/stdextended.h"
#include <a.out.h>


int main()
{
    Var age = new(4);

    print("Value of a: {}", type_of_var(age));
    

    return 0;
}