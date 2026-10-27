/*
 * SFOGame/Source/GuiAgentModify: 18 files, 00344AA0-00345110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00344AA0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00344AA0)
static inline void merge_flush_func_00344AA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344AA0 */

/* merge_units: begin func_00344B90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_00344B90, D_004E1220, GuiWidget_dtor)
static inline void merge_flush_func_00344B90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344B90 */

/* merge_units: begin func_00344BF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00344BF0)
static inline void merge_flush_func_00344BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344BF0 */

/* merge_units: begin func_00344CE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_00344CE0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_00344CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344CE0 */

/* merge_units: begin func_00344D00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00344D00, std_vector_imp_cSkeletonBBoxContributionPtr_1_dtor)
static inline void merge_flush_func_00344D00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344D00 */

/* merge_units: begin func_00344D60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00344D60)
static inline void merge_flush_func_00344D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344D60 */

/* merge_units: begin func_00344E50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer-vector helpers (end(), begin(), push_back).
 */

#include "loose03_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int count, int* value);

/* end() */
int* func_00344E50(PtrVec* v) {
    return v->data + v->count;
}

void func_00344E70(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* begin() */
int* func_00344E80(PtrVec* v) {
    return v->data;
}

int** func_00344E90(PtrVec* v) {
    return &v->data;
}

/* push_back */
int func_00344EA0(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00344E50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344E50 */

/* merge_units: begin func_00344EC0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; } Obj0C;
extern void std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(Obj0C* self, int* src, unsigned char flag);
extern void std_vector_pod_int_reserve(Obj0C* self, int value);

/* Initializes self from src, sets the value *src and stores flag at +0xC; returns self. */
Obj0C* func_00344EC0(Obj0C* self, int* src, unsigned char flag)
{
    std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(self, src, flag);
    std_vector_pod_int_reserve(self, *src);
    self->flag = flag;
    return self;
}
static inline void merge_flush_func_00344EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344EC0 */

/* merge_units: begin func_00344F10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00344F10)
static inline void merge_flush_func_00344F10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00344F10 */

/* merge_units: begin func_00345000 */
#pragma push /* merge_units */
extern int D_005331D0;
extern int GuiAgentModify_ManRender(int);

Rel* func_00345000(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int AgentRenderWrapper(void) {
    return GuiAgentModify_ManRender(D_005331D0);
}
static inline void merge_flush_func_00345000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00345000 */

/* merge_units: begin func_00345030 */
#pragma push /* merge_units */
int AgentPartCompare(char* a, char* b) {
    int i;
    for (i = 0; i < 5; i++) {
        a++; b++;
        if (*a != *b) return 0;
    }
    return 1;
}
static inline void merge_flush_func_00345030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00345030 */

/* merge_units: begin func_00345070 */
#pragma push /* merge_units */
void func_00345070(void) {
}

void GuiNetMessages_ProcessNetworkMessages(void) {
}
static inline void merge_flush_func_00345070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00345070 */

/* merge_units: begin func_00345090 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "v4_asm_copy.h"
struct V345090 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q345090 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub345090 { char pad[0x10]; Q345090 pos; };
struct T345090 { V345090 v; char pad4[0xC]; Sub345090 sub; char pad40[0x20]; unsigned char b50; };
struct A345090 { char pad[0x50]; T345090* t; char pad54[0x10]; float heading; };
extern "C" {
float Libc_Atan2f(float y, float x);
void cGOBJ_NextFrame(A345090* a, float dt);
}
extern "C" void func_00345090(A345090* a, float dt)
{
    T345090* t = a->t;
    Q345090 p;
    if (t->b50)
        t->v.v20();
    Sub345090* s = (Sub345090*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Libc_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    cGOBJ_NextFrame(a, dt);
}
static inline void merge_flush_func_00345090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00345090 */

/* merge_units: begin func_00345110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_insert.h"

extern "C" { char D_004BA0E0[] = "vector::insert length error\n"; }
DEFINE_PTRVEC_INSERT(Vector_Insert_345110, 0x1800000, 0xC00000, D_004BA0E0, D_0049AE50, 0x5C, D_0049AF00, 0x64)
static inline void merge_flush_func_00345110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00345110 */

/* merge_units: begin func_003455E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "ptrvec_reserve.h"

extern "C" { char D_004BA100[] = "vector::reserve length error\n"; }
DEFINE_PTRVEC_RESERVE(Vector_Reserve_3455E0, 0x1800000, D_004BA100, D_0049AE50, 0x5C, D_0049AF00, 0x64)
static inline void merge_flush_func_003455E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003455E0 */

/* merge_units: begin func_00345830 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_resize.h"

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(ChannelVector_Resize_345830, Elem60, std_vector_imp_cSkaSliderValue_insert, std_vector_imp_cSkaSliderValue_erase)
#pragma opt_common_subs reset
static inline void merge_flush_func_00345830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00345830 */

/* merge_units: begin func_003458C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_003458C0, Elem8, std_vector_imp_cSkaSwitchValue_insert, std_vector_imp_cSkaSwitchValue_erase)
#pragma opt_common_subs reset
static inline void merge_flush_func_003458C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003458C0 */

/* merge_units: begin func_00345930 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_00345930, std_vector_deleter_tAchievementInfo_clear, D_004AA5B8)
static inline void merge_flush_func_00345930(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00345930 */
