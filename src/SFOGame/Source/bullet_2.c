/*
 * SFOGame/Source/bullet: 6 files, 002756E0-00277E20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002756E0 */
#pragma push /* merge_units */
#include "bullet_types.h"
extern void std_vector_pod_int_resize(PtrVec* v, int n, int* fill);
#pragma opt_strength_reduction off
/* Removes every occurrence of 'value' from owner->list (swap with the last element), then shrinks it. */
void cBullet_RemoveBlastSibling(BulletOwner* owner, int value) {
    int i;
    int last = owner->list.count - 1;
    int fill;
    for (i = 0; last >= i; i++) {
        int* e = &owner->list.data[i];
        if (*e == value) {
            *e = owner->list.data[last];
            last--;
        }
    }
    fill = 0;
    std_vector_pod_int_resize(&owner->list, last + 1, &fill);
}
#pragma opt_strength_reduction reset
static inline void merge_flush_func_002756E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002756E0 */

/* merge_units: begin func_00275750 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int* value);
extern int std_vector_cBulletPtr_push_back(PtrVec* v, int* value);

/* Appends 'value' to the list at +0x78. */
void cBullet_AddBlastSibling(BulletOwner* owner, int value) {
    int tmp[1];

    tmp[0] = value;
    std_vector_cBulletPtr_push_back(&owner->list, tmp);
}

/* push_back(v, *value): std_vector_pod_int_insert at the end */
int std_vector_cBulletPtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_00275750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00275750 */

/* merge_units: begin func_002757A0 */
#pragma push /* merge_units */
/* cBullet_Render (BulletPool bullet draw) - mw38 MATCH. First OpM site (b->dir * b->len) uses a
   per-site gcc-style helper (OpM2) whose asm operand order (pa, pr, s) fixes src/dst colouring. */
#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_rotateloops off
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& s) { void* d = this; __int128 q; __asm__ volatile("lq %1, 0(%2); sq %1, 0(%0)" : "+r"(d), "=&r"(q) : "r"(&s) : "memory"); }
} __attribute__((aligned(16)));

static inline void OpM(V4* pr, const V4* pa, float s)
{
    const V4* a_ = pa;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a_)
        mfc1 t, s
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(pr)
        .set reorder
    }
}
static inline V4 operator*(const V4& a, float s)
{
    V4 r;
    OpM(&r, &a, s);
    return r;
}
static inline void OpS(V4* pr, const V4* pa, const V4* pb)
{
    const V4* a_ = pa;
    const V4* b_ = pb;
    asm {
        lqc2 vf1, 0x0(a_)
        lqc2 vf2, 0x0(b_)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
}
static inline void OpM2(V4* pr, const V4* pa, float s) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%2); .set reorder" : "=&r"(t) : "r"(pa), "r"(pr), "f"(s) : "memory"); }
static inline V4 Mul2(const V4& a, float s) { V4 r; OpM2(&r, &a, s); return r; }
static inline V4 operator-(const V4& a, const V4& b)
{
    V4 r;
    OpS(&r, &a, &b);
    return r;
}
static inline void OpA(V4* pr, const V4* pa, const V4* pb)
{
    const V4* a_ = pa;
    const V4* b_ = pb;
    asm {
        lqc2 vf1, 0x0(a_)
        lqc2 vf2, 0x0(b_)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(pr)
    }
}
static inline V4 operator+(const V4& a, const V4& b)
{
    V4 r;
    OpA(&r, &a, &b);
    return r;
}

typedef struct Rec_002757A0 { char pad[0x80]; int v[12]; char pad2[0xC0 - 0xB0]; } Rec_002757A0;
typedef struct Ent_002757A0 {
    char pad[0x24];
    Rec_002757A0* recs;
    V4* pos;
    V4* c2C;
    V4* c30;
    V4* c34;
} Ent_002757A0;
typedef struct EntB_002757A0 { char pad[0x34]; Rec_002757A0* recs; } EntB_002757A0;
typedef struct S_002757A0 { char pad[0xFA0]; EntB_002757A0 ent[1]; } S_002757A0;
typedef struct Rs_002757A0 {
    char pad[0xFB0];
    Ent_002757A0 ents[1];
} Rs_002757A0;
typedef struct Bullet_002757A0 {
    char pad0[0x20];
    char f20[0x10];
    V4 dir;
    char pad40[0x10];
    V4 pos;
    char pad60[0x110 - 0x60];
    int f110;
    char pad114;
    unsigned char f115;
    unsigned char f116;
    char pad117[0x11C - 0x117];
    int tex;
    V4 side0;
    V4 side1;
    int uv;
    float len;
} Bullet_002757A0;

extern "C" {
typedef struct G_002757A0 {
    int f10; int pad14[3]; int f20; int f24; int f28; int* f2C; int f30; int f34; int f38; int f3C; int pad40[2]; void* f48; int pad4C[33]; int fD0; int padD4; long long fD8;
} G_002757A0;
extern G_002757A0 D_00539210;
extern char g_Video[];
extern long long D_005381F8;
extern V4 D_004A90A0[];
void cParticle_Render(int h, int k, void* p);
void cTexMan_SetActive(void* m, int idx);
void XLib_NewStrip(void* s);
void XLib_NextBatchVert(void* s);
#if 0 /* merge_units */
void cVector_opAssign(V4* d, const V4* s);
#endif /* merge_units */
void cVector_opAssign(void* d, const void* s); /* merge_units */
#define cVector_opAssign(a0, a1) (cVector_opAssign((void *)(a0), (const void *)(a1))) /* merge_units */

void tIRGBA_opAssign_tRGBAR(V4* d, const V4* s);
float tVifFloatToInt_short_4_Bias(void);
#if 0 /* merge_units */
V4* cVector_ctor_float_float_float_float(V4* o, float x, float y, float z, float w);
#endif /* merge_units */
void* cVector_ctor_float_float_float_float(void*, float, float, float, float); /* merge_units */
#define cVector_ctor_float_float_float_float(a0, a1, a2, a3, a4) ((V4 *)cVector_ctor_float_float_float_float((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

void XLib_DrawStrip(void* s);
}
#define D_00539220 (D_00539210.f20)
#define D_00539224 (D_00539210.f24)
#define D_00539228 (D_00539210.f28)
#define D_0053922C (D_00539210.f2C)
#define D_00539230 (D_00539210.f30)
#define D_00539234 (D_00539210.f34)
#define D_00539238 (D_00539210.f38)
#define D_0053923C (D_00539210.f3C)
#define g_TextureMgr (D_00539210.f48)
#define g_DrawMode (D_00539210.fD0)

