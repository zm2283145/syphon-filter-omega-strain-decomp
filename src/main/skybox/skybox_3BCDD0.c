/*
 * main/skybox: 3 files, 003BCDD0-003BCED0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BCDD0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x62]; unsigned char useLos; } Col_3BCDD0;
extern int Los_TraceWithWater(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int func_003C3880(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int Los_TraceTriangles(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int Col_TraceFloorTriangles(Col_3BCDD0* c, void* ray, int mode, void* out);
unsigned char Col_TraceFloorRay(Col_3BCDD0* c, void* ray, int mode, void* out) {
    unsigned char r;
    if (c->useLos) {
        if (mode) r = Los_TraceWithWater(c, ray, mode, out);
        else r = func_003C3880(c, ray, mode, out);
    } else if (mode) r = Los_TraceTriangles(c, ray, mode, out);
    else r = Col_TraceFloorTriangles(c, ray, mode, out);
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003BCDD0 */

/* merge_units: begin func_003BCE50 */
#pragma push /* merge_units */
typedef struct { char p00[0x62]; unsigned char mask; } ColA_3BCE50;
typedef struct { char p00[0x40]; unsigned char mask; } ColB_3BCE50;
extern int Los_TraceWaterSurfaces(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int Los_IntersectRecord(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int func_003C4120(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int Col_SegmentVsTriangle(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
unsigned char Col_TestSegmentTriangles(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d) {
    unsigned char r;
    int hit = (unsigned char)(b->mask & a->mask) != 0;
    if (mode) {
        if (hit)
            r = Los_TraceWaterSurfaces(a, b, mode, d);
        else
            r = Los_IntersectRecord(a, b, mode, d);
    } else {
        if (hit)
            r = func_003C4120(a, b, mode, d);
        else
            r = Col_SegmentVsTriangle(a, b, mode, d);
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_003BCE50 */

/* merge_units: begin func_003BCED0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int ColQuery_ExecuteSweep(int);
extern int ColQuery_InitSweep(int, int, int, int, int, int, int, float, float, float, float, float, float, float);

int ColQuery_ExecuteSweepThunk(int a0) {
    return ColQuery_ExecuteSweep(a0);
}

int ColQuery_RequestSweep(int a0, int a1, int a2, int a3, int t0, int t1, int t2, float f12, float f13, float f14, float f15, float f16, float f17) {
    return ColQuery_InitSweep(a0, a1, a2, a3, t0, t1, t2, 1.0f, f12, f13, f14, f15, f16, f17);
}
#pragma pop /* merge_units */
/* merge_units: end func_003BCED0 */
