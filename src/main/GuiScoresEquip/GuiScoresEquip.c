/*
 * main/GuiScoresEquip: 6 files, 0035CD00-0035D430
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035CD00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

/* GuiScoresEquip_Init: bind the scores/equipment screen widgets: the figure view (render callback),
 * the 4x20 equipment grid, the optional player tabs (with the multiplayer stats query) and the
 * 4 pairs of row labels. */

class W {
public:
    VPAD16(a) VPAD4(b)
    virtual int IsA(char* type);
    char pad4[0x10];
    unsigned short flags;
    char pad16[0x48 - 0x16];
    void* cb;
};

struct Stats { char pad[0x10]; int a; int b; };

struct Screen {
    char pad0[0x48];
    W* tab[4];
    int x58;
    int x5C;
    unsigned char hasTabs;
    char pad61[3];
    W* grid[4][20];
    char pad1A4[0x230 - 0x1A4];
    struct { W* a; W* b; } rows[4];
};

extern "C" {
extern char D_004BB590[];
extern char D_004A9BF0[];
extern char D_004A7520[];
extern char D_004BB5A0[];
extern char D_004BB5B8[];
extern char D_004BB5C0[];
extern char D_004BB5E0[];
extern char D_00492D10[20][20];
extern Screen* D_00533760;
extern unsigned char g_IsMultiplayer;
void GuiWidget_Init(Screen* s);
W* GuiWidget_FindChildByName(void* self, char* name);
void GuiScoresEquip_FigureCallback(void);
void func_0041C0D0(W* w, int on);
void GuiTextWidget_SetDisableWrap(W* w, int on);
int sprintf(char* buf, const char* fmt, ...);
void GuiWidget_SendEvent(Screen* s, W* to, int ev, int name, int data);
void GuiScoresEquip_Init(Screen* s);
}

static inline W* FindAs(void* self, char* name, char* type)
{
    W* w = GuiWidget_FindChildByName(self, name);
    return (w && w->IsA(type)) ? w : 0;
}

