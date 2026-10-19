/*
 * main/map: range (2 files, 0026C830-0026C8D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0026C830 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int state; } Sub26C8;
typedef struct { Sub26C8* sub; } Self26C8;
typedef struct { char pad[0x10]; int kind; } Obj26C8;
extern Obj26C8* HudMarkers_GetHighlight(Sub26C8* s);
extern void HudMarkers_SetHighlight(Sub26C8* s, int v);
extern void HudMap_Commit(Self26C8* s);
extern void HudMap_NextMarker(Self26C8* s);
void func_0026C830(Self26C8* s, Obj26C8* o) {
    unsigned char ok = 1;
    if (!(o->kind == 1 || o->kind == 2)) ok = 0;
    if (ok && o == HudMarkers_GetHighlight(s->sub)) {
        if (s->sub->state == 1) {
            HudMarkers_SetHighlight(s->sub, 0);
            HudMap_Commit(s);
        } else {
            HudMap_NextMarker(s);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026C830(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026C830 */

/* merge_units: begin func_0026C8D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_26C8D0 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct Hum_26C8D0 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_26C8D0* ctl; };
struct G_26C8D0 { char pad[0x60]; unsigned char b60; };
struct S_26C8D0 { int f0; int f4; G_26C8D0** f8; };
struct M_26C8D0 { int id; char pad[0xC]; int f10; };
struct Buf_26C8D0 { char b0; char text[0x8F]; };
extern "C" {
extern unsigned char g_IsMultiplayer;
extern int g_Hud;
Hum_26C8D0* Object_LookupById(M_26C8D0* id);
#if 0 /* merge_units */
int HudMarkers_GetHighlight(int a);
#endif /* merge_units */
#define HudMarkers_GetHighlight(a0) ((int)HudMarkers_GetHighlight((Sub26C8 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void HudMarkers_SetHighlight(int a, M_26C8D0* m);
#endif /* merge_units */
#define HudMarkers_SetHighlight(a0, a1) (HudMarkers_SetHighlight((Sub26C8 *)(a0), (int)(a1))) /* merge_units */

#if 0 /* merge_units */
void HudMap_Commit(S_26C8D0* s);
#endif /* merge_units */
#define HudMap_Commit(a0) (HudMap_Commit((Self26C8 *)(a0))) /* merge_units */

void Hud_FormatPlayerCalloutName(Buf_26C8D0* b, int key, int c);
void Hud_ShowCallout(int a, M_26C8D0* m, char* text, int n, int b, int c, float f0, float f1);
void HudMap_OnTargetAdded(S_26C8D0* s, M_26C8D0* m);
}
static inline unsigned char IsPlayer_26C8D0(Hum_26C8D0* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_26C8D0(Hum_26C8D0* h) { int id; if (g_IsMultiplayer) { if (IsPlayer_26C8D0(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }

void HudMap_OnTargetAdded(S_26C8D0* s, M_26C8D0* m)
{
    bool b = m->f10 == 1 || m->f10 == 2;
    if (b) {
        if (!HudMarkers_GetHighlight(s->f0)) {
            HudMarkers_SetHighlight(s->f0, m);
            HudMap_Commit(s);
        }
    } else if (m->f10 == 0 && (*s->f8)->b60) {
        Hum_26C8D0* h = Object_LookupById(m);
        if (h && IsPlayer_26C8D0(h)) {
            int id = LocalId_26C8D0(h);
            if (id >= 0 && id < 4) {
                Buf_26C8D0 buf;
                buf.b0 = 0;
                Hud_FormatPlayerCalloutName(&buf, id, 1);
                Hud_ShowCallout(g_Hud, m, buf.text, 4, 1, 0, -1.0f, -1.0f);
            }
        }
    }
}
#undef HudMarkers_GetHighlight /* merge_units */
#undef HudMarkers_SetHighlight /* merge_units */
#undef HudMap_Commit /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026C8D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026C8D0 */
