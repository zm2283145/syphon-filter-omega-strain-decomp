/*
 * SFOGame/Source/player: 3 files, 00177DC0-00177E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00177DC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cRespawnMsg_dtor, D_004DB890, cMessage_dtor)
static inline void merge_flush_func_00177DC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00177DC0 */

/* merge_units: begin func_00177E20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cCBData_IsReferencing(void) {
    return 0;
}
static inline void merge_flush_func_00177E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00177E20 */

/* merge_units: begin func_00177E30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#include "q4_asm_copy.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004D9DA0[];
}
struct M_7E30 { __int128 r0, r1, r2, r3; };
struct Msg_7E30 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; char k; char p2[11]; M_7E30 m; };
/* clone a message: copy fields, swap vtable, 64-byte matrix via the Q4Copy idiom */
#pragma push
#pragma peephole off
extern "C" Msg_7E30* cMoveMsg_Template_1_Clone(Msg_7E30* src)
{
    Msg_7E30* p;
    {
        AllocGuard guard;
        p = (Msg_7E30*)cMemMan_Allocate(0, 0x70, "moveMsg.hh", 0x4C);
    }
    if (p) {
        M_7E30* d = &p->m;
        M_7E30* s = &src->m;
        p->vtable = D_004DFD80;
        p->a = src->a; p->b = src->b; p->c = src->c; p->d = src->d;
        p->e = src->e; p->f = src->f; p->g = src->g; p->h = src->h;
        p->vtable = D_004D9DA0;
        p->k = src->k;
        Q4Copy(d, s);
    }
    return p;
}
#pragma pop
static inline void merge_flush_func_00177E30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00177E30 */
