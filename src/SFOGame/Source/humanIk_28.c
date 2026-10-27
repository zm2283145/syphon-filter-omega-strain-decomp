/*
 * SFOGame/Source/humanIk: 5 files, 001D7840-001D7A20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001D7840 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Copy a Rec24 (0x24-byte record, see cSkaAnimDataIterator_ctor_void for its constructor). */
Rec24* cSkaAnimDataIterator_opAssign(Rec24* d, Rec24* s) {
    d->unk00 = s->unk00;
    d->unk04 = s->unk04;
    d->unk08 = s->unk08;
    d->unk0C = s->unk0C;
    d->unk10 = s->unk10;
    d->unk14 = s->unk14;
    d->unk18 = s->unk18;
    d->unk1C = s->unk1C;
    d->unk20 = s->unk20;
    return d;
}
static inline void merge_flush_func_001D7840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7840 */

/* merge_units: begin func_001D7890 */
#pragma push /* merge_units */
typedef struct { int pad0; union { unsigned int u; int i; } frames; int pad8; float fps; } C1D7890;
typedef struct { C1D7890* clip; int owner; float rate; int w0C, w10, w14, w18, w1C; unsigned char b20; } K1D7890;
extern void cSkaAnimDataIterator_GotoAnimFrame(K1D7890* k, float t);
K1D7890* cSkaAnimDataIterator_ctor_cSkaAnimDataR_cSkeletonDataR(K1D7890* k, C1D7890* clip, int owner)
{
    k->clip = clip;
    k->owner = owner;
    k->rate = 0;
    k->w0C = 0;
    k->w10 = 0;
    k->w14 = 0;
    k->w18 = 0;
    k->w1C = 0;
    k->b20 = 0;
    {
        C1D7890* c = k->clip;
        k->rate = (float)c->frames.i / ((float)c->frames.u * c->fps);
    }
    cSkaAnimDataIterator_GotoAnimFrame(k, 0.0f);
    return k;
}
static inline void merge_flush_func_001D7890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7890 */

/* merge_units: begin func_001D7940 */
#pragma push /* merge_units */
#include "stored_event_post.h"
DEFINE_STORED_EVENT_POST(cHumanIkRoutine_SendEndOfUpperBodyAnimWithRightHandLookatMessage, 0x364)
static inline void merge_flush_func_001D7940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7940 */

/* merge_units: begin func_001D79B0 */
#pragma push /* merge_units */
DEFINE_STORED_EVENT_POST(cHumanIkRoutine_SendEndOfUpperBodyAnimMessage, 0x32C)
static inline void merge_flush_func_001D79B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D79B0 */

/* merge_units: begin func_001D7A20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct It1D7A20 { char* p; };
extern "C" {
char* std_vector_imp_cBone_begin(void* v);
char* std_vector_imp_cBone_end(void* v);
void std_vector_cBone_pointer2iterator(It1D7A20* out, void* v, char** p);
extern char* UpperBodyNodeTable[];
}
struct O1D7A20 { int pad; char* list; };
static inline bool It1D7A20_eq(char* a, char* b) { return a == b; }
static inline bool It1D7A20_ne(char* a, char* b) { return !It1D7A20_eq(a, b); }
extern "C" void cHumanIkRoutine_InitializeWorkspaceAtStartOfNextFrame(O1D7A20* o)
{
    void* v = o->list + 0x18;
    It1D7A20 it;
    It1D7A20 end;
    char* p;
    {
        char* t = std_vector_imp_cBone_begin(v);
        std_vector_cBone_pointer2iterator(&it, v, &t);
    }
    p = it.p;
    {
        char* t = std_vector_imp_cBone_end(v);
        std_vector_cBone_pointer2iterator(&end, v, &t);
    }
    char** out = UpperBodyNodeTable;
    char* e = end.p;
    for (; It1D7A20_ne(p, e); p += 0x1D0) {
        *out = p;
        out += 0x40;
    }
}
static inline void merge_flush_func_001D7A20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001D7A20 */
