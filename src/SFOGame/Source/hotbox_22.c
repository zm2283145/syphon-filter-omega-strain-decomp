/*
 * SFOGame/Source/hotbox: 6 files, 001734D0-00173640
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001734D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int* value);

/* push_back on a pointer vector. */
int cArray_cHotboxPtr_PushBackActual(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_001734D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001734D0 */

/* merge_units: begin func_001734F0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4H {
    float x, y, z, w;
    V4H& operator=(const V4H& o) { const V4H* ps = &o; V4H* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct ItemsH { int unk0; int count; void** data; unsigned char bC; };
struct HotboxH {
    void* vt;
    char p4[0x60 - 4];
    ItemsH items;
    V4H bmin;
    V4H bmax;
    int type;
    int f94;
    int f98;
    int f9C;
    int fA0;
};
extern "C" {
extern char D_004EE6B8[];
extern char D_004D9AC0[];
void cGOBJ_ctor(void* self, int* gid, int n, char* cls);
void std_vector_cGOBJPtr_ctor_void(ItemsH* v);
}
extern "C" HotboxH* cHotbox_ctor_cObjectIdR_int_cVector_cVector(HotboxH* self, int* gid, int type, V4H* mn, V4H* mx)
{
    cGOBJ_ctor(self, gid, 8, D_004EE6B8);
    self->vt = D_004D9AC0;
    { ItemsH* it = &self->items; std_vector_cGOBJPtr_ctor_void(it); it->bC = 1; }
    self->bmin.x = 3.4028235e38f;
    self->bmin.y = 3.4028235e38f;
    self->bmin.z = 3.4028235e38f;
    self->bmin.w = 1.0f;
    self->bmax.x = -3.4028235e38f;
    self->bmax.y = -3.4028235e38f;
    self->bmax.z = -3.4028235e38f;
    self->bmax.w = 1.0f;
    self->f94 = -1;
    self->type = type;
    self->bmin = *mn;
    self->bmax = *mx;
    self->f98 = 0;
    self->fA0 = 0;
    self->f9C = 10;
    return self;
}
static inline void merge_flush_func_001734F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001734F0 */

/* merge_units: begin func_001735E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cBuddyHotbox_dtor, D_004D99A0, cHotbox_dtor)
static inline void merge_flush_func_001735E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001735E0 */

/* merge_units: begin func_00173640 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose00_types.h"

extern void cGOBJ_NetDeactivate(cGOBJ* obj);
extern void cGOBJ_NetActivate(cGOBJ* obj);

void cHotbox_Init(void) {
}

void cHotbox_Load(void) {
}

void* cHotbox_GetBBox(char* self) {
    return self + 112;
}

/* Set the object's +0x2C flag. */
void cHotbox_NetEnable(cGOBJ* obj) {
    obj->unk2C = 1;
}

/* Clear the object's +0x2C flag. */
void cHotbox_NetDisable(cGOBJ* obj) {
    obj->unk2C = 0;
}

void cHotbox_NetActivate(cGOBJ* obj) {
    obj->unk2C = 1;
    cGOBJ_NetActivate(obj);
}

void cHotbox_NetDeactivate(cGOBJ* obj) {
    obj->unk2C = 0;
    cGOBJ_NetDeactivate(obj);
}

int cHotbox_IsNetworked(void) {
    return 1;
}
static inline void merge_flush_func_00173640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00173640 */

/* merge_units: begin func_001736C0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(std_vector_cHotboxPtr_dtor)
static inline void merge_flush_func_001736C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001736C0 */

/* merge_units: begin func_001737B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cArray_cHotboxPtr_dtor, std_vector_imp_cHotboxPtr_1_dtor)
static inline void merge_flush_func_001737B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001737B0 */
