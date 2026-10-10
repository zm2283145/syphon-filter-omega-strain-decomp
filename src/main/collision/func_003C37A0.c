#include "types.h"
#pragma cplusplus on
#pragma bool off
struct C6Rec_3C37A0 { char pad[0x40]; unsigned char flags; char pad41[0x2F]; };
struct C6Coll_3C37A0 { int pad0; int count; };
struct C6Query_3C37A0 { unsigned char hit; char pad[0x5F]; unsigned char require; unsigned char reject; };
extern "C" C6Rec_3C37A0** func_001EEBA0(C6Coll_3C37A0*);
extern "C" void Los_IntersectRecord(C6Query_3C37A0*, C6Rec_3C37A0*);
static inline int C6Eq(C6Rec_3C37A0* a, C6Rec_3C37A0* b) { return a == b; }
extern "C" int Los_TraceTriangles(C6Query_3C37A0* q, C6Coll_3C37A0* coll) {
    C6Rec_3C37A0** pend;
    C6Rec_3C37A0* end;
    C6Rec_3C37A0* it;
    it = *func_001EEBA0(coll);
    end = *func_001EEBA0(coll) + coll->count;
    pend = &end;
    for (; C6Eq(it, *pend) ^ 1; it++) {
        unsigned char f = it->flags;
        if ((unsigned char)(f & q->reject) == 0 && q->require == (unsigned char)(f & q->require))
            Los_IntersectRecord(q, it);
    }
    return q->hit != 0;
}