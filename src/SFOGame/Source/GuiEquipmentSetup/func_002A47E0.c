/* 002A47E0 GuiEquipmentSetup::GuiEquipmentSetup() (GuiEquipmentSetup.cc), rebuilt from the prototype
 * listing and the matched sibling GuiScoresEquip_ctor (0x35D430). */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "alloc_guard.h"
#include "SFOLobby_helpers.h"
/* Empty 'asm { .set reorder }' blocks below are scheduling barriers only (emit no instructions). */
#pragma inline_depth(10)
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_common_subs on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4T;
struct V4ET { float x, y, z, w; V4ET() {} } __attribute__((aligned(16)));
struct M4T { float m[4][4]; } __attribute__((aligned(16)));
struct M4QT { __int128 r[4]; };
/* 128-bit lq/sq quadword copies: C cannot express them */
static inline void QAsgB(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void M4Cp(M4QT* d0, const M4QT* s0) { M4QT* d = d0; __int128 qa, qb; const M4QT* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct Wd { int w; };
struct Hs { char pad[0xC]; int serial; };
struct BlkT { char d[0x440]; };

class XfT {
public:
    VPAD2(a) virtual void SetMtx(M4T* m);
};

struct AnimT {
    void* f0;
    char pad4;
    unsigned char b5;
    char pad6[2];
    char v8[0x10];
};

struct ManT {
    char pad0[0x40];
    char app[0x30];
    char name[0x10];
};

class ModelT {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetMtx(M4T* m);
    VPAD4(d) VPAD2(e) virtual void Init(int a);
    char pad4[0x4C];
    XfT* xf;
    char pad54[0xC];
    ManT man;
};

#define MAN(p) (&(p)->man)
static inline char* APP(ManT* m) { return m->app; }
static inline char* NAME(ManT* m) { return m->name; }
#define FLD(p, T, o) (*(T*)((char*)(p) + (o)))

struct HumanT {
    VPAD16(a) VPAD8(b) VPAD2(c)
    virtual int IsActive();             /* +0x70 */
    virtual void SetReady(int r);       /* +0x74 */
    char pad4[8];
    unsigned int team;                  /* 0x0C */
};
struct PlayerT { char pad[0x30]; HumanT* human; };

struct SelfT {
    void* vt;
    char pad4[0x14 - 4];
    unsigned short flags;
    char pad16[0x48 - 0x16];
    ModelT* people[4];
    void* cameraTarget;
    char pad5C[4];
    V4T obj_rot;
    V4T light_rot;
    V4ET manPos[4];
    int everyone;
    int everyoneOld;
    int readyActive;
    int disguiseLevel;
    void* countdownWidget;
    char* countdownString;
    unsigned char bD8;
    int fDC;
};

struct Arr7T { char d[0x38]; };
struct Yy { char d[0x10]; };
struct SelT { char b0; char pad[3]; Arr7T arr; Yy y; };
struct StrT { char s[0x30]; };
struct ReqT {
    char b0;
    char pad1[0xF];
    char mr[0x38];
    char b48;
    char pad49[3];
    SelT sel;
    float f98;
    float f9C;
};
struct ItT { int w; };
struct EvT { char d[0x40]; };
struct RateT { char d[0x10]; };
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;
typedef struct EffectMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0xF];
    char sub30[0x48];
    char partA[0x9C];
    char partB[0xAC];
} EffectMsg;

