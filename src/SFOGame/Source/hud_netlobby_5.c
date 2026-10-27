/*
 * SFOGame/Source/hud_netlobby: 1 file, 0027ADA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027ADA0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float r, g, b, a; } Col27AD;
typedef struct { char pad0[4]; void* p4; char pad8[4]; void* pC; char pad10[0x1C]; int count; char pad30[8]; int sel; int mode; } Menu27AD;
extern unsigned char D_00504040;
extern void cHudNetLobby_SetActive(Menu27AD* s);
extern void cInterfaceElement_SetFilterColor(void* o, Col27AD* c);

void cHudNetLobby_UpdateGameAvailable(Menu27AD* s)
{
    if (s->mode == 0 && s->count && D_00504040 && s->sel == 0) {
        s->sel = 1;
        cHudNetLobby_SetActive(s);
    }
    if (s->count == 0) {
        Col27AD a, b;
        a.r = 1.0f; a.g = 1.0f; a.b = 1.0f; a.a = 1.0f;
        cInterfaceElement_SetFilterColor(s->p4, &a);
        b.r = 0.5f; b.g = 0.5f; b.b = 0.5f; b.a = 1.0f;
        cInterfaceElement_SetFilterColor(s->pC, &b);
    } else {
        Col27AD c, d;
        if (D_00504040) {
            c.r = 0.5f; c.g = 0.5f; c.b = 0.5f; c.a = 1.0f;
            cInterfaceElement_SetFilterColor(s->p4, &c);
        }
        d.r = 1.0f; d.g = 1.0f; d.b = 1.0f; d.a = 1.0f;
        cInterfaceElement_SetFilterColor(s->pC, &d);
    }
}
static inline void merge_flush_func_0027ADA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027ADA0 */
