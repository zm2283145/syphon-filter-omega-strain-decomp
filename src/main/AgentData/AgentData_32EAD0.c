/*
 * main/AgentData: 3 files, 0032EAD0-0032EB80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032EAD0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Inserts count copies of *value at pos (vector insert). */
extern int std_vector_imp_tRankInfo_insert(Vec36* v, Elem36* pos, int count, Elem36* value);

/* push_back: insert one element at the end. */
int cArray_tRankInfo_PushBackActual(Vec36* v, Elem36* value) {
    return std_vector_imp_tRankInfo_insert(v, &v->data[v->count], 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032EAD0 */

/* merge_units: begin func_0032EB00 */
#pragma push /* merge_units */
typedef struct { int a; int index; int b; int c; char name[16]; int key; } R2EB00;
extern char* strncpy(char* d, const char* s, unsigned int n);
extern int sprintf(char* buf, const char* fmt, ...);
extern int Loc_FindKeyThunk(char* key);
R2EB00* Awards_FormatRankTitle(R2EB00* r, int a, int b, int c, int index, const char* name)
{
    char buf[16];
    r->a = a;
    r->b = b;
    r->c = c;
    r->index = index;
    if (name)
        strncpy(r->name, name, 16);
    else
        r->name[0] = 0;
    sprintf(buf, "S_RANK_%2.2d", r->index + 1);
    r->key = Loc_FindKeyThunk(buf);
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_0032EB00 */

/* merge_units: begin func_0032EB80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int cArray_tRankInfo_Size(char* self) {
    return *(int*)(self + 4);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032EB80 */
