/*
 * SFOGame/Source/GuiAgentInfo: 6 files, 003643A0-003646A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003643A0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "trivial_dtor.h"
#pragma pop
#include "vc_copy.h"

/* library prototypes shared by the blocks below (C linkage) */
void *memset(void *, int, int);

#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
char * cMemMan_Allocate(...);                      
int cGOBJ_CreateXform(...);           
int cGOBJ_ctor(...);              
char * cSKM_GOBJ_ctor_cObjectIdR(...);                 
int GuiWidget_onAdd(...);                                  
extern char D_004BBA20;
extern char D_004DA470;
extern unsigned char g_ProfileLockEnabled;
extern char g_IdentityMatrix;
}
#pragma push
#pragma opt_common_subs off
extern "C" void GuiAgentDisplay_onAdd(char * arg0) {
        int x4C[1];
    char * temp_s1;
    char * var_s1;

    GuiWidget_onAdd();
    {
        AllocGuard g;
    temp_s1 = (char *)(cMemMan_Allocate(0, 0x68, &D_004BBA20, 0x49));
    }
    if (temp_s1 != NULL) {
        int x44[1]; int x40[1]; x40[0] = 0;
        x44[0] = 0;
        cGOBJ_ctor(temp_s1, x44, 9, x40);
        F_(temp_s1, 0x0, int) = (int)(&D_004DA470);
        F_(temp_s1, 0x60, int) = 0;
        F_(temp_s1, 0x64, int) = 0;
        cGOBJ_CreateXform(temp_s1, &g_IdentityMatrix, 0);
        F_(temp_s1, 0x30, int) = 0;
    }
    F_(arg0, 0x90, int) = (int)(temp_s1);
    {
        AllocGuard g;
    var_s1 = (char *)(cMemMan_Allocate(0, 0x3030, &D_004BBA20, 0x4C));
    }
    if (var_s1 != NULL) {
        x4C[0] = 0;
        var_s1 = (char *)(cSKM_GOBJ_ctor_cObjectIdR(var_s1, x4C));
    }
    F_(arg0, 0x48, int) = (int)(var_s1);
    memset(arg0 + 0xA0, 0, 0x440);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003643A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003643A0 */

/* merge_units: begin func_00364540 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_00364540)
static inline void merge_flush_func_00364540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364540 */

/* merge_units: begin func_00364590 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V3 { float x, y, z; V3() {} V3(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
struct S364590 { void* vtable; char pad4[0x44]; int unk48; char pad4C[0x34]; V3 v80; char pad90[0x4E0 - 0x90]; float f4E0; };
extern "C" char GuiAgentDisplay_vtable[];
extern "C" void GuiWidget_ctor(S364590* self);
extern "C" S364590* GuiAgentDisplay_ctor(S364590* self) {
    V3 t;
    float z;
    GuiWidget_ctor(self);
    self->vtable = GuiAgentDisplay_vtable;
    t.x = 0.0f; t.y = 0.0f; t.z = 3.1415927f;
    VCopyF(&self->v80, &t);
    z = 0.0f;
    self->unk48 = 0;
    self->f4E0 = z;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00364590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00364590 */

/* merge_units: begin func_00364600 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiAgentInfo.cc. Functions are named by address
 * until real names are known.
 */


void func_00364600(void) {
}

void func_00364610(void) {
}
static inline void merge_flush_func_00364600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364600 */

/* merge_units: begin func_00364620 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "v4_asm_copy.h"
struct V364620 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q364620 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub364620 { char pad[0x10]; Q364620 pos; };
struct T364620 { V364620 v; char pad4[0xC]; Sub364620 sub; char pad40[0x20]; unsigned char b50; };
struct A364620 { char pad[0x50]; T364620* t; char pad54[0x10]; float heading; };
extern "C" {
float Libc_Atan2f(float y, float x);
void cGOBJ_NextFrame(A364620* a, float dt);
}
extern "C" void func_00364620(A364620* a, float dt)
{
    T364620* t = a->t;
    Q364620 p;
    if (t->b50)
        t->v.v20();
    Sub364620* s = (Sub364620*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Libc_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    cGOBJ_NextFrame(a, dt);
}
static inline void merge_flush_func_00364620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00364620 */

/* merge_units: begin func_003646A0 */
#pragma push /* merge_units */
void func_003646A0(char* self) {
    self[80] = 0;
}

void func_003646B0(void) {
}

void func_003646C0(char* self) {
    self[44] = 1;
}

void func_003646D0(char* self) {
    self[44] = 0;
}

unsigned char func_003646E0(unsigned char* self) {
    return self[44];
}

int func_003646F0(void) {
    return 0;
}

void func_00364700(void) {
}

int func_00364710(void) {
    return 0;
}

int func_00364720(void) {
    return 0;
}

int func_00364730(void) {
    return 0;
}

int func_00364740(void) {
    return 0;
}

int func_00364750(void) {
    return 0;
}

void func_00364760(void) {
}

int func_00364770(void) {
    return 0;
}
static inline void merge_flush_func_003646A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003646A0 */
