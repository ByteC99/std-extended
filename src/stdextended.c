#include "../include/stdextended.h"



Var type_of_var(Var variable)
{
    switch(variable.type)
    {
        case TYPE_NONE:     return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_NONE"};
        case TYPE_INT:      return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_INT"};
        case TYPE_FLOAT:    return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_FLOAT"};
        case TYPE_DOUBLE:   return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_DOUBLE"};
        case TYPE_CHAR:     return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_CHAR"};
        case TYPE_CHAR_PTR: return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_CHAR_PTR"};
    }
}

/**
 * @param variable the variable that you want to change
 * @param add that'll be variable
 * @param change_type 0 = the type won't change - 1 = the type will change
 */
void change_value_to(Var *variable, Var add, bool change_type)
{
    if(change_type == 0)
    {
        if(variable->type == TYPE_INT and add.type == TYPE_INT)
        {
            variable->val.i = add.val.i;
        }
        else if(variable->type == TYPE_FLOAT and add.type == TYPE_FLOAT)
        {
            variable->val.f = add.val.f;
        }
        else if(variable->type == TYPE_DOUBLE and add.type == TYPE_DOUBLE)
        {
            variable->val.d = add.val.d;
        }
        else if(variable->type == TYPE_CHAR and add.type == TYPE_CHAR)
        {
            variable->val.c = add.val.c;
        }
        else if(variable->type == TYPE_CHAR_PTR and add.type == TYPE_CHAR_PTR)
        {
            variable->val.s = add.val.s;
        }
        else
        {
            printf("TYPE_ERROR\n10\n");
            exit(10);
        }
    }
    else if(change_type == 1)
    {
        if(add.type == TYPE_INT)
        {
            if(variable->type == TYPE_INT)
            {
                variable->val.i = add.val.i;
            }
            else
            {
                variable->type = TYPE_INT;
                variable->val.i = add.val.i;
            }
        }
        else if(add.type == TYPE_FLOAT)
        {
            if(variable->type == TYPE_FLOAT)
            {
                variable->val.f = add.val.f;
            }
            else
            {
                variable->type = TYPE_FLOAT;
                variable->val.f = add.val.f;
            }
        }
        else if(add.type == TYPE_DOUBLE)
        {
            if(variable->type == TYPE_DOUBLE)
            {
                variable->val.d = add.val.d;
            }
            else
            {
                variable->type = TYPE_DOUBLE;
                variable->val.d = add.val.d;
            }
        }
        else if(add.type == TYPE_CHAR)
        {
            if(variable->type == TYPE_CHAR)
            {
                variable->val.c = add.val.c;
            }
            else
            {
                variable->type = TYPE_CHAR;
                variable->val.c = add.val.c;
            }
        }
        else if(add.type == TYPE_CHAR_PTR)
        {
            if(variable->type == TYPE_CHAR_PTR)
            {
                variable->val.s = add.val.s;
            }
            else
            {
                variable->type = TYPE_CHAR_PTR;
                variable->val.s = add.val.s;
            }
        }
    }
    else
    {
        printf("Invalid argument value - CHANGE_TYPE");
    }
}


void change_type_to(Var *variable, const char *type)
{
    int j = 0;
    char ch;
    while(type[j])
    {
        ch = type[j];
        putchar(toupper(ch));
        j++;
    }

    if(type == "TYPE_INT" or type == "INT")
    {
        variable->type = TYPE_INT;
    }
    else if(type == "TYPE_FLOAT" or type == "FLOAT")
    {
        variable->type = TYPE_FLOAT;
    }
    else if(type == "TYPE_DOUBLE" or type == "DOUBLE")
    {
        variable->type = TYPE_FLOAT;
    }
    else if(type == "TYPE_CHAR" or type == "CHAR")
    {
        variable->type = TYPE_CHAR;
    }
    else if(type == "TYPE_CHAR_PTR" or type == "STRING")
    {
        variable->type = TYPE_CHAR_PTR;
    }
    else
    {
        printf("UNKNOWN TYPE");
    }
}









void __finder(int *counter, const char *text)
{
    uint8_t cont = true;
    int line = 0;
    while(cont)
    {
        if(text[line] == '\0')
        {
            cont = false;
            break;
        }
        else
        {
            if(text[line] == '{' and text[line + 1] == '}')
            {
                *counter += 1;
                line   += 2;
            }
            else
            {
                line += 1;
            }
        }
    }
}

void print(const char *text, ...)
{
    int counter = 0;
    __finder(&counter, text);

    va_list ap;
    va_start(ap, text);

    int i = 0;
    int arg_index = 0;

    while(text[i] != '\0')
    {
        if(text[i] == '{' and text[i+1] == '}' && arg_index < counter)
        {
            Var arg = va_arg(ap, Var);

            switch(arg.type)
            {
                case TYPE_NONE:     continue;
                case TYPE_INT:      printf("%d", arg.val.i); break;
                case TYPE_FLOAT:    printf("%f", arg.val.f); break;
                case TYPE_DOUBLE:   printf("%lf", arg.val.d); break;
                case TYPE_CHAR_PTR: printf("%s", arg.val.s); break;
                case TYPE_CHAR:     printf("%c", arg.val.c); break;
            }

            i += 2;
            arg_index++;
        }
        else
        {
            printf("%c", text[i]);
            i++;
        }
    }

    va_end(ap);
}