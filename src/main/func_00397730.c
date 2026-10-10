#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004BC4C0[];
void Mem_Free(int, void*, char*, int);
}
struct GrpG { char pad[8]; void* buf; };
extern "C" void func_00397A00(GrpG* g);
extern "C" void operator_delete(void* p);
extern "C" GrpG* Group_Clear(GrpG* g, short flags)
{
    if (g) {
        if (g) {
            void* b;
            func_00397A00(g);
            b = g->buf;
            if (b) {
                if (b) {
                    AllocGuard g2;
                    Mem_Free(0, b, D_004BC4C0, 100);
                }
            }
        }
        if (flags > 0) operator_delete(g);
    }
    return g;
}