#define RS_002757A0 ((Rs_002757A0*)g_Video)

struct V4c_002757A0 {
    float x, y, z, w;
    V4c_002757A0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};
static inline V4* UV_002757A0(const V4& uv)
{
    V4 tmp;
    float u = uv.x + tVifFloatToInt_short_4_Bias();
    return cVector_ctor_float_float_float_float(&tmp, u, uv.y + tVifFloatToInt_short_4_Bias(), uv.z, uv.w);
}
static inline void Emit_002757A0(const V4& pos, const V4c_002757A0& col, const V4& uv)
{
    Ent_002757A0* e;
    XLib_NextBatchVert(g_Video);
    e = &RS_002757A0->ents[D_00539210.f10];
    cVector_opAssign(&e->pos[D_00539224 - 1], &pos);
    tIRGBA_opAssign_tRGBAR(&e->c30[D_00539224 - 1], (V4*)&col);
    cVector_opAssign(&e->c34[D_00539224 - 1], UV_002757A0(uv));
    D_005381F8 = 6LL << 32;
}
static inline unsigned char Prim_002757A0(void) { if (g_DrawMode & 1) return 3; return 2; }
static inline int Mode_002757A0(void) { if (g_DrawMode & 1) return 0x41; return 0x62; }

static inline void Restart_002757A0(void)
{
    if (D_00539220 > 0) {
        if (D_00539230 > 0) {
            int k = D_00539220 - 1;
            if (D_00539234 < 12) {
                Ent_002757A0* e = &RS_002757A0->ents[D_00539210.f10]; int v = D_00539238 - 1 + D_00539230 * D_00539238; e->recs[k].v[D_00539234] = v;
                D_00539234++;
            } else {
                if (D_00539220 > 0) D_0053922C[D_00539220 - 1] = D_00539230;
                { int v; int j; Rec_002757A0* s; v = D_00539238 - 1; s = ((Rec_002757A0**)(g_Video + 0xFD4))[D_00539210.f10 * 14] + D_00539220; j = 0; for (; j < 12; j++) s->v[j] = v; }
                D_00539230 = 0;
                D_00539234 = 0;
                D_00539228++;
                D_00539220++;
            }
        }
    }
}

extern "C" void cBullet_Render(Bullet_002757A0* b)
{
    if (b->f115 && b->f110) cParticle_Render(b->f110, 2, b->f20);
    if (b->f116 && b->f110 == 0) {
        V4* pos = &b->pos;
        V4 tail = *pos - Mul2(b->dir, b->len);
        __int128 z0 = 0;
        V4 u = b->side0 * 0.3f;
        __int128 z1 = 0;
        V4 w = b->side1 * 0.3f;
        V4 p0 = *pos + u;
        V4 p1 = *pos - u;
        V4 p2 = tail + u;
        V4 p3 = tail - u;
        V4 p4 = *pos + w;
        V4 p5 = *pos - w;
        V4 p6 = tail + w;
        V4 p7 = tail - w;
        V4c_002757A0 c1(1.0f, 1.0f, 1.0f, 1.0f);
        V4c_002757A0 c2(1.0f, 1.0f, 1.0f, 0.5f);
        Ent_002757A0* e;
        int saved = g_DrawMode;
        g_DrawMode = 5;
        cTexMan_SetActive(g_TextureMgr, b->tex);
        D_00539238 = Prim_002757A0();
        D_0053923C = Mode_002757A0();
        D_00539228 = 0;
        D_0053923C &= ~1;
        e = &RS_002757A0->ents[D_00539210.f10];
        e->pos += D_00539224;
        e->c2C += D_00539224;
        e->c30 += D_00539224;
        e->c34 += D_00539224;
        XLib_NewStrip(g_Video);
        D_00539224 = 0;
        Emit_002757A0(p0, c1, D_004A90A0[b->uv]);
        Emit_002757A0(p1, c1, D_004A90A0[b->uv + 1]);
        Emit_002757A0(p2, c2, D_004A90A0[b->uv + 2]);
        Emit_002757A0(p3, c2, D_004A90A0[b->uv + 3]);
        Restart_002757A0();
        Emit_002757A0(p4, c1, D_004A90A0[b->uv]);
        Emit_002757A0(p5, c1, D_004A90A0[b->uv + 1]);
        Emit_002757A0(p6, c2, D_004A90A0[b->uv + 2]);
        Emit_002757A0(p7, c2, D_004A90A0[b->uv + 3]);
        XLib_DrawStrip(g_Video);
        g_DrawMode = saved;
    }
}
#undef cVector_opAssign /* merge_units */
#undef cVector_ctor_float_float_float_float /* merge_units */
static inline void merge_flush_func_002757A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002757A0 */

