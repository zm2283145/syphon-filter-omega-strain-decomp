#pragma cplusplus on
#include "types.h"
struct Sub_0029DFC0 { char pad[0x70]; int f70; };
struct Ui_0029DFC0 { char pad[0x265]; unsigned char f265; };
struct S_0029DFC0 {
    char pad0[0x88]; int f88; char pad8C[0xF4 - 0x8C]; Sub_0029DFC0* pF4; char padF8[0x100 - 0xF8];
    Sub_0029DFC0* p100; char pad104[0x118 - 0x104]; int f118;
};
extern "C" {
extern Ui_0029DFC0* D_004FFC04;
extern char D_004FFB50[];
extern char D_004AAC70[];
extern char D_004AAC80[];
void func_0029CBB0(S_0029DFC0* self, unsigned char sel);
void* func_00414790(void);
void* func_004147A0(void);
void* func_00418A80(void* a, char* b, char* c);
void func_00414AC0(void* ui, S_0029DFC0* self, void* pg);
int func_002CA070(void* ui);
void func_00288DE0(void* pg, int a);
char* Agent_GetSelected(void* a, int b);
int strlen(const char* s);
}
static inline bool HasText_DFC0(const char* s) { return strlen(s) != 0; }
static inline int IsEmpty_DFC0(const char* s) { return HasText_DFC0(s) ^ 1; }
extern "C" void func_0029DFC0(S_0029DFC0* self)
{
    unsigned char go = 0;
    int st = self->f118;
    if (st == 4 || st == 0) {
        self->f88 = 8;
        func_0029CBB0(self, 1);
        if (!self->pF4->f70)
            func_0029DFC0(self);
    } else if (st == 1 && self->f88 == 8) {
        self->f88 = 9;
        func_0029CBB0(self, 1);
        if (!self->pF4->f70)
            func_0029DFC0(self);
    } else if (st == 1 || st == 2) {
        func_0029CBB0(self, 2);
        if (!self->p100->f70)
            go = 1;
        else
            self->f88 = 0xA;
    }
    if (go) {
        void* pg;
        func_0029CBB0(self, 4);
        pg = func_00418A80(func_00414790(), D_004AAC70, D_004AAC80);
        if (pg) {
            unsigned char ok = 1;
            if (!D_004FFC04->f265 && !IsEmpty_DFC0(Agent_GetSelected(D_004FFB50, -1) + 0x8CC))
                ok = 0;
            if (ok && func_002CA070(D_004FFC04))
                func_00288DE0(pg, 1);
            else
                func_00288DE0(pg, 0);
            func_00414AC0(func_004147A0(), self, pg);
        }
    }
}


