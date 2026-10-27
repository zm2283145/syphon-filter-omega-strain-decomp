#include "types.h"
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