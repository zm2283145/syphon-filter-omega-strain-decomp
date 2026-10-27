/*
 * main/AgentData: 3 files, 0032E930-0032E9D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032E930 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Inserts count copies of *value at pos (vector insert). */
extern int std_vector_imp_RatingRecord_insert(Vec24* v, Elem24* pos, int count, Elem24* value);

/* push_back: insert one element at the end. */
int cArray_RatingRecord_PushBackActual(Vec24* v, Elem24* value) {
    return std_vector_imp_RatingRecord_insert(v, &v->data[v->count], 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E930 */

/* merge_units: begin func_0032E960 */
#pragma push /* merge_units */
#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char data[0x1C]; } RatingReq;
extern char D_00532AD0[];
extern void* cAgentData_RatingRecord_ctor_charP_int_eScoreTypes_int_etc_2(RatingReq* r, int a, int b, int c, int d, int e, int f);
#if 0 /* merge_units */
extern void cArray_RatingRecord_PushBackActual(void* registry, void* item);
#endif /* merge_units */
#define cArray_RatingRecord_PushBackActual(a0, a1) ((void)cArray_RatingRecord_PushBackActual((Vec24 *)(a0), (Elem24 *)(a1))) /* merge_units */
int Script_cAgentData__RegisterRating_2(ScriptArg* args)
{
    RatingReq r;
    int b2;
    int p0[1];
    int p1[1];
    int p3[1];
    int p4[1];
    int p5[1];
    p5[0] = args[5].i;
    p4[0] = args[4].i;
    p3[0] = args[3].i;
    b2 = args[2].b;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    cArray_RatingRecord_PushBackActual(D_00532AD0, cAgentData_RatingRecord_ctor_charP_int_eScoreTypes_int_etc_2(&r, *(int*)p0, *(int*)p1, b2, *(int*)p3, *(int*)p4, *(int*)p5));
    return 0;
}
#undef cArray_RatingRecord_PushBackActual /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E960 */

/* merge_units: begin func_0032E9D0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cArray_RatingRecord_PushBackActual(void* registry, void* item);
#endif /* merge_units */
#define cArray_RatingRecord_PushBackActual(a0, a1) ((void)cArray_RatingRecord_PushBackActual((Vec24 *)(a0), (Elem24 *)(a1))) /* merge_units */
int Script_cAgentData__RegisterRating(ScriptArg* args)
{
    RatingReq r;
    int b2;
    int p0[1];
    int p1[1];
    int p3[1];
    int p4[1];
    p4[0] = args[4].i;
    p3[0] = args[3].i;
    b2 = args[2].b;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    cArray_RatingRecord_PushBackActual(D_00532AD0, cAgentData_RatingRecord_ctor_charP_int_eScoreTypes_int_etc_2(&r, *(int*)p0, *(int*)p1, b2, *(int*)p3, *(int*)p4, 0));
    return 0;
}
#undef cArray_RatingRecord_PushBackActual /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032E9D0 */
