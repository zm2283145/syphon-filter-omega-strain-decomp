#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

typedef struct Node_380DB0 { struct Node_380DB0* prev; struct Node_380DB0* next; int value; } Node_380DB0;
typedef struct { Node_380DB0* p; } It_380DB0;
typedef struct { int count; Node_380DB0* prev; Node_380DB0* next; } List_380DB0;
typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    int pad0C;
    int next;
    unsigned char pad14[0x428 - 0x14];
    List_380DB0 freeB;
    List_380DB0 freeA;
} Obj_380DB0;

extern "C" {
extern char D_004BC2B8[], D_004BC300[];
void func_00383560(It_380DB0* result, void* list, It_380DB0* pos);
int func_00380360(void* t);
void Tex_DestroyRecord(void* t, int a, int b, char* file, int line);
void func_003801A0(Obj_380DB0* o, int v);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void* func_003BBC90(void* t);
void func_003BB6D0(void* t, int a, int b, int c, int d, int e);
}

static inline void Erase(It_380DB0* out, List_380DB0* l, It_380DB0* b) { It_380DB0 result; It_380DB0 value; value = *b; func_00383560(&result, l, &value); *out = result; }

extern "C" int func_00380DB0(Obj_380DB0* o, int a, int b, int c, int d)
{
    int idx;
    void* t;
    if (o->freeA.count) {
        It_380DB0 r;
        It_380DB0 pos;
        Node_380DB0* n = o->freeA.next;
        idx = n->value;
        pos.p = n;
        Erase(&r, &o->freeA, &pos);
    } else if (o->freeB.count) {
        It_380DB0 r;
        It_380DB0 pos;
        Node_380DB0* n = o->freeB.next;
        idx = n->value;
        pos.p = n;
        Erase(&r, &o->freeB, &pos);
    } else {
        idx = o->next++;
    }
    if (o->tex[idx] && func_00380360(o->tex[idx]) <= 0) {
        Tex_DestroyRecord(o->tex[idx], 0, 1, D_004BC300, 0x39E);
        o->tex[idx] = 0;
        func_003801A0(o, idx);
    }
    {
        AllocGuard guard;
        t = Mem_Alloc(0, 0x70, D_004BC2B8, 0x41B);
    }
    if (t) {
        t = func_003BBC90(t);
    }
    o->tex[idx] = t;
    func_003BB6D0(o->tex[idx], a, b, c, d, 0);
    return idx;
}
