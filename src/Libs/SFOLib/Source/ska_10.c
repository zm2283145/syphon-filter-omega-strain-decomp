/*
 * Libs/SFOLib/Source/ska: 6 files, 003AC450-003AC530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003AC450 */
#pragma push /* merge_units */
#include "types.h"
#include "ska_types.h"

typedef struct {
    unsigned int count;  /* +0x0 number of blocks */
    int unk4;
    unsigned int first;  /* +0x8 first block index */
    char** blocks;       /* +0xC */
    unsigned int pos;    /* +0x10 element position */
} BlockRing;

/* Returns the address of element pos: 8 elements of 0xF8 bytes per block, blocks in a ring. */
char* std_deque_deleter_common_cSkaSystem_Request_front(BlockRing* r)
{
    unsigned int pos = r->pos;
    unsigned int block = (r->first + (pos >> 3)) % r->count;
    return r->blocks[block] + (pos & 7) * 0xF8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC450 */

/* merge_units: begin func_003AC4A0 */
#pragma push /* merge_units */
typedef struct Ring {
    unsigned int size;  /* 0x00 */
    int unk04;
    unsigned int head;  /* 0x08 */
    int* items;         /* 0x0C */
} Ring;
int* cdeque_cSkaSystem_RequestPtr_opIndex(Ring* ring, unsigned int offset); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


#if 0 /* merge_units */
extern char** cdeque_cSkaSystem_RequestPtr_opIndex(void* blocks, unsigned int block);
#endif /* merge_units */
#define cdeque_cSkaSystem_RequestPtr_opIndex(a0, a1) ((char * *)cdeque_cSkaSystem_RequestPtr_opIndex((Ring *)(a0), (a1))) /* merge_units */


extern void* std_deque_deleter_common_cSkaSystem_Request_buf(void* self);

/* Address of entry (first + index) in a block array of 248-byte entries, eight per block. */
char* std_deque_cSkaSystem_Request_opIndex(SkaBlockArray* self, int index) {
    int i = index + self->first;
    return *cdeque_cSkaSystem_RequestPtr_opIndex(std_deque_deleter_common_cSkaSystem_Request_buf(self), (unsigned int)i >> 3) + (i & 7) * 248;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC4A0(void) {}
#undef cdeque_cSkaSystem_RequestPtr_opIndex /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AC4A0 */

/* merge_units: begin func_003AC4F0 */
#pragma push /* merge_units */
/* Returns the address of the slot `offset` past the ring head. */
int* cdeque_cSkaSystem_RequestPtr_opIndex(Ring* ring, unsigned int offset) {
    return &ring->items[(ring->head + offset) % ring->size];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC4F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC4F0 */

/* merge_units: begin func_003AC520 */
#pragma push /* merge_units */
void* std_deque_deleter_common_cSkaSystem_Request_buf(void* self) {
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC520 */

/* merge_units: begin func_003AC530 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
extern "C" float AnimGroup_IsReady(void* list, int id); /* gsynth: defined below */
#pragma pop
typedef struct { char pad[0xE0]; float start; float cur; char grp[4]; } S3AC530;
typedef struct { float a; float b; } R3AC530;
extern int cSkaSystem_Request_PlaybackGroupId(void);
#if 0 /* merge_units */
extern float AnimGroup_IsReady(void* grp, int x);
#endif /* merge_units */
#define AnimGroup_IsReady(a0, a1) ((float)AnimGroup_IsReady((a0), (a1))) /* merge_units */


int IsReadyForNextAnim(S3AC530* p, R3AC530* r)
{
    float d;
    if (p->start != -1.0f) {
        d = p->start - p->cur;
    } else {
        d = AnimGroup_IsReady(p->grp, cSkaSystem_Request_PlaybackGroupId());
    }
    return d <= 0.5f * (r->a + r->b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC530(void) {}
#undef AnimGroup_IsReady /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003AC530 */

/* merge_units: begin func_003AC5C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C4Anim3AC { char pad[0x1C]; float x1C; char p20[4]; float x24; char p28[9]; unsigned char complete; };
struct C4It3AC { void* p; C4It3AC() {} C4It3AC(const C4It3AC& o) : p(o.p) {} };
extern "C" {
C4It3AC cArray_cString_REnd(void* list);
C4It3AC func_00198B60(void* list);
bool opNe_cConstLListIteratorR_cConstLListIteratorR(C4It3AC* a, C4It3AC* b);
void cConstLListIterator_cSkaPlaybackGroupPtr_opInc(C4It3AC* it);
C4Anim3AC** cConstLListIterator_cSkaPlaybackGroupPtr_opMul(C4It3AC* it);
bool cSkaPlaybackGroup_CheckId(C4Anim3AC* a, int id);
}
inline float Ready(C4Anim3AC* a) { if (a->complete) return 0.0f; return a->x1C * (1.0f - a->x24); }
extern "C" float AnimGroup_IsReady(void* list, int id) {
    C4Anim3AC* found = 0;
    C4It3AC it = cArray_cString_REnd(list);
    C4It3AC end = func_00198B60(list);
    while (opNe_cConstLListIteratorR_cConstLListIteratorR(&it, &end)) {
        if (cSkaPlaybackGroup_CheckId(*cConstLListIterator_cSkaPlaybackGroupPtr_opMul(&it), id)) {
            found = *cConstLListIterator_cSkaPlaybackGroupPtr_opMul(&it);
            break;
        }
        cConstLListIterator_cSkaPlaybackGroupPtr_opInc(&it);
    }
    return found ? Ready(found) : 0.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC5C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC5C0 */
