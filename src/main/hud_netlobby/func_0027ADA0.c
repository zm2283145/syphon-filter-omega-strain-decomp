#include "types.h"
typedef struct { float r, g, b, a; } Col27AD;
typedef struct { char pad0[4]; void* p4; char pad8[4]; void* pC; char pad10[0x1C]; int count; char pad30[8]; int sel; int mode; } Menu27AD;
extern unsigned char D_00504040;
extern void func_0027B4E0(Menu27AD* s);
extern void IeElement_SetColour(void* o, Col27AD* c);

void func_0027ADA0(Menu27AD* s)
{
    if (s->mode == 0 && s->count && D_00504040 && s->sel == 0) {
        s->sel = 1;
        func_0027B4E0(s);
    }
    if (s->count == 0) {
        Col27AD a, b;
        a.r = 1.0f; a.g = 1.0f; a.b = 1.0f; a.a = 1.0f;
        IeElement_SetColour(s->p4, &a);
        b.r = 0.5f; b.g = 0.5f; b.b = 0.5f; b.a = 1.0f;
        IeElement_SetColour(s->pC, &b);
    } else {
        Col27AD c, d;
        if (D_00504040) {
            c.r = 0.5f; c.g = 0.5f; c.b = 0.5f; c.a = 1.0f;
            IeElement_SetColour(s->p4, &c);
        }
        d.r = 1.0f; d.g = 1.0f; d.b = 1.0f; d.a = 1.0f;
        IeElement_SetColour(s->pC, &d);
    }
}
