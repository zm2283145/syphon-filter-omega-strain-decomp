/*
 * main/human: range (3 files, 00188E60-00188FB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00188E60 */
#pragma push /* merge_units */
typedef struct { char pad[0x3204]; int flags; } O_188E60;
int cHuman_GetMovementState(O_188E60* o)
{
    int f = o->flags;
    if ((f >> 5) & 1) return 2;
    if (((f >> 1) & 1) || ((f >> 7) & 1) || ((f >> 6) & 1)) return 1;
    if ((((f >> 3) & 1) || ((f >> 4) & 1)) && (f & 1)) return 4;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00188E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00188E60 */

/* merge_units: begin func_00188F00 */
#pragma push /* merge_units */
typedef struct { char d[0x9C]; } E4Str;
typedef struct {
    char pad0[0x48];
    E4Str s48;
    E4Str sE4;
    char pad180[0x10];
} __attribute__((aligned(16))) E4Req;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    E4Str s78;
    E4Str s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) E4Ev;
extern char g_Game[];
extern char D_004DAE30[];
extern void cSndFx_ctor_int_charP_cGOBJP_int(E4Req* r, int a, char* b, int c, int d);
extern void cPlaySoundMsg_ctor_cSndFxR(E4Ev* e, E4Req* r, int preset);
extern void QueueMessage_cMessageR_cSystemP_int(E4Ev* e, char* tgt, int n);
extern void cFileMan_dtor(E4Str* s, int flag);
extern void cMessage_dtor(E4Ev* e, int flag);
void cHuman_HandleLadderStepEvent(int preset)
{
    E4Req req;
    E4Ev ev;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, "F_LADDER_M", 0, 0);
    cPlaySoundMsg_ctor_cSndFxR(&ev, &req, preset);
    ev.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
    ev.vt = D_004DAE30;
    cFileMan_dtor(&ev.s114, -1);
    cFileMan_dtor(&ev.s78, -1);
    cMessage_dtor(&ev, 0);
    cFileMan_dtor(&req.sE4, -1);
    cFileMan_dtor(&req.s48, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00188F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00188F00 */

/* merge_units: begin func_00188FB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void Q8FB0(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(int) { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }
    V(float a, float b, float c, float d) { void* xx = this; x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; Q8FB0(d, &o); }
    V& operator=(const V& o) { Q8FB0(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Q4 { float f[4]; } __attribute__((aligned(16)));
struct M { Q4 r[3]; V t; };
typedef struct { char d[0x9C]; } SStr;
struct SReq {
    char pad0[0x48];
    SStr s48;
    SStr sE4;
    char pad180[0x10];
} __attribute__((aligned(16)));
struct SEv {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    SStr s78;
    SStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16)));
struct MatSub { char pad0[0x18]; int fx; int snd; char name[0x18]; };
struct Mat { MatSub e[5]; };
struct GB { char p[0x40]; char ref[0x310 - 0x140]; };
struct Ground {
    char pad0[0xE4]; float fE4;
    char padE8[0x100 - 0xE8]; GB b;
    V n;
};
struct Actor {
    char pad0[0x3204]; int flags; char pad3208[4]; int state;
    char pad3210[0x3310 - 0x3210]; Ground* g;
};
extern "C" {
extern signed char D_004E1D88;
extern V D_004E1D90;
extern char D_0049D920[];
extern char D_0049D928[];
extern char D_0049D938[];
extern char D_0049D950[];
extern char D_0049D960[];
extern float g_NegFltMax;
extern float D_0049CF40;
extern float D_0049CF38;
float cHumanCollisionRoutine_GetWaterDepth(Ground* g);
void cHumanCollisionRoutine_GetFloorContactPoint(V* hit, Ground* g, unsigned char* ok, int n, float r);
Mat* cCollisionModel_FaceProperties_GetMaterialProperties(void* ref);
char* cString_CStr(void* p);
#if 0 /* merge_units */
void cSndFx_ctor_int_charP_cGOBJP_int(SReq* r, int a, char* b, int c, int d);
#endif /* merge_units */
#define cSndFx_ctor_int_charP_cGOBJP_int(a0, a1, a2, a3, a4) (cSndFx_ctor_int_charP_cGOBJP_int((E4Req *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(SEv* e, SReq* r, V* pos);
#if 0 /* merge_units */
void cPlaySoundMsg_ctor_cSndFxR(SEv* e, SReq* r, Actor* a);
#endif /* merge_units */
#define cPlaySoundMsg_ctor_cSndFxR(a0, a1, a2) (cPlaySoundMsg_ctor_cSndFxR((E4Ev *)(a0), (E4Req *)(a1), (int)(a2))) /* merge_units */

#if 0 /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(SEv* e, char* tgt, int n);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((E4Ev *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
void cFileMan_dtor(SStr* s, int flag);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((E4Str *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cMessage_dtor(SEv* e, int flag);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((E4Ev *)(a0), (a1))) /* merge_units */

void cVector_Cross(V* out, const V* a, const V* b);
int cVector_IsZeroXYZ(const V* v);
void cVector_GetNormalized_void(V* out, const V* v);
V* cVector_Normalize_void(V* v);
void cVector_ctor_cVectorR(V* d, const V* s);
V* cVector_ctor_float_float_float_float(V* out, float x, float y, float z, float w);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, V* a, V* b, V* c, V* t);
void cMatrix_MakeLookAtMatrix_cVectorR(M* m, V* v);
void cMatrix_SetUnit(M* m);
void SfxParticleEffect_int_cMatrixR(int id, M* m);
}
static inline GB* GetB(Ground* g) { return (GB*)((char*)g + 0x100); }
static inline MatSub* Sub(Mat* m, unsigned char i) { return &m->e[i]; }
static inline bool Crouched(Actor* a) { return (a->flags >> 4) & 1; }
static inline void FrameFromNormal(M* m, V* n)
{
    V up(0.0f, 0.0f, 1.0f, 0.0f);
    V c;
    cVector_Cross(&c, n, &up);
    if (!cVector_IsZeroXYZ(&c)) {
        V b;
        V a;
        V d;
        V t;
        cVector_GetNormalized_void(&b, n);
        cVector_ctor_cVectorR(&a, cVector_Normalize_void(&c));
        cVector_Cross(&d, &a, &b);
        cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &a, &b, &d, cVector_ctor_float_float_float_float(&t, 0.0f, 0.0f, 0.0f, 1.0f));
    } else if (!cVector_IsZeroXYZ(n)) {
        cMatrix_MakeLookAtMatrix_cVectorR(m, n);
    } else {
        cMatrix_SetUnit(m);
    }
}
extern "C" void cHuman_HandleFootstepEvent(Actor* a, unsigned char mode, int force)
{
    if (a->g == 0)
        return;
    unsigned char water = a->g->fE4 != g_NegFltMax;
    float depth = cHumanCollisionRoutine_GetWaterDepth(a->g);
    if (!water) {
        V hit;
        unsigned char ok;
        int n;
        if (mode == 1)
            n = 1;
        else
            n = 2;
        cHumanCollisionRoutine_GetFloorContactPoint(&hit, a->g, &ok, n, 2.25f);
        if (ok) {
            Mat* mat = cCollisionModel_FaceProperties_GetMaterialProperties(GetB(a->g)->ref);
            int idx = Crouched(a) ? 4 : 1;
            int snd = mat->e[(unsigned char)idx].snd;
            if (snd != -1) {
                if (snd != -2) {
                int f = a->flags;
                char* nm;
                if (((f >> 2) & 1) || ((f >> 1) & 1) || ((f >> 4) & 1) || a->state == 0x15 || force) {
                    nm = cString_CStr(Sub(mat, idx)->name);
                } else {
                    snd = 1;
                    nm = D_0049D920;
                }
                SReq req;
                SEv ev;
                cSndFx_ctor_int_charP_cGOBJP_int(&req, snd, nm, 0, 0);
                cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&ev, &req, &hit);
                ev.flag = 1;
                QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
                ev.vt = D_004DAE30;
                cFileMan_dtor(&ev.s114, -1);
                cFileMan_dtor(&ev.s78, -1);
                cMessage_dtor(&ev, 0);
                cFileMan_dtor(&req.sE4, -1);
                cFileMan_dtor(&req.s48, -1);
                }
            } else {
                int f = a->flags;
                int k;
                char* nm;
                if (((f >> 2) & 1) || ((f >> 1) & 1) || a->state == 0x15 || force) {
                    k = 0;
                    nm = D_0049D928;
                } else {
                    k = 1;
                    nm = D_0049D920;
                }
                SReq req;
                SEv ev;
                cSndFx_ctor_int_charP_cGOBJP_int(&req, k, nm, 0, 0);
                cPlaySoundMsg_ctor_cSndFxR(&ev, &req, a);
                ev.flag = 1;
                QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
                ev.vt = D_004DAE30;
                cFileMan_dtor(&ev.s114, -1);
                cFileMan_dtor(&ev.s78, -1);
                cMessage_dtor(&ev, 0);
                cFileMan_dtor(&req.sE4, -1);
                cFileMan_dtor(&req.s48, -1);
            }
            int fx = mat->e[(unsigned char)idx].fx;
            if (fx != -1 && fx != -2) {
                V* src;
                if (a->g) {
                    src = &a->g->n;
                } else {
                    if (!D_004E1D88) {
                        D_004E1D90.x = 0.0f;
                        D_004E1D90.y = 0.0f;
                        D_004E1D90.z = 0.0f;
                        D_004E1D90.w = 0.0f;
                        D_004E1D88 = 1;
                    }
                    src = &D_004E1D90;
                }
                V nrm = *src;
                M m;
                FrameFromNormal(&m, &nrm);
                m.t = hit;
                SfxParticleEffect_int_cMatrixR(fx, &m);
            }
        }
    }
    if (water) {
        char* nm;
        if (!(depth <= D_0049CF40))
            nm = D_0049D938;
        else if (!(depth <= D_0049CF38))
            nm = D_0049D950;
        else
            nm = D_0049D960;
        SReq req;
        SEv ev;
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, nm, 0, 0);
        cPlaySoundMsg_ctor_cSndFxR(&ev, &req, a);
        ev.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
        ev.vt = D_004DAE30;
        cFileMan_dtor(&ev.s114, -1);
        cFileMan_dtor(&ev.s78, -1);
        cMessage_dtor(&ev, 0);
        cFileMan_dtor(&req.sE4, -1);
        cFileMan_dtor(&req.s48, -1);
    }
}
#undef cSndFx_ctor_int_charP_cGOBJP_int /* merge_units */
#undef cPlaySoundMsg_ctor_cSndFxR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00188FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00188FB0 */
