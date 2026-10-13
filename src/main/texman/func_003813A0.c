#pragma cplusplus on
#include "types.h"

typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    unsigned char pad0C[0x428 - 0xC];
    int list428[3];
    int freeA[3];
} Obj_3813A0;

extern "C" {
extern char D_004BC300[];
void TexEntry_Release(void* t);
int func_00380360(void* t);
void func_00380280(void* t, int a, int b, char* file, int line);
void func_003801A0(Obj_3813A0* o, int v);
void func_00380170(void* list, int* value);
}

extern "C" void func_003813A0(Obj_3813A0* o, int idx, int keep)
{
    int i = idx;
    if (o->tex[idx]) {
        TexEntry_Release(o->tex[idx]);
        if (func_00380360(o->tex[i]) == 0) {
            func_00380170(o->list428, &i);
        }
    }
    if (keep == 0) {
        int j = idx;
        if (o->tex[idx] && func_00380360(o->tex[idx]) <= 0) {
            func_00380280(o->tex[j], 0, 1, D_004BC300, 0x39E);
            o->tex[j] = 0;
            func_003801A0(o, j);
            func_00380170(o->freeA, &j);
        }
    }
}