/* merge_units: begin func_00276460 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "alloc_guard.h"
#pragma inline_depth(8)
#pragma opt_propagation off

/* 16-byte vector: lq/sq copy idiom (asm keeps lq unfolded); VU0 ops as COP2 asm; .set noreorder in the scale op only drops the mfc1->qmtc2 hazard nop. */
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    V& operator=(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    V operator-(const V& o) const { V r; const V* tp = this; V* rp = &r; const V* op = &o; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(rp), "r"(tp), "r"(op) : "memory"); return r; }
    V Mul2(float k) const { V r; __int128 t = 0; const V* tp = this; V* rp = &r; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); return r; }
    V operator*(float k) const { V r; V* rp = &r; const V* tp = this; __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); return r; }
    V& operator+=(V o) { V* d = this; V* a = this; V* b = &o; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(a), "r"(b), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct BM { V r0, r1, r2, r3; };
union M { __int128 q[4]; float f[16]; V& R(int i) { return *(V*)&f[i * 4]; } };

static inline float Dot3(const V* a, const V* b) { int t; float r = 0.0f; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $zero, 0x6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a), "r"(b) : "memory"); return r; }
static inline void Neg(V* v) { V* d = v; V* s = v; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(s), "r"(d) : "memory"); }
static inline void Rot3(V* v, const M* m) { __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(v), "r"(m), "r"(v) : "memory"); }
static inline void Translate(M* m, const V* s) { __asm__ volatile("lqc2 $vf1, 0x30(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x30(%0)" : : "r"(m), "r"(s) : "memory"); }

struct Obj;
struct Sub { VPAD16(a) VPAD2(b) VPAD1(c) virtual int F54(); };
struct Obj {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual void Hit(Obj* src, int one, signed char kind, int a, int b, int c, float dmg);
    char pad4[8];
    int serial;
    char pad10[4];
    unsigned char b14;
    char pad15[0x4C - 0x15];
    int team;
    char pad50[8];
    Sub* sub;
};

struct H { Obj* p; int serial; };

static inline bool IEq(int a, int b) { return a == b; }
static inline bool HValid(H* h) { return !h->p || IEq(h->p->serial, h->serial); }
static inline Obj* HGet(H* h) { return HValid(h) ? h->p : 0; }

struct Type {
    char pad0[0x34];
    int t34; int t38; int t3C;
    char pad40[0x24];
    int d64; int d68; int d6C;
    char pad70[0xBC - 0x70];
    unsigned char kind;
    char padBD[0xC4 - 0xBD];
    float rC4; float rC8;
    char padCC[0xD8 - 0xCC];
    int fxD8;
    char padDC[0xF0 - 0xDC];
    unsigned char cls;
    char padF1[0xFC - 0xF1];
    float noise;
    int DamageAt(float t)
    {
        int d = d68;
        if (t > (float)t34) {
            float c, b, a;
            if (t > (float)t38) { c = (float)(d6C - d64); b = (float)(t3C - t38); a = t - (float)t38; }
            else if (t > (float)t34) { c = (float)(d64 - d68); b = (float)(t38 - t34); a = t - (float)t34; }
            d = (int)((float)d + c * a / b);
        }
        return d;
    }
};

struct Emitter { char pad0[0x1C]; int busy; char pad20[0x4A]; unsigned char b6A; };

struct Bullet {
    float age;
    float speed;
    float range;
    int id;
    int n10;
    char pad14[0xC];
    V m0, m1, m2, m3;
    H h60;
    H h68;
    H h70;
    char pad78[4];
    int count;
    Bullet** list;
    char pad84[0x3C];
    V normal;
    char matref[0x30];
    V pos;
    Emitter* emitter;
    unsigned char b114;
    unsigned char b115;
    unsigned char active;
    char pad117;
    unsigned char b118;
    unsigned char b119;
    char pad11A[0x2E];
    Type* type;
};

struct Query {
    Obj* owner;
    M* mtx;
    Obj* other;
    unsigned char b5C, b5D;
    int id;
    float step;
    Type* type;
    float age;
    unsigned char b70;
    int n74;
    float f78;
    unsigned char b7C, b7D;
    int kind;
    float hitStep;
    Obj* hit;
    Query() { id = -1; b70 = 0; age = 0.0f; b7C = 1; b7D = 1; b5C = 0; other = 0; n74 = 0; }
};

struct MatEntry { int fx; int snd; char name[0x18]; int fx2; float scale; unsigned char size; char pad[0xF]; };
struct Material { char pad[0x18]; MatEntry e[4]; };

typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SoundRequest;

typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
} SoundMsg;

struct S3 { signed char c[3]; };

extern "C" {
extern int D_0048B340;
extern float D_0048B330;
extern float D_0048B338;
extern float D_0048B348;
extern float D_0048B318;
extern float D_0048B320;
extern float D_0048B328;
extern S3 D_0048B350;
extern int g_HumanActorClassKey[];
extern signed char D_004E1DA0;
extern signed char D_004E1DA8;
extern V D_00497F20;
extern V D_00497F30;
extern char g_Game[];
extern char D_004EE5C0[];
extern SoundRequest D_004EF590;
extern char D_004D92A0[];
extern char D_004DAE30[];
extern char D_004A91A0[];
extern char D_004A91B0[];
extern void* g_DecalMgr;
void cParticle_SetScale(Emitter* e, float r);
void cParticle_NextFrame(Emitter* e, float dt, M* m, int z);
void cParticle_dtor(Emitter* e, int f);
void CheckBulletCollisions(Query* q);
Material* cCollisionModel_FaceProperties_GetMaterialProperties(void* ref);
const char* cString_CStr(void* s);
void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, const char* name, int a, int b);
void cPlaySoundMsg_ctor_cSndFxR_cGOBJP(SoundMsg* msg, SoundRequest* req, V* pos);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
#if 0 /* merge_units */
V* cVector_ctor_float_float_float_float(V* v, float x, float y, float z, float w);
#endif /* merge_units */
#define cVector_ctor_float_float_float_float(a0, a1, a2, a3, a4) ((V *)cVector_ctor_float_float_float_float((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */


