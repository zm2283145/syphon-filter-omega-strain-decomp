/*
 * main/hotbox: range (2 files, 00171B30-00171B60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00171B30 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
V4* cVector_Transform_cMatrixR(V4* a, V4* b) {
    asm {
        lqc2 vf8, 0x0(a)
        lqc2 vf4, 0x0(b)
        lqc2 vf5, 0x10(b)
        lqc2 vf6, 0x20(b)
        lqc2 vf7, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00171B30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00171B30 */

/* merge_units: begin func_00171B60 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x24]; unsigned char kind; char pad2[0xB]; int arg; } F6HbEvt;
extern "C" int* cMessage_Name(F6HbEvt*);
extern "C" int D_004EE698;
struct F6Hb { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void Handle(int a); };
extern "C" void cHotbox_HandleEnter(F6Hb*, int);
extern "C" void cHotbox_HandleExit(F6Hb*, int);
extern "C" int cHotbox_HandleMessage(F6Hb* self, F6HbEvt* e)
{
    int t = *cMessage_Name(e);
    if (t == D_004EE698) {
        switch (e->kind) {
        case 0:
            cHotbox_HandleEnter(self, e->arg);
            break;
        case 1:
            break;
        case 2:
            cHotbox_HandleExit(self, e->arg);
            break;
        case 3:
            self->Handle(e->arg);
            break;
        }
        return 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00171B60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00171B60 */
