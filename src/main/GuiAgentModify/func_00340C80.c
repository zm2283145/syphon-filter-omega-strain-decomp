#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; } W_340C80;
typedef struct { char pad[4]; char s4[4]; } Snd_340C80;
typedef struct {
    char pad[0x88]; W_340C80* f88; char pad8C[0xEC - 0x8C]; int fEC; int fF0; char padF4[4]; int fF8;
    char padFC[0x144 - 0xFC]; int f144; int f148; int f14C; int f150;
} O_340C80;
extern char D_004B9F50[]; extern char D_004B9F58[]; extern char D_004B9F60[]; extern char D_004B9F68[];
extern char D_0055DDA0[]; extern char D_004B9ED0[]; extern char D_004B9EE8[];
char* func_001692D0(void* s);
void func_00341C50(O_340C80* o, char* s);
int strcmp(const char* a, const char* b);
void func_00341170(O_340C80* o, int v);
void func_00341240(O_340C80* o, Snd_340C80* s);
void func_00340320(O_340C80* o);
void func_00340850(O_340C80* o);
void func_00403310(void* p);
void func_0040F540(void);
void* func_00414790(void);
void* func_004147A0(void);
void* func_00418A80(void* mgr, char* a, char* b);
void func_00414AC0(void* mgr, void* o, void* w);
int func_00441CA0(O_340C80* o, Snd_340C80* s, unsigned short msg, int param, int extra);

int func_00340C80(O_340C80* o, Snd_340C80* snd, unsigned short msg, int param, int extra)
{
    if (msg == 0x10 && param == 1) return 1;
    if (msg == 0) {
        char* s;
        o->fF0 = 0;
        s = func_001692D0(snd->s4);
        func_00341C50(o, s);
        if (!strcmp(s, D_004B9F50)) {
            func_00341170(o, o->f144);
            func_00341170(o, o->f14C);
            func_00341170(o, o->f150);
            func_00341240(o, snd);
            if (o->fF8 == 0 && o->f88) o->f88->flags &= ~2;
            o->fEC = 3;
            o->fF0 = 1;
        }
        if (!strcmp(s, D_004B9F58)) {
            func_00341170(o, o->f148);
            func_00341170(o, o->f14C);
            func_00341170(o, o->f150);
            func_00341240(o, snd);
            o->fEC = 2;
            o->fF0 = 1;
        }
        if (!strcmp(s, D_004B9F60)) {
            func_00341170(o, o->f148);
            func_00341170(o, o->f144);
            func_00341170(o, o->f150);
            func_00341240(o, snd);
            o->fEC = 0;
            o->fF0 = 1;
        }
        if (!strcmp(s, D_004B9F68)) {
            func_00341170(o, o->f148);
            func_00341170(o, o->f144);
            func_00341170(o, o->f14C);
            func_00341240(o, snd);
            o->fEC = 1;
            o->fF0 = 1;
        }
        if (o->fF0 == 0 && o->fEC == 1) func_00340320(o);
        func_00340850(o);
    }
    if (msg == 0x1A && param == 0xC) {
        void* w;
        func_00403310(D_0055DDA0);
        func_0040F540();
        w = func_00418A80(func_00414790(), D_004B9ED0, D_004B9EE8);
        func_00414AC0(func_004147A0(), o, w);
        return 1;
    }
    return func_00441CA0(o, snd, msg, param, extra);
}