float cVector_Z_void(V* v);
float Math_Fabs(float f);
void cVector_GetNormalized_void(V* out, V* in);
void cVector_Cross(V* out, V* a, V* b);
V* cVector_Normalize_void(V* v);
#if 0 /* merge_units */
void cVector_ctor_cVectorR(V* d, V* s);
#endif /* merge_units */
void cVector_ctor_cVectorR(void* d, const void* s); /* merge_units */
#define cVector_ctor_cVectorR(a0, a1) (cVector_ctor_cVectorR((void *)(a0), (const void *)(a1))) /* merge_units */

void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M* m, V* a, V* b, V* c, V* t);
void SfxParticleEffect_int_cMatrixR(int id, void* m);
void SfxParticleEffect_eEffectName_cMatrixR(int id, void* m);
void cDecalMan_AddDecal(void* r, M* m, int id, signed char size, Obj* o, float f);
int* nSfxLoader_GetHandle(int id);
void* cSystemContainer_GetSystem(void* a, void* b);
void cAISoundSystemGOBJPositionMessage_ctor(void* msg, float a, float b, int* id, V* pos, signed char kind);
void cDecalMan_AddProjectedDecal(void* r, V* p, int id, int z, float f);
void Blast_Prepare(Obj* o, int a, int b, V* p, int c, int d, float e, float f, float g);
char* cGameSystem_GetAgentData(void* list, int idx);
void cAgentData_AddScore(char* agent, int stat, int n);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cAreaEffect_ctor(void* self, Obj* o, V pos, Type* t, int f);
#if 0 /* merge_units */
void cBullet_RemoveBlastSibling(Bullet* b, Bullet* self);
#endif /* merge_units */
#define cBullet_RemoveBlastSibling(a0, a1) (cBullet_RemoveBlastSibling((BulletOwner *)(a0), (int)(a1))) /* merge_units */


}

struct AiMsg {
    void* vt; char d[0x4C];
    AiMsg(float a, float b, int* id, V* pos, signed char k) { cAISoundSystemGOBJPositionMessage_ctor(this, a, b, id, pos, k); }
    AiMsg() {}
    inline AiMsg& Init(struct Bullet* s);
    void Send(void* to) { QueueMessage_cMessageR_cSystemP_int(this, to, 0); }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~AiMsg() { vt = D_004D92A0; cMessage_dtor(this, 0); }
};

struct AreaEffect {
    char d[0xE0];
    AreaEffect(Obj* o, const V& p, Type* t) { cAreaEffect_ctor(this, o, p, t, 1); }
    static void* operator new(unsigned int sz, int line)
    {
        void* p;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        p = cMemMan_Allocate(0, sz, D_004A91A0, line);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        return p;
    }
};

static inline void BuildFrame(M* m, V* n, V* ref) { V up; V right; V fwd; V c1; V t0; cVector_GetNormalized_void(&up, n); cVector_Cross(&c1, n, ref); cVector_ctor_cVectorR(&right, cVector_Normalize_void(&c1)); cVector_Cross(&fwd, &right, &up); cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(m, &right, &up, &fwd, cVector_ctor_float_float_float_float(&t0, 0.0f, 0.0f, 0.0f, 1.0f)); }
static inline void BF2(M* m, V* n, V* ref) { BuildFrame(m, n, ref); }
static inline void BF3(M* m, V* n, V* ref) { BF2(m, n, ref); }
static inline void BF4(M* m, V* n, V* ref) { BF3(m, n, ref); }
static inline bool HasCtl(Obj* o) { bool r = false; Sub* s = o->sub; if (s && s->F54()) r = true; return r; }

static inline void BF2(M* m, V* n, V* ref);
#pragma enumsalwaysint off
enum MI { MI0, MI1, MI2, MI3 };
#pragma enumsalwaysint reset
static inline float Pow(float b, int n) { float r = 1.0f; int i; for (i = 0; i < n; i++) r *= b; return r; }

