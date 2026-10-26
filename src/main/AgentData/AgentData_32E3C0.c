/*
 * main/AgentData: 2 files, 0032E3C0-0032E400
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032E3C0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* end() of a vector of 24-byte elements. */
Elem24* std_vector_imp_Record_end(Vec24* v) {
    return v->data + v->count;
}

void std_vector_Record_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
Elem24* std_vector_imp_Record_begin(Vec24* v) {
    return v->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E3C0 */

/* merge_units: begin func_0032E400 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

typedef struct OmegaReq {
    char b[0x20];
} OmegaReq;

extern int D_00532BB0;
extern void* OmegaReqRow_Construct(OmegaReq*, int, int, int, int, int, int);
extern void cArray_tRequirementInfo_PushBackActual(void*, void*);

/* Script: cAgentData::RegisterOmegaReq(a, b, c, d). */
int Script_cAgentData__RegisterOmegaReq(ScriptArg* args) {
    OmegaReq req;
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    d[0] = args[3].i;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    cArray_tRequirementInfo_PushBackActual(&D_00532BB0, OmegaReqRow_Construct(&req, *(int*)a, 0, 0, *(int*)b, *(int*)c, *(int*)d));
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E400 */
