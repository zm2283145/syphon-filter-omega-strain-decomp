/*
 * SFOGame/Source/weapon: 3 files, 00140D40-00140E10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00140D40 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cCharActionMsg_dtor, D_004E0840, cMessage_dtor)
static inline void merge_flush_func_00140D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00140D40 */

/* merge_units: begin func_00140DA0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void Event_PackHeader();
extern "C" void cMessage_getSOBJClassId();
extern "C" void cAISoundSystemGOBJMessage_Clone();
extern void * const D_004D92C0[];
extern char D_004D92A0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cAISoundSystemGOBJMessage_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D92C0);
        if (self) {
            self->vtable = D_004D92A0;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D92C0[8] = { (void*)0x0, (void*)0x0, (void*)cAISoundSystemGOBJMessage_dtor, (void*)cAISoundSystemGOBJMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00140DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00140DA0 */

/* merge_units: begin func_00140E10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int Libc_Cosf(float);
extern int Libc_Sinf(float);

int cGobjController_IsNPC(void) {
    return 0;
}

Mtx44* cMatrix_Set_ColumnMajorForm(Mtx44* m, float a, float b, float c, float d, float e, float f,
                     float g, float h, float i) {
    m->m[0][0] = a;
    m->m[0][1] = d;
    m->m[0][2] = g;
    m->m[1][0] = b;
    m->m[1][1] = e;
    m->m[1][2] = h;
    m->m[2][0] = c;
    m->m[2][1] = f;
    m->m[2][2] = i;
    m->m[0][3] = 0;
    m->m[1][3] = 0;
    m->m[2][3] = 0;
    m->m[3][0] = 0;
    m->m[3][1] = 0;
    m->m[3][2] = 0;
    m->m[3][3] = 1.0f;
    return m;
}

int SIN(float f12) {
    return Libc_Sinf(f12);
}

int COS(float f12) {
    return Libc_Cosf(f12);
}

int func_00140E90(void) {
    return 0;
}
static inline void merge_flush_func_00140E10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00140E10 */
