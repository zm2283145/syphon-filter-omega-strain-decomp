#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"

#pragma cplusplus on
#pragma inline_depth(10)
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_common_subs on

/* GuiAgentDisplay_Wake: (re)builds the front-end agent model of the agent display widget:
 * camera and turntable matrices, appearance copied from the widget's block, body model,
 * collision spheres, idle animation, and the default display parameters.
 * Same model set-up as GuiAgentModify_ctor (GuiAgentModify/GuiAgentModify_ctor.c). */

struct V4_A1 { float x, y, z, w; };
struct M4_A1 { float m[4][4]; } __attribute__((aligned(16)));
struct M4Q_A1 { __int128 r[4]; };
static inline void M4Cp_A1(M4Q_A1* d0, const M4Q_A1* s0) { M4Q_A1* d = d0; __int128 qa, qb; const M4Q_A1* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct Ent_A1 { __int128 a; __int128 b; };
struct Name_A1 { char s[16]; };
struct Sph_A1 { char pad[0x20]; };
struct SVec_A1 { char pad[0x10]; };
struct Word_A1 { int w; };
struct H_A1 { char pad[0xC]; int serial; };

class Xf_A1 {
public:
    VPAD2(a) virtual void SetMtx(M4_A1* m);
};

struct Man_A1 {
    char pad0[0x40];
    char app[0x30];
    char name[0x10];
    Ent_A1 e[(0x23C0 - 0x80) / 0x20];
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
    H_A1* f2D70;
    int f2D74;
    char pad2D78[8];
    V4_A1 pos;
    char pad2D90[4];
    short s2D94;
    char pad2D96[0xA];
    unsigned char b2DA0;
};

class Model_A1 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetMtx(M4_A1* m);
    VPAD4(d) VPAD2(e) virtual void Init(int a);
    char pad4[0x4C];
    Xf_A1* xf;
    char pad54[0xC];
    Man_A1 man;
};

struct Blk_A1 { char d[0x440]; };
struct GDef_A1 { Name_A1 name; int i; float f[7]; };

struct Self_A1 {
    void* vt;
    char pad4[0x48 - 0x4];
    Model_A1* model;
    char pad4C[0x50 - 0x4C];
    Name_A1 name;
    int i60;
    float f64[7];
    char pad80[0xA0 - 0x80];
    Blk_A1 app;
    float speed;
};

