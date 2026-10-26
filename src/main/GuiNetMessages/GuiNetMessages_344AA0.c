/*
 * main/GuiNetMessages: 13 files, 00344AA0-00345090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00344AA0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00344AA0)
#pragma pop /* merge_units */
/* merge_units: end func_00344AA0 */

/* merge_units: begin func_00344B90 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_00344B90, D_004E1220, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_00344B90 */

/* merge_units: begin func_00344BF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00344BF0)
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
#pragma pop /* merge_units */
/* merge_units: end func_00344CE0 */

/* merge_units: begin func_00344D00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00344D00, std_vector_imp_cSkeletonBBoxContributionPtr_1_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00344D00 */

/* merge_units: begin func_00344D60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00344D60)
#pragma pop /* merge_units */
/* merge_units: end func_00344D60 */

/* merge_units: begin func_00344E50 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Pointer-vector helpers (end(), begin(), push_back).
 */

#include "loose03_types.h"

extern int PtrVec_Insert(PtrVec* v, int* pos, int count, int* value);

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
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_00344E50 */

/* merge_units: begin func_00344EC0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char flag; } Obj0C;
extern void std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(Obj0C* self, int* src, unsigned char flag);
extern void PtrVec_Reserve(Obj0C* self, int value);

/* Initializes self from src, sets the value *src and stores flag at +0xC; returns self. */
Obj0C* func_00344EC0(Obj0C* self, int* src, unsigned char flag)
{
    std_vector_imp_cSkeletonBBoxContributionPtr_1_ctor(self, src, flag);
    PtrVec_Reserve(self, *src);
    self->flag = flag;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00344EC0 */

/* merge_units: begin func_00344F10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00344F10)
#pragma pop /* merge_units */
/* merge_units: end func_00344F10 */

/* merge_units: begin func_00345000 */
#pragma push /* merge_units */
extern int D_005331D0;
extern int GuiAgentModify_DrawModelCallback(int);

Rel* func_00345000(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int AgentRenderWrapper(void) {
    return GuiAgentModify_DrawModelCallback(D_005331D0);
}
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
#pragma pop /* merge_units */
/* merge_units: end func_00345030 */

/* merge_units: begin func_00345070 */
#pragma push /* merge_units */
void func_00345070(void) {
}

void GuiNetMessages_ProcessNetworkMessages(void) {
}
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
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A345090* a, float dt);
}
extern "C" void func_00345090(A345090* a, float dt)
{
    T345090* t = a->t;
    Q345090 p;
    if (t->b50)
        t->v.v20();
    Sub345090* s = (Sub345090*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}
#pragma pop /* merge_units */
/* merge_units: end func_00345090 */
