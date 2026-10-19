/*
 * main/map: range (2 files, 0026D810-0026D940)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0026D810 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_26D810 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct M_26D810 { int id; };
struct Hum_26D810 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_26D810* ctl; };
struct Node_26D810 { int f0; Node_26D810* next; M_26D810* id; };
struct Holder_26D810 { char pad[0x30]; Hum_26D810* x30; };
struct Self_26D810 { int* x0; };
extern "C" {
extern int g_Hud;
extern Holder_26D810* g_LocalPlayer;
Hum_26D810* Object_LookupById(M_26D810* id);
void List_Begin_16E880(int* out, int* list);
void func_0026C390(Node_26D810** out, int b);
void func_0026C320(int* out, int* list);
void func_0026C350(Node_26D810** out, int* e);
void Hud_ClearCallout(int a, M_26D810* m, int n, int b, int c);
void HudMap_ClearCallouts(Self_26D810* self);
}
static inline Node_26D810* Begin_26D810(int* list) { Node_26D810* n; int b; List_Begin_16E880(&b, list); func_0026C390(&n, b); return n; }
static inline void End_26D810(Node_26D810** out, int* list) { int e; func_0026C320(&e, list); func_0026C350(out, &e); }

void HudMap_ClearCallouts(Self_26D810* self)
{
    int* list = self->x0 + 3;
    unsigned char r;
    Hum_26D810* h;
    Node_26D810* end;
    Node_26D810* it;
    for (it = Begin_26D810(list); End_26D810(&end, list), it != end; it = it->next) {
        h = Object_LookupById(it->id);
        if (h) {
            r = 0;
            if (h->ctl && h->ctl->IsPlayer()) r = 1;
            if (r) Hud_ClearCallout(g_Hud, it->id, 4, 1, 0);
        }
    }
    Holder_26D810* hd = g_LocalPlayer;
    if (hd) {
        h = hd->x30;
        if (h)
            Hud_ClearCallout(g_Hud, (M_26D810*)&h->flags, 4, 1, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026D810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026D810 */

/* merge_units: begin func_0026D940 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_26D940 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct M_26D940 { int id; };
struct Hum_26D940 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_26D940* ctl; };
struct Node_26D940 { int f0; Node_26D940* next; M_26D940* id; };
struct Holder_26D940 { char pad[0x30]; Hum_26D940* x30; };
struct Self_26D940 { int* x0; };
struct Buf_26D940 { char b0; char text[0x8F]; };
extern "C" {
extern unsigned char g_IsMultiplayer;
#if 0 /* merge_units */
extern Holder_26D940* g_LocalPlayer;
#endif /* merge_units */
#define g_LocalPlayer (*(Holder_26D940 **)&g_LocalPlayer) /* merge_units */

#if 0 /* merge_units */
Hum_26D940* Object_LookupById(M_26D940* id);
#endif /* merge_units */
#define Object_LookupById(a0) ((Hum_26D940 *)Object_LookupById((M_26D810 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void func_0026C390(Node_26D940** out, int b);
#endif /* merge_units */
#define func_0026C390(a0, a1) (func_0026C390((Node_26D810 * *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void func_0026C350(Node_26D940** out, int* e);
#endif /* merge_units */
#define func_0026C350(a0, a1) (func_0026C350((Node_26D810 * *)(a0), (a1))) /* merge_units */

void Hud_FormatPlayerCalloutName(Buf_26D940* b, int key, int c);
void Hud_ShowCallout(int a, M_26D940* m, char* text, int n, int b, int c, float f0, float f1);
void HudMap_AddPlayerCallouts(Self_26D940* self);
}
static inline unsigned char IsPlayer_26D940(Hum_26D940* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_26D940(Hum_26D940* h) { int id; if (g_IsMultiplayer) { if (IsPlayer_26D940(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
static inline Node_26D940* Begin_26D940(int* list) { Node_26D940* n; int b; List_Begin_16E880(&b, list); func_0026C390(&n, b); return n; }
static inline void End_26D940(Node_26D940** out, int* list) { int e; func_0026C320(&e, list); func_0026C350(out, &e); }

void HudMap_AddPlayerCallouts(Self_26D940* self)
{
    int* list = self->x0 + 3;
    Hum_26D940* h;
    Node_26D940* end;
    for (Node_26D940* it = Begin_26D940(list); End_26D940(&end, list), it != end; it = it->next) {
        h = Object_LookupById(it->id);
        if (h && IsPlayer_26D940(h)) {
            int id = LocalId_26D940(h);
            if (id >= 0 && id < 4) {
                Buf_26D940 buf;
                buf.b0 = 0;
                Hud_FormatPlayerCalloutName(&buf, id, 1);
                Hud_ShowCallout(g_Hud, it->id, buf.text, 4, 1, 0, -1.0f, -1.0f);
            }
        }
    }
    Holder_26D940* hd = g_LocalPlayer;
    if (hd) {
        h = hd->x30;
        if (h) {
            int id = LocalId_26D940(h);
            if (id >= 0 && id < 4) {
                Buf_26D940 buf;
                buf.b0 = 0;
                Hud_FormatPlayerCalloutName(&buf, id, 1);
                Hud_ShowCallout(g_Hud, (M_26D940*)&hd->x30->flags, buf.text, 4, 1, 0, -1.0f, -1.0f);
            }
        }
    }
}
#undef g_LocalPlayer /* merge_units */
#undef Object_LookupById /* merge_units */
#undef func_0026C390 /* merge_units */
#undef func_0026C350 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0026D940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0026D940 */
