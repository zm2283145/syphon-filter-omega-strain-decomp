/*
 * SFOGame/Source/player: 6 files, 00176400-00176590
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00176400 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct V { float x, y, z, w; } __attribute__((aligned(16)));
struct Mtx { V r[4]; };
struct Src {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC]; Mtx xform; unsigned char dirty;
};
struct Owner_76400 { char pad[0x50]; Src* src; };
struct P_76400 { char pad[0x30]; char* p30; char pad34[0x1A0 - 0x34]; Owner_76400* x1A0; };
extern "C" void cMan_GetGunBarrelMatrix(Mtx* out, void* p, unsigned char f);
static inline Mtx* GetXform(Src* s) {
    if (s->dirty) s->Refresh();
    return &s->xform;
}
static inline void GQ(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void VC(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void MulV(V* o, Mtx* m, V* v) {
    asm {
        lqc2 vf8, 0x0(v)
        lqc2 vf4, 0x0(m)
        lqc2 vf5, 0x10(m)
        lqc2 vf6, 0x20(m)
        lqc2 vf7, 0x30(m)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0x0(o)
    }
}
/* cPlayer_GetBulletDir: muzzle/eye frame (else branch is cNPC_GetBulletDir, npc_14F380.c) */
extern "C" int cPlayer_GetBulletDir(P_76400* self, Mtx* out, int flag, int eye)
{
    char* p = self->p30;
    if (eye) {
        V u;
        GQ(out, GetXform(self->x1A0->src));
        u.x = 0.0f; u.y = 1.0f; u.z = 0.0f; u.w = 1.0f;
        MulV(&u, out, &u);
        VC(&out->r[3], &u);
    } else {
        Mtx tmp;
        __int128 qa; __int128 qb; Mtx* s;
        unsigned short f;
        if (flag) f = 1; else f = 0;
        { char* q = p + 0x60; cMan_GetGunBarrelMatrix(&tmp, q, f); }
        s = &tmp;
        asm {
            .set noreorder
            lq qa, 0x0(s)
            lq qb, 0x10(s)
            sq qa, 0x0(out)
            lq qa, 0x20(s)
            sq qb, 0x10(out)
            lq qb, 0x30(s)
            sq qa, 0x20(out)
            sq qb, 0x30(out)
            .set reorder
        }
    }
    return 1;
}
static inline void merge_flush_func_00176400(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00176400 */

/* merge_units: begin func_00176540 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player component (cPlayer): script natives, type registration and setup.
 */

#include "player_types.h"

extern void* cGameSystem_GetAgentData(void* agents, int index);
extern char g_Game[];
extern void cPlayerControls_HandleDeath(PlayerInputState* input);
extern void cAgentData_AddScore(void* agent, int a1, int a2);

void cPlayer_NoticeDeath(PlayerComponent* self) {
    cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 8, 1);
    cPlayerControls_HandleDeath(&self->input);
}
static inline void merge_flush_func_00176540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00176540 */

/* merge_units: begin func_00176590 */
#pragma push /* merge_units */
typedef struct { char pad[0x1AC]; float f1AC; } A2P176;
void cPlayer_v1E(A2P176* p, float x) {
    if (!(x <= p->f1AC)) p->f1AC = x;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176590(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176590 */

/* merge_units: begin func_001765B0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; char* obj; char pad2[0x1A8 - 0x34]; float maxv; } S1765B0;
extern int g_Hud;
extern char* nGlobalization_GetString_charP(char* key);
extern void cHud_SetCallout(int a, char* b, char* c, int d, int e, int f, float g, float h);
void cPlayer_NoticeThreat_cGobjControllerP_int_float_int(S1765B0* p, int a1, int a2, int flag, float v)
{
    if (v > p->maxv) {
        p->maxv = v;
    }
    if (flag == 0 && v > 0.5f) {
        char* s;
        int d;
        d = g_Hud;
        s = p->obj + 0xC;
        cHud_SetCallout(d, s, nGlobalization_GetString_charP("headshot"), 0, 0, 0, 0.1f, 1.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001765B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001765B0 */

/* merge_units: begin func_00176660 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(8)

struct Pri_76660 {
    int cur;
    int w[1];
    int Test(int i) { return ((w[i / 32] >> (i & 31)) & 1) != 0; }
    void Update() {
        int i = 11;
        while (i >= 0 && !Test(i))
            i--;
        if (!Test(i))
            cur = -1;
        else
            cur = i;
    }
    void Set(int i) { w[i / 32] |= 1 << (i & 31); Update(); }
    void Clear(int i) { w[i / 32] &= ~(1 << (i & 31)); Update(); }
};
struct Q_76660 { int type; unsigned char a; unsigned char b; char pad6[2]; void* vt; void* obj; };
struct Msg_76660 { char pad[0x24]; int id; };
struct PC_76660 {
    char pad0[0x50];
    char input[0x40];
    Pri_76660 pri;
    char pad98[0x110 - 0x98];
    char h110[8];
    char h118[0x13C - 0x118];
    char f13C[4];
};
extern "C" {
extern void* g_Fader;
extern char D_004D9DE0[];
extern char D_004D9DC0[];
extern char D_0049CAE8[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void nCallback_SetCallback(Q_76660* q);
void cScreenFader_StartFade(float, void*, int);
int cSafePtr_cGOBJ_opAssign_cGOBJP(void*, int);
void cLList_cSafePtr_cGOBJ_Clear(void*);
void cPlayerControls_HandleRespawn(void*);
}
static inline void Init_76660(Q_76660* q, void* obj)
{
    q->vt = D_004D9DE0;
    q->a = 1;
    q->type = 0xF;
    q->b = 0;
    q->vt = D_004D9DC0;
    q->obj = obj;
}
extern "C" int cPlayer_HandleCASEvent(PC_76660* self, Msg_76660* msg)
{
    switch (msg->id) {
    case 2:
        self->pri.Set(4);
        self->pri.Set(2);
        break;
    case 3:
        self->pri.Clear(2);
        break;
    case 4:
        self->pri.Clear(4);
        self->pri.Set(3);
        break;
    case 5:
        self->pri.Clear(3);
        break;
    case 6:
        self->pri.Set(7);
        break;
    case 7:
        self->pri.Clear(7);
        break;
    case 8:
    case 9:
    case 11:
        break;
    case 10:
        self->pri.Set(6);
        break;
    case 12:
        self->pri.Clear(6);
        break;
    case 16: {
        Q_76660* q;
        cScreenFader_StartFade(1.0f, g_Fader, 2);
        {
            AllocGuard guard;
            q = (Q_76660*)cMemMan_Allocate(0, 0x10, D_0049CAE8, 0x204);
        }
        if (q)
            Init_76660(q, self);
        nCallback_SetCallback(q);
        cSafePtr_cGOBJ_opAssign_cGOBJP(self->h110, cSafePtr_cGOBJ_opAssign_cGOBJP(self->h118, 0));
        cLList_cSafePtr_cGOBJ_Clear(self->f13C);
        break;
    }
    case 17:
        cPlayerControls_HandleRespawn(self->input);
        break;
    default:
        return 0;
    }
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176660(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176660 */

/* merge_units: begin func_00176E60 */
#pragma push /* merge_units */
typedef struct { int a; int b; void* vt; } S_6E60;
extern void operator_delete(void* p);
S_6E60* cCBData_dtor(S_6E60* self, short flag)
{
    if (self) {
        self->vt = D_004D9DE0;
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00176E60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00176E60 */
