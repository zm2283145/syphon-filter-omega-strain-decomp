/* Empty 'asm { .set reorder }' blocks below are scheduling barriers only (emit no instructions). */
#pragma cplusplus on
#include "SFOLobby_helpers.h"
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

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_D430;
struct V4E_D430 { float x, y, z, w; V4E_D430() {} } __attribute__((aligned(16)));
struct M4_D430 { float m[4][4]; } __attribute__((aligned(16)));
struct M4Q_D430 { __int128 r[4]; };
static inline void QAsgB_D430(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void M4Cp_D430(M4Q_D430* d0, const M4Q_D430* s0) { M4Q_D430* d = d0; __int128 qa, qb; const M4Q_D430* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct Word_D430 { int w; };
struct H_D430 { char pad[0xC]; int serial; };
struct Blk_D430 { char d[0x440]; };

class Xf_D430 {
public:
    VPAD2(a) virtual void SetMtx(M4_D430* m);
};

struct Anim_D430 {
    void* f0;
    char pad4;
    unsigned char b5;
    char pad6[2];
    char v8[0x10];
};

struct Man_D430 {
    char pad0[0x40];
    char app[0x30];
    char name[0x10];
};

class Model_D430 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetMtx(M4_D430* m);
    VPAD4(d) VPAD2(e) virtual void Init(int a);
    char pad4[0x4C];
    Xf_D430* xf;
    char pad54[0xC];
    Man_D430 man;
};

#define MAN(p) (&(p)->man)
static inline char* APP_D430(Man_D430* m) { return m->app; }
static inline char* NAME_D430(Man_D430* m) { return m->name; }
#define FLD(p, T, o) (*(T*)((char*)(p) + (o)))

struct Self_D430 {
    void* vt;
    char pad4[0x60 - 4];
    unsigned char b60;
    char pad61[0x1A4 - 0x61];
    Model_D430* models[4];
    void* gobj;
    char pad1B8[0x1C0 - 0x1B8];
    V4_D430 f1C0;
    V4_D430 f1D0;
    V4E_D430 pos[4];
    unsigned char b220[4];
    int f224;
    int f228;
    unsigned char b22C;
};

struct Arr7_D430 { char d[0x38]; };
struct Y_D430 { char d[0x10]; };
struct Sel_D430 { char b0; char pad[3]; Arr7_D430 arr; Y_D430 y; };
struct Str_D430 { char s[0x30]; };
struct Req_D430 {
    char b0;
    char pad1[0xF];
    char mr[0x38];
    char b48;
    char pad49[3];
    Sel_D430 sel;
    float f98;
    float f9C;
};
struct It_D430 { int w; };
struct Ev_D430 { char d[0x40]; };
struct Rate_D430 { char d[0x10]; };

extern "C" {
extern char D_004DA470[];
extern char D_004DF140[];
extern signed char D_00493A60;
extern char D_004BB600[];
extern char D_004BB618[];
extern char D_004BB628[];
extern char D_004BB4B8[];
extern char D_004BB4C8[];
extern char D_004BB640[];
extern char D_004FFBC0[];
extern char g_IdentityMatrix[];
extern Blk_D430 D_0055D510[];
extern V4_D430 D_00492EA0;
extern unsigned char g_GameState;
extern void* D_004FFC04;
extern void* D_004F77A0;
extern unsigned char g_IsMultiplayer;
void FrontEnd_GetCharacterData(void* p);
void GuiWidget_ctor(Self_D430* self);
void* Mem_Alloc(int pool, int size, char* file, int line);
void cGOBJ_ctor(void* p, int* a, int b, int* c);
void Object_AttachTransform(void* p, void* t, int a);
Model_D430* DisplayActor_Construct(void* p, int* idx);
float Math_SinThunk(float a);
float Math_CosThunk(float a);
void Mtx44_SetRotation(M4_D430* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
int Appearance_GetBodyKind(void* app);
void Appearance_ReorderParts(Man_D430* m);
void cVUM_GOBJ_InitModel(Model_D430* m, char* name);
void func_001AF160(It_D430* it, void* tab, char* key);
void func_001AF150(It_D430* it, void* tab);
int func_001AF130(It_D430* a, It_D430* b);
void** func_001AF120(It_D430* it);
void Model_Attach(void* a, void* b);
void AnimModel_InitAnim(void* a);
void MotionTokens_Init(Arr7_D430* a);
void func_0018A8C0(Y_D430* y);
void MotionRequest_Construct(void* mr, Str_D430* s);
void func_0018A710(Sel_D430* d, Sel_D430* s);
void func_001BE5A0(Y_D430* y, int f);
void __destroy_array(void* a, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void func_0018A700(Word_D430* w, int a);
void Actor_ResolveMotionSelection(Req_D430* r, int* sel, Word_D430* w, void* m);
float Model_GetFirstFloat(void* m);
V4_D430* AnimRate_Init(Rate_D430* r, float f);
void Vec4_Copy_18A350(Rate_D430* d, V4_D430* s);
void AnimEvent_Construct(Ev_D430* e);
int MotionRequest_GetMode(Req_D430* r);
int func_0018A2E0(Req_D430* r);
float func_0018A2D0(Req_D430* r);
float func_0018A2C0(Req_D430* r);
void AnimCtl_InstallMotion(Anim_D430* a, int sel, int b, Rate_D430* r, Word_D430* w, Ev_D430* e0, Ev_D430* e1, int c, float f0, float f1);
void AnimEvent_dtor(Ev_D430* e, int f);
void Model_HardMeshAttachPoints(Man_D430* m);
void func_0038E030(Man_D430* m);
void ActorModel_Setup(Man_D430* m, int flag);
void Skel_ApplyScalePreset(Man_D430* m, int a);
Self_D430* GuiScoresEquip_BuildActor(Self_D430* self);
}

static inline void QCopy_D430(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
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
static inline float Max_D430(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline float Min_D430(float a, float b) { float r; asm { min.s r, a, b } return r; }
static inline void G_D430(void* p, int a, int n, int b) { int* pa = &a; cGOBJ_ctor(p, pa, n, &b); }
struct V4C_D430 { float x, y, z, w; V4C_D430() {} V4C_D430(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } V4C_D430(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
static inline void Q3_D430(void* a0, const void* b0, void* c0, float z) { void* d1 = a0; const void* s1 = b0; void* d2 = c0; __int128 q = 0; q = *(const __int128*)s1; *(__int128*)d1 = q; { V4C_D430 r(0.0f, 0.0f, z); const void* s2 = &r; q = *(const __int128*)s2; *(__int128*)d2 = q; } }
static inline void Q3B_D430(void* a0, const void* b0, void* c0, const void* e0) { void* d1 = a0; const void* s1 = b0; void* d2 = c0; __int128 q = 0; q = *(const __int128*)s1; *(__int128*)d1 = q; { const void* s2 = e0; q = *(const __int128*)s2; *(__int128*)d2 = q; } }
static inline void Q3C_D430(void* a0, const void* b0, void* c0, V4C_D430* e0, float z) { void* d1 = a0; const void* s1 = b0; void* d2 = c0; __int128 q = 0; q = *(const __int128*)s1; *(__int128*)d1 = q; { V4C_D430* rr = e0; rr->x = 0.0f; rr->y = 0.0f; rr->z = z; { const void* s2 = rr; q = *(const __int128*)s2; *(__int128*)d2 = q; } } } static inline void Q3D_D430(void* a0, const void* b0, void* c0, V4C_D430& rr, float z) { void* d1 = a0; const void* s1 = b0; void* d2 = c0; __int128 q = 0; q = *(const __int128*)s1; *(__int128*)d1 = q; { rr.x = 0.0f; rr.y = 0.0f; rr.z = z; { const void* s2 = &rr; q = *(const __int128*)s2; *(__int128*)d2 = q; } } } static inline void* Alloc_D430(int n, int line) { AllocGuard g; return Mem_Alloc(0, n, D_004BB600, line); }

static inline void SelInit_D430(Sel_D430* s0) { Sel_D430* s = s0; s->b0 = 0; MotionTokens_Init(&s->arr); func_0018A8C0(&s->y); }
static inline void ReqInit2_D430(Req_D430* r0, Str_D430* str0, Sel_D430* sel) { Str_D430* str = str0; Req_D430* r = r0; r->b0 = 0; MotionRequest_Construct(r->mr, str); r->b48 = 3; func_0018A710(&r->sel, sel); r->f98 = -1.0f; FLD(r, int, 0x9C) = 0; }
static inline void Install_D430(Anim_D430* an, int* selp, Req_D430* rq, Word_D430* wp)
{
                Rate_D430 rate;
                Rate_D430 tmp;
                Ev_D430 e0;
                Ev_D430 e1;
                V4_D430* v;
                if (an->b5) v = (V4_D430*)an->v8;
                else { v = AnimRate_Init(&tmp, Model_GetFirstFloat(an->f0)); asm { .set reorder } }
                Vec4_Copy_18A350(&rate, v);
                an->b5 = 0;
                AnimEvent_Construct(&e0);
                AnimEvent_Construct(&e1);
                AnimCtl_InstallMotion(an, *selp, MotionRequest_GetMode(rq), &rate, wp, &e0, &e1, func_0018A2E0(rq), func_0018A2D0(rq), func_0018A2C0(rq));
                AnimEvent_dtor(&e1, -1);
                AnimEvent_dtor(&e0, -1);
}
static inline void FindAnim_D430(Self_D430* self, int i, int kind)
{
            It_D430 it;
            It_D430 end;
            void* a;
            char* nm;
            if (kind == 1) nm = D_004BB4C8; else { nm = D_004BB4B8; asm { .set reorder } }
            func_001AF160(&it, D_004FFBC0, nm);
            func_001AF150(&end, D_004FFBC0);
            if (func_001AF130(&it, &end)) a = *func_001AF120(&it);
            else { a = 0; asm { .set reorder } }
            {
                void** an = (void**)((char*)self->models[i] + 0x2EC0);
                Model_Attach(an + 4, a);
                *an = a;
                AnimModel_InitAnim(an);
            }
}

static inline void Motion_D430(Model_D430* md, Req_D430* rq)
{
            char* c = (char*)md + 0x2EC0;
            Anim_D430* an = (Anim_D430*)(c + 0x34);
            int sel;
            Word_D430 w[3];
            func_0018A700(w, -1);
            Actor_ResolveMotionSelection(rq, &sel, w, an->f0);
            if (sel) {
                Install_D430(an, &sel, rq, w);
            }
}

static inline int& Neg1_D430(int& d) { d = -1; return d; }
static inline int& Ser_D430(H_D430* o, int& d) { return *(o ? &o->serial : &Neg1_D430(d)); }

static inline void Else_D430(Self_D430* self, int i, int kind, V4_D430* tbl, Req_D430* req)
{
                FindAnim_D430(self, i, kind);
                {
                    { void* d = tbl; const void* s = &D_00492EA0; *(__int128*)d = *(const __int128*)s; }
                    int k = i % 4;
                    Str_D430 str;
                    Sel_D430 sel;
                    SelInit_D430(&sel);
                    {
                        bool done;
                        int j;
                        char c;
                        const char* src;
                        done = false;
                        j = 0;
                        src = D_004BB640;
                        for (; j < 0x2F; j++) {
                            if (!src[j]) done = true;
                            c = 0; if (done) asm { .set reorder } else c = src[j];
                            str.s[j] = c;
                        }
                        str.s[j] = 0;
                    }
                    ReqInit2_D430(req, &str, &sel);
                    func_001BE5A0(&sel.y, 0);
                    __destroy_array(&sel.arr, (void*)func_0018A210, 8, 7);
                    { float v = (&tbl->x)[k]; float lo = 0.0f; float hi = 1.0f; asm { max.s lo, v, lo } asm { min.s lo, lo, hi } req->f9C = lo; }
                }
                Motion_D430(self->models[i], req);
                {
                    Y_D430* y = &req->sel.y;
                    if (y) { if (y) { if (y) func_001BE5A0(y, 0); } }
                }
                {
                    Arr7_D430* a = &req->sel.arr;
                    if (a) __destroy_array(a, (void*)func_0018A210, 8, 7);
                }
}
static inline void Tail_D430(Self_D430* self, int i)
{
            { Model_D430* mm = self->models[i]; FLD(mm, float, 0x2450) = 1.0f; }
            FLD(self->models[i], float, 0x2454) = 0.0f;
            Model_HardMeshAttachPoints(MAN(self->models[i]));
            {
                V4_D430 v;
                Man_D430* m;
                v.x = 0.0f; v.y = 30.0f; v.z = 0.0f; v.w = 1.0f;
                { Model_D430* md = self->models[i]; FLD(md, H_D430*, 0x2DD0) = 0; m = MAN(md); }
                {
                    int d;
                    FLD(m, int, 0x2D74) = Ser_D430(0, d);
                }
                { QAsgB_D430(&FLD(m, V4_D430, 0x2D80), &v); FLD(m, float, 0x2D8C) = 1.0f; }
            }
            { Man_D430* mm = MAN(self->models[i]); FLD(mm, unsigned char, 0x2DA0) = 1; }
}
extern "C" Self_D430* GuiScoresEquip_BuildActor(Self_D430* p0)
{
    Self_D430* self = p0;
    int kind;
    Model_D430* p;
    int i;
    int x;
    GuiWidget_ctor(p0);
    self->vt = D_004DF140;
    { V4E_D430* p = self->pos; V4E_D430* e = self->pos + 4; do { p++; } while (p != e); }
    if (g_GameState == 2) FrontEnd_GetCharacterData(D_004FFC04);
    {
        void* p;
        p = Alloc_D430(0x68, 0x54);
        if (p) {
            G_D430(p, 0, 9, 0);
            *(char**)p = D_004DA470;
            ((int*)p)[0x60 / 4] = 0;
            ((int*)p)[0x64 / 4] = 0;
            Object_AttachTransform(p, g_IdentityMatrix, 0);
            ((int*)p)[0x30 / 4] = 0;
        }
        self->gobj = p;
    }
    {
        M4_D430 mtx;
        V4_D430 tbl;
        Req_D430 req;
        {
            M4_D430 t;
            float one = 1.0f; float tz = -3.25f;
            t.m[0][0] = one; t.m[0][1] = 0.0f; t.m[0][2] = 0.0f; t.m[0][3] = 0.0f;
            t.m[1][0] = 0.0f; t.m[1][1] = one; t.m[1][2] = 0.0f; t.m[1][3] = 0.0f;
            t.m[2][0] = 0.0f; t.m[2][1] = 0.0f; t.m[2][2] = one; t.m[2][3] = 0.0f;
            t.m[3][0] = 0.0f; t.m[3][1] = 0.0f; t.m[3][2] = tz; t.m[3][3] = one;
            M4Cp_D430((M4Q_D430*)&mtx, (M4Q_D430*)&t);
        }
        float pa = 3.1415927f; float pb = 3.1415927f;
        {
            V4C_D430 r1(0.0f, 0.0f, pa, 0.0f);
            V4C_D430 r;
            Q3D_D430(&self->f1C0, &r1, &self->f1D0, r, pb);
        }
        if (g_IsMultiplayer) {
            V4C_D430 v(-3.2f, 8.0f, -2.0f, 1.0f);
            QAsgB_D430(&self->pos[0], &v);
        } else {
            V4C_D430 v(3.2f, 8.0f, -1.7f, 1.0f);
            QAsgB_D430(&self->pos[0], &v);
        }
        { V4C_D430 v(-0.4f, 8.0f, -2.0f, 1.0f); QAsgB_D430(&self->pos[1], &v); }
        { V4C_D430 v(2.4f, 8.0f, -2.0f, 1.0f); QAsgB_D430(&self->pos[2], &v); }
        { V4C_D430 v(5.2f, 8.0f, -2.0f, 1.0f); QAsgB_D430(&self->pos[3], &v); }
        for (i = 0; i < 4; i++) {
            {
                p = (Model_D430*)Alloc_D430(0x3030, 0x6C);
                if (p) {
                    x = i;
                    p = DisplayActor_Construct(p, &x);
                }
                self->models[i] = p;
            }
            {
                Model_D430* m = self->models[i];
                { void* t = (char*)m + 0x2E50; FLD(m, void*, 0x2C64) = t; }
            }
            self->models[i]->SetMtx(&mtx);
            {
                Xf_D430* xf = self->models[i]->xf;
                M4_D430 rot;
                float s = Math_SinThunk(0.0f);
                float c = Math_CosThunk(0.0f);
                { M4_D430* pr = &rot; float z = 0.0f; Mtx44_SetRotation(pr, c, -s, z, s, c, z, z, z, 1.0f); }
                { M4_D430* pr = &rot; xf->SetMtx(pr); }
            }
            { int n = 0x44; int j = D_00493A60; Model_D430* m = self->models[i]; Man_D430* mn = MAN(m); QCopy_D430(APP_D430(mn), (Blk_D430*)((int)D_0055D510 + j * 0x440), n); }
            Appearance_ReorderParts(MAN(self->models[i]));
            kind = Appearance_GetBodyKind(APP_D430(MAN(self->models[i])));
            {
                char* nm; if (kind == 0) nm = D_004BB618; else { nm = D_004BB628; asm { .set reorder } }
                cVUM_GOBJ_InitModel(self->models[i], nm);
                String_Copy(NAME_D430(MAN(self->models[i])), nm);
            }
            self->models[i]->Init(1);
            if (g_GameState == 2) {
                void* a = D_004F77A0;
                void** an = (void**)((char*)self->models[i] + 0x2EC0);
                Model_Attach(an + 4, a);
                *an = a;
                AnimModel_InitAnim(an);
            } else {
                Else_D430(self, i, kind, &tbl, &req);
            }
            Tail_D430(self, i);
            func_0038E030(MAN(self->models[i]));
            { Model_D430* mm = self->models[i]; FLD(mm, int, 0x2C30) = 1; }
            ActorModel_Setup(MAN(self->models[i]), 1);
            Skel_ApplyScalePreset(MAN(self->models[i]), -1);
            FLD(self->models[i], short, 0x2DF4) = 0;
            self->b220[i] = 0;
        }
    }
    self->f224 = 0;
    self->b60 = 1;
    self->f228 = 0;
    self->b22C = 1;
    return self;
}