void GuiScoresEquip_Init(Screen* s)
{
    int i;
    int j;
    GuiWidget_Init(s);
    {
        W* f = FindAs(s, D_004BB590, D_004A9BF0);
        if (f) {
            D_00533760 = s;
            f->cb = (void*)GuiScoresEquip_FigureCallback;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 20; j++) {
            *((char*)D_00492D10 + j * 20) = '1' + i;
            s->grid[i][j] = FindAs(s, D_00492D10[j], D_004A7520);
            if (s->grid[i][j]) {
                func_0041C0D0(s->grid[i][j], 1);
                GuiTextWidget_SetDisableWrap(s->grid[i][j], 1);
            }
        }
    }
    if (s->hasTabs) {
        for (i = 0; i < 4; i++) {
            char buf[0x1C];
            sprintf(buf, D_004BB5A0, i + 1);
            s->tab[i] = GuiWidget_FindChildByName(s, buf);
            if (s->tab[i]) s->tab[i]->flags &= ~2;
        }
        if (g_IsMultiplayer && s->tab[0]) {
            Stats* r = 0;
            GuiWidget_SendEvent(s, s->tab[0], 4, (int)D_004BB5B8, (int)&r);
            if (r) {
                s->x58 = r->a;
                s->x5C = r->b;
            }
        }
    }
    /* row labels: retail places the loop setup after the body (entry jumps to it, then to the test) */
    {
        int k;
        char* a;
        char* b;
        k = 0;
        goto init;
    loop:
        a[0] = '1' + k;
        b[0] = '1' + k;
        s->rows[k].a = GuiWidget_FindChildByName(s, a);
        s->rows[k].b = GuiWidget_FindChildByName(s, b);
        k++;
    test:
        if (k < 4) goto loop;
        return;
    init:
        a = D_004BB5C0;
        b = D_004BB5E0;
        goto test;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0035CD00 */

/* merge_units: begin func_0035CFB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "child_list_iter.h"

/* Set or clear flag 2 on every other child. */
extern "C" void MakeChildrenVisible(ChildWidget* o, int on);
void MakeChildrenVisible(ChildWidget* o, int on)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        ChildWidget* c = n->obj;
        if (c != o) {
            if (on) c->flags |= 2;
            else c->flags &= ~2;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0035CFB0 */

/* merge_units: begin func_0035D0A0 */
#pragma push /* merge_units */
#pragma cplusplus on
class W35D0A0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x10]; unsigned short a14;
};
struct S35D0A0 { char pad[0x224]; int a224; };
extern "C" {
extern char D_004BB4D8[];
extern char D_004BB4E8[];
extern char D_004BB500[];
extern char D_004BB520[];
extern char D_004BB530[];
extern char D_004BB540[];
extern char D_004A9870[];
#if 0 /* merge_units */
W35D0A0* GuiWidget_FindChildByName(void* self, char* name);
#endif /* merge_units */
#define GuiWidget_FindChildByName(a0, a1) ((W35D0A0 *)GuiWidget_FindChildByName((a0), (a1))) /* merge_units */

char* Loc_LookupText(char* key);
void GuiTextWidget_SetText(W35D0A0* w, char* text, int flags);
void GuiScoresEquip_SetScreen(S35D0A0* o, int mode);
}
static inline W35D0A0* cast35D0A0(W35D0A0* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
/* Switches the screen between its two modes: toggles two widgets and relabels a third. */
void GuiScoresEquip_SetScreen(S35D0A0* o, int mode)
{
    W35D0A0* a;
    W35D0A0* b;
    W35D0A0* c;
    o->a224 = mode;
    a = GuiWidget_FindChildByName(o, D_004BB4D8);
    b = GuiWidget_FindChildByName(o, D_004BB4E8);
    if (a) {
        if (!mode) a->a14 |= 2;
        else a->a14 &= ~2;
    }
    if (b) {
        if (mode) b->a14 |= 2;
        else b->a14 &= ~2;
    }
    c = cast35D0A0(GuiWidget_FindChildByName(o, D_004BB500));
    if (c) {
        char* t = Loc_LookupText(mode == 0 ? D_004BB520 : D_004BB540);
        GuiTextWidget_SetText(c, t ? t : D_004BB530, 0);
    }
}
#undef GuiWidget_FindChildByName /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0035D0A0 */

/* merge_units: begin func_0035D1F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct V0035D1F0 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); char pad4[0x2420 - 4]; short h2420; char pad2422[0x2C74 - 0x2422]; int x2C74; };
struct O0035D1F0 { void* vt; char pad[0x1A0]; V0035D1F0* items[4]; V0035D1F0* p1B4; };
extern "C" {

extern char g_AgentPartCache[];
extern char D_004DF140[];
extern char D_004E1220[];
extern int D_00506500;
void Mem_Free(int pool, void* p, char* file, int line);
void AgentPartCache_Unlock(void* p);
void World_ClearPendingIfLoaded(void);
void GuiEquipmentModify_RingRelease(void* p);
void GuiWidget_Destroy(void* p, int f);
void operator_delete(void* p);
}
static inline void Del0035D1F0(V0035D1F0* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, "GuiScoresEquip.cc", line);
}
extern "C" O0035D1F0* GuiScoresEquip_dtor(O0035D1F0* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DF140;
        Del0035D1F0(self->p1B4, 0xB9);
        for (i = 0; i < 4; i++) {
            self->items[i]->h2420 = 0;
            self->items[i]->x2C74 = 0;
            self->items[i]->v22(1);
            Del0035D1F0(self->items[i], 0xBF);
        }
        World_ClearPendingIfLoaded();
        GuiWidget_Destroy(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0035D1F0 */

/* merge_units: begin func_0035D3D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_0035D3D0, D_004DA470, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0035D3D0 */

/* merge_units: begin func_0035D430 */
#pragma push /* merge_units */
/* Empty 'asm { .set reorder }' blocks below are scheduling barriers only (emit no instructions). */
#pragma cplusplus on
#include "SFOLobby_helpers.h"
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
void cAssocArray_cString_cSkaAnimationSetPtr_Find(It_D430* it, void* tab, char* key);
void cAssocArray_cString_cSkaAnimationSetPtr_End(It_D430* it, void* tab);
int cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(It_D430* a, It_D430* b);
void** cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(It_D430* it);
void Model_Attach(void* a, void* b);
void AnimModel_InitAnim(void* a);
void MotionTokens_Init(Arr7_D430* a);
void cArray_cTimedEvent_ctor_void(Y_D430* y);
void MotionRequest_Construct(void* mr, Str_D430* s);
void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(Sel_D430* d, Sel_D430* s);
void func_001BE5A0(Y_D430* y, int f);
void __destroy_array(void* a, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void cSkaPlaybackGroupId_ctor_int(Word_D430* w, int a);
void Actor_ResolveMotionSelection(Req_D430* r, int* sel, Word_D430* w, void* m);
float Model_GetFirstFloat(void* m);
V4_D430* AnimRate_Init(Rate_D430* r, float f);
void Vec4_Copy_18A350(Rate_D430* d, V4_D430* s);
void AnimEvent_Construct(Ev_D430* e);
int MotionRequest_GetMode(Req_D430* r);
int cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(Req_D430* r);
float cSkaRequestStream_AnimationPacket_GetDuration(Req_D430* r);
float func_0018A2C0(Req_D430* r);
void AnimCtl_InstallMotion(Anim_D430* a, int sel, int b, Rate_D430* r, Word_D430* w, Ev_D430* e0, Ev_D430* e1, int c, float f0, float f1);
void AnimEvent_dtor(Ev_D430* e, int f);
void Model_HardMeshAttachPoints(Man_D430* m);
void cMan_GetTextureIDs(Man_D430* m);
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

static inline void SelInit_D430(Sel_D430* s0) { Sel_D430* s = s0; s->b0 = 0; MotionTokens_Init(&s->arr); cArray_cTimedEvent_ctor_void(&s->y); }
static inline void ReqInit2_D430(Req_D430* r0, Str_D430* str0, Sel_D430* sel) { Str_D430* str = str0; Req_D430* r = r0; r->b0 = 0; MotionRequest_Construct(r->mr, str); r->b48 = 3; cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&r->sel, sel); r->f98 = -1.0f; FLD(r, int, 0x9C) = 0; }
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
                AnimCtl_InstallMotion(an, *selp, MotionRequest_GetMode(rq), &rate, wp, &e0, &e1, cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(rq), cSkaRequestStream_AnimationPacket_GetDuration(rq), func_0018A2C0(rq));
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
            cAssocArray_cString_cSkaAnimationSetPtr_Find(&it, D_004FFBC0, nm);
            cAssocArray_cString_cSkaAnimationSetPtr_End(&end, D_004FFBC0);
            if (cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(&it, &end)) a = *cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(&it);
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
            cSkaPlaybackGroupId_ctor_int(w, -1);
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
            cMan_GetTextureIDs(MAN(self->models[i]));
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
#pragma pop /* merge_units */
/* merge_units: end func_0035D430 */
