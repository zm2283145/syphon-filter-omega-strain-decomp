#include "types.h"
extern char D_004AC9E0[];
static void * const dat_0048C138[2] = { (void*)D_004AC9E0, (void*)0x0 };
typedef struct { char pad[0x2AC]; char name[0x40]; } NameObjA0E0;
char* func_002CA0E0(NameObjA0E0* o)
{
    if (o->name[0])
        return o->name;
    return (*(char**)dat_0048C138);
}