extern "C" {
extern char D_004BBA00[];
extern char D_004BBA10[];
extern void* D_004F77A0;
extern GDef_A1 D_0056F9B0;
void GuiWidget_Init(Self_A1* self);
float Math_SinThunk(float a);
float Math_CosThunk(float a);
void Mtx44_SetRotation(M4_A1* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
unsigned short Appearance_GetPairCount(void* app);
unsigned short AgentPacking_AddBlankPairs(void* app, unsigned short n);
void Appearance_ReorderParts(Man_A1* m);
int Appearance_GetBodyKind(void* app);
void cVUM_GOBJ_InitModel(Model_A1* m, char* name);
void String_Copy(char* d, const char* s);
void cArrayCapacity_ctor(Word_A1* w, int n);
void cArray_cSkeletonBBoxContributionPtr_ctor(SVec_A1* v, Word_A1* w, unsigned char f);
V4_A1* Vec4_Set(V4_A1* v, float x, float y, float z, float w);
void cSkeletonBBoxContribution_ctor(Sph_A1* s, int bone, float r, V4_A1* off);
void cArray_cSkeletonBBoxContributionPtr_PushBackActual(SVec_A1* v, Sph_A1** p);
void cSkeletonBBoxContribution_dtor(Sph_A1* s, int f);
void* cSKM_GOBJ_GetSkeleton_void_2(Model_A1* m);
void FrontEnd_SetNodeSpheres(void* n, SVec_A1* v);
void cArray_cSkeletonBBoxContributionPtr_dtor(SVec_A1* v, int f);
void Model_Attach(void* a, void* b);
void AnimModel_InitAnim(void* a);
void Model_HardMeshAttachPoints(Man_A1* m);
void cMan_GetTextureIDs(Man_A1* m);
void ActorModel_Setup(Man_A1* m, int flag);
void Skel_ApplyScalePreset(Man_A1* m, int a);
void GuiAgentDisplay_Wake(Self_A1* self);
}

/* quadword block copy (addi loop counter, hand-scheduled delay slot): not expressible in C */
static inline void QCopy_A1(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
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

static inline Man_A1* MANP_A1(Model_A1* m) { return &m->man; }
static inline char* APP_A1(Man_A1* m) { return m->app; }
static inline char* NAME_A1(Man_A1* m) { return m->name; }
static inline V4_A1* Splat_A1(V4_A1* t, float) { float z = 0.0f; return Vec4_Set(t, z, z, z, z); }
static inline void Spheres_A1(Model_A1* md)
{
            Word_A1 w;
            {
                SVec_A1 vec;
                Sph_A1 arr[12];
                V4_A1 t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
                int k;
                cArrayCapacity_ctor(&w, 0x15);
                cArray_cSkeletonBBoxContributionPtr_ctor(&vec, &w, 1);
                cSkeletonBBoxContribution_ctor(&arr[0], 0, 0.75f, Splat_A1(&t0, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[1], 4, 0.41666666f, Splat_A1(&t1, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[2], 6, 0.41666666f, Splat_A1(&t2, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[3], 0xC, 0.75f, Splat_A1(&t3, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[4], 0x10, 0.75f, Splat_A1(&t4, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[5], 0xE, 1.0f, Splat_A1(&t5, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[6], 0xD, 0.33333334f, Splat_A1(&t6, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[7], 0xF, 0.33333334f, Splat_A1(&t7, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[8], 0x11, 0.33333334f, Splat_A1(&t8, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[9], 0x12, 0.33333334f, Splat_A1(&t9, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[10], 0x13, 0.6666667f, Splat_A1(&t10, 0.0f));
                cSkeletonBBoxContribution_ctor(&arr[11], 0x14, 0.6666667f, Splat_A1(&t11, 0.0f));
                for (k = 0; k < 12; k++) {
                    Sph_A1* sp; Sph_A1** pp = &sp; sp = &arr[k]; cArray_cSkeletonBBoxContributionPtr_PushBackActual(&vec, pp);
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
static inline void QAsgB_A1(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline char* Buf_A1(Model_A1* m) { return (char*)m + 0x2E50; }
static inline void SetF_A1(Model_A1* md, float v) { md->man.f23F0 = v; }
static inline int& Neg1_A1(int& d) { d = -1; return d; }
static inline int& Ser_A1(H_A1* o, int& d) { return *(o ? &o->serial : &Neg1_A1(d)); }
static inline void SetS_A1(Model_A1* md, short v) { md->man.s2D94 = v; }
static inline void SetB_A1(Model_A1* md, unsigned char v) { md->man.b2C11 = v; }
static inline void Tail_A1(Self_A1* self, V4_A1& v)
{
    int d;
            {
                Spheres_A1(self->model);
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
                SetF_A1(self->model, 1.0f);
                self->model->man.f23F4 = 0.0f;
                Model_HardMeshAttachPoints(&self->model->man);
            }
            {
                Man_A1* m;
                v.x = 0.0f; v.y = 30.0f; v.z = 0.0f; v.w = 1.0f;
                { Model_A1* md = self->model; md->man.f2D70 = 0; m = &md->man; }
                m->f2D74 = Ser_A1(0, d);
                { QAsgB_A1(&m->pos, &v); m->pos.w = 1.0f; }
            }
            { Man_A1* mm = &self->model->man; mm->b2DA0 = 1; }
            cMan_GetTextureIDs(&self->model->man);
            {
                int c;
                Model_A1* m;
                c = 1; m = self->model; m->man.f2BD0 = c;
                ActorModel_Setup(&self->model->man, 1);
            }
            Skel_ApplyScalePreset(&self->model->man, -1);
            {
                SetS_A1(self->model, 0);
                SetB_A1(self->model, 1);
            }
}
extern "C" void GuiAgentDisplay_Wake(Self_A1* self)
{
    M4_A1 mtx;
    GuiWidget_Init(self);
    self->speed = 0.0f;
    {
        MANP_A1(self->model)->f2C04 = Buf_A1(self->model);
        {
            M4_A1 t;
            float one = 1.0f; float tz = -3.25f;
            t.m[0][0] = one; t.m[0][1] = 0.0f; t.m[0][2] = 0.0f; t.m[0][3] = 0.0f;
            t.m[1][0] = 0.0f; t.m[1][1] = one; t.m[1][2] = 0.0f; t.m[1][3] = 0.0f;
            t.m[2][0] = 0.0f; t.m[2][1] = 0.0f; t.m[2][2] = one; t.m[2][3] = 0.0f;
            t.m[3][0] = 0.0f; t.m[3][1] = 0.0f; t.m[3][2] = tz; t.m[3][3] = one;
            M4Cp_A1((M4Q_A1*)&mtx, (M4Q_A1*)&t);
        }
        self->model->SetMtx(&mtx);
    }
    {
        Xf_A1* xf = self->model->xf;
        M4_A1 rot;
        float s = Math_SinThunk(0.0f);
        float c = Math_CosThunk(0.0f);
        { M4_A1* pr = &rot; float z = 0.0f; Mtx44_SetRotation(pr, c, -s, z, s, c, z, z, z, 1.0f); }
        { M4_A1* pr = &rot; xf->SetMtx(pr); }
    }
    QCopy_A1(APP_A1(MANP_A1(self->model)), &self->app, 0x44);
    {
        Man_A1* m = &self->model->man;
        m->cnt = Appearance_GetPairCount(m->app);
    }
    {
        Man_A1* m = &self->model->man;
        m->cnt = AgentPacking_AddBlankPairs(m->app, m->cnt);
    }
    Appearance_ReorderParts(&self->model->man);
    {
        char* nm; if (Appearance_GetBodyKind(APP_A1(&self->model->man)) == 0) nm = D_004BBA00; else { nm = D_004BBA10; asm { .set reorder } }
        cVUM_GOBJ_InitModel(self->model, nm);
        String_Copy(NAME_A1(&self->model->man), nm);
    }
    self->model->Init(1);
    { V4_A1 v; Tail_A1(self, v); }
    self->name = D_0056F9B0.name;
    self->i60 = D_0056F9B0.i;
    self->f64[0] = D_0056F9B0.f[0];
    self->f64[1] = D_0056F9B0.f[1];
    self->f64[2] = D_0056F9B0.f[2];
    self->f64[3] = D_0056F9B0.f[3];
    self->f64[4] = D_0056F9B0.f[4];
    self->f64[5] = D_0056F9B0.f[5];
    self->f64[6] = D_0056F9B0.f[6];
    self->f64[1] = 0.75f;
    self->f64[2] = 11.5f;
    self->f64[3] = 0.3f;
}
