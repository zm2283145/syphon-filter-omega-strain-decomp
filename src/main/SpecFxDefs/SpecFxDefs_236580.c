/*
 * main/SpecFxDefs: range (2 files, 00236580-00236810)
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

/* merge_units: begin func_00236580 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004A6E38[];
extern char D_004DBD80[];
extern char D_004DF860[];
void cGOBJ_dtor(void* p, int flag);
void cParticle_dtor(void* p, int flag);
void operator_delete(void* p);
}
struct E_00236580 { void* a; };
struct S_00236580 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(int a);
    char pad4[0x28]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2f[0x7C - 0x2F]; E_00236580** arr; int pad80; int n;
};
static inline void Free_00236580(void* p, int line) { AllocGuard g; cMemMan_Deallocate(0, p, D_004A6E38, line); }
extern "C" S_00236580* cHumanParticleGroup_dtor(S_00236580* self, short flag)
{
    if (self) {
        int i;
        *(char**)self = D_004DBD80;
        for (i = 0; i < self->n; i++) {
            E_00236580* e = self->arr[i];
            AllocGuard g;
            if (e) {
                if (e->a) { void* q = e->a; AllocGuard g2; cParticle_dtor(q, -1); cMemMan_Deallocate(0, q, "specFxDefs.hh", 0x10A); }
            }
            cMemMan_Deallocate(0, e, D_004A6E38, 0x1A8);
        }
        Free_00236580(self->arr, 0x1AA);
        if (self) {
            bool ok;
            *(char**)self = D_004DF860;
            ok = self->b2D && self->b2C && !self->b2E;
            if (ok) self->v22(1);
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236580(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236580 */

/* merge_units: begin func_00236810 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
#if 0 /* merge_units */
int Alloc_Lock(int);
#endif /* merge_units */
#define Alloc_Lock(a0) (Alloc_Lock((a0))) /* merge_units */
                                    
#if 0 /* merge_units */
int EnableIntc(int);
#endif /* merge_units */
#define EnableIntc(a0) (EnableIntc((a0))) /* merge_units */
                                  
int nGobjManager_GetNextId(char *, int);                           
char * cMemMan_Allocate(int, int, char *, int);                    
int cGOBJ_ctor(char * , char *, int, int *);                
#if 0 /* merge_units */
extern char D_004A6E38;
#endif /* merge_units */
#define D_004A6E38 (*(char*)&D_004A6E38) /* merge_units */

#if 0 /* merge_units */
extern char D_004DBD80;
#endif /* merge_units */
#define D_004DBD80 (*(char*)&D_004DBD80) /* merge_units */

#if 0 /* merge_units */
extern char D_004DF860;
#endif /* merge_units */
#define D_004DF860 (*(char*)&D_004DF860) /* merge_units */

extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

typedef struct { int f0; char p4[43]; signed char f2F; char p30[48]; int f60; int f64; short f68; char p6A[6]; int f70; int f74; int f78; int f7C; int f80; int f84; } PS0_00236810;
char * cHumanParticleGroup_ctor(PS0_00236810 *arg0, int arg1, int arg2, int arg3, float farg0) {
    int sp9C;
    int sp98;
    int var_s0;
    char * temp_s5;
    char * temp_s6;
    int var_s5;

    nGobjManager_GetNextId(&sp9C, 0xE7);
    sp98 = 0;
    cGOBJ_ctor(arg0, &sp9C, 4, &sp98);
    arg0->f0 = (int)(&D_004DF860);
    arg0->f60 = -1;
    arg0->f64 = 0;
    arg0->f68 = 0;
    arg0->f70 = 0x3F800000;
    arg0->f2F = 1;
    arg0->f0 = (int)(&D_004DBD80);
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s5 = cMemMan_Allocate(0, arg3 * 4, &D_004A6E38, 0x194);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    var_s0 = 0;
    g_ProfileLockDepth -= 1;
    arg0->f7C = (int)(temp_s5);
    for (var_s0 = 0; var_s0 < arg3; var_s0++) {
            if (g_ProfileLockEnabled != 0) {
                Alloc_Lock(9);
            }
            g_ProfileLockDepth += 1;
            temp_s6 = cMemMan_Allocate(0, 0x20, &D_004A6E38, 0x197);
            if (g_ProfileLockEnabled != 0) {
                EnableIntc(9);
            }
            g_ProfileLockDepth -= 1;
            if (temp_s6 != NULL) {
                F_(temp_s6, 0x0, int) = 0;
                F_(temp_s6, 0x4, float) = farg0;
            }
            ((char **)arg0->f7C)[var_s0] = temp_s6;
    }
    arg0->f78 = arg2;
    arg0->f84 = arg3;
    arg0->f74 = arg1;
    arg0->f80 = 0x3C23D70A;
    return arg0;
}
#undef Alloc_Lock /* merge_units */
#undef EnableIntc /* merge_units */
#undef D_004A6E38 /* merge_units */
#undef D_004DBD80 /* merge_units */
#undef D_004DF860 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00236810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00236810 */
