/*
 * main/map: range (2 files, 0026DBC0-0026DDC0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_0026DBC0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct V3_26DBC0 { float x, y, z; };
struct Obj26DBC0 {
    void* vt;
};

struct Holder26DBC0 {
    char pad[0x30];
    char* x30;
};

struct Cam26DBC0 {
    char pad[0x100];
    char x100[0x514];
    float x614;
    float x618;
    float x61C;
    float x620;
    float x624;
};

struct Self26DBC0 {
    char pad[8];
    int* x8;
    Obj26DBC0* xC;
    char pad10[0x50];
    int x60;
    int x64;
    char pad68[0x28];
    int x90;
    int x94;
};

extern "C" {
extern int D_004FFD70;
extern int D_004FFD68;
extern char D_004FF0B0[];
extern Holder26DBC0* D_004FFC0C;
extern char D_004A8808[];
extern char D_004E0360[];
extern Cam26DBC0* D_004FFC2C;
extern float D_004FF030;
extern float D_004FF038;
extern float D_004FF040;
extern float D_004FF048;
extern float D_004FF050;

void IeNode_SetShown(int h, int a, int b);
int IeElement_Create(int h);
void IeElement_SetColour(int h, char* name);
void* Mem_Alloc(int pool, int size, char* file, int line);
void HudTracker_Construct(Obj26DBC0* o, int h, char* p);
void func_0026D040(float t, Self26DBC0* self);
void func_0026D940(Self26DBC0* self);
void func_003FA380(char* p, int n);
void func_0026C570(Self26DBC0* self);
}

extern "C" void func_0026DBC0(Self26DBC0* self)
{
    int h;
    Holder26DBC0* hd;
    Cam26DBC0* c;

    IeNode_SetShown(*self->x8, 1, 0);
    IeNode_SetShown(D_004FFD70, 1, 1);
    IeNode_SetShown(D_004FFD68, 1, 1);
    h = IeElement_Create(D_004FFD70);
    IeElement_SetColour(h, D_004FF0B0);
    hd = D_004FFC0C;
    if (hd && hd->x30) {
        Obj26DBC0* o;
        {
            AllocGuard g;
            o = (Obj26DBC0*)Mem_Alloc(0, 0x90, D_004A8808, 0x14A);
        }
        if (o) {
            HudTracker_Construct(o, h, hd->x30 + 0xC);
            o->vt = D_004E0360;
        }
        self->xC = o;
    }
    func_0026D040(0.0f, self);
    func_0026D940(self);
    c = D_004FFC2C;
    D_004FF030 = c->x620;
    D_004FF038 = c->x624;
    c->x620 = 0.5f;
    c->x624 = -1.0f;
    D_004FF040 = c->x614;
    D_004FF048 = c->x618;
    D_004FF050 = c->x61C;
    {
        V3_26DBC0 t;
        t.x = D_004FF040;
        t.y = D_004FF048;
        t.z = 0.25f;
        *(V3_26DBC0*)&c->x614 = t;
    }
    func_003FA380(c->x100, 2);
    func_0026C570(self);
    self->x64 = 0;
    self->x60 = self->x64;
    self->x94 = 0;
    self->x90 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026DBC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026DBC0 */

/* merge_units: begin func_0026DDC0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void operator_delete(void* allocation);
void Interface_Dtor(void* p, int flag);
int* func_0026D030(PtrVec* v, int i);
void func_0026DF80(PtrVec* v, int flag);
extern char D_004DCBB0[];
extern char D_004DC930[];
}

struct Elem {
    virtual void Destroy(int flag);
};

struct Holder {
    int unk0;
    void* vtbl;
    void* p;
    int unkC;
    PtrVec list;
};

extern "C" Holder* func_0026DDC0(Holder* self, short deleteFlag) {
    if (self) {
        self->vtbl = D_004DCBB0;
        {
            void* p = self->p;
            AllocGuard guard;
            Interface_Dtor(p, -1);
            Mem_Free(0, p, D_004A8808, 0x133);
        }
        {
            int i;
            for (i = self->list.count - 1; i >= 0; i--) {
                Elem* e = *(Elem**)func_0026D030(&self->list, i);
                AllocGuard guard;
                e->Destroy(-1);
                Mem_Free(0, e, D_004A8808, 0x137);
            }
        }
        self->list.count = 0;
        if (&self->list) func_0026DF80(&self->list, -1);
        if (self) self->vtbl = D_004DC930;
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026DDC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026DDC0 */
