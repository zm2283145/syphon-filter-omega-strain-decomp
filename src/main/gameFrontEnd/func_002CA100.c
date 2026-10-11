#include "types.h"
extern char* strncpy(char* dst, const char* src, int n);
typedef struct { char pad[0x26C]; char name[0x40]; } NameObjA100;
void func_002CA100(NameObjA100* o, const char* s)
{
    if (s == 0)
        o->name[0] = 0;
    else
        strncpy(o->name, s, 0x40);
}