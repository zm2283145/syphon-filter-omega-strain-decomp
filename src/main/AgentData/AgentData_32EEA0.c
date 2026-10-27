/*
 * main/AgentData: 2 files, 0032EEA0-0032EED0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032EEA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

extern int std_vector_imp_tParTimes_insert(PairVec* v, Pair* pos, int count, Pair* value);

/* push_back on a vector of Pair. */
int cArray_tParTimes_PushBackActual(PairVec* v, Pair* value) {
    return std_vector_imp_tParTimes_insert(v, v->data + v->count, 1, value);
}

/* Pair constructor. */
Pair* cAgentData_tParTimes_ctor(Pair* self, int first, int second) {
    self->first = first;
    self->second = second;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032EEA0 */

/* merge_units: begin func_0032EED0 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

typedef struct LevelReq {
    char b[0x18];
} LevelReq;

typedef struct LevelKey {
    char b[8];
} LevelKey;

extern int D_004926E0;
extern int D_00532AF0;
extern int D_00532B90;
extern void* cAgentData_Record_ctor_charP_int_int(LevelReq*, int, int, int);
extern void cArray_Record_PushBackActual(void*, void*);
#if 0 /* merge_units */
extern void* cAgentData_tParTimes_ctor(LevelKey*, int, int);
#endif /* merge_units */
#define cAgentData_tParTimes_ctor(a0, a1, a2) ((void *)cAgentData_tParTimes_ctor((Pair *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cArray_tParTimes_PushBackActual(void*, void*);
#endif /* merge_units */
#define cArray_tParTimes_PushBackActual(a0, a1) ((void)cArray_tParTimes_PushBackActual((PairVec *)(a0), (Pair *)(a1))) /* merge_units */


/* Script: cAgentData::_RegisterLevel(a, b, c) - registers a level and its key. */
int Script_cAgentData__RegisterLevel(ScriptArg* args) {
    LevelReq req;
    LevelKey key;
    int a[1];
    int b[1];
    int c[1];
    int index;
    int cv;
    int bv;
    c[0] = args[2].i;
    index = D_004926E0;
    cv = *(int*)c;
    b[0] = args[1].i;
    bv = *(int*)b;
    a[0] = args[0].i;
    D_004926E0 = index + 1;
    cArray_Record_PushBackActual(&D_00532AF0, cAgentData_Record_ctor_charP_int_int(&req, *(int*)a, -1, index));
    cArray_tParTimes_PushBackActual(&D_00532B90, cAgentData_tParTimes_ctor(&key, bv, cv));
    return 0;
}
#undef cAgentData_tParTimes_ctor /* merge_units */
#undef cArray_tParTimes_PushBackActual /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032EED0 */
