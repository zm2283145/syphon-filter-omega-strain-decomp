#pragma cplusplus on
#include "types.h"
struct VObj45 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(void*); };
struct Ev45 { char p[0x10]; int id; };
struct Mgr45 { char p[0x20]; Ev45* sel; };
struct W456830 { char p[0xB0]; int id; };
extern "C" {
extern char D_004C1C60[];
extern char D_004C1C70[];
extern char D_004C1A38[];
extern char D_004A7520[];
extern unsigned char D_004FFBA0;
extern int D_004FFC2C;
extern char D_004FFB50[];
VObj45* func_0041DB80(W456830*, char*);
int sprintf(char*, const char*, ...);
char* Loc_LookupText(char*);
void func_0041BEB0(VObj45*, char*, int);
Mgr45* func_004147A0(void);
void func_004562E0(W456830*, int);
void func_00242900(int);
void func_0012FA60(void*, int);
void func_00131470(void*, int);
int func_003680A0(W456830*, Ev45*, int, int, int);
}

extern "C" int func_00456830(W456830* self, Ev45* ev, int code, int a3, int a4)
{
    unsigned short c = code;
    if (c == 0) {
        int id = ev->id;
        if (id != -1) {
            VObj45* o;
            char buf[16];
            self->id = id;
            o = func_0041DB80(self, D_004C1C60);
            o = (o != 0 && o->v20(D_004A7520) != 0) ? o : 0;
            if (o) {
                char* s;
                sprintf(buf, D_004C1C70, id);
                s = Loc_LookupText(buf);
                if (s) func_0041BEB0(o, s, 0);
                else func_0041BEB0(o, D_004C1A38, 0);
            }
            return 1;
        }
    }
    if (c == 2) {
        int x; if (func_004147A0()->sel) x = func_004147A0()->sel->id; else {
            asm { .set reorder } /* barrier: keeps the else block out of the beqz delay slot */
            x = -1;
        }
        if (x != -1) {
            func_004562E0(self, x);
            return 1;
        }
    }
    if (c == 0x1A && a3 == 0) {
        if (D_004FFBA0 != 0x13 && D_004FFBA0 != 0x14) {
            func_00242900(D_004FFC2C);
            func_0012FA60(D_004FFB50, 2);
            func_00131470(D_004FFB50, 0);
        }
        return 1;
    }
    return func_003680A0(self, ev, code, a3, a4);
}