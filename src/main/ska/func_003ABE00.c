/* MotionGraph_ClearActive: walks the active motion deque, resetting both message slots and the notify slot of
 * every 0xF8-byte record, then clears the deque. Hand-matched (fam1).
 * The empty destructor keeps the iterator in memory (fields reached through s-register addresses, as in retail);
 * the field-wise operator= gives the word-by-word iterator copy. */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h" /* ALLOC_GUARD_DTOR: discard the out-of-line copy of the empty dtor */
struct Ring { int** cur; int** begin; int** x8; int** end; };
struct DqIt {
    Ring ring; char* elem; char* bend;
    DqIt() {}
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~DqIt() {}
    DqIt& operator=(const DqIt& o) {
        ring.cur = o.ring.cur; ring.begin = o.ring.begin; ring.x8 = o.ring.x8; ring.end = o.ring.end;
        elem = o.elem; bend = o.bend;
        return *this;
    }
    bool Ne(char* p) const { return !(elem == p); }
    DqIt& operator++() {
        if ((elem += 0xF8) == bend) {
            if (++ring.cur == ring.end) ring.cur = ring.begin;
            elem = (char*)*ring.cur;
            bend = elem + 0x7C0;
        }
        return *this;
    }
};
struct BlockArray { int cap; int size; int start; int** data; int first; int count; };
struct MGraph { char pad[0x18]; BlockArray arr; };
extern "C" {
void func_00397840(DqIt* out, BlockArray* a, int n);
void MotionMsg_Send(void* m, unsigned char kind, float value);
void MotionNotify_SendSlot(void* h, int idx, unsigned char clear);
void func_003B86D0(BlockArray* a);
}
extern "C" void MotionGraph_ClearActive(MGraph* g)
{
    DqIt it;
    DqIt b;
    char* p;
    char* e;
    func_00397840(&b, &g->arr, 0);
    it = b;
    {
        DqIt r;
        func_00397840(&r, &g->arr, g->arr.count);
        e = r.elem;
    }
    while (it.Ne(e)) {
        p = it.elem;
        MotionMsg_Send(p + 0x24, 5, 0.0f);
        MotionMsg_Send(p + 0x5C, 5, 0.0f);
        MotionNotify_SendSlot(p + 0x94, 6, 0);
        ++it;
    }
    func_003B86D0(&g->arr);
}
