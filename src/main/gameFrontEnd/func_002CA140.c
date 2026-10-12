#include "types.h"
extern char D_004ACA00[];
static void * const dat_0048C140[2] = { (void*)D_004ACA00, (void*)0x0 };
typedef struct { char pad[0x26C]; char name[0x40]; } NameObjA140;
char* func_002CA140(NameObjA140* o)
{
    if (o->name[0])
        return o->name;
    return (*(char**)dat_0048C140);
}