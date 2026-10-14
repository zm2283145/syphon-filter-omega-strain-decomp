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

extern int func_00337B10(PairVec* v, Pair* pos, int count, Pair* value);

/* push_back on a vector of Pair. */
int func_0032EEA0(PairVec* v, Pair* value) {
    return func_00337B10(v, v->data + v->count, 1, value);
}

/* Pair constructor. */
Pair* func_0032EEC0(Pair* self, int first, int second) {
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
extern void* ObjectiveRow_Construct(LevelReq*, int, int, int);
extern void func_00147600(void*, void*);
#if 0 /* merge_units */
extern void* func_0032EEC0(LevelKey*, int, int);
#endif /* merge_units */
#define func_0032EEC0(a0, a1, a2) ((void *)func_0032EEC0((Pair *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_0032EEA0(void*, void*);
#endif /* merge_units */
#define func_0032EEA0(a0, a1) ((void)func_0032EEA0((PairVec *)(a0), (Pair *)(a1))) /* merge_units */


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
    func_00147600(&D_00532AF0, ObjectiveRow_Construct(&req, *(int*)a, -1, index));
    func_0032EEA0(&D_00532B90, func_0032EEC0(&key, bv, cv));
    return 0;
}
#undef func_0032EEC0 /* merge_units */
#undef func_0032EEA0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032EED0 */
