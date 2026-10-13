#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct { char pad[0xC]; int serial; char pad10[0x2C - 0x10]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x3468 - 0x2F]; unsigned char b3468; unsigned char b3469; char pad346A[0x3528 - 0x346A]; int inv; } T_66B0;
typedef struct { char pad[0x94]; int id; } RT_66B0;
class S_66B0 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Enable(int on);
    char padv[0xC - 4];
    int id;
    char pad10[0x2FC - 0x10];
    RT_66B0* rt;
    T_66B0* tgt;
    int serial;
};
extern "C" {
RT_66B0* Hotbox_CreateRuntime(int, S_66B0*, int, int);
int ItemInv_Any(int);
void Object_Register(S_66B0*);
}
extern int D_004FFBD0;
static inline T_66B0* Get_66B0(S_66B0* s) { T_66B0* t = s->tgt; bool ok = !t || t->serial == s->serial; return ok ? t : 0; }
static inline unsigned char CanA(S_66B0* s)
{
    unsigned char r = 0;
    if (Get_66B0(s)) {
        T_66B0* g = Get_66B0(s);
        int ok = g->b2D != 0;
        ok = ok ? g->b2C != 0 : ok;
        ok = ok ? (g->b2E != 0) ^ 1 : ok;
        ok = ok ? g->b3468 != 0 : ok;
        if (ok) r = 1;
    }
    return r;
}
static inline unsigned char CanB(S_66B0* s)
{
    unsigned char r = 0;
    if (Get_66B0(s)) {
        T_66B0* g = Get_66B0(s);
        int ok = g->b2D != 0;
        ok = ok ? g->b2C != 0 : ok;
        ok = ok ? (g->b2E != 0) ^ 1 : ok;
        ok = ok ? g->b3469 != 0 : ok;
        if (ok) r = 1;
    }
    return r;
}

extern "C" void func_002566B0(S_66B0* s, T_66B0* t)
{
    s->tgt = t;
    {
        int tmp;
        int* p;
        if (t) p = &t->serial; else { tmp = -1; p = &tmp; }
        s->serial = *p;
    }
    if (CanA(s) || CanB(s) || (t && ItemInv_Any(t->inv))) {
        if (!s->rt) {
            s->Enable(1);
            Object_Register(s);
            if (!s->rt) {
                s->rt = Hotbox_CreateRuntime(D_004FFBD0, s, 0, 1);
                s->rt->id = s->id;
            }
        }
    }
}


