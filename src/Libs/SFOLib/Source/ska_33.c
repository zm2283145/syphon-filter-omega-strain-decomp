/*
 * Libs/SFOLib/Source/ska: 2 files, 003B1260-003B1290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B1260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern int std_list_deleter_voidPtr_insert(int* result, List* list, void** pos, int value);

/* Append value at the end of the list (insert before the sentinel at +4). */
int std_list_cSkaPlaybackGroupPtr_push_back(List* list, int value) {
    struct {
        void* pos;
        int result;
    } loc;

    loc.pos = &list->first;
    return std_list_deleter_voidPtr_insert(&loc.result, list, &loc.pos, value);
}
static inline void merge_flush_func_003B1260(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B1260 */

/* merge_units: begin func_003B1290 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
/* cSkaPlaybackGroup_Add: add a clip's contribution to a channel, merging it into an existing entry for the same clip */
struct V4 { float x, y, z, w; V4() {} } __attribute__((aligned(16)));
typedef struct { char pad[0x45]; unsigned char b45; } Obj;
typedef struct { Obj* id; float weight; unsigned char active; char pad[7]; V4 v; } Ent;
typedef struct { int cap; int count; Ent* data; } EVec;
typedef struct Contrib {
    int id;
    EVec vec;
    int pad10;
    unsigned char active;
    char pad15[3];
    float sum;
    float wsum;
    int f20[3];
    int f2C;
    unsigned char f30;
    unsigned char f31;
    unsigned char f32;
} Contrib;
extern "C" {
Ent** std_vector_deleter_cSkaPlaybackItem_data(EVec* v);
Ent* cSkaPlaybackItem_opAssign(Ent* d, Ent* s);
V4 cSkaPlaybackItem_GetSummedOffsetRootRotation(Ent* e);
V4 cQuaternion_opAdd_cQuaternionR(V4* a, V4* b);
V4* cQuaternion_opAssign(V4* d, V4* s);
int std_vector_imp_cSkaPlaybackItem_insert(EVec* v, Ent* pos, int n, Ent* value);
void cSkaPlaybackGroup_Add(Contrib* c, Ent* e, float k);
}
static inline bool Ne(Ent* a, Ent* b) { return !(a == b); }
void cSkaPlaybackGroup_Add(Contrib* c, Ent* e, float k)
{
    bool found = 0;
    float w = e->weight;
    c->active = 1;
    c->sum += w;
    c->wsum += k * w;
    Ent* it = *std_vector_deleter_cSkaPlaybackItem_data(&c->vec);
    Ent* end = *std_vector_deleter_cSkaPlaybackItem_data(&c->vec) + c->vec.count;
    while (Ne(it, end)) {
        if (it->id == e->id) {
            if (it->weight == 0.0f) {
                cSkaPlaybackItem_opAssign(it, e);
            } else {
                cQuaternion_opAssign(&it->v, &cQuaternion_opAdd_cQuaternionR(&cSkaPlaybackItem_GetSummedOffsetRootRotation(it), &cSkaPlaybackItem_GetSummedOffsetRootRotation(e)));
                it->weight += e->weight;
                it->active = 0;
            }
            found = 1;
            break;
        }
        it++;
    }
    if (!found) {
        std_vector_imp_cSkaPlaybackItem_insert(&c->vec, c->vec.data + c->vec.count, 1, e);
        c->f32 = c->f32 && e->id->b45;
    }
}
static inline void merge_flush_func_003B1290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B1290 */
