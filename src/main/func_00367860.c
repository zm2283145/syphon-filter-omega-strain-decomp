#include "types.h"
typedef struct { char pad[0x3C]; } E3678;
typedef struct { int unk0; int count; E3678* data; } V3678;
extern void func_001AEF70(E3678* e, int a);
void func_00367860(V3678* v)
{
    E3678* b = v->data;
    E3678* e = b + v->count;
    while (b < e) {
        e--;
        func_001AEF70(e, -1);
    }
    v->count = 0;
}