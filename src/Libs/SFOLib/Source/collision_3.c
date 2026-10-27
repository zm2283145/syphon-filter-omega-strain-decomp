/*
 * Libs/SFOLib/Source/collision: 2 files, 003BD8F0-003BD900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BD8F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

char* cCollisionFace_Vertex(char* base, int i) {
    return base + i * 16;
}
static inline void merge_flush_func_003BD8F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BD8F0 */

/* merge_units: begin func_003BD900 */
#pragma push /* merge_units */
#pragma cplusplus on
struct CqTri { char p[0x40]; unsigned char flags; char p41[0x2F]; };
struct CqMesh { int a; int count; };
struct CqVec { CqTri* data; };
struct CqQuery { unsigned char hit; char p[0xCF]; CqMesh* mesh; };
extern "C" CqVec* std_vector_deleter_cCollisionFace_data_void(CqMesh* m);
extern "C" void cCollisionProbe_SphereSweptRay_DetectForCollision_cCollisionFaceR(CqQuery* q, CqTri* t);
inline bool CqEq(CqTri* const& a, CqTri* const& b) { return a == b; }
inline bool CqNe(CqTri* const& a, CqTri* const& b) { return !CqEq(a, b); }
extern "C" bool cCollisionProbe_SphereSweptRay_DetectForCollision_IgnoreMovementOfCollidingObjects(CqQuery* q, unsigned char want, unsigned char mask) {
    CqTri* end;
    CqTri** pe;
    CqMesh* m;
    CqTri* it = std_vector_deleter_cCollisionFace_data_void(q->mesh)->data;
    m = q->mesh;
    end = std_vector_deleter_cCollisionFace_data_void(m)->data + m->count;
    for (pe = &end; CqNe(it, *pe); it++) {
        if ((unsigned char)(it->flags & mask) == 0 && (unsigned char)(it->flags & want) == want)
            cCollisionProbe_SphereSweptRay_DetectForCollision_cCollisionFaceR(q, it);
    }
    return q->hit != 0;
}
static inline void merge_flush_func_003BD900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BD900 */
