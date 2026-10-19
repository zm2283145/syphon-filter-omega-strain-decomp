#include "types.h"
typedef struct { char p0[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; } Obj2D4FF0;
typedef struct { char p0[0x5C]; int x5C; } Ctl2D4FF0;
typedef struct { char p0[0x2C]; int id; int val; unsigned char flag; } Ev2D4FF0;
typedef struct {
    char p0[0x30]; Obj2D4FF0* obj; char p34[0x1B0 - 0x34]; Ctl2D4FF0* ctl; char p1B4[0x1F0 - 0x1B4];
    char vec[0x1C]; int val; char p210[4]; unsigned char b0 : 1; unsigned char b1 : 1;
} Self2D4FF0;
extern int D_004ED9B8, g_CasEventMsgClass, D_0051F0C0;
extern int* Event_GetType(Ev2D4FF0*);
extern void cNPC_v01(Self2D4FF0*, Ev2D4FF0*);
extern void func_0015F9B0(Ctl2D4FF0*, int, int, void*);
extern void func_0015FBD0(Ctl2D4FF0*, void*, int);
extern void func_002D79A0(Ev2D4FF0*, void*);
int func_002D4FF0(Self2D4FF0* s, Ev2D4FF0* e)
{
    int t = *Event_GetType(e);
    if (t == D_004ED9B8 || (t = *Event_GetType(e), t == g_CasEventMsgClass)) {
        cNPC_v01(s, e);
    } else if (t = *Event_GetType(e), t == D_0051F0C0) {
        Obj2D4FF0* o;
        int b;
        s->val = e->val;
        if ((e->flag != 0) ^ 1) {
            func_0015F9B0(s->ctl, e->id, s->val, 0);
        } else {
            func_002D79A0(e, s->vec);
            if (s->val >= 0) func_0015F9B0(s->ctl, e->id, s->val, s->vec);
            else func_0015FBD0(s->ctl, s->vec, s->ctl->x5C);
        }
        o = s->obj;
        b = o->b2D != 0 && o->b2C != 0 && !(o->b2E != 0);
        if (!b) s->b1 = 1;
    }
    return 1;
}


