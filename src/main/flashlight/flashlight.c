/*
 * main/flashlight: 2 files, 0045B990-0045BAD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0045B990 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "flashlight.h"
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC0045B990 { char vpad[4]; virtual int v0(...); };
struct VD0045B990 { virtual int v0(...); };
extern "C" {
int Mem_Free(...);
int TargetVis_Unregister(...);
int operator_delete(...);
extern char g_TargetVisMgr;
extern unsigned char D_00533880;
}
/* Deleting destructor (called as (fl, 1) from 001b57c0); frees the object when (short)flags > 0. */
extern "C" char * Flashlight_Destroy(Flashlight *fl, long long flags) {
    void **spot;
    char * light;
    char * glare;

    if (fl != NULL) {
        TargetVis_Unregister(&g_TargetVisMgr, fl->litSpot);
        light = (char *)(fl->beamLight);
        if ((light != NULL) && (light != NULL)) { /* inlined delete */
            ((VC0045B990 *)(light))->v0(1);
        }
        glare = (char *)(fl->glareLight);
        if ((glare != NULL) && (glare != NULL)) {
            ((VC0045B990 *)(glare))->v0(1);
        }
        spot = (void **)(fl->litSpot);
        {
            AllocGuard g;
        ((VD0045B990 *)(spot))->v0(-1);
        Mem_Free(0, spot, "flashlight.cc", 0x58);
        }
        if (((long long) (flags << 0x30) >> 0x30) > 0) {
            operator_delete(fl);
        }
    }
    return (char *)(fl);
}
#pragma pop /* merge_units */
/* merge_units: end func_0045B990 */

/* merge_units: begin func_0045BAD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on


struct VC0045BAD0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(); virtual int v24(); virtual int v25(); virtual int v26(); virtual int v27(); virtual int v28(); virtual int v29(); virtual int v30(); virtual int v31(); virtual int v32(); virtual int v33(); virtual int v34(...); };
extern "C" {
int IdMgr_Allocate(...);
void **Mem_Alloc(...);
void **cGOBJ_ctor(...);
extern char D_004C2018;
extern char D_0055C9F0; /* identity matrix */
}
extern "C" Flashlight * Flashlight_Construct(Flashlight * fl, int owner) {
    int kind;
    int id;
    void **spotObj;
    void **obj;

    {
        AllocGuard g;
    obj = Mem_Alloc(0, 0x60, &D_004C2018, 0x42); /* "flashlight.cc" */
    }
    if (obj != NULL) {
        kind = 0;
        IdMgr_Allocate(&id, FLASHLIGHT_LITSPOT_ID_CATEGORY);
        obj = cGOBJ_ctor(obj, &id, 0, &kind);
    }
    fl->litSpot = obj;
    spotObj = (void **)(fl->litSpot);
    ((VC0045BAD0 *)(spotObj))->v34(&D_0055C9F0, 0); /* vcall +0x90: set transform to identity */
    fl->on = 0;
    fl->beamLight = 0;
    fl->glareLight = 0;
    fl->owner = (void *)owner;
    *(int *)&fl->beamLength = 0xBF800000; /* -1.0f */
    *(int *)&fl->beamSpeed = 0;
    return fl;
}
#pragma pop /* merge_units */
/* merge_units: end func_0045BAD0 */