static inline bool SameTeam(Obj* o) { int* p = g_HumanActorClassKey; int t = p[0]; return o->team == t; }
inline AiMsg& AiMsg::Init(Bullet* s) { cAISoundSystemGOBJPositionMessage_ctor(this, 1.0f, s->type->noise, &HGet(&s->h68)->serial, &s->pos, 4); return *this; }
static inline V Scl(V* d) { return *d * 0.2f; }
extern "C" void cBullet_Move(Bullet* s, float dt)
{
    if (s->emitter) {
        Type* ty = s->type;
        if (ty->cls == 8) {
            float r = 1.0f; float b = s->age / (float)ty->t3C; for (int i = 0; i < D_0048B340; i++) r *= b;
            cParticle_SetScale(s->emitter, D_0048B330 + r * (D_0048B338 - D_0048B330));
        }
        cParticle_NextFrame(s->emitter, dt, (M*)&s->m0, 0);
    }
    if (s->active) {
        float step = dt * s->speed;
        bool clamped = false;
        if (step > s->range) { step = s->range; clamped = true; }
        Query q;
        M qm;
        V p;
        if (HGet(&s->h68)) {
            q.owner = HGet(&s->h68);
            /* 64-byte matrix copy: documented lq/sq idiom */
            { M* d = &qm; __int128 qa, qb; M* sp = (M*)&s->m0; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(qa) : "r"(sp)); __asm__ volatile("lq %0, 0x10(%1)" : "=r"(qb) : "r"(sp)); d->q[0] = qa; __asm__ volatile("lq %0, 0x20(%1)" : "=r"(qa) : "r"(sp)); d->q[1] = qb; __asm__ volatile("lq %0, 0x30(%1)" : "=r"(qb) : "r"(sp)); d->q[2] = qa; d->q[3] = qb; }
            q.mtx = &qm;
            p = s->m3;
            p += s->m1.Mul2(D_0048B348);
            qm.R(3) = p;
            q.b5C = s->b114;
            q.b5D = s->b118;
            q.id = s->id;
            q.other = HGet(&s->h60);
            q.type = s->type;
            q.step = step;
            q.age = s->age;
            q.n74 = s->n10;
            q.f78 = 0.2f;
            q.b7C = s->b119;
            q.b7D = s->type->kind == 1;
            CheckBulletCollisions(&q);
            s->n10 = q.n74;
        } else {
            q.hit = 0;
        }
        step = q.hit ? q.hitStep : step;
        s->range -= step;
        s->age += step;
        V sv(0.0f, step, 0.0f, 0.0f);
        Rot3(&sv, (M*)&s->m0);
        V old = s->m3;
        Translate((M*)&s->m0, &sv);
        V delta = s->m3 - old;
        if (clamped && HGet(&s->h70) && !q.hit && s->type->kind != 4) {
            Material* mat = cCollisionModel_FaceProperties_GetMaterialProperties(s->matref);
            MI mi = MI0;
            if (s->type) {
                switch (*((unsigned char*)s->type + 0x48)) {
                case 2:
                    mi = MI2;
                    break;
                case 4:
                case 6:
                    mi = MI3;
                    break;
                }
            }
            {
                int snd = mat->e[mi].snd;
                bool fb = snd == -1 && mi != 0;
                if (fb) snd = mat->e[0].snd;
                if (snd != -1) {
                    if (snd != -2) {
                        SoundRequest req;
                        SoundMsg msg;
                        unsigned char j = fb ? 0 : mi;
                        cSndFx_ctor_int_charP_cGOBJP_int(&req, snd, cString_CStr(mat->e[j].name), 0, 0);
                        cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, &req, &s->pos);
                        msg.flag = 1;
                        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
                        msg.vtbl = D_004DAE30;
                        cFileMan_dtor(msg.partB, -1);
                        cFileMan_dtor(msg.partA, -1);
                        cMessage_dtor(&msg, 0);
                        cFileMan_dtor(req.partB, -1);
                        cFileMan_dtor(req.partA, -1);
                    }
                } else {
                    SoundMsg msg;
                    cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, &D_004EF590, &s->pos);
                    msg.flag = 1;
                    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
                    msg.vtbl = D_004DAE30;
                    cFileMan_dtor(msg.partB, -1);
                    cFileMan_dtor(msg.partA, -1);
                    cMessage_dtor(&msg, 0);
                }
            }
            {
                V n = s->normal;
                if (Dot3(&n, &delta) > 0.0f) Neg(&n);
                if (D_004E1DA0 == 0) { cVector_ctor_float_float_float_float(&D_00497F20, 1.0f, 0.0f, 0.0f, 0.0f); D_004E1DA0 = 1; }
                if (D_004E1DA8 == 0) { cVector_ctor_float_float_float_float(&D_00497F30, 0.0f, 0.0f, 1.0f, 0.0f); D_004E1DA8 = 1; }
                V* ref;
                if (Math_Fabs(cVector_Z_void(&n)) < 0.707f) ref = &D_00497F30;
                else ref = &D_00497F20;
                M m;
                BF4(&m, &n, ref);
                V p2 = s->pos;
                p2 += n * 0.08f;
                m.R(3) = p2;
                int fx = mat->e[mi].fx;
                if (fx == -1 && mi != 0) fx = mat->e[0].fx;
                if (fx != -1) {
                    if (fx != -2) SfxParticleEffect_int_cMatrixR(fx, &m);
                } else {
                    SfxParticleEffect_eEffectName_cMatrixR(4, &m);
                }
                int fx2 = mat->e[mi].fx2;
                if (fx2 == -1 && mi != 0) { mi = MI0; fx2 = mat->e[mi].fx2; }
                if (fx2 != -1) {
                    if (fx2 != -2) {
                        float sc = mat->e[mi].scale;
                        S3 sz = D_0048B350;
                        signed char z = sz.c[mat->e[mi].size];
                        cDecalMan_AddDecal(g_DecalMgr, &m, fx2, z, HGet(&s->h70), sc);
                    }
                } else {
                    int id = *nSfxLoader_GetHandle(0x24); cDecalMan_AddDecal(g_DecalMgr, &m, id, 8, HGet(&s->h70), 0.2f);
                }
            }
            if (HGet(&s->h68)) {
                void* svc = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
                AiMsg().Init(s).Send(svc);
                Obj* tgt = HGet(&s->h70);
                Obj* src = HGet(&s->h68);
                int dmg = s->type->DamageAt(s->age);
                tgt->Hit(src, 1, s->type->kind, 0, 0, 0, (float)dmg);
            }
        }
        if (q.hit || (HGet(&s->h70) && clamped)) {
            if (s->type->kind != 4) {
                if (q.hit && q.kind == 2 && HGet(&s->h70) && s->type->kind != 7 && s->range < D_0048B318 && SameTeam(q.hit)) {
                    int id = *nSfxLoader_GetHandle(0x26);
                    if (id > -1) {
                        V a = s->pos; int z = 0;
                        V d = s->m3 - s->pos;
                        a += Scl(&d);
                        cDecalMan_AddProjectedDecal(g_DecalMgr, &a, id, z, D_0048B320);
                    }
                }
                if (s->type->rC4 > 0.0f) {
                    if (s->type->fxD8 != -1) SfxParticleEffect_int_cMatrixR(s->type->fxD8, (M*)&s->m0);
                    V a; a = s->pos;
                    a += s->m1.Mul2(D_0048B348);
                    V b = a;
                    Blast_Prepare(HGet(&s->h68), s->type->d64, 1, &b, 0, 1, 1.0f, s->type->rC4, s->type->rC8);
                    int id = *nSfxLoader_GetHandle(0x25);
                    if (id > -1) { int z = 0; cDecalMan_AddProjectedDecal(g_DecalMgr, &a, id, z, D_0048B328); }
                }
            }
        }
        if (q.hit || clamped) {
            unsigned char c = s->type->cls;
            if (c == 9 || (c == 8 && (q.hit || HGet(&s->h70)))) {
                if (s->type->fxD8 != -1) SfxParticleEffect_int_cMatrixR(s->type->fxD8, (M*)&s->m0);
                if (q.hit) {
                    if (HasCtl(HGet(&s->h68)) && HGet(&s->h68)->b14 && s->type->cls == 9 && !HasCtl(q.hit) && SameTeam(q.hit))
                        cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 0xA, 1);
                }
                AreaEffect* ae = (AreaEffect*)AreaEffect::operator new(0xE0, 0x1F5); if (ae) cAreaEffect_ctor(ae, HGet(&s->h68), s->m3, s->type, 1);
                V b; b = s->m3;
                Blast_Prepare(HGet(&s->h68), 1, 1, &b, 1, 1, 0.0f, 10.0f, 10.0f);
                if (s->type->cls == 9) {
                    SoundRequest req;
                    SoundMsg msg;
                    cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, D_004A91B0, 0, 0);
                    cPlaySoundMsg_ctor_cSndFxR_cGOBJP(&msg, &req, &s->pos);
                    msg.flag = 1;
                    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
                    msg.vtbl = D_004DAE30;
                    cFileMan_dtor(msg.partB, -1);
                    cFileMan_dtor(msg.partA, -1);
                    cMessage_dtor(&msg, 0);
                    cFileMan_dtor(req.partB, -1);
                    cFileMan_dtor(req.partA, -1);
                }
            }
            if (q.hit && s->b119) {
                int i;
                for (i = 0; i < s->count; i++) s->list[i]->b119 = 0;
            }
            s->active = 0;
            if (s->emitter) s->emitter->b6A = 1;
        }
    } else {
        Emitter* e = s->emitter;
        if (e) {
            if (e->busy == 0) {
                {
                    AllocGuard g;
                    cParticle_dtor(e, -1);
                    cMemMan_Deallocate(0, e, D_004A91A0, 0x216);
                }
                s->emitter = 0;
            }
        } else {
            int i;
            s->b115 = 0;
            for (i = 0; i < s->count; i++) cBullet_RemoveBlastSibling(s->list[i], s);
        }
    }
}
#undef cVector_ctor_float_float_float_float /* merge_units */
#undef cVector_ctor_cVectorR /* merge_units */
#undef cBullet_RemoveBlastSibling /* merge_units */
static inline void merge_flush_func_00276460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00276460 */

