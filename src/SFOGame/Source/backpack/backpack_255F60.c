/*
 * main/backpack: range (2 files, 00255F60-00256120)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00255F60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tgt {
    char pad0[0xC];
    int serial;
    char pad10[0x2C - 0x10];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x3468 - 0x2F];
    unsigned char b3468;
    unsigned char b3469;
    char pad346A[0x3528 - 0x346A];
    int inv;
};
struct Hnd {
    Tgt* target;
    int serial;
    Tgt* Get() { Tgt* t = target; bool ok = !t || t->serial == serial; return ok ? t : 0; }
};
struct Ctl { char pad[0x9C]; int mode; };
struct Obj {
    char pad0[0x60];
    unsigned char b60;
    char pad61[0x2FC - 0x61];
    Ctl* ctl;
    Hnd h;
};
extern "C" int ItemInv_Any(int);
static inline bool A(Tgt* t) { bool v = t->b2D && t->b2C && !t->b2E && t->b3468; return v; }
static inline bool B(Tgt* t) { bool v = t->b2D && t->b2C && !t->b2E && t->b3469; return v; }
extern "C" void Backpack_UpdateBoxPriority(Obj* o)
{
    if (o->ctl) {
        int m = 0;
        if (o->b60 == 1) {
            m = 5;
        } else if (o->h.Get()) {
            if (A(o->h.Get()) || B(o->h.Get()) || ItemInv_Any(o->h.Get()->inv))
                m = 0x14;
        }
        o->ctl->mode = m;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00255F60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00255F60 */

/* merge_units: begin func_00256120 */
#pragma push /* merge_units */
typedef struct { char pad[0x2FC]; int effect; char pad300[0x14]; int unk314; } Obj002579E0;
extern void* g_HotboxTracker;
extern void cHotboxMan_RemoveHotbox(void* mgr, int effect);
extern void nGobjManager_RemoveGOBJ(int effect);
extern void cSystem_ActualScheduleDelete(int effect, float time);
/* Stop and release the attached effect. */
void cBackpack_RemoveInteractBox(Obj002579E0* obj)
{
    if (obj->effect) {
        cHotboxMan_RemoveHotbox(g_HotboxTracker, obj->effect);
        nGobjManager_RemoveGOBJ(obj->effect);
        cSystem_ActualScheduleDelete(obj->effect, 0.1f);
        obj->effect = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00256120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00256120 */
