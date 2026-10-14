/*
 * main/scriptManager: range (4 files, 003DC5A0-003DC8A0)
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
int Mem_Free();

/* merge_units: begin func_003DC5A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int *Mem_Alloc(...);                     
int func_003D6BE0(...);                   
int func_003DD9F0(...);                           
extern int D_004BD4C0;
extern unsigned char D_00533880;
extern int D_00555070;
}
extern "C" void func_003DC5A0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
int *var_s4;
int temp_s3;
int var_s2;
int *var_s1;
int temp_s5;
    int *var_s0;
    int temp_a1;
    int temp_v0;

    temp_s5 = arg4;
    var_s4 = (int *)(arg5);
    temp_s3 = func_003DD9F0(&D_00555070);
    if (temp_s5 != 0) {
        {
            AllocGuard g;
        var_s1 = Mem_Alloc(0, temp_s5 * 4, &D_004BD4C0, 0xB76);
        }
    } else {
        var_s1 = NULL;
    }
    for (var_s2 = 0; var_s2 < temp_s5; var_s2++) {
        temp_v0 = func_003D6BE0(temp_s3, var_s4[var_s2]);
        if (temp_v0 != NULL) {
            var_s1[var_s2] = F_(temp_v0, 0x4, int);
        } else if (arg2 != 0) {
            var_s1[var_s2] = 0;
        }
    }
    temp_a1 = arg7 * 4;
    *(int *)((char *)F_(arg0, 0x28, int) + temp_a1) = (int)(var_s1);
    *(int *)((char *)F_(arg0, 0x38, int) + temp_a1) = F_(temp_s3, 0x38, int);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DC5A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DC5A0 */

/* merge_units: begin func_003DC720 */
#pragma push /* merge_units */
typedef struct F1Ctx3DC { char pad0[0x18]; int* defs; } F1Ctx3DC;
typedef struct F1Def3DC { int pad0; int type; int count; char pad0C[0x10]; int args[23]; int linked; } F1Def3DC;
#if 0 /* merge_units */
extern char D_00555070[];
#endif /* merge_units */
#define D_00555070 ((char*)&D_00555070) /* merge_units */

extern int Script_ResolveType(F1Ctx3DC* ctx, int type);
extern int Script_LinkDefinition(void* tab, F1Def3DC* def, F1Ctx3DC* ctx);
int func_003DC720(F1Ctx3DC* ctx, F1Def3DC* def, int idx)
{
    int i;
    int r;
    def->type = Script_ResolveType(ctx, def->type);
    for (i = 0; i < def->count; i++) {
        def->args[i] = Script_ResolveType(ctx, def->args[i]);
    }
    r = 0;
    if (def->type >= 0) {
        r = Script_LinkDefinition(D_00555070, def, def->linked ? ctx : 0);
    }
    ctx->defs[idx] = r;
    return r;
}
#undef D_00555070 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DC720(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DC720 */

/* merge_units: begin func_003DC7F0 */
#pragma push /* merge_units */
typedef struct Ctx3DC7 { char pad0[0x8]; int* defs; } Ctx3DC7;
#if 0 /* merge_units */
extern char D_00555070[];
#endif /* merge_units */
#define D_00555070 ((char*)&D_00555070) /* merge_units */

#if 0 /* merge_units */
extern int Script_ResolveType(Ctx3DC7* ctx, int type);
#endif /* merge_units */
#define Script_ResolveType(a0, a1) (Script_ResolveType((void *)(a0), (a1))) /* merge_units */

extern int func_003DD790(void* tab, int a, int type, int b, int c, Ctx3DC7* ctx, int d);
void func_003DC7F0(Ctx3DC7* ctx, int a, int type, int b, int c, int d, int idx)
{
    int r;
    int t = Script_ResolveType(ctx, type);
    r = 0;
    if (t >= 0) {
        r = func_003DD790(D_00555070, a, t, b, c, ctx, d);
    }
    ctx->defs[idx] = r;
}
#undef D_00555070 /* merge_units */
#undef Script_ResolveType /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DC7F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DC7F0 */

