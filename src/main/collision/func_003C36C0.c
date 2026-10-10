#pragma cplusplus on
#include "types.h"
struct C5Tri { char pad[0x40]; unsigned char flags; char pad2[0x2F]; };
struct C5TriVec { int cap; int count; };
struct C5Trace { unsigned char hit; char pad[0x5F]; unsigned char want; unsigned char reject; };
struct C5TriIt { C5Tri* p; C5TriIt() {} C5TriIt(C5Tri* q) : p(q) {} };
inline bool operator==(const C5TriIt& a, const C5TriIt& b) { return a.p == b.p; }
inline bool operator!=(const C5TriIt& a, const C5TriIt& b) { return !(a == b); }
extern "C" C5Tri** func_001EEBA0(C5TriVec* v);
extern "C" void Col_SegmentVsTriangle(C5Trace* t, C5Tri* tri);
extern "C" bool Col_TraceFloorTriangles(C5Trace* t, C5TriVec* v) {
    C5TriIt it(*func_001EEBA0(v));
    const C5TriIt& end = C5TriIt(*func_001EEBA0(v) + v->count);
    for (; it != end; it.p++) {
        if ((unsigned char)(it.p->flags & t->reject) == 0 && t->want == (unsigned char)(it.p->flags & t->want))
            Col_SegmentVsTriangle(t, it.p);
    }
    return t->hit != 0;
}