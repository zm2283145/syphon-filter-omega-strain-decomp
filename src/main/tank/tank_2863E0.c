/*
 * main/tank: range (2 files, 002863E0-00286520)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#include "net_local_id.h"

/* merge_units: begin func_002863E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct Obj_63E0 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void activate(int on);
    char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0x4B]; int f60; int f64; int f68; int f6C; unsigned char b70; char pad71[3]; int f74;
};
extern "C" {
extern char g_TargetVisMgr[];
void TargetVis_Register(void* list);
void Object_Register(Obj_63E0* o);
int NetMap_BindReceiver(int id, int owner, Obj_63E0* o);
}
static inline int NetHostOk_63E0(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" void func_002863E0(Obj_63E0* o, int arg1)
{
    o->f60 = arg1;
    o->f6C = 0;
    o->f68 = 0;
    o->f64 = 0;
    o->b70 = 1;
    TargetVis_Register(g_TargetVisMgr);
    Object_Register(o);
    o->activate(1);
    o->f74 = 0;
    if (g_IsMultiplayer) {
        o->id10 = o->idC;
        if (!NetHostOk_63E0()) o->b14 = 0;
        {
            int t = o->id10;
            NetMap_BindReceiver(t, NetObjId(), o);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002863E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002863E0 */

/* merge_units: begin func_00286520 */
#pragma push /* merge_units */
void func_00286520(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 92) = a1;
    if (cond) goto L00286538;
    v1 = a1 + 12;
    goto L00286548;
L00286538:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L00286548:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 96) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00286520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00286520 */
