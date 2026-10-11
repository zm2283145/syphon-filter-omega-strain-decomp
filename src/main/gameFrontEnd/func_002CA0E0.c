#include "types.h"
extern char* D_0048C138;
typedef struct { char pad[0x2AC]; char name[0x40]; } NameObjA0E0;
char* func_002CA0E0(NameObjA0E0* o)
{
    if (o->name[0])
        return o->name;
    return D_0048C138;
}