#pragma cplusplus on
#include "types.h"

typedef struct Node_3812D0 {
    int pad0;
    int pad4;
    int value;
} Node_3812D0;

typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    unsigned char pad0C[0x428 - 0xC];
    int count;
    int pad42C;
    Node_3812D0* head;
    int freeA[3];
} Obj_3812D0;

extern "C" {
extern char D_004BC300[];
int func_00380360(void* t);
void func_00380280(void* t, int a, int b, char* file, int line);
void func_003801A0(Obj_3812D0* o, int v);
void func_00380170(void* list, int* value);
}

extern "C" void func_003812D0(Obj_3812D0* o)
{
    while (o->count) {
        int v = o->head->value;
        int idx = v;
        if (o->tex[v] && func_00380360(o->tex[idx]) <= 0) {
            func_00380280(o->tex[idx], 0, 1, D_004BC300, 0x39E);
            o->tex[idx] = 0;
            func_003801A0(o, idx);
            func_00380170(o->freeA, &idx);
        }
    }
}