/* merge_units: begin func_00277AA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* cBullet_InitBullet: fills a pooled bullet from a fire request (frame,
 * owner/target handles, hit triangle copy, type), creates its tracer when the
 * type has one, and builds the two streak side vectors from the bullet's
 * forward axis. Request layout as in cBulletManager_AddBullet (cBulletManager_AddBullet.c). */
struct V_00277AA0 {
    float x, y, z, w;
    V_00277AA0() {}
    V_00277AA0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_00277AA0(const V_00277AA0& o) { const V_00277AA0* s = &o; V_00277AA0* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V_00277AA0& operator=(const V_00277AA0& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct VP { float x, y, z, w; } __attribute__((aligned(16)));
struct Mtx { VP r[4]; Mtx& operator=(const Mtx& o) { void* d = this; __int128 qa; __int128 qb; const void* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; } };
struct Sub40 { char b[0x10]; };
struct Sub60 { char b[0x10]; };
struct Tracked { char pad[0xC]; int serial; };
struct TrCopy {
    VP v[4];
    Sub40 s40;
    unsigned char b50, b51, b52; char p53[0xD];
    Sub60 s60;
};
struct Type_00277AA0 { char pad[0xF8]; int fxF8; char padFC[0x134 - 0xFC]; int tracer; };
struct Req {
    Mtx m;
    float f40;
    Tracked* f44;
    Tracked* f48;
    Tracked* f4C;
    TrCopy tr;
    VP hit;
    int fD0;
    unsigned char fD4, fD5, fD6;
    float fD8;
    Type_00277AA0* fDC;
    int fE0;
    float fE4;
};
struct H_00277AA0 { Tracked* p; int serial; };
struct Bullet_00277AA0 {
    float age;
    float speed;
    float range;
    int id;
    int fx;
    char pad14[0xC];
    Mtx m;
    H_00277AA0 h60;
    H_00277AA0 h68;
    H_00277AA0 h70;
    char pad78[4];
    int count;
    char pad80[0x10];
    TrCopy tr;
    V_00277AA0 hit;
    void* emitter;
    unsigned char b114, b115, active, b117, b118, b119;
    char pad11A[2];
    int tex;
    V_00277AA0 side0;
    V_00277AA0 side1;
    int uv;
    float len;
    Type_00277AA0* type;
};
extern "C" {
extern int D_00504038;
void* cParticle_ctor(void* p, int id, Mtx* m, float scale);
void cVector_opAssign(void* d, const void* s);
void cCollisionModel_FaceProperties_opAssign(void* d, const void* s);
void cCollisionModel_FaceLocator_opAssign(void* d, const void* s);
void cBullet_InitBullet(Bullet_00277AA0* b, Req* r);
}
static inline const int& IdOf(Tracked* p) { if (p) return p->serial; int m = -1; return m; }
static inline void SetH(H_00277AA0* h, Tracked* p) { h->p = p; h->serial = IdOf(p); }
static inline void Crs(V_00277AA0* d, const V_00277AA0* l, const V_00277AA0* r) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory"); }
static inline V_00277AA0 Cross(const V_00277AA0& a, const V_00277AA0& b) { V_00277AA0 r; Crs(&r, &a, &b); return r; }
static inline void* NewTracer(int line)
{
    void* p;
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, 0x70, D_004A91A0, line);
    }
    return p;
}

void cBullet_InitBullet(Bullet_00277AA0* b, Req* r)
{
    b->m = r->m;
    b->speed = r->f40;
    SetH(&b->h60, r->f48);
    SetH(&b->h68, r->f44);
    b->b114 = r->fD4;
    b->b118 = r->fD5;
    b->id = r->fD0;
    b->active = 1;
    b->b115 = 1;
    SetH(&b->h70, r->f4C);
    cVector_opAssign(&b->tr.v[0], &r->tr.v[0]);
    cVector_opAssign(&b->tr.v[1], &r->tr.v[1]);
    cVector_opAssign(&b->tr.v[2], &r->tr.v[2]);
    cVector_opAssign(&b->tr.v[3], &r->tr.v[3]);
    b->tr.b50 = r->tr.b50;
    cCollisionModel_FaceProperties_opAssign(&b->tr.s40, &r->tr.s40);
    cCollisionModel_FaceLocator_opAssign(&b->tr.s60, &r->tr.s60);
    b->tr.b51 = r->tr.b51;
    b->tr.b52 = r->tr.b52;
    b->hit = *(V_00277AA0*)&r->hit;
    b->b117 = r->fD6;
    b->type = r->fDC;
    b->range = r->fD8;
    b->age = 0.0f;
    b->fx = b->type->fxF8;
    b->b119 = 1;
    b->count = 0;
    if (b->type->tracer > -1) {
        void* p = NewTracer(0xE0);
        if (p) p = cParticle_ctor(p, b->type->tracer, &b->m, r->fE4);
        b->emitter = p;
    } else {
        b->emitter = 0;
    }
    b->tex = *nSfxLoader_GetHandle(26);
    {
        V_00277AA0 fwd = *(V_00277AA0*)&b->m.r[1];
        b->side0 = Cross(fwd, V_00277AA0(0.0f, 0.0f, 1.0f, 0.0f));
        b->side1 = Cross(fwd, b->side0);
    }
    b->uv = D_00504038;
    b->len = 8.0f;
    D_00504038 += 4;
    if (D_00504038 == 16)
        D_00504038 = 0;
}
static inline void merge_flush_func_00277AA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00277AA0 */

/* merge_units: begin func_00277E20 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
struct V_00277E20;

extern "C" {
extern char g_LosCheckService[];
extern char D_00504030[];
int cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(void* mgr, V_00277E20* a, struct LosHit* b, V_00277E20* c, V_00277E20 d, int e1, void* e2, int g, unsigned char h, unsigned char i, void* j, unsigned char k);
void cMatrix_ctor_cMatrixR(void* d, const void* s);
void cCollisionFace_ctor_cCollisionFaceR(void* d, const void* s);
void cVector_ctor_cVectorR(void* d, const void* s);
#if 0 /* merge_units */
void cVector_opAssign(V_00277E20* d, const V_00277E20* s);
#endif /* merge_units */
#define cVector_opAssign(a0, a1) (cVector_opAssign((void *)(a0), (const void *)(a1))) /* merge_units */

#if 0 /* merge_units */
void cBullet_InitBullet(struct Bullet_00277E20* b, struct Req_00277E20* r);
#endif /* merge_units */
#define cBullet_InitBullet(a0, a1) (cBullet_InitBullet((Bullet_00277AA0 *)(a0), (Req *)(a1))) /* merge_units */

struct Bullet_00277E20* cBulletManager_AddBullet(struct Req_00277E20* req);
}
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V_00277E20* rp, const V_00277E20* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%1); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%2); .set reorder" : "+r"(t) : "r"(tp), "r"(rp), "f"(k) : "memory"); }
static inline void AddV(V_00277E20* d, V_00277E20* a, V_00277E20* b);
static inline void SubV(V_00277E20* d, const V_00277E20* a, const V_00277E20* b) { __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(b), "r"(d), "r"(a) : "memory"); }
struct V_00277E20 {
    float x, y, z, w;
    V_00277E20() {}
    // 128-bit lq/sq quadword copy idiom
    V_00277E20(const V_00277E20& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // 128-bit lq/sq quadword copy idiom
    V_00277E20& operator=(const V_00277E20& o) { __int128* d = (__int128*)this; const __int128* s = (const __int128*)&o; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; return *this; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V_00277E20 operator-(const V_00277E20& o) const { V_00277E20 r; SubV(&r, this, &o); return r; }
    V_00277E20 operator*(float k) const { V_00277E20 r; ScaleV(&r, this, k); return r; }
    V_00277E20& operator+=(V_00277E20 o) { AddV(this, this, &o); return *this; }
} __attribute__((aligned(16)));
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void AddV(V_00277E20* d, V_00277E20* a, V_00277E20* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline void AddV2(V_00277E20* d, V_00277E20* a, V_00277E20* b) { AddV(d, a, b); }

// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len0(V_00277E20* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
static inline float Len(V_00277E20 a) { return Len0(&a); }
struct LosHit {
    VP arr[3];
    V_00277E20 normal;
    unsigned char b40; char p41; unsigned char b42; char p43[0xD];
    unsigned char b50; unsigned char b51; unsigned char b52; char p53[0xD];
    int x60;
    int* x64;
    char pad68[0x8];
    LosHit() { LosHit* q = this; VP* i = q->arr; do { i++; } while (i != q->arr + 3); q->b40 = 0; q->b42 = 0; q->x60 = 0; q->x64 = 0; }
};
struct Mtx_00277E20 { VP r[4]; Mtx_00277E20() {} Mtx_00277E20(const Mtx_00277E20& o) { cMatrix_ctor_cMatrixR(this, &o); } };
struct HV { float x, y, z, w; HV() {} HV(const HV& o) { cVector_ctor_cVectorR(this, &o); } HV& operator=(const V_00277E20& o) { *(V_00277E20*)this = o; return *this; } } __attribute__((aligned(16)));
struct TrCopy_00277E20 {
    VP v[4];
    Sub40 s40;
    unsigned char b50, b51, b52; char p53[0xD];
    Sub60 s60;
    TrCopy_00277E20() {}
    TrCopy_00277E20(const TrCopy_00277E20& o) { cCollisionFace_ctor_cCollisionFaceR(this, &o); }
};
struct Req_00277E20 {
    Mtx_00277E20 m;
    float f40;
    int f44;
    int f48;
    int f4C;
    TrCopy_00277E20 tr;
    HV hit;
    int fD0;
    unsigned char fD4, fD5, fD6;
    float fD8;
    int fDC;
    int fE0;
    float fE4;
    Req_00277E20() {}
};
static inline void CopyReq(Req_00277E20* d, const Req_00277E20* s) { cMatrix_ctor_cMatrixR(&d->m, &s->m); d->f40 = s->f40; d->f44 = s->f44; d->f48 = s->f48; d->f4C = s->f4C; cCollisionFace_ctor_cCollisionFaceR(&d->tr, &s->tr); cVector_ctor_cVectorR(&d->hit, &s->hit); d->fD0 = s->fD0; d->fD4 = s->fD4; d->fD5 = s->fD5; d->fD6 = s->fD6; d->fD8 = s->fD8; d->fDC = s->fDC; d->fE0 = s->fE0; d->fE4 = s->fE4; }
struct BulletReq : Req_00277E20 {};
struct Bullet_00277E20 { char pad[0x115]; unsigned char active; char pad116[0x150 - 0x116]; };
extern "C" Bullet_00277E20 D_004FFE60[];


Bullet_00277E20* cBulletManager_AddBullet(Req_00277E20* req)
{
    void* svc = cSystemContainer_GetSystem(g_Game, g_LosCheckService);
    V_00277E20 hit;
    LosHit res;
    V_00277E20 start = *(V_00277E20*)&req->m.r[3];
    start += (*(V_00277E20*)&req->m.r[1]) * D_0048B348;
    unsigned char ok = (unsigned char)cLosManager_cCollisionModelList_Game_PerformImmediateRayIntersectionTest(svc, &hit, &res, &start, (*(V_00277E20*)&req->m.r[1]) * req->fD8, req->f44, 0, 0, 0x10, 0x80, D_00504030, 1);
    Req_00277E20 r; Req_00277E20* d = &r; const Req_00277E20* s = req; cMatrix_ctor_cMatrixR(&d->m, &s->m); d->f40 = s->f40; d->f44 = s->f44; d->f48 = s->f48; d->f4C = s->f4C; cCollisionFace_ctor_cCollisionFaceR(&d->tr, &s->tr); cVector_ctor_cVectorR(&d->hit, &s->hit); d->fD0 = s->fD0; d->fD4 = s->fD4; d->fD5 = s->fD5; d->fD6 = s->fD6; d->fD8 = s->fD8; d->fDC = s->fDC; d->fE0 = s->fE0; d->fE4 = s->fE4;
    if (ok) {
        V_00277E20 h = hit;
        r.fD8 = Len(h - *(V_00277E20*)&req->m.r[3]);
        r.f4C = *res.x64;
        cVector_opAssign((V_00277E20*)&r.tr.v[0], (V_00277E20*)&res.arr[0]);
        cVector_opAssign((V_00277E20*)&r.tr.v[1], (V_00277E20*)&res.arr[1]);
        cVector_opAssign((V_00277E20*)&r.tr.v[2], (V_00277E20*)&res.arr[2]);
        cVector_opAssign((V_00277E20*)&r.tr.v[3], &res.normal);
        r.tr.b50 = res.b50;
        cCollisionModel_FaceProperties_opAssign(&r.tr.s40, &res.b40);
        cCollisionModel_FaceLocator_opAssign(&r.tr.s60, &res.x60);
        r.tr.b51 = res.b51;
        r.tr.b52 = res.b52;
        r.hit = h;
    }
    Bullet_00277E20* b = 0;
    for (int i = 0; !b && i < 50; i++) {
        if (!D_004FFE60[i].active) {
            b = &D_004FFE60[i];
            cBullet_InitBullet(b, &r);
        }
    }
    return b;
}
#undef cVector_opAssign /* merge_units */
#undef cBullet_InitBullet /* merge_units */
static inline void merge_flush_func_00277E20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00277E20 */
