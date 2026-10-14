#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "vslot_pad.h"
#pragma inline_depth(10)
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_common_subs on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_1100;
struct M4_1100 { float m[4][4]; } __attribute__((aligned(16)));
struct M4Q_1100 { __int128 r[4]; };
static inline void MK_1100(V4_1100* t0, float x0, float y0, float z0, float w0) { V4_1100* t = t0; float x = x0, y = y0, z = z0, w = w0; t->x = x; t->y = y; t->z = z; t->w = w; }
static inline void MK3_1100(V4_1100* t0, float x0, float y0, float z0) { V4_1100* t = t0; float x = x0, y = y0, z = z0; t->x = x; t->y = y; t->z = z; }
static inline void QAsgB_1100(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void QAsgA_1100(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void M4Cp_1100(M4Q_1100* d0, const M4Q_1100* s0) { M4Q_1100* d = d0; __int128 qa, qb; const M4Q_1100* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct Sph_1100 { char pad[0x20]; };
struct SVec_1100 { char pad[0x10]; };
struct Word_1100 { int w; };
struct H_1100 { char pad[0xC]; int serial; };
struct Blk_1100 { char d[0x440]; };
struct Wpn_1100 { char pad[0x40A]; short id; };
struct WDef_1100 { char pad[0x30]; unsigned char b30; };
struct Tab_1100 { void* p; char pad[0xC]; };

class Xf_1100 {
public:
    VPAD2(a) virtual void SetMtx(M4_1100* m);
};

struct Anim_1100 {
    void* f0;
    char pad4;
    unsigned char b5;
    char pad6[2];
    char v8[0x10];
};

struct Man_1100 {
    char pad0[0x40];
    char app[0x30];
    char name[0x10];
    char pad80[0x23F0 - 0x80];
    float f23F0;
    float f23F4;
    char pad23F8[0x2410 - 0x23F8];
    Wpn_1100* wpn[10];
    char pad2438[0x2BD0 - 0x2438];
    int f2BD0;
    char pad2BD4[0x2C04 - 0x2BD4];
    void* f2C04;
    char pad2C08[0x2C11 - 0x2C08];
    unsigned char b2C11;
    char pad2C12[0x2D70 - 0x2C12];
    H_1100* f2D70;
    int f2D74;
    char pad2D78[8];
    V4_1100 pos;
    char pad2D90[4];
    short s2D94;
    char pad2D96[0xA];
    unsigned char b2DA0;
};

class Model_1100 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetMtx(M4_1100* m);
    VPAD4(d) VPAD2(e) virtual void Init(int a);
    char pad4[0x4C];
    Xf_1100* xf;
    char pad54[0xC];
    Man_1100 man;
};

#define MAN(p) (&(p)->man)
static inline char* APP_1100(Man_1100* m) { return m->app; }
static inline char* NAME_1100(Man_1100* m) { return m->name; }
#define FLD(p, T, o) (*(T*)((char*)(p) + (o)))

struct Self_1100 {
    void* vt;
    char pad4[0x48 - 4];
    Model_1100* plr;
    Model_1100* model;
    void* gobj;
    char pad54[0xC];
    V4_1100 f60;
    V4_1100 f70;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    char pad94[0xA8 - 0x94];
    int fA8;
    float fAC[7];
    char padC8[8];
    int fD0;
    int fD4;
    int fD8;
    short fDC[10];
    unsigned char fF0[12];
    int fFC;
    int f100;
    int f104;
    int f108;
    char pad10C[0x90C - 0x10C];
    short f90C[10];
    int f920;
    char pad924[0x958 - 0x924];
    int f958;
};

struct Arr7_1100 { char d[0x38]; };
struct Y_1100 { char d[0x10]; };
struct Sel_1100 { char b0; char pad[3]; Arr7_1100 arr; Y_1100 y; };
struct Str_1100 { char s[0x30]; };
struct Req_1100 {
    char b0;
    char pad1[0xF];
    char mr[0x38];
    char b48;
    char pad49[3];
    Sel_1100 sel;
    float f98;
    int f9C;
};
struct It_1100 { int w; };
struct Ev_1100 { char d[0x40]; };
struct Rate_1100 { char d[0x10]; };

extern "C" {
extern char D_004DDEE0[];
extern char D_004DA470[];
extern int D_0055DE94;
extern Tab_1100 D_0055DE98[];
extern unsigned char D_005721C8;
extern signed char D_00493A60;
extern char D_004AC5C0[];
extern char D_004AC5D8[];
extern char D_004AC5E8[];
extern char D_004AC288[];
extern char D_004AC298[];
extern char D_004AC600[];
extern char D_004FFBC0[];
extern char D_0055C9F0[];
extern Blk_1100 D_0055D510[];
extern void* D_00506500;
extern void* D_004FFD30;
void GuiWidget_ctor(Self_1100* self);
void* Mem_Alloc(int pool, int size, char* file, int line);
void cGOBJ_ctor(void* p, int* a, int b, int* c);
void Object_AttachTransform(void* p, void* t, int a);
Model_1100* func_00393FF0(void* p, int* idx);
float Math_SinThunk(float a);
float Math_CosThunk(float a);
void Mtx44_SetRotation(M4_1100* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
Model_1100* PlayerSlots_Get(void* a);
WDef_1100* WeaponDb_Get(void* db, int id);
int Appearance_GetBodyKind(void* app);
void func_00391020(Man_1100* m, void* p);
void Skel_Rebind(Model_1100* m, Man_1100* src);
void Appearance_ReorderParts(Man_1100* m);
void cVUM_GOBJ_InitModel(Model_1100* m, char* name);
void String_Copy(char* d, const char* s);
void func_00290BB0(Word_1100* w, int n);
void func_00290A50(SVec_1100* v, Word_1100* w, unsigned char f);
V4_1100* func_00132000(V4_1100* v, float x, float y, float z, float w);
void func_002909C0(Sph_1100* s, int bone, float r, V4_1100* off);
void func_002909A0(SVec_1100* v, Sph_1100** p);
void func_001B06F0(Sph_1100* s, int f);
void* func_00290990(Model_1100* m);
void FrontEnd_SetNodeSpheres(void* n, SVec_1100* v);
void func_001AF880(SVec_1100* v, int f);
void func_001AF160(It_1100* it, void* tab, char* key);
void func_001AF150(It_1100* it, void* tab);
int func_001AF130(It_1100* a, It_1100* b);
void** func_001AF120(It_1100* it);
void Model_Attach(void* a, void* b);
void AnimModel_InitAnim(void* a);
void func_0018A910(Arr7_1100* a);
void func_0018A8C0(Y_1100* y);
void MotionRequest_Construct(void* mr, Str_1100* s);
void func_0018A710(Sel_1100* d, Sel_1100* s);
void func_001BE5A0(Y_1100* y, int f);
void __destroy_array(void* a, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void func_0018A700(Word_1100* w, int a);
void Actor_ResolveMotionSelection(Req_1100* r, int* sel, Word_1100* w, void* m);
float Model_GetFirstFloat(void* m);
V4_1100* AnimRate_Init(Rate_1100* r, float f);
}
static inline V4_1100* Splat_1100(V4_1100* t, float) { float z = 0.0f; return func_00132000(t, z, z, z, z); }
extern "C" {
void Vec4_Copy_18A350(Rate_1100* d, V4_1100* s);
void AnimEvent_Construct(Ev_1100* e);
int func_0018A2F0(Req_1100* r);
int func_0018A2E0(Req_1100* r);
float func_0018A2D0(Req_1100* r);
float func_0018A2C0(Req_1100* r);
void AnimCtl_InstallMotion(Anim_1100* a, int sel, int b, Rate_1100* r, Word_1100* w, Ev_1100* e0, Ev_1100* e1, int c, float f0, float f1);
void func_0018A260(Ev_1100* e, int f);
void Model_HardMeshAttachPoints(Man_1100* m);
void func_0038E030(Man_1100* m);
void ActorModel_Setup(Man_1100* m, int flag);
void Skel_ApplyScalePreset(Man_1100* m, int a);
Self_1100* func_002C1100(Self_1100* self);
}

static inline void QCopy_1100(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
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
static inline void G_1100(void* p, int a, int n, int b) { int* pa = &a; cGOBJ_ctor(p, pa, n, &b); }
static inline Model_1100* M_1100(void* p, int x) { return func_00393FF0(p, &x); }
struct V4C_1100 { float x, y, z, w; V4C_1100(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } V4C_1100(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
static inline void MKd_1100(V4_1100* t, float x, float y, float z, float w) { t->x = x; t->y = y; t->z = z; t->w = w; }
static inline void MKd3_1100(V4_1100* t, float x, float y, float z) { t->x = x; t->y = y; t->z = z; }
static inline void Q3_1100(void* a0, const void* b0, void* c0, float z) { void* d1 = a0; const void* s1 = b0; void* d2 = c0; __int128 q = 0; q = *(const __int128*)s1; *(__int128*)d1 = q; { V4C_1100 r(0.0f, 0.0f, z); const void* s2 = &r; q = *(const __int128*)s2; *(__int128*)d2 = q; } }
static inline Man_1100* ManA_1100(Model_1100* md) { return &md->man; }
static inline Wpn_1100* GetW_1100(Man_1100* m, int o) { return *(Wpn_1100**)((char*)m->wpn + o); }
struct V4R_1100 { float x, y, z, w; V4R_1100(const float& a, const float& b, const float& c, const float& d) { x = a; y = b; z = c; w = d; } V4R_1100(const float& a, const float& b, const float& c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
static inline void* Alloc_1100(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004AC5C0, line); }

static inline void SelInit_1100(Sel_1100* s0) { Sel_1100* s = s0; s->b0 = 0; func_0018A910(&s->arr); func_0018A8C0(&s->y); }
static inline void ReqInit2_1100(Req_1100* r0, Str_1100* str0, Sel_1100* sel) { Str_1100* str = str0; Req_1100* r = r0; r->b0 = 0; MotionRequest_Construct(r->mr, str); r->b48 = 3; func_0018A710(&r->sel, sel); r->f98 = -1.0f; r->f9C = 0; }
static inline void Spheres_1100(Model_1100* md)
{
            Word_1100 w;
            {
            SVec_1100 vec;
            Sph_1100 arr[12];
            V4_1100 t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
            int k;
            func_00290BB0(&w, 0x15);
            func_00290A50(&vec, &w, 1);
            func_002909C0(&arr[0], 0, 0.75f, Splat_1100(&t0, 0.0f));
            func_002909C0(&arr[1], 4, 0.41666666f, Splat_1100(&t1, 0.0f));
            func_002909C0(&arr[2], 6, 0.41666666f, Splat_1100(&t2, 0.0f));
            func_002909C0(&arr[3], 0xC, 0.75f, Splat_1100(&t3, 0.0f));
            func_002909C0(&arr[4], 0x10, 0.75f, Splat_1100(&t4, 0.0f));
            func_002909C0(&arr[5], 0xE, 1.0f, Splat_1100(&t5, 0.0f));
            func_002909C0(&arr[6], 0xD, 0.33333334f, Splat_1100(&t6, 0.0f));
            func_002909C0(&arr[7], 0xF, 0.33333334f, Splat_1100(&t7, 0.0f));
            func_002909C0(&arr[8], 0x11, 0.33333334f, Splat_1100(&t8, 0.0f));
            func_002909C0(&arr[9], 0x12, 0.33333334f, Splat_1100(&t9, 0.0f));
            func_002909C0(&arr[10], 0x13, 0.6666667f, Splat_1100(&t10, 0.0f));
            func_002909C0(&arr[11], 0x14, 0.6666667f, Splat_1100(&t11, 0.0f));
            for (k = 0; k < 12; k++) {
Sph_1100* sp; Sph_1100** pp = &sp; sp = &arr[k]; func_002909A0(&vec, pp);
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
static inline void Install_1100(Anim_1100* an, int* selp, Req_1100* rq, Word_1100* wp)
{
                Rate_1100 rate;
                Rate_1100 tmp;
                Ev_1100 e0;
                Ev_1100 e1;
                V4_1100* v;
                if (an->b5) v = (V4_1100*)an->v8;
                else { v = AnimRate_Init(&tmp, Model_GetFirstFloat(an->f0)); asm { .set reorder } }
                Vec4_Copy_18A350(&rate, v);
                an->b5 = 0;
                AnimEvent_Construct(&e0);
                AnimEvent_Construct(&e1);
                AnimCtl_InstallMotion(an, *selp, func_0018A2F0(rq), &rate, wp, &e0, &e1, func_0018A2E0(rq), func_0018A2D0(rq), func_0018A2C0(rq));
                func_0018A260(&e1, -1);
                func_0018A260(&e0, -1);
}
static inline void FindAnim_1100(Self_1100* self, int kind)
{
            It_1100 it;
            It_1100 end;
            void* a;
            char* nm;
            if (kind == 1) nm = D_004AC298; else { nm = D_004AC288; asm { .set reorder } }
            func_001AF160(&it, D_004FFBC0, nm);
            func_001AF150(&end, D_004FFBC0);
            if (func_001AF130(&it, &end)) a = *func_001AF120(&it);
            else { a = 0; asm { .set reorder } }
            {
                void** an = (void**)((char*)self->model + 0x2EC0);
                Model_Attach(an + 4, a);
                *an = a;
                AnimModel_InitAnim(an);
            }
        }

static inline void Motion_1100(Model_1100* md, Req_1100* rq)
{
            char* c = (char*)md + 0x2EC0;
            Anim_1100* an = (Anim_1100*)(c + 0x34);
            int sel;
            Word_1100 w[3];
            func_0018A700(w, -1);
            Actor_ResolveMotionSelection(rq, &sel, w, an->f0);
            if (sel) {
                Install_1100(an, &sel, rq, w);
            }
        }

static inline void SetF_1100(Model_1100* md, float v) { FLD(md, float, 0x2450) = v; }
static inline int& Neg1_1100(int& d) { d = -1; return d; }
static inline int& Ser_1100(H_1100* o, int& d) { return *(o ? &o->serial : &Neg1_1100(d)); }
static inline void F_1100(Self_1100* self, M4_1100* mtx, Req_1100* req)
{
    int kind;
        {
            Model_1100* m = self->model;
            m->man.f2C04 = (char*)m + 0x2E50;
        }
        self->model->SetMtx(mtx);
        {
            Xf_1100* xf = self->model->xf;
            M4_1100 rot;
            float s = Math_SinThunk(0.0f);
            float c = Math_CosThunk(0.0f);
            { M4_1100* pr = &rot; float z = 0.0f; Mtx44_SetRotation(pr, c, -s, z, s, c, z, z, z, 1.0f); }
            { M4_1100* pr = &rot; xf->SetMtx(pr); }
        }
        self->fFC = 0;
        self->plr = PlayerSlots_Get(D_00506500);
        Model_1100* pl;
        if ((pl = self->plr) != 0) {
            Wpn_1100* w = pl->man.wpn[0];
            if (w) {
                int n = WeaponDb_Get(D_004FFD30, w->id)->b30;
                if (n > 0 && n < 10) self->fFC = n;
            }
            if (!D_005721C8 && D_0055DE94) {
                void* a = D_0055DE98[Appearance_GetBodyKind(APP_1100(MAN(self->plr)))].p;
                if (a) func_00391020(MAN(self->plr), a);
            }
            Skel_Rebind(self->model, MAN(self->plr));
        } else {
            { int n = 0x44; int i = D_00493A60; Model_1100* m = self->model; QCopy_1100(APP_1100(MAN(m)), &D_0055D510[i], n); }
            if (!D_005721C8 && D_0055DE94) {
                void* a = D_0055DE98[Appearance_GetBodyKind(APP_1100(MAN(self->model)))].p;
                if (a) func_00391020(MAN(self->model), a);
            }
        }
        self->f100 = self->fFC;
        Appearance_ReorderParts(MAN(self->model));
        kind = Appearance_GetBodyKind(APP_1100(MAN(self->model)));
        {
            char* nm; if (kind == 0) nm = D_004AC5D8; else { nm = D_004AC5E8; asm { .set reorder } }
            cVUM_GOBJ_InitModel(self->model, nm);
            String_Copy(NAME_1100(MAN(self->model)), nm);
        }
        self->model->Init(1);
        {
            Spheres_1100(self->model);
        }
        FindAnim_1100(self, kind);
        {
            Str_1100 str;
            Sel_1100 sel;
            SelInit_1100(&sel);
            {
                bool done;
                int k;
                char c;
                const char* src;
                done = false;
                k = 0;
                src = D_004AC600;
                for (; k < 0x2F; k++) {
                    if (!src[k]) done = true;
                    c = 0; if (done) asm { .set reorder } else c = src[k];
                    str.s[k] = c;
                }
                str.s[k] = 0;
            }
            ReqInit2_1100(req, &str, &sel);
            func_001BE5A0(&sel.y, 0);
            __destroy_array(&sel.arr, (void*)func_0018A210, 8, 7);
        }
        Motion_1100(self->model, req);
        {
            Y_1100* y = &req->sel.y;
            if (y) { if (y) { if (y) func_001BE5A0(y, 0); } }
        }
        {
            Arr7_1100* a = &req->sel.arr;
            if (a) __destroy_array(a, (void*)func_0018A210, 8, 7);
        }
    SetF_1100(self->model, 1.0f);
    FLD(self->model, float, 0x2454) = 0.0f;
    Model_HardMeshAttachPoints(MAN(self->model));
    {
        V4_1100 v;
        Man_1100* m;
        v.x = 0.0f; v.y = 30.0f; v.z = 0.0f; v.w = 1.0f;
        { Model_1100* md = self->model; FLD(md, H_1100*, 0x2DD0) = 0; m = MAN(md); }
        {
            int d;
            H_1100* o = 0;
            FLD(m, int, 0x2D74) = Ser_1100(0, d);
        }
        { QAsgB_1100(&FLD(m, V4_1100, 0x2D80), &v); FLD(m, float, 0x2D8C) = 1.0f; }
    }
    { Man_1100* mm = MAN(self->model); FLD(mm, unsigned char, 0x2DA0) = 1; }
}

static inline void SetI_1100(Model_1100* md, int v) { FLD(md, int, 0x2C30) = v; }
static inline void SetS_1100(Model_1100* md, short v) { FLD(md, short, 0x2DF4) = v; }
static inline void SetB_1100(Model_1100* md, unsigned char v) { FLD(md, unsigned char, 0x2C71) = v; }
extern "C" Self_1100* func_002C1100(Self_1100* p0)
{
    Self_1100* self = p0;
    int i;
    int x;
    GuiWidget_ctor(p0);
    self->vt = D_004DDEE0;
    self->f84 = -1;
    self->f90 = 0;
    self->f88 = 2;
    self->f80 = D_0055DE94;
    {
        void* p;
        p = Alloc_1100(0x68, 0xC6);
        if (p) {
            G_1100(p, 0, 9, 0);
            *(char**)p = D_004DA470;
            ((int*)p)[0x60 / 4] = 0;
            ((int*)p)[0x64 / 4] = 0;
            Object_AttachTransform(p, D_0055C9F0, 0);
            ((int*)p)[0x30 / 4] = 0;
        }
        self->gobj = p;
    }
    {
        M4_1100 mtx;
        Req_1100 req;
        {
            M4_1100 t;
            float one = 1.0f; float tz = -3.25f;
            t.m[0][0] = one; t.m[0][1] = 0.0f; t.m[0][2] = 0.0f; t.m[0][3] = 0.0f;
            t.m[1][0] = 0.0f; t.m[1][1] = one; t.m[1][2] = 0.0f; t.m[1][3] = 0.0f;
            t.m[2][0] = 0.0f; t.m[2][1] = 0.0f; t.m[2][2] = one; t.m[2][3] = 0.0f;
            t.m[3][0] = 0.0f; t.m[3][1] = 0.0f; t.m[3][2] = tz; t.m[3][3] = one;
            M4Cp_1100((M4Q_1100*)&mtx, (M4Q_1100*)&t);
        }
        float pa = 3.1415927f; float pb = 3.1415927f;
        {
            V4C_1100 r1(0.0f, 0.0f, pa, 0.0f);
            Q3_1100(&self->f60, &r1, &self->f70, pb);
        }
        {
            Model_1100* p;
            p = (Model_1100*)Alloc_1100(0x3030, 0xCD);
            if (p) {
                x = 0;
                p = func_00393FF0(p, &x);
            }
            self->model = p;
        }
        F_1100(self, &mtx, &req);
    func_0038E030(MAN(self->model));
    SetI_1100(self->model, 1);
    ActorModel_Setup(MAN(self->model), 1);
    Skel_ApplyScalePreset(MAN(self->model), -1);
    SetS_1100(self->model, 0);
    SetB_1100(self->model, 1);
    self->fD8 = 0;
    for (i = 0; i < 10; i++) {
        int o;
        Wpn_1100* w;
        o = i * 4;
        w = GetW_1100(ManA_1100(self->model), o);
        if (w) {
            self->fDC[self->fD8] = w->id;
            self->fF0[self->fD8] = WeaponDb_Get(D_004FFD30, GetW_1100(ManA_1100(self->model), o)->id)->b30;
            self->fD8++;
        }
    }
    self->fD0 = 0;
    self->fD4 = 0;
    self->f104 = 0;
    self->f108 = 0;
    self->f8C = 0;
    { int j; for (j = 0; j < 10; j++) self->f90C[j] = 0; }
    {
    float pi = 3.1415927f;
    self->fAC[0] = pi;
    self->fAC[1] = 6.2831855f;
    self->fAC[2] = 4.712389f;
    self->fAC[3] = pi;
    self->fAC[4] = pi;
    self->fAC[5] = pi;
    self->fAC[6] = pi;
    }
    self->f920 = 0;
    self->fA8 = 0xC;
    self->f958 = 0;
    }
    return self;
}
