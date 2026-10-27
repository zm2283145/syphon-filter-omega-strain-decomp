/*
 * main/collision: range (4 files, 003C36C0-003C3A60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003C36C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C5Tri { char pad[0x40]; unsigned char flags; char pad2[0x2F]; };
struct C5TriVec { int cap; int count; };
struct C5Trace { unsigned char hit; char pad[0x5F]; unsigned char want; unsigned char reject; };
struct C5TriIt { C5Tri* p; C5TriIt() {} C5TriIt(C5Tri* q) : p(q) {} };
inline bool operator==(const C5TriIt& a, const C5TriIt& b) { return a.p == b.p; }
inline bool operator!=(const C5TriIt& a, const C5TriIt& b) { return !(a == b); }
extern "C" C5Tri** std_vector_deleter_cCollisionFace_data_void(C5TriVec* v);
extern "C" void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(C5Trace* t, C5Tri* tri);
extern "C" bool cCollisionProbe_Ray_DetectForCollision_cArrayR(C5Trace* t, C5TriVec* v) {
    C5TriIt it(*std_vector_deleter_cCollisionFace_data_void(v));
    const C5TriIt& end = C5TriIt(*std_vector_deleter_cCollisionFace_data_void(v) + v->count);
    for (; it != end; it.p++) {
        if ((unsigned char)(it.p->flags & t->reject) == 0 && t->want == (unsigned char)(it.p->flags & t->want))
            cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(t, it.p);
    }
    return t->hit != 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C36C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C36C0 */

/* merge_units: begin func_003C37A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma bool off
struct C6Rec_3C37A0 { char pad[0x40]; unsigned char flags; char pad41[0x2F]; };
struct C6Coll_3C37A0 { int pad0; int count; };
struct C6Query_3C37A0 { unsigned char hit; char pad[0x5F]; unsigned char require; unsigned char reject; };
#if 0 /* merge_units */
extern "C" C6Rec_3C37A0** std_vector_deleter_cCollisionFace_data_void(C6Coll_3C37A0*);
#endif /* merge_units */
#define std_vector_deleter_cCollisionFace_data_void(a0) ((C6Rec_3C37A0 * *)std_vector_deleter_cCollisionFace_data_void((C5TriVec *)(a0))) /* merge_units */

extern "C" void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(C6Query_3C37A0*, C6Rec_3C37A0*);
static inline int C6Eq(C6Rec_3C37A0* a, C6Rec_3C37A0* b) { return a == b; }
extern "C" int cCollisionProbe_Ray_DetectForCollision_cArrayR_2(C6Query_3C37A0* q, C6Coll_3C37A0* coll) {
    C6Rec_3C37A0** pend;
    C6Rec_3C37A0* end;
    C6Rec_3C37A0* it;
    it = *std_vector_deleter_cCollisionFace_data_void(coll);
    end = *std_vector_deleter_cCollisionFace_data_void(coll) + coll->count;
    pend = &end;
    for (; C6Eq(it, *pend) ^ 1; it++) {
        unsigned char f = it->flags;
        if ((unsigned char)(f & q->reject) == 0 && q->require == (unsigned char)(f & q->require))
            cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(q, it);
    }
    return q->hit != 0;
}
#undef std_vector_deleter_cCollisionFace_data_void /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C37A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C37A0 */

/* merge_units: begin func_003C3880 */
#pragma push /* merge_units */
typedef struct { char pad0[0x40]; unsigned char mask; char pad41[0x2F]; } Pt2_LRec;
typedef struct { int pad0; int count; } Pt2_LVec;
typedef struct { unsigned char hit; char pad1[0x5F]; unsigned char want; unsigned char excl; unsigned char alt; } Pt2_LQ;
#if 0 /* merge_units */
extern Pt2_LRec** std_vector_deleter_cCollisionFace_data_void(Pt2_LVec*);
#endif /* merge_units */
#define std_vector_deleter_cCollisionFace_data_void(a0) ((Pt2_LRec * *)std_vector_deleter_cCollisionFace_data_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(Pt2_LQ*, Pt2_LRec*);
#endif /* merge_units */
#define cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(a0, a1) (cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR((void *)(a0), (void *)(a1))) /* merge_units */

extern void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_2(Pt2_LQ*, Pt2_LRec*);
static inline int Pt2_Ne(Pt2_LRec* a, Pt2_LRec** b) { return !(a == *b); }

int cCollisionProbe_Ray_DetectForCollision_cArrayR_3(Pt2_LQ* q, Pt2_LVec* v) {
    unsigned char deferred = 0;
    {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *std_vector_deleter_cCollisionFace_data_void(v);
        end[0] = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if (!(unsigned char)(m & q->excl)) {
                if (q->want == (unsigned char)(m & q->want)) {
                    if (!(unsigned char)(m & q->alt)) cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(q, it);
                    else deferred = 1;
                }
            }
        }
    }
    if (deferred) {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *std_vector_deleter_cCollisionFace_data_void(v);
        end[0] = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if ((unsigned char)(m & q->alt)) {
                if (!(unsigned char)(m & q->excl)) {
                    if (q->want == (unsigned char)(m & q->want)) cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_2(q, it);
                }
            }
        }
    }
    return q->hit != 0;
}
#undef std_vector_deleter_cCollisionFace_data_void /* merge_units */
#undef cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3880(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C3880 */

/* merge_units: begin func_003C3A60 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern Pt2_LRec** std_vector_deleter_cCollisionFace_data_void(Pt2_LVec*);
#endif /* merge_units */
#define std_vector_deleter_cCollisionFace_data_void(a0) ((Pt2_LRec * *)std_vector_deleter_cCollisionFace_data_void((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(Pt2_LQ*, Pt2_LRec*);
#endif /* merge_units */
#define cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(a0, a1) (cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3((void *)(a0), (void *)(a1))) /* merge_units */

extern void cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4(Pt2_LQ*, Pt2_LRec*);

int cCollisionProbe_Ray_DetectForCollision_cArrayR_4(Pt2_LQ* q, Pt2_LVec* v) {
    unsigned char deferred = 0;
    {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *std_vector_deleter_cCollisionFace_data_void(v);
        end[0] = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if (!(unsigned char)(m & q->excl)) {
                if (q->want == (unsigned char)(m & q->want)) {
                    if (!(unsigned char)(m & q->alt)) cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(q, it);
                    else deferred = 1;
                }
            }
        }
    }
    if (deferred) {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *std_vector_deleter_cCollisionFace_data_void(v);
        end[0] = *std_vector_deleter_cCollisionFace_data_void(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if ((unsigned char)(m & q->alt)) {
                if (!(unsigned char)(m & q->excl)) {
                    if (q->want == (unsigned char)(m & q->want)) cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4(q, it);
                }
            }
        }
    }
    return q->hit != 0;
}
#undef std_vector_deleter_cCollisionFace_data_void /* merge_units */
#undef cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C3A60 */
