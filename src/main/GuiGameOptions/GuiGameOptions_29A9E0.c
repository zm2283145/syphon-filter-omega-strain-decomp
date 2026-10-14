/*
 * main/GuiGameOptions: range (2 files, 0029A9E0-0029AA50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

/* merge_units: begin func_0029A9E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetKickMsg_dtor, D_004DD5E0, D_004DCF10, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0029A9E0 */

/* merge_units: begin func_0029AA50 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Wdg_AA50;
extern "C" {
void func_0041BEB0(Wdg_AA50* w, char* text, int flags);
void func_0043F150(Wdg_AA50* w, int a, int b, int c, int d, int e);
}
static inline void Wdg_SetText(Wdg_AA50* w, char* t) { func_0041BEB0(w, t, 0); }
static inline void Wdg_SetValue(Wdg_AA50* w, float v, float t) { func_0043F150(w, 0, (int)(100.0f * v), 0, 100, (int)t); }

struct Hud_AA50 {
    char pad0[0xBC];
    unsigned char bBC, bBD, bBE, bBF;
    float fC0, fC4, fC8;
    int iCC;
    char padD0[4];
    float fD4;
    int iD8;
    char padDC[0x408 - 0xDC];
    Wdg_AA50* w408;
    Wdg_AA50* w40C;
    Wdg_AA50* w410;
    Wdg_AA50* w414;
    Wdg_AA50* w418;
    Wdg_AA50* w41C;
    Wdg_AA50* w420;
    Wdg_AA50* w424;
    Wdg_AA50* w428;
    Wdg_AA50* w42C;
    char pad430[8];
    char* t438[2];
    char* t440[6];
    char* t458;
    char* t45C;
    char* t460;
    char* t464;
};

extern "C" void func_0029AA50(Hud_AA50* h, int mask)
{
    float k10 = 10.0f;
    float k5 = 5.0f;
    
    if (h->w408 && (mask & 1)) Wdg_SetText(h->w408, h->bBC ? h->t45C : h->t458);
    if (h->w410 && (mask & 4)) Wdg_SetText(h->w410, h->bBE ? h->t45C : h->t458);
    if (h->w414 && (mask & 8)) Wdg_SetText(h->w414, h->bBF ? h->t458 : h->t45C);
    if (h->w40C && (mask & 2)) Wdg_SetText(h->w40C, h->bBD ? h->t460 : h->t464);
    if (h->w418 && (mask & 0x10)) Wdg_SetValue(h->w418, h->fC0, k10);
    if (h->w41C && (mask & 0x20)) Wdg_SetValue(h->w41C, h->fC4, k10);
    if (h->w420 && (mask & 0x40)) Wdg_SetValue(h->w420, h->fC8, k10);
    if (h->w424 && (mask & 0x80)) Wdg_SetText(h->w424, h->t438[h->iCC]);
    if (h->w428 && (mask & 0x400)) Wdg_SetValue(h->w428, h->fD4, k5);
    if (h->w42C && (mask & 0x800)) Wdg_SetText(h->w42C, h->t440[h->iD8]);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0029AA50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0029AA50 */
