#include "types.h"
typedef struct { char pad[0x48]; unsigned int n48; int f4c; int f50; int f54; char pad2[8]; char vec[4]; int f64; char pad3[8]; int f70; char pad4[0x18]; void* f8c; } O424;
extern void PtrVec_PushBack_1C1080(void*, char*);
extern void func_0043BC70(void*, int, int, int, int);
void func_00424750(O424* o, int a, int b) {
    o->n48 = a;
    o->f4c = b;
    o->f70 = a;
    if (a != o->f64) {
        unsigned int i;
        o->f64 = 0;
        for (i = 0; i < o->n48; i++) PtrVec_PushBack_1C1080(o->vec, "<");
    }
    if (o->f8c) func_0043BC70(o->f8c, 0, o->f54, 0, o->f4c - 1);
}
