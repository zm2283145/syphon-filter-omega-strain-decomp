#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Obj_002A1780 {
    VPAD16(a) VPAD4(b) virtual int IsA(void* t);
};
struct Game_002A1780 { char pad[0x255C]; volatile int state; };
struct Self_002A1780 {
    char pad0[0x80];
    unsigned char b80;
    char pad81[7];
    char s88[0x1C];
    char sA4[0x1C];
    char sC0[0x1C];
    Obj_002A1780* pDC;
    Obj_002A1780* pE0;
    Obj_002A1780* pE4;
    Obj_002A1780* pE8;
    Obj_002A1780* pEC;
    char padF0[8];
    unsigned char bF8;
};
extern "C" {
extern char* D_0048BA40;
extern char* D_0048BA48;
extern char* D_0048BA50;
extern char* D_0048BA58;
extern char* D_0048BA60;
extern char* D_0048BA68;
extern char D_004A7520[];
extern char D_004AAFF0[];
extern char* D_004FFC04;
extern char D_005064A8;
extern int D_005064B0;
extern int D_005064B8;
void func_002CC260(void);
Obj_002A1780* func_0041DB80(Self_002A1780* self, char* name);
void func_0041BEB0(void* w, char* s, int a);
void func_002A1670(Self_002A1780* self);
Game_002A1780* func_004294C0(void);
void func_004426B0(Game_002A1780* g);
unsigned char func_004518F0(Game_002A1780* g, void* cb, void* a, void* b, void* c);
char* func_0033CE30(Self_002A1780* self, int a, int b, int c, int d, int e);
int func_002CAE30(void* ui, int a, char* b, char* c, Self_002A1780* d, int e);
}

static inline Obj_002A1780* AsA(Obj_002A1780* obj) { return (obj && obj->IsA(D_004A7520)) ? obj : 0; }
#define CAST(p) p = AsA(p)
extern "C" void func_002A1780(Self_002A1780* self)
{
    Obj_002A1780* p;
    Game_002A1780* g;
    if (self->b80)
        return;
    self->pDC = func_0041DB80(self, D_0048BA40);
    self->pE0 = func_0041DB80(self, D_0048BA48);
    self->pE4 = func_0041DB80(self, D_0048BA60);
    p = func_0041DB80(self, D_0048BA50);
    CAST(p);
    self->pE8 = p;
    p = func_0041DB80(self, D_0048BA58);
    CAST(p);
    self->pEC = p;
    p = func_0041DB80(self, D_0048BA68);
    CAST(p);
    if (p) {
        asm { .set reorder }
        func_0041BEB0(p, D_004FFC04 + 0x1C8, 0);
    }
    func_002A1670(self);
    self->bF8 = 0;
    g = func_004294C0();
    if (g) {
        if (g->state == 4) {
            asm { .set reorder }
            func_004426B0(g);
        } else {
            asm { .set reorder }
            if (g->state != 5) {
                self->bF8 = func_004518F0(g, (void*)func_002CC260, self->s88, self->sA4, self->sC0);
                if (!self->bF8) {
                    asm { .set reorder }
                    char* ui = D_004FFC04;
                    func_002CAE30(ui, 2, D_004AAFF0, func_0033CE30(self, 0x5A, 0, 0, 0, 0), self, 0xB);
                }
            }
        }
    }
    D_005064A8 = 0;
    D_005064B0 = 0;
    D_005064B8 = 0;
    self->b80 = 1;
}




