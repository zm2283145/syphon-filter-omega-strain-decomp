#include "types.h"
typedef struct { char pad0[0xC]; unsigned char en; char p1[3]; unsigned char b10; char p2[0xB];
    unsigned char b1C; char p3[0xB]; unsigned char b28; char p4[0xB]; unsigned char b34; char p5[0xB];
    unsigned char b40; char p6[0x1B]; } E34FEC0;
typedef struct { int a; unsigned int count; E34FEC0* items; } T34FEC0;
typedef struct { char pad[0xC0]; T34FEC0* tab; } S34FEC0;
extern char D_00587BA0[];
extern char D_00587BB0[];
extern char D_00587BC0[];
extern void func_00425DB0(S34FEC0*, char*);
extern void func_00425EA0(S34FEC0*, unsigned int, unsigned int, int);
void func_0034FEC0(S34FEC0* self, unsigned int kind, unsigned int idx, int arg) {
    T34FEC0* t = self->tab;
    E34FEC0* e;
    char* s;
    if (!t || kind >= 11 || idx >= t->count) return;
    e = &t->items[idx];
    s = D_00587BB0;
    if (!e->en && kind != 0) return;
    switch (kind) {
    case 0:
        if (e->en) s = D_00587BA0;
        else s = D_00587BC0;
        break;
    case 1: case 2:
        if (e->b10) s = D_00587BA0;
        break;
    case 4: case 5:
        if (e->b1C) s = D_00587BA0;
        break;
    case 7:
        if (e->b28) s = D_00587BA0;
        break;
    case 9:
        if (e->b34) s = D_00587BA0;
        break;
    case 10:
        if (e->b40) s = D_00587BA0;
        break;
    }
    func_00425DB0(self, s);
    func_00425EA0(self, kind, idx, arg);
}