/* merge_units: begin func_003DC8A0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VObj_3DC8A0 { virtual void dtor(int f); };
typedef struct { char pad[0x10]; int refs; } RefA_3DC8A0;
typedef struct { char pad[0x38]; int refs; } RefB_3DC8A0;
typedef struct { int pad0; int count; void** data; int padC; } Vec_3DC8A0;
typedef struct {
    Vec_3DC8A0 v0; Vec_3DC8A0 v10; Vec_3DC8A0 v20; Vec_3DC8A0 v30;
    Vec_3DC8A0 v40; Vec_3DC8A0 v50; Vec_3DC8A0 v60; Vec_3DC8A0 v70;
    void* p80; void* p84; void* p88;
} Self_3DC8A0;
extern "C" {
#if 0 /* merge_units */
extern char D_004BD4C0[];
#endif /* merge_units */
#define D_004BD4C0 ((char*)&D_004BD4C0) /* merge_units */

void func_0013A040(void* p, int f);
void func_00145F10(void* p, int f);
void** func_002151B0(void* v, int i);
void func_00397F80(void* p, int f);
void func_003D8160(void* p, int f);
void func_003D8250(void* p, int f);
VObj_3DC8A0** func_003DC060(void* v, int i);
void** func_003DC070(void* v, int i);
void func_003DCE80(void* p, int f);
void operator_delete(void* p);
}
static inline void Free_3DC8A0(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BD4C0, line); }
static inline void FreeV_3DC8A0(VObj_3DC8A0* o, int line) { AllocGuard g; o->dtor(-1); Mem_Free(0, o, D_004BD4C0, line); }

#pragma opt_strength_reduction off
extern "C" Self_3DC8A0* func_003DC8A0(Self_3DC8A0* self, short f)
{
    if (self) {
        Free_3DC8A0(self->p80, 0xB29);
        if (self->p84) Free_3DC8A0(self->p84, 0xB2C);
        if (self->p88) Free_3DC8A0(self->p88, 0xB2F);
        {
            int n = self->v60.count; int i;
            for (i = 0; i < n; i++) Free_3DC8A0(*func_002151B0(&self->v60, i), 0xB35);
            self->v60.count = 0;
        }
        {
            int i; int n = self->v20.count;
            for (i = 0; i < n; i++)
                if (self->v20.data[i]) Free_3DC8A0(*func_003DC070(&self->v20, i), 0xB3D);
        }
        {
            int n = self->v0.count; int i;
            for (i = 0; i < n; i++) {
                RefA_3DC8A0* r = (RefA_3DC8A0*)self->v0.data[i];
                if (r) r->refs--;
            }
        }
        {
            int n = self->v10.count; int i;
            for (i = 0; i < n; i++) {
                RefB_3DC8A0* r = (RefB_3DC8A0*)self->v10.data[i];
                if (r) r->refs--;
            }
        }
        {
            VObj_3DC8A0* o; int n = self->v50.count; int i;
            for (i = 0; i < n; i++) { o = *func_003DC060(&self->v50, i); FreeV_3DC8A0(o, 0xB4B); }
        }
        {
            int n = self->v70.count; int i;
            for (i = 0; i < n; i++) Free_3DC8A0(*func_002151B0(&self->v70, i), 0xB4F);
        }
        if (&self->v70) func_00145F10(&self->v70, -1);
        if (&self->v60) func_00145F10(&self->v60, -1);
        if (&self->v50) func_003DCE80(&self->v50, -1);
        if (&self->v40) func_0013A040(&self->v40, -1);
        if (&self->v30) func_0013A040(&self->v30, -1);
        if (&self->v20) func_00397F80(&self->v20, -1);
        if (&self->v10) func_003D8250(&self->v10, -1);
        if (self) func_003D8160(self, -1);
        if (f > 0) operator_delete(self);
    }
    return self;
}
#undef D_004BD4C0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DC8A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DC8A0 */
