/*
 * main/GuiAgentCreate: range (3 files, 0028F520-0028F760)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "vslot_pad.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int Mem_Free();

/* merge_units: begin func_0028F520 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V28F520 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); };
struct O28F520 { void* vt; char pad[0x5C]; V28F520* items[4]; char pad70[4]; V28F520* p74; };
extern "C" {
extern char D_004DD1B0[];
extern char D_0055DDA0[];
void AgentPartCache_Unlock(void* p);
void World_ClearPendingIfLoaded(void);
void GuiWidget_Destroy(void* p, int f);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}
static inline void Del28F520(V28F520* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, "GuiAgentCreate.cc", line);
}
extern "C" O28F520* GuiAgentCreate_dtor(O28F520* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DD1B0;
        Del28F520(self->p74, 0x169);
        for (i = 0; i < 4; i++) {
            self->items[i]->v22(1);
            Del28F520(self->items[i], 0x16D);
        }
        AgentPartCache_Unlock(D_0055DDA0);
        World_ClearPendingIfLoaded();
        GuiWidget_Destroy(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028F520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028F520 */

/* merge_units: begin func_0028F700 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_0028F700, D_004DA470, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0028F700 */

/* merge_units: begin func_0028F760 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_common_subs on

struct V4_F760 { float x, y, z, w; };
struct Q4_F760 { __int128 q; };
struct M4_F760 { float m[4][4]; } __attribute__((aligned(16)));
struct M4Q_F760 { __int128 r[4]; };
static inline void M4Cp_F760(M4Q_F760* d0, const M4Q_F760* s0) { M4Q_F760* d = d0; __int128 qa, qb; const M4Q_F760* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct V4C_F760 { float x, y, z, w; V4C_F760(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } V4C_F760(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
static inline void* QAsg0_F760(void* d0, const void* s0) { void* d = d0; __int128 q = 0; const void* s = s0; q = *(const __int128*)s; *(__int128*)d = q; return d; }
struct Ent_F760 { __int128 a; __int128 b; };
struct Name_F760 { char s[16]; };
struct Sph_F760 { char pad[0x20]; };
struct SVec_F760 { char pad[0x10]; };
struct Word_F760 { int w; };
struct H_F760 { char pad[0xC]; int serial; };

class Xf_F760 {
public:
    VPAD2(a) virtual void SetMtx(M4_F760* m);
};

struct Man_F760 {
    char pad0[0x40];
    char app[0x30];
    char name[0x10];
    Ent_F760 e[(0x23C0 - 0x80) / 0x20];
    unsigned short cnt;
    char pad23C2[0x23F0 - 0x23C2];
    float f23F0;
    float f23F4;
    char pad23F8[0x2BD0 - 0x23F8];
    int f2BD0;
    char pad2BD4[0x2C04 - 0x2BD4];
    void* f2C04;
    char pad2C08[0x2C11 - 0x2C08];
    unsigned char b2C11;
    char pad2C12[0x2D70 - 0x2C12];
    H_F760* f2D70;
    int f2D74;
    char pad2D78[8];
    V4_F760 pos;
    char pad2D90[4];
    short s2D94;
    char pad2D96[0xA];
    unsigned char b2DA0;
};

class Model_F760 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetMtx(M4_F760* m);
    VPAD4(d) VPAD2(e) virtual void Init(int a);
    char pad4[0x4C];
    Xf_F760* xf;
    char pad54[0xC];
    Man_F760 man;
};

struct Self_F760 {
    void* vt;
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x5C - 0x16];
    int f5C;
    Model_F760* models[4];
    Model_F760* f70;
    void* f74;
    char pad78[8];
    Name_F760 name;
    int f90;
    float f94[7];
    V4_F760 fB0;
    int fC0;
    char padC4[8];
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    int fDC;
    int fE0;
    int fE4;
    int fE8;
    signed char fEC;
    unsigned char fED;
    unsigned char fEE;
    signed char fEF;
    unsigned char fF0;
};

struct Tab_F760 { unsigned char mode; unsigned char slot; short pos; };
struct TabP_F760 { short pos; short pad; };
struct TabS_F760 { unsigned char slot; char pad[3]; };
struct Blk_F760 { char d[0x440]; };
struct GDef_F760 { Name_F760 name; int i; float f[7]; };

extern "C" {
extern char D_004DA470[];
extern int D_004FFC04;
extern signed char D_00493A60;
extern char D_004A9AC0[];
extern char D_004A9AE0[];
extern char D_004A9AA0[];
extern char D_0055C9F0[];
extern char D_004A9B00[];
extern char D_004A9B10[];
extern char D_004A9A28[];
extern Blk_F760 D_0055D510[];
extern void* D_004F77A0;
extern char D_0048B470[2][11][6];
extern Tab_F760 D_0048B500[2][11];
extern GDef_F760 D_0056F9B0;
void GuiWidget_ctor(Self_F760* self);
void FrontEnd_GetCharacterData(int a);
void Skl_Load(void* a, char* b, char* c);
void* Mem_Alloc(int pool, int size, char* file, int line);
void cGOBJ_ctor(void* p, int* a, int b, int* c);
void Object_AttachTransform(void* p, void* t, int a);
Model_F760* DisplayActor_Construct(void* p, int* idx);
float Math_SinThunk(float a);
float Math_CosThunk(float a);
void Mtx44_SetRotation(M4_F760* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
unsigned short Appearance_GetPairCount(void* app);
unsigned short AgentPacking_AddBlankPairs(void* app, unsigned short n);
void Appearance_ReorderParts(Man_F760* m);
int Appearance_GetBodyKind(void* app);
int Appearance_GetToneDigit(void* app);
void cVUM_GOBJ_InitModel(Model_F760* m, char* name);
void func_00290BB0(Word_F760* w, int n);
void func_00290A50(SVec_F760* v, Word_F760* w, unsigned char f);
V4_F760* Vec4_Set(V4_F760* v, float x, float y, float z, float w);
void func_002909C0(Sph_F760* s, int bone, float r, V4_F760* off);
void func_002909A0(SVec_F760* v, Sph_F760** p);
void func_001B06F0(Sph_F760* s, int f);
void* func_00290990(Model_F760* m);
void FrontEnd_SetNodeSpheres(void* n, SVec_F760* v);
void func_001AF880(SVec_F760* v, int f);
void Model_Attach(void* a, void* b);
void AnimModel_InitAnim(void* a);
void Model_HardMeshAttachPoints(Man_F760* m);
void func_0038E030(Man_F760* m);
void ActorModel_Setup(Man_F760* m, int flag);
void Skel_ApplyScalePreset(Man_F760* m, int a);
int AgentPartCache_FindMesh(void* db, __int128 key);
int AgentPartCache_FindTexture(void* db, __int128 key);
void GuiAgentCreate_UpdateCount(Self_F760* self);
Self_F760* GuiAgentCreate_ctor(Self_F760* self);
}

static inline void SetH_F760(Man_F760* m, H_F760* o) { m->f2D70 = o; { int d; m->f2D74 = *(o ? &o->serial : (d = -1, &d)); } }
static inline void QCopy_F760(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
    asm {
        .set noreorder
    loop:
        lq $v0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $v0, -0x10(d)
        .set reorder
    }
}
static inline int KeyEq_F760(__int128 m, __int128 a, __int128 b) {
    __int128 r;
    asm {
        pand r, m, a
        pand b, m, b
        pceqw r, r, b
        ppach r, r, r
    }
    return (long)r == -1;
}
static inline long KeyR_F760(__int128 m, __int128 a, __int128 b) {
    __int128 r, o;
    asm {
        pand r, m, a
        pand b, m, b
        pceqw r, r, b
        ppach o, r, r
    }
    return (long)o;
}
static inline __int128 KeyMask_F760(__int128 v) { __int128 r; asm { pcpyld r, $zero, v } return r; }
static inline void* Alloc_F760(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004A9AA0, line); }
static inline int Eq4_F760(const char* a, const char* b) {
    int k;
    for (k = 0; k < 4; k++) {
        if (*++a != *++b) return 0;
    }
    return 1;
}

static inline Man_F760* MANP_F760(Model_F760* m) { return &m->man; }
static inline char* APP_F760(Man_F760* m) { return m->app; }
static inline char* NAME_F760(Man_F760* m) { return m->name; }
static inline V4_F760* Splat_F760(V4_F760* t, float) { float z = 0.0f; return Vec4_Set(t, z, z, z, z); }
static inline void Spheres_F760(Model_F760* md)
{
            Word_F760 w;
            {
                SVec_F760 vec;
                Sph_F760 arr[12];
                V4_F760 t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
                int k;
                func_00290BB0(&w, 0x15);
                func_00290A50(&vec, &w, 1);
                func_002909C0(&arr[0], 0, 0.75f, Splat_F760(&t0, 0.0f));
                func_002909C0(&arr[1], 4, 0.41666666f, Splat_F760(&t1, 0.0f));
                func_002909C0(&arr[2], 6, 0.41666666f, Splat_F760(&t2, 0.0f));
                func_002909C0(&arr[3], 0xC, 0.75f, Splat_F760(&t3, 0.0f));
                func_002909C0(&arr[4], 0x10, 0.75f, Splat_F760(&t4, 0.0f));
                func_002909C0(&arr[5], 0xE, 1.0f, Splat_F760(&t5, 0.0f));
                func_002909C0(&arr[6], 0xD, 0.33333334f, Splat_F760(&t6, 0.0f));
                func_002909C0(&arr[7], 0xF, 0.33333334f, Splat_F760(&t7, 0.0f));
                func_002909C0(&arr[8], 0x11, 0.33333334f, Splat_F760(&t8, 0.0f));
                func_002909C0(&arr[9], 0x12, 0.33333334f, Splat_F760(&t9, 0.0f));
                func_002909C0(&arr[10], 0x13, 0.6666667f, Splat_F760(&t10, 0.0f));
                func_002909C0(&arr[11], 0x14, 0.6666667f, Splat_F760(&t11, 0.0f));
                for (k = 0; k < 12; k++) {
                    Sph_F760* sp; Sph_F760** pp = &sp; sp = &arr[k]; func_002909A0(&vec, pp);
                }
                func_001B06F0(&arr[11], -1);
                func_001B06F0(&arr[10], -1);
                func_001B06F0(&arr[9], -1);
                func_001B06F0(&arr[8], -1);
                func_001B06F0(&arr[7], -1);
                func_001B06F0(&arr[6], -1);
                func_001B06F0(&arr[5], -1);
                func_001B06F0(&arr[4], -1);
                func_001B06F0(&arr[3], -1);
                func_001B06F0(&arr[2], -1);
                func_001B06F0(&arr[1], -1);
                func_001B06F0(&arr[0], -1);
                FrontEnd_SetNodeSpheres(func_00290990(md), &vec);
                func_001AF880(&vec, -1);
            }
}
static inline void QAsgB_F760(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void SetF_F760(Model_F760* md, float v) { md->man.f23F0 = v; }
static inline int& Neg1_F760(int& d) { d = -1; return d; }
static inline int& Ser_F760(H_F760* o, int& d) { return *(o ? &o->serial : &Neg1_F760(d)); }
static inline void SerSet_F760(Man_F760* m) { int d; m->f2D74 = Ser_F760(0, d); }
static inline void SetI_F760(Model_F760* md, int v) { md->man.f2BD0 = v; }
static inline void SetS_F760(Model_F760* md, short v) { md->man.s2D94 = v; }
static inline void SetB_F760(Model_F760* md, unsigned char v) { md->man.b2C11 = v; }
static inline void G_F760(void* p, int a, int n, int b) { int* pa = &a; cGOBJ_ctor(p, pa, n, &b); }
static inline void Tail_F760(Self_F760* self, int i, V4_F760& v)
{
    int d;
            {
                Spheres_F760(self->models[i]);
            }
            {
                void* a = D_004F77A0;
                void** an = (void**)((char*)self->models[i] + 0x2EC0);
                Model_Attach(an + 4, a);
                *an = a;
                AnimModel_InitAnim(an);
            }
            {
                Model_F760** pm = (Model_F760**)(i * 4 + (char*)self->models);
                SetF_F760(*pm, 1.0f);
                (*pm)->man.f23F4 = 0.0f;
                Model_HardMeshAttachPoints(&(*pm)->man);
            }
            {
                Man_F760* m;
                v.x = 0.0f; v.y = 30.0f; v.z = 0.0f; v.w = 1.0f;
                { Model_F760* md = self->models[i]; md->man.f2D70 = 0; m = &md->man; }
                m->f2D74 = Ser_F760(0, d);
                { QAsgB_F760(&m->pos, &v); m->pos.w = 1.0f; }
            }
            { Man_F760* mm = &self->models[i]->man; mm->b2DA0 = 1; }
            func_0038E030(&self->models[i]->man);
            {
                int c;
                Model_F760* m;
                Model_F760** pm = (Model_F760**)(i * 4 + (char*)self->models);
                c = 1; m = *pm; m->man.f2BD0 = c;
                ActorModel_Setup(&(*pm)->man, 1);
            }
            Skel_ApplyScalePreset(&self->models[i]->man, -1);
            {
                Model_F760** pm = (Model_F760**)(i * 4 + (char*)self->models);
                SetS_F760(*pm, 0);
                SetB_F760(*pm, 1);
            }
}
extern "C" Self_F760* GuiAgentCreate_ctor(Self_F760* p0)
{
    int i;
    Self_F760* self = p0;
    GuiWidget_ctor(p0);
    self->vt = D_004DD1B0;
    self->flags |= 0x20;
    self->fCC = -1;
    self->fD0 = 1;
    FrontEnd_GetCharacterData(D_004FFC04);
    D_00493A60 = -1;
    Skl_Load(D_0055DDA0, D_004A9AC0, D_004A9AE0);
    {
        void* p;
        p = Alloc_F760(0x68, 0xFB);
        if (p) {
            G_F760(p, 0, 9, 0);
            *(char**)p = D_004DA470;
            ((int*)p)[0x60 / 4] = 0;
            ((int*)p)[0x64 / 4] = 0;
            Object_AttachTransform(p, D_0055C9F0, 0);
            ((int*)p)[0x30 / 4] = 0;
        }
        self->f74 = p;
    }
    {
        M4_F760 mtx;
        {
            M4_F760 t;
            float one = 1.0f; float tz = -3.25f;
            t.m[0][0] = one; t.m[0][1] = 0.0f; t.m[0][2] = 0.0f; t.m[0][3] = 0.0f;
            t.m[1][0] = 0.0f; t.m[1][1] = one; t.m[1][2] = 0.0f; t.m[1][3] = 0.0f;
            t.m[2][0] = 0.0f; t.m[2][1] = 0.0f; t.m[2][2] = one; t.m[2][3] = 0.0f;
            t.m[3][0] = 0.0f; t.m[3][1] = 0.0f; t.m[3][2] = tz; t.m[3][3] = one;
            M4Cp_F760((M4Q_F760*)&mtx, (M4Q_F760*)&t);
        }
        float pb = 3.1415927f;
        {
            V4C_F760 r(0.0f, 0.0f, pb);
            QAsg0_F760(&self->fB0, &r);
        }
        self->fD4 = 0;
        self->fE8 = 0;
        self->fED = 0;
        self->fEE = 0;
        self->fEF = 0xB;
        self->fF0 = 0;
        for (i = 0; i < 4; i++) {
            Model_F760* p;
            p = (Model_F760*)Alloc_F760(0x3030, 0x10A);
            if (p) {
                int x[1]; x[0] = i;
                p = DisplayActor_Construct(p, x);
            }
            {
                Model_F760* m;
                char* buf;
                Model_F760** pm = (Model_F760**)(i * 4 + (char*)self->models);
                *pm = p;
                m = *pm; buf = (char*)m + 0x2E50; m->man.f2C04 = buf;
                (*pm)->SetMtx(&mtx);
            }
            {
                Xf_F760* xf = self->models[i]->xf;
                M4_F760 rot;
                float s = Math_SinThunk(0.0f);
                float c = Math_CosThunk(0.0f);
                { M4_F760* pr = &rot; float z = 0.0f; Mtx44_SetRotation(pr, c, -s, z, s, c, z, z, z, 1.0f); }
                { M4_F760* pr = &rot; xf->SetMtx(pr); }
            }
            QCopy_F760(APP_F760(&self->models[i]->man), &D_0055D510[i & 1], 0x44);
            {
                Man_F760* m = &self->models[i]->man;
                m->cnt = Appearance_GetPairCount(m->app);
            }
            {
                Man_F760* m = &self->models[i]->man;
                m->cnt = AgentPacking_AddBlankPairs(m->app, m->cnt);
            }
            Appearance_ReorderParts(&self->models[i]->man);
            self->fD8 = Appearance_GetBodyKind(APP_F760(&self->models[i]->man));
            {
                char* nm; if (self->fD8 == 0) nm = D_004A9B00; else { nm = D_004A9B10; asm { .set reorder } }
                cVUM_GOBJ_InitModel(self->models[i], nm);
                String_Copy(NAME_F760(&self->models[i]->man), nm);
            }
            self->models[i]->Init(1);
            { V4_F760 v; Tail_F760(self, i, v); }
        }
    }
    self->f70 = self->models[0];
    self->fD8 = Appearance_GetBodyKind(APP_F760(&self->models[0]->man));
    self->fDC = (signed char)Appearance_GetToneDigit(APP_F760(&self->models[0]->man));
    Appearance_GetBodyKind(APP_F760(&self->models[1]->man));
    {
        int n;
        int j;
        const char* str;
        int k;
        for (j = 0; j < 11; j++) {
            {
                str = D_0048B470[0][j];
                for (k = 0, n = self->models[1]->man.cnt; k <= n; k++) {
                    if (Eq4_F760(str, (char*)&MANP_F760(self->models[1])->e[k].b)) {
                        D_0048B500[0][j].slot = k;
                        break;
                    }
                }
            }
            {
                str = D_0048B470[1][j];
                for (k = 0, n = self->models[0]->man.cnt; k <= n; k++) {
                    if (Eq4_F760(str, (char*)&MANP_F760(self->models[0])->e[k].b)) {
                        D_0048B500[1][j].slot = k;
                        break;
                    }
                }
            }
        }
    }
    {
        int j;
        for (j = 0; j < 11; j++) {
            D_0048B500[0][j].pos = 0;
            D_0048B500[1][j].pos = 0;
        }
    }
    {
        __int128 mask;
        { long v = 0xFFFFFFFF00; asm { pcpyld mask, $zero, v } }
        union { __int128 q; char s[16]; } key;
        String_Copy(key.s, D_004A9A28);
        {
            int k;
            for (k = 0; k < self->f70->man.cnt; k++) {
                if (KeyR_F760(mask, key.q, MANP_F760(self->f70)->e[k].a) == -1) {
                    self->fEC = k;
                    break;
                }
            }
        }
    }
    self->fED = D_0048B500[self->fD8][self->fEF].slot;
    self->fEE = D_0048B500[self->fD8][self->fEF].mode;
    self->fE0 = AgentPartCache_FindMesh(D_0055DDA0, MANP_F760(self->f70)->e[(signed char)self->fED].a);
    self->fE4 = AgentPartCache_FindTexture(D_0055DDA0, MANP_F760(self->f70)->e[(signed char)self->fED].b);
    GuiAgentCreate_UpdateCount(self);
    self->fC0 = 0;
    self->name = D_0056F9B0.name;
    self->f90 = D_0056F9B0.i;
    self->f94[0] = D_0056F9B0.f[0];
    self->f94[1] = D_0056F9B0.f[1];
    self->f94[2] = D_0056F9B0.f[2];
    self->f94[3] = D_0056F9B0.f[3];
    self->f94[4] = D_0056F9B0.f[4];
    self->f94[5] = D_0056F9B0.f[5];
    self->f94[6] = D_0056F9B0.f[6];
    self->f5C = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0028F760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0028F760 */
