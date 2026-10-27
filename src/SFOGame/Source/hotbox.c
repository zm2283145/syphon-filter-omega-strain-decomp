/*
 * SFOGame/Source/hotbox: 3 files, 0016F890-0016F9E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016F890 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable3_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

#pragma cplusplus on

/* Three-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE3_BASE_DTOR(cAISoundSystemGobjToGobjMessage_dtor, D_004D9870, D_004D92C0, D_004D92A0, cMessage_dtor)
static inline void merge_flush_func_0016F890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016F890 */

/* merge_units: begin func_0016F910 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004D9870[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(void* self, void* other);
void cObjectId_ctor_cObjectIdR(void* dst, void* src);
void cVector_ctor_cVectorR(void* dst, void* src);
}
struct Msg_0016F910 {
    void* vtable;
    char base[0x30];
    char a[0xC];
    char v[0x10];
};
extern "C" Msg_0016F910* cAISoundSystemGobjToGobjMessage_Clone(Msg_0016F910* self)
{
    Msg_0016F910* p;
    {
        AllocGuard guard;
        p = (Msg_0016F910*)cMemMan_Allocate(0, 0x50, "ai.hh", 0x16E);
    }
    if (p) {
        cAISoundSystemGOBJMessage_ctor_cAISoundSystemGOBJMessageR(p, self);
        p->vtable = D_004D9870;
        cObjectId_ctor_cObjectIdR(p->a, self->a);
        cVector_ctor_cVectorR(p->v, self->v);
    }
    return p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016F910(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016F910 */

/* merge_units: begin ai_16F9E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_0016F9E0(void) {
}

void PlayerComp_OnHitNop(void) {
}

void func_0016FA00(void) {
}

int PlayerComp_GetDeathCode(int a0, int a1) {
    return a1;
}

int func_0016FA20(void) {
    return 0;
}
static inline void merge_flush_ai_16F9E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end ai_16F9E0 */
