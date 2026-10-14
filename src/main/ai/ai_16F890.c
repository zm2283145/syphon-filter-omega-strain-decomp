/*
 * main/ai: range (2 files, 0016F890-0016F910)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable3_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* merge_units: begin func_0016F890 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE3_BASE_DTOR(func_0016F890, D_004D9870, D_004D92C0, D_004D92A0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0016F890 */

/* merge_units: begin func_0016F910 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004D9870[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void cMessage_ctor2(void* self, void* other);
void func_0016F7E0(void* dst, void* src);
void Vec4_Assign(void* dst, void* src);
}
struct Msg_0016F910 {
    void* vtable;
    char base[0x30];
    char a[0xC];
    char v[0x10];
};
extern "C" Msg_0016F910* func_0016F910(Msg_0016F910* self)
{
    Msg_0016F910* p;
    {
        AllocGuard guard;
        p = (Msg_0016F910*)Mem_Alloc(0, 0x50, "ai.hh", 0x16E);
    }
    if (p) {
        cMessage_ctor2(p, self);
        p->vtable = D_004D9870;
        func_0016F7E0(p->a, self->a);
        Vec4_Assign(p->v, self->v);
    }
    return p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016F910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016F910 */
