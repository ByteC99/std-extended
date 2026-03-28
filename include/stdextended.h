#ifndef STDEXTENDED
#define STDEXTENDED

#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

#define or ||
#define and &&

// Extended variables
typedef enum {
    TYPE_NONE,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR_PTR,
    TYPE_CHAR
} Type;

// Variable struct
typedef struct {
    Type type;
    union {
        int         i;
        float       f;
        double      d;
        const char* s;
        char        c;
    } val;
} Var;

static inline Var var_int(int x)
{
    return (Var){ .type = TYPE_INT, .val.i = x};
}

static inline Var var_float(float x)
{
    return (Var){ .type = TYPE_FLOAT, .val.f = x};
}

static inline Var var_double(double x)
{
    return (Var){ .type = TYPE_DOUBLE, .val.d = x};
}

static inline Var var_char(char x)
{
    return (Var){ .type = TYPE_CHAR, .val.c = x};
}

static inline Var var_string(char* x)
{
    return (Var){ .type = TYPE_CHAR_PTR, .val.s = x};
}

static inline Var var_var(Var x)
{
    switch(x.type)
    {
        case TYPE_NONE:     return (Var){ .type = TYPE_NONE};
        case TYPE_INT:      return (Var){ .type = TYPE_INT, .val.i = x.val.i};
        case TYPE_FLOAT:    return (Var){ .type = TYPE_FLOAT, .val.f = x.val.f};
        case TYPE_DOUBLE:   return (Var){ .type = TYPE_DOUBLE, .val.d = x.val.d};
        case TYPE_CHAR:     return (Var){ .type = TYPE_CHAR, .val.c = x.val.c};
        case TYPE_CHAR_PTR: return (Var){ .type = TYPE_CHAR_PTR, .val.s = x.val.s};
    }
}


#define new(x) _Generic((x), \
    int: var_int, \
    float: var_float, \
    double: var_double, \
    char*:  var_string, \
    const char*: var_string, \
    char: var_char, \
    Var: var_var    \
)(x)


// Inline functions
static inline Var arg_int(int x)
{
    return (Var){ .type = TYPE_INT, .val.i = x };
}

static inline Var arg_float(float x)
{
    return (Var){ .type = TYPE_FLOAT, .val.f = x };
}

static inline Var arg_double(double x)
{
    return (Var){ .type = TYPE_DOUBLE, .val.d = x };
}

static inline Var arg_str(const char *x)
{
    return (Var){ .type = TYPE_CHAR_PTR, .val.s = x };
}

static inline Var arg_char(char x)
{
    return (Var){ .type = TYPE_CHAR, .val.c = x };
}

static inline Var arg_var(Var x)
{
    switch(x.type)
    {
        case TYPE_INT:      return (Var){ .type = TYPE_INT, .val.i = x.val.i};
        case TYPE_FLOAT:    return (Var){ .type = TYPE_FLOAT, .val.f = x.val.f};
        case TYPE_DOUBLE:   return (Var){ .type = TYPE_DOUBLE, .val.d = x.val.d};
        case TYPE_CHAR:     return (Var){ .type = TYPE_CHAR, .val.c = x.val.c};
        case TYPE_CHAR_PTR: return (Var){ .type = TYPE_CHAR_PTR, .val.s = x.val.s};
    }
}


/*static inline Var arg_type(Type x)
{
    switch(x)
    {
        case TYPE_INT:      return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_INT"};
        case TYPE_FLOAT:    return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_FLOAT"};
        case TYPE_DOUBLE:   return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_DOUBLE"};
        case TYPE_CHAR:     return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_CHAR"};
        case TYPE_CHAR_PTR: return (Var){ .type = TYPE_CHAR_PTR, .val.s = "TYPE_CHAR_PTR"};
    }
}*/

#define ARG(x) _Generic((x),       \
    int:         arg_int,           \
    float:       arg_float,         \
    double:      arg_double,        \
    char*:       arg_str,           \
    const char*: arg_str,           \
    char:        arg_char,          \
    Var:         arg_var           \
)(x)









/*#define value_of_var(x) _Generic((x),       \
    int:         value_int,           \
    float:       value_float,         \
    double:      value_double,        \
    char*:       value_str,           \
    const char*: value_str,           \
    char:        value_char           \
)(x)

#define __value_of_var_int(x) _Generic((x),       \
    int:         value_int,           \
    float:       value_float,         \
    double:      value_double,        \
    char*:       value_str,           \
    const char*: value_str,           \
    char:        value_char           \
)(x)

#define __value_of_var_float(x) _Generic((x),       \
    int:         value_int,           \
    float:       value_float,         \
    double:      value_double,        \
    char*:       value_str,           \
    const char*: value_str,           \
    char:        value_char           \
)(x)

#define __value_of_var_double(x) _Generic((x),       \
    int:         value_int,           \
    float:       value_float,         \
    double:      value_double,        \
    char*:       value_str,           \
    const char*: value_str,           \
    char:        value_char           \
)(x)

#define __value_of_var_char(x) _Generic((x),       \
    int:         value_int,           \
    float:       value_float,         \
    double:      value_double,        \
    char*:       value_str,           \
    const char*: value_str,           \
    char:        value_char           \
)(x)

#define __value_of_var_const_char(x) _Generic((x),       \
    int:         value_int,           \
    float:       value_float,         \
    double:      value_double,        \
    char*:       value_str,           \
    const char*: value_str,           \
    char:        value_char           \
)(x)

#define __value_of_var_char_ptr(x) _Generic((x),       \
    int:         value_int,           \
    float:       value_float,         \
    double:      value_double,        \
    char*:       value_str,           \
    const char*: value_str,           \
    char:        value_char           \
)(x)


// Inline functions for value_of_var
static inline int value_int(int x)
{
    return x;
}

static inline float value_float(float x)
{
    return x;
}

static inline double value_double(double x)
{
    return x;
}

static inline char value_char(char x)
{
    return x;
}

static inline const char* value_char_ptr(const char* x)
{
    return x;
}
*/




            



// About variables
Var type_of_var(Var variable);

// The variables that created with new can't be changed directly. You must use this func for change it.
void change_value_to(Var *variable, Var add, bool change_type);
void change_type_to(Var *variable, const char *type);


// {} finder
void __finder(int *counter, const char *text);

// New 
void print(const char *text, ...);



#endif