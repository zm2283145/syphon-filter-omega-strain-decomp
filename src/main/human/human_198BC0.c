/*
 * main/human: range (3 files, 00198BC0-00198CF0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "human_types.h"

/* merge_units: begin func_00198BC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* 24-byte iterator returned by the lookup at 0x001BE960. */
typedef struct Iter24 {
    int w[6];
} Iter24;

extern int func_001BE960(Iter24*, char*, int);

void* func_00198BC0(char* self) {
    return self + 232;
}

int func_00198BD0(char* self) {
    return *(int*)(self + 16);
}

/* Lookup using the key at src+0x14; copy the resulting iterator to out. */
void func_00198BE0(Iter24* out, char* src) {
    Iter24 it;

    func_001BE960(&it, src, *(int*)(src + 20));
    out->w[0] = it.w[0];
    out->w[1] = it.w[1];
    out->w[2] = it.w[2];
    out->w[3] = it.w[3];
    out->w[4] = it.w[4];
    out->w[5] = it.w[5];
}

/* Same lookup with key 0. */
void func_00198C40(Iter24* out) {
    Iter24 it;
    char* src;

    func_001BE960(&it, src, 0);
    out->w[0] = it.w[0];
    out->w[1] = it.w[1];
    out->w[2] = it.w[2];
    out->w[3] = it.w[3];
    out->w[4] = it.w[4];
    out->w[5] = it.w[5];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198BC0 */

/* merge_units: begin func_00198CA0 */
#pragma push /* merge_units */
float cSkaPlaybackGroup_Weight(char* self); /* gsynth: defined below */
typedef struct { char pad[0xE8]; char map[1]; } Table198;
typedef struct { char pad[0x3C]; char ref[1]; } Obj198;

extern Table198* Deque_Back(void* ref);
extern void* cSkaPlaybackList_FindPlaybackGroup(void* map, int key);
#if 0 /* merge_units */
extern float cSkaPlaybackGroup_Weight(void* entry);
#endif /* merge_units */
#define cSkaPlaybackGroup_Weight(a0) (cSkaPlaybackGroup_Weight((void *)(a0))) /* merge_units */


/* Looks up key in the object's table and returns the entry's value, or 0. */
float Actor_GetGaitPhase(Obj198* self, int key)
{
    void* entry = cSkaPlaybackList_FindPlaybackGroup(Deque_Back(self->ref)->map, key);
    if (entry)
        return cSkaPlaybackGroup_Weight(entry);
    return 0.0f;
}
#undef cSkaPlaybackGroup_Weight /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198CA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198CA0 */

/* merge_units: begin func_00198CF0 */
#pragma push /* merge_units */
float cSkaPlaybackGroup_Weight(char* self) {
    return *(float*)(self + 36);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198CF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198CF0 */