extern "C" {
extern char D_004DD7C0[];
extern char D_004DA470[];
extern char D_004DAE10[];
extern signed char D_00493A60;
extern char D_004AB260[];
extern char D_004AB278[];
extern char D_004AB288[];
extern char D_004AB0C0[];
extern char D_004AB0D0[];
extern char D_004AB2A0[];
extern char D_004FFBC0[];
extern char g_IdentityMatrix[];
extern BlkT D_0055D510[];
extern V4T D_0048BAC0;
extern char D_0048BAA0[][8];
extern unsigned char g_GameState;
extern void* D_004FFC04;
extern int D_0055DE94;
extern PlayerT* g_LocalPlayer;
extern char g_Game[];
extern int D_00506508;
extern int D_00506510;
extern unsigned char D_00506518[];
extern long long D_00506520[];
void FrontEnd_GetCharacterData(void* p);
void GuiWidget_ctor(SelfT* self);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cGOBJ_ctor(void* p, int* a, int b, int* c);
void cGOBJ_CreateXform(void* p, void* t, int a);
ModelT* cSKM_GOBJ_ctor_cObjectIdR(void* p, int* idx);
float SIN(float a);
float COS(float a);
void cMatrix_Set_ColumnMajorForm(M4T* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
int SKL_FindSex(void* app);
void cMan_SortParts(ManT* m);
void cSKM_GOBJ_ResetSkeleton(ModelT* m, char* name);
void cAssocArray_cString_cSkaAnimationSetPtr_Find(ItT* it, void* tab, char* key);
void cAssocArray_cString_cSkaAnimationSetPtr_End(ItT* it, void* tab);
int cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(ItT* a, ItT* b);
void** cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(ItT* it);
void cSkaParams_HandleNewAnimationSet(void* a, void* b);
void cSkaSystem_SetInitialAnimation(void* a);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(Arr7T* a);
void cArray_cTimedEvent_ctor_void(Yy* y);
void cString16N_3_ctor_cString16NR(void* mr, StrT* s);
void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(SelT* d, SelT* s);
void func_001BE5A0(Yy* y, int f);
void __destroy_array(void* a, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void cSkaPlaybackGroupId_ctor_int(Wd* w, int a);
void cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(ReqT* r, int* sel, Wd* w, void* m);
float cSkaAnimationSet_DefaultCrossFadeDuration(void* m);
V4T* cSkaCrossFadeDuration_ctor_float(RateT* r, float f);
void cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(RateT* d, V4T* s);
void cSkaAnimEndedMessage_ctor_void(EvT* e);
int cSkaRequestStream_AnimationPacket_GetInstruction(ReqT* r);
int cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(ReqT* r);
float cSkaRequestStream_AnimationPacket_GetDuration(ReqT* r);
float func_0018A2C0(ReqT* r);
void cSkaRequestStream_AddRequest(AnimT* a, int sel, int b, RateT* r, Wd* w, EvT* e0, EvT* e1, int c, float f0, float f1);
void cSkaAnimEndedMessage_dtor(EvT* e, int f);
void cMan_SetGunOffsets(ManT* m);
void cMan_GetTextureIDs(ManT* m);
void cMan_BuildMan(ManT* m, int flag);
void cMan_SetBoneSet(ManT* m, int a);
void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, void* name, int a, int b);
void cPlaySoundMsg_ctor_netPlaySoundMsgR(EffectMsg* msg, SoundRequest* req, void* p);
void QueueMessage_cMessageR_cSystemP_int(EffectMsg* msg, void* target, int flags);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
SelfT* GuiEquipmentSetup_ctor(SelfT* self);
}

static inline void QCopy(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
    /* quadword copy loop (lq/sq) */
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
static inline void G(void* p, int a, int n, int b) { int* pa = &a; cGOBJ_ctor(p, pa, n, &b); }
struct V4CT { float x, y, z, w; V4CT() {} V4CT(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } V4CT(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
/* 128-bit copies through a quadword register; the light_rot copy starts from a zeroed temp (retail paddub) */
static inline void CpZ(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 q = 0; q = *(const __int128*)s; *(__int128*)d = q; }
static inline void CpN(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 q; q = *(const __int128*)s; *(__int128*)d = q; }
static inline void* Alloc(int n, int line) { AllocGuard g; return cMemMan_Allocate(0, n, D_004AB260, line); }

static inline void SelInit(SelT* s0) { SelT* s = s0; s->b0 = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(&s->arr); cArray_cTimedEvent_ctor_void(&s->y); }
static inline void ReqInit2(ReqT* r0, StrT* str0, SelT* sel) { StrT* str = str0; ReqT* r = r0; r->b0 = 0; cString16N_3_ctor_cString16NR(r->mr, str); r->b48 = 3; cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&r->sel, sel); r->f98 = -1.0f; FLD(r, int, 0x9C) = 0; }
static inline void Install(AnimT* an, int* selp, ReqT* rq, Wd* wp)
{
                RateT rate;
                RateT tmp;
                EvT e0;
                EvT e1;
                V4T* v;
                if (an->b5) v = (V4T*)an->v8;
                else { v = cSkaCrossFadeDuration_ctor_float(&tmp, cSkaAnimationSet_DefaultCrossFadeDuration(an->f0)); asm { .set reorder } }
                cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&rate, v);
                an->b5 = 0;
                cSkaAnimEndedMessage_ctor_void(&e0);
                cSkaAnimEndedMessage_ctor_void(&e1);
                cSkaRequestStream_AddRequest(an, *selp, cSkaRequestStream_AnimationPacket_GetInstruction(rq), &rate, wp, &e0, &e1, cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(rq), cSkaRequestStream_AnimationPacket_GetDuration(rq), func_0018A2C0(rq));
                cSkaAnimEndedMessage_dtor(&e1, -1);
                cSkaAnimEndedMessage_dtor(&e0, -1);
}
static inline void FindAnim(SelfT* self, int i, int kind)
{
            ItT it;
            ItT end;
            void* a;
            char* nm;
            if (kind == 1) nm = D_004AB0D0; else { nm = D_004AB0C0; asm { .set reorder } }
            cAssocArray_cString_cSkaAnimationSetPtr_Find(&it, D_004FFBC0, nm);
            cAssocArray_cString_cSkaAnimationSetPtr_End(&end, D_004FFBC0);
            if (cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(&it, &end)) a = *cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(&it);
            else { a = 0; asm { .set reorder } }
            {
                void** an = (void**)((char*)self->people[i] + 0x2EC0);
                cSkaParams_HandleNewAnimationSet(an + 4, a);
                *an = a;
                cSkaSystem_SetInitialAnimation(an);
            }
}

static inline void Motion(ModelT* md, ReqT* rq)
{
            char* c = (char*)md + 0x2EC0;
            AnimT* an = (AnimT*)(c + 0x34);
            int sel;
            Wd w[3];
            cSkaPlaybackGroupId_ctor_int(w, -1);
            cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(rq, &sel, w, an->f0);
            if (sel) {
                Install(an, &sel, rq, w);
            }
}

static inline int& Neg1(int& d) { d = -1; return d; }
static inline int& Ser(Hs* o, int& d) { return *(o ? &o->serial : &Neg1(d)); }

static inline void Else(SelfT* self, int i, int kind, V4T* tbl, ReqT* req)
{
                FindAnim(self, i, kind);
                {
                    { void* d = tbl; const void* s = &D_0048BAC0; *(__int128*)d = *(const __int128*)s; }
                    int k = i % 4;
                    StrT str;
                    SelT sel;
                    SelInit(&sel);
                    {
                        bool done;
                        int j;
                        char c;
                        const char* src;
                        done = false;
                        j = 0;
                        src = D_004AB2A0;
                        for (; j < 0x2F; j++) {
                            if (!src[j]) done = true;
                            if (done) c = 0; else c = src[j];
                            str.s[j] = c;
                        }
                        str.s[j] = 0;
                    }
                    ReqInit2(req, &str, &sel);
                    func_001BE5A0(&sel.y, 0);
                    __destroy_array(&sel.arr, (void*)func_0018A210, 8, 7);
                    { float v = (&tbl->x)[k]; float lo = 0.0f; float hi = 1.0f; asm { max.s lo, v, lo } asm { min.s lo, lo, hi } req->f9C = lo; }
                }
                Motion(self->people[i], req);
                {
                    Yy* y = &req->sel.y;
                    if (y) { if (y) { if (y) func_001BE5A0(y, 0); } }
                }
                {
                    Arr7T* a = &req->sel.arr;
                    if (a) __destroy_array(a, (void*)func_0018A210, 8, 7);
                }
}
static inline void Tail(SelfT* self, int i)
{
            { ModelT* mm = self->people[i]; FLD(mm, float, 0x2450) = 1.0f; }
            FLD(self->people[i], float, 0x2454) = 0.0f;
            cMan_SetGunOffsets(MAN(self->people[i]));
            {
                V4T v;
                ManT* m;
                v.x = 0.0f; v.y = 30.0f; v.z = 0.0f; v.w = 1.0f;
                { ModelT* md = self->people[i]; FLD(md, Hs*, 0x2DD0) = 0; m = MAN(md); }
                {
                    int d;
                    FLD(m, int, 0x2D74) = Ser(0, d);
                }
                { QAsgB(&FLD(m, V4T, 0x2D80), &v); FLD(m, float, 0x2D8C) = 1.0f; }
            }
            { ManT* mm = MAN(self->people[i]); FLD(mm, unsigned char, 0x2DA0) = 1; }
}
extern "C" SelfT* GuiEquipmentSetup_ctor(SelfT* p0)
{
    SelfT* self = p0;
    int kind;
    ModelT* p;
    int i;
    int x;
    GuiWidget_ctor(p0);
    self->vt = D_004DD7C0;
    { V4ET* p = self->manPos; V4ET* e = self->manPos + 4; do { p++; } while (p != e); }
    self->flags &= ~0x20;
    if (g_GameState == 2) FrontEnd_GetCharacterData(D_004FFC04);
    self->disguiseLevel = D_0055DE94;
    if (D_00493A60 == -1) D_00493A60 = 1;
    {
        void* p;
        p = Alloc(0x68, 0x8A);
        if (p) {
            G(p, 0, 9, 0);
            *(char**)p = D_004DA470;
            ((int*)p)[0x60 / 4] = 0;
            ((int*)p)[0x64 / 4] = 0;
            cGOBJ_CreateXform(p, g_IdentityMatrix, 0);
            ((int*)p)[0x30 / 4] = 0;
        }
        self->cameraTarget = p;
    }
    {
        M4T mtx;
        V4T tbl;
        ReqT req;
        SoundRequest fx;
        EffectMsg msg;
        {
            M4T t;
            float one = 1.0f; float tz = -3.25f;
            t.m[0][0] = one; t.m[0][1] = 0.0f; t.m[0][2] = 0.0f; t.m[0][3] = 0.0f;
            t.m[1][0] = 0.0f; t.m[1][1] = one; t.m[1][2] = 0.0f; t.m[1][3] = 0.0f;
            t.m[2][0] = 0.0f; t.m[2][1] = 0.0f; t.m[2][2] = one; t.m[2][3] = 0.0f;
            t.m[3][0] = 0.0f; t.m[3][1] = 0.0f; t.m[3][2] = tz; t.m[3][3] = one;
            M4Cp((M4QT*)&mtx, (M4QT*)&t);
        }
        float pa = 3.1415927f; float pb = 3.1415927f;
        {
            V4CT r1(0.0f, 0.0f, pa, 0.0f);
            CpN(&self->obj_rot, &r1);
            V4CT r; r.x = 0.0f; r.y = 0.0f; r.z = pb;
            CpZ(&self->light_rot, &r);
        }
        { V4CT v(-4.2f, 5.0f, -2.0f, 1.0f); QAsgB(&self->manPos[0], &v); }
        { V4CT v(-1.4f, 5.0f, -2.0f, 1.0f); QAsgB(&self->manPos[1], &v); }
        { V4CT v(1.4f, 5.0f, -2.0f, 1.0f); QAsgB(&self->manPos[2], &v); }
        { V4CT v(4.2f, 5.0f, -2.0f, 1.0f); QAsgB(&self->manPos[3], &v); }
        for (i = 0; i < 4; i++) {
            {
                p = (ModelT*)Alloc(0x3030, 0x97);
                if (p) {
                    x = i;
                    p = cSKM_GOBJ_ctor_cObjectIdR(p, &x);
                }
                self->people[i] = p;
            }
            {
                ModelT* m = self->people[i];
                { void* t = (char*)m + 0x2E50; FLD(m, void*, 0x2C64) = t; }
            }
            self->people[i]->SetMtx(&mtx);
            {
                XfT* xf = self->people[i]->xf;
                M4T rot;
                float s = SIN(0.0f);
                float c = COS(0.0f);
                { M4T* pr = &rot; float z = 0.0f; cMatrix_Set_ColumnMajorForm(pr, c, -s, z, s, c, z, z, z, 1.0f); }
                { M4T* pr = &rot; xf->SetMtx(pr); }
            }
            { int n = 0x44; int j = D_00493A60; ModelT* m = self->people[i]; ManT* mn = MAN(m); QCopy(APP(mn), (BlkT*)((int)D_0055D510 + j * 0x440), n); }
            kind = SKL_FindSex(APP(MAN(self->people[i])));
            cMan_SortParts(MAN(self->people[i]));
            {
                char* nm; if (kind == 0) nm = D_004AB278; else { nm = D_004AB288; asm { .set reorder } }
                cSKM_GOBJ_ResetSkeleton(self->people[i], nm);
                Libc_Strcpy(NAME(MAN(self->people[i])), nm);
            }
            self->people[i]->Init(1);
            Else(self, i, kind, &tbl, &req);
            Tail(self, i);
            cMan_GetTextureIDs(MAN(self->people[i]));
            { ModelT* mm = self->people[i]; FLD(mm, int, 0x2C30) = 1; }
            cMan_BuildMan(MAN(self->people[i]), 1);
            cMan_SetBoneSet(MAN(self->people[i]), -1);
            { ModelT* m = self->people[i]; FLD(m, short, 0x2DF4) = 0; }
            FLD(self->people[i], unsigned char, 0x2C71) = 1;
            D_00506518[i] = 0;
            D_00506520[i] = 0;
        }
    {
        int commander = 22;
        int commanderTens = commander / 10;
        int commanderOnes = commander - commanderTens;
        int j;
        for (j = 0; j < 4; j++) {
            D_0048BAA0[j][0] = commanderTens;
            D_0048BAA0[j][1] = commanderOnes;
            D_0048BAA0[j][3] = '1';
        }
    }
    {
        HumanT* human = g_LocalPlayer->human;
        human->SetReady(1);
        int found = ((human->team & 0x7F000000) >> 24) - 1;
        cSndFx_ctor_int_charP_cGOBJP_int(&fx, 4, D_0048BAA0[found], 0, 0);
        cPlaySoundMsg_ctor_netPlaySoundMsgR(&msg, &fx, human);
        msg.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
        g_LocalPlayer->human->SetReady(1);
        self->everyone = 0;
        self->readyActive = 0;
        D_00506508 = 0;
        D_00506510 = 0;
        self->countdownWidget = 0;
        self->bD8 = 0;
        self->fDC = 0;
        {
            int j;
            for (j = 0; j < 4; j++) D_0048BAA0[j][3] = '2';
        }
        msg.vtbl = D_004DAE10;
        cFileMan_dtor(msg.partB, -1);
        cFileMan_dtor(msg.partA, -1);
        cMessage_dtor(&msg, 0);
        cFileMan_dtor(fx.partB, -1);
        cFileMan_dtor(fx.partA, -1);
    }
    }
    return self;
}
