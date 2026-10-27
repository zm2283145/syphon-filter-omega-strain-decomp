/*
 * SFOGame/Source/ai: 1 file, 0016F710
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016F710 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004D9850[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(void* self, void* other);
void cObjectId_ctor_cObjectIdR(void* dst, void* src);
void cVector_ctor_cVectorR(void* dst, void* src);
}
struct Msg_0016F710 {
    void* vtable;
    char base[0x30];
    char a[0xC];
    char v[0x10];
};
extern "C" Msg_0016F710* cAISoundSystemGOBJPositionMessage_Clone(Msg_0016F710* self)
{
    Msg_0016F710* p;
    {
        AllocGuard guard;
        p = (Msg_0016F710*)cMemMan_Allocate(0, 0x50, "ai.hh", 0x164);
    }
    if (p) {
        cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(p, self);
        p->vtable = D_004D9850;
        cObjectId_ctor_cObjectIdR(p->a, self->a);
        cVector_ctor_cVectorR(p->v, self->v);
    }
    return p;
}
static inline void merge_flush_func_0016F710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016F710 */
