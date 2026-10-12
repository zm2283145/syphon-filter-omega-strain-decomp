#pragma cplusplus on
#include "types.h"
#pragma opt_propagation off
struct RingE960 {
    int** cur; int** begin; int** x8; int** end;
};
struct DqItE960 { RingE960 ring; char* elem; char* bend; };
struct DqE960 { int capacity; int count; int size; int** data; unsigned int start; };
extern "C" void func_001BEAD0(RingE960* out, DqE960* arr);
extern "C" RingE960* func_001BEAA0(RingE960* d, RingE960* s);
extern "C" void func_001BE960(DqItE960* out, DqE960* dq, int n) {
    unsigned int idx = n + dq->start;
    RingE960 q;
    RingE960 it;
    RingE960 s;
    char* blk;
    func_001BEAD0(&s, dq);
    func_001BEAA0(&q, &s);
    it = q;
    RingE960* rp = &it;
    {
        int nn = idx >> 3;
        int size = it.end - it.begin;
        nn += it.cur - it.begin;
        if (nn < 0) nn += size;
        else if (nn >= size) nn -= size;
        rp->cur = rp->begin + nn;
    }
    int** c0 = rp->cur; int** c1 = rp->begin; int** c2 = rp->x8; int** c3 = rp->end;
    blk = dq->count == 0 ? 0 : (char*)*c0;
    out->ring.cur = c0; out->ring.begin = c1; out->ring.x8 = c2; out->ring.end = c3;
    out->elem = blk + (idx & 7) * 248;
    out->bend = blk + 0x7C0;
}
