/*
 * SFOGame/Source/human: 11 files, 00198AD0-00198E00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00198AD0 */
#pragma push /* merge_units */
#include "types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int* cSkaPlaybackGroupId_ctor_cSkaPlaybackGroupIdR(int* dst, int* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198AD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198AD0 */

/* merge_units: begin func_00198AF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x40]; int key; } MotionGroup;
typedef struct { MotionGroup* group; int key; } MotionKey;
/* Build a key handle: the group is set only when its key is unassigned (-1). */
MotionKey* cSkaPlaybackGroupId_ctor_cSkaAnimR(MotionKey* out, MotionGroup* group)
{
    out->group = group->key == -1 ? group : 0;
    out->key = group->key;
    return out;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198AF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198AF0 */

/* merge_units: begin func_00198B20 */
#pragma push /* merge_units */
int cSkaPlaybackItem_GetAnimation(char* self) {
    return *(int*)(self + 0);
}

/* Address of 32-byte element i. */
char* cArray_cSkaPlaybackItem_opIndex(PtrVec* v, int i) {
    return (char*)v->data + (i << 5);
}

int cArray_cSkaPlaybackItem_Size(char* self) {
    return *(int*)(self + 4);
}

char* cConstLListIterator_cSkaPlaybackGroupPtr_opMul(Iter* it) {
    return (char*)it->p + 8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198B20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198B20 */

/* merge_units: begin func_00198B60 */
#pragma push /* merge_units */
#include "iter_return_copy.h"

/* Return the end iterator. */
DEFINE_ITER_END(func_00198B60)
static inline void merge_flush_func_00198B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198B60 */

/* merge_units: begin func_00198B90 */
#pragma push /* merge_units */
/* Return the begin iterator. */
DEFINE_ITER_BEGIN(cArray_cString_REnd)
static inline void merge_flush_func_00198B90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198B90 */

/* merge_units: begin func_00198BC0 */
#pragma push /* merge_units */
#include "human_types.h"

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
#if 0 /* merge_units */
float cSkaPlaybackGroup_Weight(char* self); /* gsynth: defined below */
#endif /* merge_units */
float cSkaPlaybackGroup_Weight(); /* merge_units */

typedef struct { char pad[0xE8]; char map[1]; } Table198;
typedef struct { char pad[0x3C]; char ref[1]; } Obj198;

extern Table198* Deque_Back(void* ref);
#if 0 /* merge_units */
extern void* cSkaPlaybackList_FindPlaybackGroup(void* map, int key);
#endif /* merge_units */
void * cSkaPlaybackList_FindPlaybackGroup(); /* merge_units */

#if 0 /* merge_units */
extern float cSkaPlaybackGroup_Weight(void* entry);
#endif /* merge_units */
float cSkaPlaybackGroup_Weight(); /* merge_units */



/* Looks up key in the object's table and returns the entry's value, or 0. */
float cSkaParams_GetPlaybackWeight(Obj198* self, int key)
{
    void* entry = cSkaPlaybackList_FindPlaybackGroup(Deque_Back(self->ref)->map, key);
    if (entry)
        return cSkaPlaybackGroup_Weight(entry);
    return 0.0f;
}
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

/* merge_units: begin func_00198D00 */
#pragma push /* merge_units */
#pragma opt_common_subs off
typedef struct { void* p; int id; } H_198D00;
typedef struct L_198D00 { int pad0; struct L_198D00* next; void* item; } L_198D00;
typedef struct { L_198D00* n; } It_198D00;
typedef struct { int raw; } RIt_198D00;
extern void std_list_deleter_voidPtr_begin_void_2(RIt_198D00* out, void* self);
extern void std_list_deleter_voidPtr_end_void_2(RIt_198D00* out, void* self);
extern void std_list_cSkaPlaybackGroupPtr_generic_iterator_1_ctor(It_198D00* out, int raw);
#if 0 /* merge_units */
extern void cSkaPlaybackGroup_GetId(H_198D00* out, void* item);
#endif /* merge_units */
void cSkaPlaybackGroup_GetId(); /* merge_units */

#if 0 /* merge_units */
extern int cSkaPlaybackGroupId_opEq(void* key, H_198D00* h);
#endif /* merge_units */
int cSkaPlaybackGroupId_opEq(); /* merge_units */

void* cSkaPlaybackList_FindPlaybackGroup(void* self, void* key)
{
    It_198D00 b;
    It_198D00 d;
    RIt_198D00 a;
    RIt_198D00 c;
    H_198D00 h;
    void* r = 0;
    L_198D00* it;
    L_198D00* end;
    std_list_deleter_voidPtr_begin_void_2(&a, self);
    std_list_cSkaPlaybackGroupPtr_generic_iterator_1_ctor(&b, a.raw);
    it = b.n;
    std_list_deleter_voidPtr_end_void_2(&c, self);
    std_list_cSkaPlaybackGroupPtr_generic_iterator_1_ctor(&d, c.raw);
    end = d.n;
    for (; it != end; it = it->next) {
        cSkaPlaybackGroup_GetId(&h, it->item);
        if (cSkaPlaybackGroupId_opEq(key, &h)) {
            r = it->item;
            break;
        }
    }
    return r;
}
static inline void merge_flush_func_00198D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198D00 */

/* merge_units: begin func_00198DD0 */
#pragma push /* merge_units */
typedef struct IntPair {
    int a;
    int b;
} IntPair;

/* Compares two int pairs for equality. */
int cSkaPlaybackGroupId_opEq(IntPair* x, IntPair* y) {
    return x->a == y->a && x->b == y->b;
}
static inline void merge_flush_func_00198DD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198DD0 */

/* merge_units: begin func_00198E00 */
#pragma push /* merge_units */
typedef struct { void* p; int id; } H_198E00;
typedef struct { char pad[0x40]; int id; } N_198E00;
typedef struct { int id; int pad4; int kind; N_198E00** node; } R_198E00;
static inline void Make_198E00(H_198E00* h, N_198E00* o)
{
    h->p = (o->id == -1) ? o : 0;
    h->id = o->id;
}
void cSkaPlaybackGroup_GetId(H_198E00* out, R_198E00* r)
{
    H_198E00 a;
    H_198E00 b;
    H_198E00* p;
    if (r->kind == 1) {
        Make_198E00(&a, *r->node);
        p = &a;
    } else {
        b.id = r->id;
        b.p = 0;
        p = &b;
    }
    out->p = p->p;
    out->id = p->id;
}
static inline void merge_flush_func_00198E00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00198E00 */
