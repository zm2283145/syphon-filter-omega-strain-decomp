#include "types.h"
typedef struct { char pad[0x20]; char flag; char pad2[0xBF]; } G6E13;
typedef struct { int x; int count; G6E13* arr; } G6C13;
void func_0013B430(G6C13* c)
{
    G6E13* arr = c->arr;
    G6E13* e = arr + c->count;
    while (arr < e) {
        --e;
        if (e) e->flag = 0;
    }
    c->count = 0;
}