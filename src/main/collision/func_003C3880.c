
#include "types.h"
typedef struct { char pad0[0x40]; unsigned char mask; char pad41[0x2F]; } Pt2_LRec;
typedef struct { int pad0; int count; } Pt2_LVec;
typedef struct { unsigned char hit; char pad1[0x5F]; unsigned char want; unsigned char excl; unsigned char alt; } Pt2_LQ;
extern Pt2_LRec** func_001EEBA0(Pt2_LVec*);
extern void Col_SegmentVsTriangle(Pt2_LQ*, Pt2_LRec*);
extern void func_003C4120(Pt2_LQ*, Pt2_LRec*);
static inline int Pt2_Ne(Pt2_LRec* a, Pt2_LRec** b) { return !(a == *b); }

int func_003C3880(Pt2_LQ* q, Pt2_LVec* v) {
    unsigned char deferred = 0;
    {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *func_001EEBA0(v);
        end[0] = *func_001EEBA0(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if (!(unsigned char)(m & q->excl)) {
                if (q->want == (unsigned char)(m & q->want)) {
                    if (!(unsigned char)(m & q->alt)) Col_SegmentVsTriangle(q, it);
                    else deferred = 1;
                }
            }
        }
    }
    if (deferred) {
        Pt2_LRec* end[1];
        Pt2_LRec** ep;
        Pt2_LRec* it = *func_001EEBA0(v);
        end[0] = *func_001EEBA0(v) + v->count;
        ep = end;
        for (; Pt2_Ne(it, ep); it++) {
            unsigned char m = it->mask;
            if ((unsigned char)(m & q->alt)) {
                if (!(unsigned char)(m & q->excl)) {
                    if (q->want == (unsigned char)(m & q->want)) func_003C4120(q, it);
                }
            }
        }
    }
    return q->hit != 0;
}