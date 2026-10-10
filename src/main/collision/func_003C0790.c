#include "types.h"
typedef struct { char data[0x70]; } TriC0790;
typedef struct { TriC0790* data; int count; } VecC0790;
extern void func_001EFA30(void* a);
extern TriC0790** func_001EEBA0(VecC0790* v);
extern void Col_GatherTriangleEdges(void* ctx, void* a, TriC0790* t);
static inline int NeC0790(TriC0790* a, TriC0790* b) { return (a == b) ^ 1; }
void Col_GatherEdges(void* ctx, void* a, VecC0790* v) {
    TriC0790* it;
    TriC0790* end;
    func_001EFA30(a);
    it = *func_001EEBA0(v);
    end = *func_001EEBA0(v) + v->count;
    while (NeC0790(it, end)) {
        Col_GatherTriangleEdges(ctx, a, it);
        it++;
    }
}