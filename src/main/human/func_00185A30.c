#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma push
class V58_5A { public: VPAD16(p) VPAD2(q) virtual void v18(); virtual int v19(); };
class T_5A { public: VPAD16(p) VPAD2(q) virtual void v18(); virtual void v19(); virtual void v20();
    char pad4[0xC]; char sub10[0x40]; unsigned char b50; };
typedef struct { char pad0[8]; int id; char padC[4]; } Slot_5A;
typedef struct { Slot_5A slots[8]; char pad80[4]; unsigned char cur; } Weap_5A;
typedef struct { short ids[4]; float f; } Ids_5A;
typedef struct { char pad0[0x40]; char m40[0x40]; } Sub_5A;
typedef struct {
    char pad0[0xC]; int iC; int i10; char pad14[0x18];
    unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x11];
    float f40; char pad44[0xC]; T_5A* p50; char pad54[4]; V58_5A* o58; char pad5C[4];
    Sub_5A sub60; char padE0[0x3318 - 0xE0]; char m3318[0x3524 - 0x3318]; Weap_5A* weapons;
    char pad3528[0x3590 - 0x3528]; unsigned char b3590;
} O_5A;
extern Ids_5A D_0048A2F8;
static inline bool Ready_5A(O_5A* o) { return o->b2D && o->b2C && !o->b2E; }
extern "C" void func_002C72A0(int a, int b, int c, void* d, void* e, Ids_5A* ids, int f);
extern "C" void func_002C7110(int a, int b, int c, void* d, void* e, Ids_5A* ids, unsigned char r, unsigned char g, int f);
extern "C" int func_00185A30(O_5A* o, int a)
{
    if (Ready_5A(o)) {
        Ids_5A ids = D_0048A2F8;
        if (o->weapons) {
            int i;
            short* p;
            short first;
            Weap_5A* w = o->weapons;
            first = ids.ids[0] = (w->cur != 6) ? w->slots[w->cur].id : -1;
            i = 0;
            p = &ids.ids[1];
            for (; i < 6; i++) {
                int v = o->weapons->slots[(unsigned char)i].id;
                if (v != -1 && first != v) *p++ = v;
            }
        }
        bool ok = false;
        if (o->o58 && o->o58->v19()) ok = true;
        if (ok) {
            T_5A* t = o->p50;
            int b = o->i10;
            int c = o->iC;
            Sub_5A* s = &o->sub60;
            int f = (int)o->f40;
            if (t->b50) t->v20();
            func_002C72A0(a, b, c, t->sub10, s->m40, &ids, f);
        } else {
            int b;
            int c;
            unsigned char r;
            T_5A* t;
            char* e;
            int v = o->b2D;
            b = o->i10;
            c = o->iC;
            t = o->p50;
            e = o->m3318;
            if (v) v = o->b2C;
            r = v;
            if (v) r = !o->b2E;
            int f = (int)o->f40;
            if (t->b50) t->v20();
            func_002C7110(a, b, c, t->sub10, e, &ids, r, o->b3590, f);
        }
    }
    return 1;
}
#pragma pop