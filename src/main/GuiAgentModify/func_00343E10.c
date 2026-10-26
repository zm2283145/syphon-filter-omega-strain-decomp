#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"
#include "SFOLobby_helpers.h"

#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_common_subs on

/* Empty 'asm { .set reorder }' blocks below are scheduling barriers only (emit no instructions). */

struct V4_E10 { float x, y, z, w; };
struct M4_E10 { float m[4][4]; } __attribute__((aligned(16)));
struct M4Q_E10 { __int128 r[4]; };
static inline void M4Cp_E10(M4Q_E10* d0, const M4Q_E10* s0) { M4Q_E10* d = d0; __int128 qa, qb; const M4Q_E10* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct V4C_E10 { float x, y, z, w; V4C_E10(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } V4C_E10(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
static inline void* QAsg0_E10(void* d0, const void* s0) { void* d = d0; __int128 q = 0; const void* s = s0; q = *(const __int128*)s; *(__int128*)d = q; return d; }
struct Ent_E10 { __int128 a; __int128 b; };
struct Name_E10 { char s[16]; };
struct Sph_E10 { char pad[0x20]; };
struct SVec_E10 { char pad[0x10]; };
struct Word_E10 { int w; };
struct H_E10 { char pad[0xC]; int serial; };
struct Aw_E10 { char pad[0xC]; unsigned char bC; char padD[3]; };

class Xf_E10 {
public:
    VPAD2(a) virtual void SetMtx(M4_E10* m);
};

struct Man_E10 {
    char pad0[0x40];
    char app[0x30];
    char name[0x10];
    Ent_E10 e[(0x23C0 - 0x80) / 0x20];
    unsigned short cnt;
    char pad23C2[0x23F0 - 0x23C2];
    float f23F0;
    float f23F4;
    char pad23F8[0x2BD0 - 0x23F8];
    int f2BD0;
    char pad2BD4[0x2C04 - 0x2BD4];
    void* f2C04;
    char pad2C08[0x2C0D - 0x2C08];
    signed char b2C0D;
    char pad2C0E[0x2C11 - 0x2C0E];
    unsigned char b2C11;
    char pad2C12[0x2D70 - 0x2C12];
    H_E10* f2D70;
    int f2D74;
    char pad2D78[8];
    V4_E10 pos;
    char pad2D90[4];
    short s2D94;
    char pad2D96[0xA];
    unsigned char b2DA0;
};

class Model_E10 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetMtx(M4_E10* m);
    VPAD4(d) VPAD2(e) virtual void Init(int a);
    char pad4[0x4C];
    Xf_E10* xf;
    char pad54[0xC];
    Man_E10 man;
};

struct Self_E10 {
    void* vt;
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x48 - 0x16];
    int f48;
    char pad4C[0x7C - 0x4C];
    int f7C;
    char pad80[0x8C - 0x80];
    Model_E10* model;
    void* f90;
    char pad94[0xA0 - 0x94];
    Name_E10 name;
    int fB0;
    float fB4[7];
    V4_E10 fD0;
    int fE0;
    char padE4[0xEC - 0xE4];
    int fEC;
    int fF0;
    int fF4;
    int fF8;
    int fFC;
    int f100;
    int f104;
    int f108;
    signed char f10C;
    signed char f10D;
    unsigned char f10E;
    signed char f10F;
    unsigned char f110;
};

struct Tab_E10 { unsigned char mode; signed char slot; short pos; };
struct TabS_E10 { signed char slot; char pad[3]; };
struct TabP_E10 { short pos; short pad; };
struct Blk_E10 { char d[0x440]; };
struct GDef_E10 { Name_E10 name; int i; float f[7]; };

extern "C" {
extern char D_004E1220[];
extern char D_004DE920[];
extern char D_004DA470[];
extern int D_004FFC04;
extern signed char D_00493A60;
extern char D_004BA0A0[];
extern char D_004BA0B8[];
extern char D_004BA0C8[];
extern char D_004B9F80[];
extern char g_IdentityMatrix[];
extern char g_AgentPartCache[];
extern char g_Game[];
extern Blk_E10 D_0055D510[];
extern void* D_004F77A0;
extern char D_00492900[2][16][8];
extern Tab_E10 D_00492A00[16];
extern TabS_E10 D_00492A01[16];
extern TabP_E10 D_00492A02[16];
extern GDef_E10 D_0056F9B0;
void GuiWidget_ctor(Self_E10* self);
void FrontEnd_GetCharacterData(int a);
void* Mem_Alloc(int pool, int size, char* file, int line);
void cGOBJ_ctor(void* p, int* a, int b, int* c);
void Object_AttachTransform(void* p, void* t, int a);
Model_E10* DisplayActor_Construct(void* p, int* idx);
float Math_SinThunk(float a);
float Math_CosThunk(float a);
void Mtx44_SetRotation(M4_E10* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
unsigned short Appearance_GetPairCount(void* app);
unsigned short AgentPacking_AddBlankPairs(void* app, unsigned short n);
void Appearance_ReorderParts(Man_E10* m);
int Appearance_GetBodyKind(void* app);
int Appearance_GetToneDigit(void* app);
void cVUM_GOBJ_InitModel(Model_E10* m, char* name);
void cArrayCapacity_ctor(Word_E10* w, int n);
void cArray_cSkeletonBBoxContributionPtr_ctor(SVec_E10* v, Word_E10* w, unsigned char f);
V4_E10* Vec4_Set(V4_E10* v, float x, float y, float z, float w);
void cSkeletonBBoxContribution_ctor(Sph_E10* s, int bone, float r, V4_E10* off);
void cArray_cSkeletonBBoxContributionPtr_PushBackActual(SVec_E10* v, Sph_E10** p);
void cSkeletonBBoxContribution_dtor(Sph_E10* s, int f);
void* cSKM_GOBJ_GetSkeleton_void_2(Model_E10* m);
void FrontEnd_SetNodeSpheres(void* n, SVec_E10* v);
void cArray_cSkeletonBBoxContributionPtr_dtor(SVec_E10* v, int f);
void Model_Attach(void* a, void* b);
void AnimModel_InitAnim(void* a);
void Model_HardMeshAttachPoints(Man_E10* m);
void cMan_GetTextureIDs(Man_E10* m);
void ActorModel_Setup(Man_E10* m, int flag);
void Skel_ApplyScalePreset(Man_E10* m, int a);
int AgentPartCache_FindMesh(void* db, __int128 key);
int AgentPartCache_FindTexture(void* db, __int128 key);
void GuiAgentModify_Refresh(Self_E10* self);
void std_vector_charPtr_ctor_void_2(Aw_E10* a);
void* Agent_GetSelected(void* p, int n);
void AgentData_FilterAwards(void* ag, Aw_E10* a);
void AgentPartCache_Lock(void* db, Aw_E10* a);
void std_vector_charPtr_dtor_void_2(Aw_E10* a, int flags);
Self_E10* GuiAgentModify_ctor(Self_E10* self);
}

static inline void QCopy_E10(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
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
static inline long KeyR_E10(__int128 m, __int128 a, __int128 b) {
    __int128 r, o;
    asm {
        pand r, m, a
        pand b, m, b
        pceqw r, r, b
        ppach o, r, r
    }
    return (long)o;
}
static inline void* Alloc_E10(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004BA0A0, line); }
static inline int Eq5_E10(const char* a, const char* b) {
    int k;
    for (k = 0; k < 5; k++) {
        if (*++a != *++b) return 0;
    }
    return 1;
}

static inline Man_E10* MANP_E10(Model_E10* m) { return &m->man; }
static inline char* APP_E10(Man_E10* m) { return m->app; }
static inline char* NAME_E10(Man_E10* m) { return m->name; }
static inline V4_E10* Splat_E10(V4_E10* t, float) { float z = 0.0f; return Vec4_Set(t, z, z, z, z); }
static inline void Spheres_E10(Model_E10* md)
{
            Word_E10 w;
            {
                SVec_E10 vec;
                Sph_E10 arr[12];
                V4_E10 t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
                int k;
                cArrayCapacity_ctor(&w, 0x15);
                cArray_cSkeletonBBoxContributionPtr_ctor(&vec, &w, 1);
                cSkeletonBBoxContribution_ctor(&arr[0], 0, 0.75f, Splat_E10(&t0, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[1], 4, 0.41666666f, Splat_E10(&t1, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[2], 6, 0.41666666f, Splat_E10(&t2, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[3], 0xC, 0.75f, Splat_E10(&t3, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[4], 0x10, 0.75f, Splat_E10(&t4, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[5], 0xE, 1.0f, Splat_E10(&t5, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[6], 0xD, 0.33333334f, Splat_E10(&t6, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[7], 0xF, 0.33333334f, Splat_E10(&t7, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[8], 0x11, 0.33333334f, Splat_E10(&t8, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[9], 0x12, 0.33333334f, Splat_E10(&t9, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[10], 0x13, 0.6666667f, Splat_E10(&t10, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[11], 0x14, 0.6666667f, Splat_E10(&t11, 0.0f));
                for (k = 0; k < 12; k++) {
                    Sph_E10* sp; Sph_E10** pp = &sp; sp = &arr[k]; cArray_cSkeletonBBoxContributionPtr_PushBackActual(&vec, pp);
                }
                cSkeletonBBoxContribution_dtor(&arr[11], -1);
                cSkeletonBBoxContribution_dtor(&arr[10], -1);
                cSkeletonBBoxContribution_dtor(&arr[9], -1);
                cSkeletonBBoxContribution_dtor(&arr[8], -1);
                cSkeletonBBoxContribution_dtor(&arr[7], -1);
                cSkeletonBBoxContribution_dtor(&arr[6], -1);
                cSkeletonBBoxContribution_dtor(&arr[5], -1);
                cSkeletonBBoxContribution_dtor(&arr[4], -1);
                cSkeletonBBoxContribution_dtor(&arr[3], -1);
                cSkeletonBBoxContribution_dtor(&arr[2], -1);
                cSkeletonBBoxContribution_dtor(&arr[1], -1);
                cSkeletonBBoxContribution_dtor(&arr[0], -1);
                FrontEnd_SetNodeSpheres(cSKM_GOBJ_GetSkeleton_void_2(md), &vec);
                cArray_cSkeletonBBoxContributionPtr_dtor(&vec, -1);
            }
}
static inline void QAsgB_E10(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline char* Buf_E10(Model_E10* m) { return (char*)m + 0x2E50; }
static inline void SetF_E10(Model_E10* md, float v) { md->man.f23F0 = v; }
static inline int& Neg1_E10(int& d) { d = -1; return d; }
static inline int& Ser_E10(H_E10* o, int& d) { return *(o ? &o->serial : &Neg1_E10(d)); }
static inline void SetS_E10(Model_E10* md, short v) { md->man.s2D94 = v; }
static inline void SetB_E10(Model_E10* md, unsigned char v) { md->man.b2C11 = v; }
static inline void G_E10(void* p, int a, int n, int b) { int* pa = &a; cGOBJ_ctor(p, pa, n, &b); }
static inline void Tail_E10(Self_E10* self, V4_E10& v)
{
    int d;
            {
                Spheres_E10(self->model);
            }
            {
                void** an;
                void* a = D_004F77A0;
                an = (void**)((char*)self->model + 0x2EC0);
                Model_Attach(an + 4, a);
                *an = a;
                AnimModel_InitAnim(an);
            }
            {
                SetF_E10(self->model, 1.0f);
                self->model->man.f23F4 = 0.0f;
                Model_HardMeshAttachPoints(&self->model->man);
            }
            {
                Man_E10* m;
                v.x = 0.0f; v.y = 30.0f; v.z = 0.0f; v.w = 1.0f;
                { Model_E10* md = self->model; md->man.f2D70 = 0; m = &md->man; }
                m->f2D74 = Ser_E10(0, d);
                { QAsgB_E10(&m->pos, &v); m->pos.w = 1.0f; }
            }
            { Man_E10* mm = &self->model->man; mm->b2DA0 = 1; }
            cMan_GetTextureIDs(&self->model->man);
            {
                int c;
                Model_E10* m;
                c = 1; m = self->model; m->man.f2BD0 = c;
                ActorModel_Setup(&self->model->man, 1);
            }
            Skel_ApplyScalePreset(&self->model->man, -1);
            {
                SetS_E10(self->model, 0);
                SetB_E10(self->model, 1);
            }
}
extern "C" Self_E10* GuiAgentModify_ctor(Self_E10* p0)
{
    Self_E10* self = p0;
    M4_E10 mtx;
    Aw_E10 a;
    GuiWidget_ctor(p0);
    self->vt = D_004E1220;
    self->f48 = -2;
    self->vt = D_004DE920;
    self->flags |= 0x20;
    self->fEC = -1;
    self->fF0 = 0;
    self->f7C = 0;
    FrontEnd_GetCharacterData(D_004FFC04);
    {
        void* p;
        p = Alloc_E10(0x68, 0x11C);
        if (p) {
            G_E10(p, 0, 9, 0);
            *(char**)p = D_004DA470;
            ((int*)p)[0x60 / 4] = 0;
            ((int*)p)[0x64 / 4] = 0;
            Object_AttachTransform(p, g_IdentityMatrix, 0);
            ((int*)p)[0x30 / 4] = 0;
        }
        self->f90 = p;
    }
    {
        Model_E10* p;
        p = (Model_E10*)Alloc_E10(0x3030, 0x11D);
        if (p) {
            int x[1]; x[0] = 0;
            p = DisplayActor_Construct(p, x);
        }
        self->model = p;
    }
    {
        {
            M4_E10 t;
            float one = 1.0f; float tz = -3.25f;
            t.m[0][0] = one; t.m[0][1] = 0.0f; t.m[0][2] = 0.0f; t.m[0][3] = 0.0f;
            t.m[1][0] = 0.0f; t.m[1][1] = one; t.m[1][2] = 0.0f; t.m[1][3] = 0.0f;
            t.m[2][0] = 0.0f; t.m[2][1] = 0.0f; t.m[2][2] = one; t.m[2][3] = 0.0f;
            t.m[3][0] = 0.0f; t.m[3][1] = 0.0f; t.m[3][2] = tz; t.m[3][3] = one;
            M4Cp_E10((M4Q_E10*)&mtx, (M4Q_E10*)&t);
        }
        float pb = 3.1415927f;
        {
            V4C_E10 r(0.0f, 0.0f, pb);
            QAsg0_E10(&self->fD0, &r);
        }
        self->fF4 = 0;
        self->f108 = 0;
        self->f10D = 0;
        self->f10E = 0;
        self->f10F = 0x10;
        self->f110 = 0;
        {
            MANP_E10(self->model)->f2C04 = Buf_E10(self->model);
            self->model->SetMtx(&mtx);
        }
        {
            Xf_E10* xf = self->model->xf;
            M4_E10 rot;
            float s = Math_SinThunk(0.0f);
            float c = Math_CosThunk(0.0f);
            { M4_E10* pr = &rot; float z = 0.0f; Mtx44_SetRotation(pr, c, -s, z, s, c, z, z, z, 1.0f); }
            { M4_E10* pr = &rot; xf->SetMtx(pr); }
        }
        if (D_00493A60 == -1) D_00493A60 = 0;
        { int n = 0x44; int j = D_00493A60; Model_E10* m = self->model; Man_E10* mn = MANP_E10(m); QCopy_E10(APP_E10(mn), &D_0055D510[j], n); }
        {
            Man_E10* m = &self->model->man;
            m->cnt = Appearance_GetPairCount(m->app);
        }
        {
            Man_E10* m = &self->model->man;
            m->cnt = AgentPacking_AddBlankPairs(m->app, m->cnt);
        }
        Appearance_ReorderParts(&self->model->man);
        self->fF8 = Appearance_GetBodyKind(APP_E10(&self->model->man));
        self->fFC = (signed char)Appearance_GetToneDigit(APP_E10(&self->model->man));
        { Model_E10* m = self->model; m->man.b2C0D = self->fFC; }
        {
            char* nm; if (self->fF8 == 0) nm = D_004BA0B8; else { nm = D_004BA0C8; asm { .set reorder } }
            cVUM_GOBJ_InitModel(self->model, nm);
            String_Copy(NAME_E10(&self->model->man), nm);
        }
        self->model->Init(1);
        { V4_E10 v; Tail_E10(self, v); }
    }
    {
        int n;
        int j;
        const char* str;
        int k;
        for (j = 0; j < 16; j++) {
            n = self->fF8;
            str = D_00492900[n][j];
            for (k = 0; k <= MANP_E10(self->model)->cnt; k++) {
                if (Eq5_E10(str, (char*)&MANP_E10(self->model)->e[k].a)) {
                    D_00492A01[j].slot = k;
                    break;
                }
                if (Eq5_E10(str, (char*)&MANP_E10(self->model)->e[k].b)) {
                    D_00492A01[j].slot = k;
                    break;
                }
            }
            D_00492A02[j].pos = 0;
        }
    }
    {
        __int128 mask;
        { long v = 0xFFFFFFFF00; asm { pcpyld mask, $zero, v } }
        union { __int128 q; char s[16]; } key;
        String_Copy(key.s, D_004B9F80);
        {
            int k;
            for (k = 0; k < self->model->man.cnt; k++) {
                if (KeyR_E10(mask, key.q, MANP_E10(self->model)->e[k].a) == -1) {
                    self->f10C = k;
                    break;
                }
            }
        }
    }
    self->f10D = D_00492A01[self->f10F].slot;
    self->f10E = D_00492A00[self->f10F].mode;
    self->f100 = AgentPartCache_FindMesh(g_AgentPartCache, MANP_E10(self->model)->e[self->f10D].a);
    self->f104 = AgentPartCache_FindTexture(g_AgentPartCache, MANP_E10(self->model)->e[self->f10D].b);
    GuiAgentModify_Refresh(self);
    self->fE0 = 0;
    self->name = D_0056F9B0.name;
    self->fB0 = D_0056F9B0.i;
    self->fB4[0] = D_0056F9B0.f[0];
    self->fB4[1] = D_0056F9B0.f[1];
    self->fB4[2] = D_0056F9B0.f[2];
    self->fB4[3] = D_0056F9B0.f[3];
    self->fB4[4] = D_0056F9B0.f[4];
    self->fB4[5] = D_0056F9B0.f[5];
    self->fB4[6] = D_0056F9B0.f[6];
    {
        Aw_E10* pa = &a;
        std_vector_charPtr_ctor_void_2(pa);
        pa->bC = 1;
        AgentData_FilterAwards(Agent_GetSelected(g_Game, -1), pa);
        AgentPartCache_Lock(g_AgentPartCache, pa);
        std_vector_charPtr_dtor_void_2(pa, -1);
    }
    return self;
}
