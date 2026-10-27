/*
 * Libs/SFOLib/Source/vu0man: 1 file, 003C6440
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003C6440 */
#pragma push /* merge_units */
#pragma peephole off
#include "types.h"
typedef struct { float m[4][4]; } __attribute__((aligned(16))) M40;
typedef struct { M40 m; __int128 q4; __int128 q5; } Xf60;

extern void cXform_GetInverseMatrix(M40* out, void* xf);
extern void cMatrix_Copy_InvertRotTrans(M40* out, M40* in);
extern void* cMatrix_LocalTransform(void* a, M40* b);
extern void* cLineSegment_Transform(void* a, M40* b);

void nCollision_GetTransformedCollectorObject_RelativeToObjectWithXform_cRayMatrixR_cRayMatrixR_cGOBJP_cXformP(__int128* dst, __int128* src, int unused, void* xf)
{
    M40 inv;
    M40 rig;
    /* empty asm: emits nothing, scheduling barrier so the entry daddu s0 precedes the first lq */
    { __int128 x, y; asm { .set noreorder; .set reorder } x = src[0]; y = src[1]; dst[0] = x; x = src[2]; dst[1] = y; y = src[3]; dst[2] = x; x = src[4]; dst[3] = y; y = src[5]; dst[4] = x; dst[5] = y; }
    cXform_GetInverseMatrix(&inv, xf);
    cMatrix_Copy_InvertRotTrans(&rig, &inv);
    cMatrix_LocalTransform(dst, &rig);
    cLineSegment_Transform(dst + 4, &inv);
}
static inline void merge_flush_func_003C6440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003C6440 */
