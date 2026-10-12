#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

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

void func_003EEBE0(int h, int a, int b);
int func_003EF010(int h);
void func_003E7EE0(int h, char* name);
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_003E99B0(Obj26DBC0* o, int h, char* p);
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

    func_003EEBE0(*self->x8, 1, 0);
    func_003EEBE0(D_004FFD70, 1, 1);
    func_003EEBE0(D_004FFD68, 1, 1);
    h = func_003EF010(D_004FFD70);
    func_003E7EE0(h, D_004FF0B0);
    hd = D_004FFC0C;
    if (hd && hd->x30) {
        Obj26DBC0* o;
        {
            AllocGuard g;
            o = (Obj26DBC0*)Mem_Alloc(0, 0x90, D_004A8808, 0x14A);
        }
        if (o) {
            func_003E99B0(o, h, hd->x30 + 0xC);
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
