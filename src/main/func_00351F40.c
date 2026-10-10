#include "types.h"
extern void func_00351FC0(void*, int);
typedef struct { char d[0x14]; } G6E35;
typedef struct { int x; int count; G6E35* arr; } G6C35;
void func_00351F40(G6C35* c)
{
    G6E35* arr = c->arr;
    G6E35* e = arr + c->count;
    while (arr < e) {
        --e;
        func_00351FC0(e, -1);
    }
    c->count = 0;
}