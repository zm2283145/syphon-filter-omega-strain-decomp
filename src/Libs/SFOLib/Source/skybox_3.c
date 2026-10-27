/*
 * main/skybox: range (2 files, 003BC520-003BC5A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_003BC520 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; int count; void* items[1]; } G4_Act;
extern void cSLayer_Update(void* a);
extern void cGOBJ_NextFrame(G4_Act* a, float dt);
void cSKYBOX_GOBJ_NextFrame(G4_Act* a, float dt)
{
    int i;
    for (i = 0; i < a->count; i++) {
        cSLayer_Update(a->items[i]);
    }
    cGOBJ_NextFrame(a, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BC520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BC520 */

/* merge_units: begin func_003BC5A0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004BD038[];
extern char D_004DFC70[];
void cGOBJ_dtor(void* self, int flag);
void cHogFile_dtor(void* p, int flag);
void cVU1Model_dtor(void* p, int flag);
void cVU1Model_Unload(void* p);
void operator_delete(void* p);
}
struct SkyM {
    char pad0[0x16C]; void* p16C; unsigned char b170; char pad171[3]; char m174[4];
};
struct SkyG {
    void* vt; char pad4[0x64]; int n68; SkyM* a6C[1];
};
static inline void DelSky(SkyM* p)
{
    AllocGuard g;
    if (p) {
        cVU1Model_Unload(p->m174);
        if (p->b170) {
            void* q = p->p16C;
            AllocGuard g2;
            cMemMan_Deallocate(0, q, D_004BD038, 0x2B);
        }
        cVU1Model_dtor(p->m174, -1);
        cHogFile_dtor(p, -1);
    }
    cMemMan_Deallocate(0, p, D_004BD038, 0x97);
}
extern "C" SkyG* cSKYBOX_GOBJ_dtor(SkyG* self, short flag)
{
    int i;
    if (self) {
        self->vt = D_004DFC70;
        for (i = 0; i < self->n68; i++) {
            if (self->a6C[i])
                DelSky(self->a6C[i]);
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BC5A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BC5A0 */
