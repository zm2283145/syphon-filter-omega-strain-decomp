#include "types.h"
typedef struct { int a; int b; char name[0x10]; int x18; char pad[0x18]; int x34; char pad2[0x64]; int x9C; } Rec0DB0;
extern char* strncpy(char* d, const char* s, int n);
int func_002D0DB0(Rec0DB0* r, const char* name, int x18, int x34, int x9C)
{
    if (!r)
        return -13;
    r->a = 1;
    r->b = 1;
    strncpy(r->name, name, 0x14);
    r->x18 = x18;
    r->x34 = x34;
    if (x9C)
        r->x9C = x9C;
    return 0;
}