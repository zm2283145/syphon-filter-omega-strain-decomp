#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

typedef struct Node_37FEA0 { struct Node_37FEA0* prev; struct Node_37FEA0* next; int value; } Node_37FEA0;
typedef struct { Node_37FEA0* p; } It_37FEA0;
typedef struct { int count; Node_37FEA0* prev; Node_37FEA0* next; } List_37FEA0;
typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    int pad0C;
    int next;
    unsigned char pad14[0x428 - 0x14];
    List_37FEA0 freeB;
    List_37FEA0 freeA;
    unsigned char data[1];
} Obj_37FEA0;

extern "C" {
extern char D_004BC2B8[], D_004BC300[];
extern char func_003809E0[];
int FileMan_FindMember(int* f);
unsigned int FileMan_GetSize(int* f);
int func_0036D880(int* f);
void* Tdx_Read(Obj_37FEA0* o, int* f, int* flags);
void List_Erase_383560(It_37FEA0* result, void* list, It_37FEA0* pos);
int func_00380360(void* t);
void Tex_DestroyRecord(void* t, int a, int b, char* file, int line);
void func_003801A0(Obj_37FEA0* o, int v);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void* func_003BBC90(void* t);
int Fstream_GetLoader(void);
void AsyncLoader_QueueLoad(int q, int* f, void* cb, void* t, int a, int b, int c);
void Tex_BuildGsRegisters(void* t, int a, void* data, int flags);
}

static inline void Erase(It_37FEA0* out, List_37FEA0* l, It_37FEA0* b) { It_37FEA0 result; It_37FEA0 value; value = *b; List_Erase_383560(&result, l, &value); *out = result; }

extern "C" int TexMan_LoadNewTexture(Obj_37FEA0* o, int* file, int arg2)
{
    int flags;
    void* data;
    int idx;
    void* t;
    if ((unsigned char)FileMan_FindMember(file)) {
        return -1;
    }
    if (FileMan_GetSize(file) > 0x100040) {
        return -1;
    }
    flags = 0;
    if (func_0036D880(file)) {
        flags |= 0x1000;
    }
    if (!(*file & 4)) {
        data = Tdx_Read(o, file, &flags);
        if (!data) {
            return -1;
        }
    }
    if (o->freeA.count) {
        It_37FEA0 r;
        It_37FEA0 pos;
        Node_37FEA0* n = o->freeA.next;
        idx = n->value;
        pos.p = n;
        Erase(&r, &o->freeA, &pos);
    } else if (o->freeB.count) {
        It_37FEA0 r;
        It_37FEA0 pos;
        Node_37FEA0* n = o->freeB.next;
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
        t = Mem_Alloc(0, 0x70, D_004BC2B8, 0x4D8);
    }
    if (t) {
        t = func_003BBC90(t);
    }
    o->tex[idx] = t;
    if (*file & 4) {
        data = o->data;
        AsyncLoader_QueueLoad(Fstream_GetLoader(), file, func_003809E0, o->tex[idx], 0, 1, 1);
        flags |= 0x2000;
    }
    Tex_BuildGsRegisters(o->tex[idx], arg2, data, flags);
    return idx;
}



