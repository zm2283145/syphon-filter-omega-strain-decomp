#include "types.h"
typedef struct { unsigned int kind; char pad[0x2C]; char a[0x10]; char b[0x30]; char c[1]; } O_190E60;
void* func_00190E60(O_190E60* o)
{
    if (o->kind >= 3) return o->c;
    if (o->kind == 2) return o->b;
    return o->a;
}