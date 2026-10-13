#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Al3DD { int x; };
struct Scr3DD {
    char* name;
    char m4[0x10];
    char m14[0x10];
    char m24[0x10];
    int x34;
    int x38;
    unsigned char x3C;
    char pad3d[3];
    int x40;
    unsigned char x44;
    unsigned char x45;
    char pad46[2];
    int x48;
    unsigned char x4C;
};
struct Info3DD { char pad0[8]; int x8; char padc[0x38 - 0xC]; int id; unsigned char on; };
struct Mgr3DD { int pad0; int count; };
extern "C" {
extern char D_004BD4C0[];
extern Mgr3DD* D_00554F28;
void* Mem_Alloc(int pool, int size, char* file, int line);
char* Str_Duplicate(char*);
Al3DD* func_00290BB0(Al3DD*, int);
void func_003D8EF0(void*, Al3DD*, int);
void func_003D8E80(void*, Al3DD*, int);
void func_003D8E30(void*);
void func_003D8E10(Mgr3DD*, Scr3DD**);
void func_003D6D00(Scr3DD*, int, int, int, int, int);
Info3DD* func_003E0C30(int, char*);
}
static inline int Data3DD(Info3DD* i) { return i->on ? i->x8 : 0; }
extern "C" Scr3DD* func_003DD9F0(int ctx, char* name, int noInit, char* parent, int a, int b, int c)
{
    Scr3DD* s = (Scr3DD*)func_003E0C30(ctx, name);
    Info3DD* p = parent ? func_003E0C30(ctx, parent) : 0;
    int id = p ? p->id : -1;
    int d = (p && p->on) ? p->x8 : 0;
    if (!s) {
        Scr3DD* n;
        {
            AllocGuard g;
            n = (Scr3DD*)Mem_Alloc(0, 0x50, D_004BD4C0, 0xA84);
        }
        if (n) {
            char* nm = Str_Duplicate(name);
            Al3DD t1;
            func_003D8EF0(n->m4, func_00290BB0(&t1, 5), 1);
            Al3DD t2;
            func_003D8E80(n->m14, func_00290BB0(&t2, 5), 1);
            func_003D8E30(n->m24);
            n->name = nm;
            n->x34 = 0;
            n->x3C = 0;
            n->x40 = -1;
            n->x44 = 0;
            n->x45 = 0;
            n->x48 = 0;
            n->x4C = 1;
        }
        s = n;
        if (!noInit)
            func_003D6D00(s, a, b, c, id, d);
        s->x38 = D_00554F28->count + 100;
        func_003D8E10(D_00554F28, &s);
    } else if (!noInit) {
        func_003D6D00(s, a, b, c, id, d);
    }
    return s;
}


