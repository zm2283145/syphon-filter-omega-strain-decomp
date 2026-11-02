/*
 * SFOGame/Source/npc: 16 files, 0014F610-00150CA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014F610 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void cAIWeaponFiredMsg_Clone();
extern "C" void cAIWeaponFiredMsg_getSOBJClassId();
extern "C" void cAIGOBJMsg_Pack();
extern void * const D_004DCBF0[];
extern char D_004DCD70[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cAIWeaponFiredMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DCBF0);
        if (self) {
            self->vtable = D_004DCD70;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DCBF0[8] = { (void*)0x0, (void*)0x0, (void*)cAIWeaponFiredMsg_dtor, (void*)cAIWeaponFiredMsg_Clone, (void*)cAIGOBJMsg_Pack, (void*)cAIWeaponFiredMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014F610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014F610 */

/* merge_units: begin func_0014F680 */
#pragma push /* merge_units */
#pragma cplusplus on
struct VNpc_14F680 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100(int, int, float);
};
extern "C" {

typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char kind;
    char pad21[3];
    int killer;
    char how;
} Msg_14F680;

typedef struct {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
} Bits_14F680;

typedef struct { char pad[0x20]; Bits_14F680 bits; } Perc_14F680;
typedef struct { char pad[0x4C]; unsigned char ok; char pad4D[3]; } WTab_14F680;
typedef struct { char pad[0x310]; unsigned char a; unsigned char b; } Wpn_14F680;

typedef struct {
    char pad0[0x2C];
    unsigned char f2C;
    unsigned char f2D;
    unsigned char f2E;
    char pad2F[0x3314 - 0x2F];
    Wpn_14F680* weapon;
    char pad3318[0x3468 - 0x3318];
    unsigned char f3468;
    char pad3469[0x3524 - 0x3469];
    int inv;
} Actor_14F680;

typedef struct Npc_14F680 {
    void** vtable;
    char pad4[0x2C];
    Actor_14F680* actor;
    char pad34[0x50];
    float t84;
    char pad88[0x20];
    int hp;
    char padAC[0x100];
    Perc_14F680* perc;
} Npc_14F680;

extern char g_Game[];
extern char g_NpcRouteMgr[];
extern char g_ScriptAIDeadMsgKey[];
extern char D_004DCCF0[];
extern char g_NpcDeadList[];
extern WTab_14F680 SecondaryStateTable[];
extern void* cSystemContainer_GetSystem(void* a, void* b);
extern void cPathSystem_ClearRequests(void* mgr, Actor_14F680* a);
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_14F680* m, void* key);
#endif /* merge_units */
void cMessage_ctor_cMessageNameR(void*, void*); /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg_14F680* m, void* target, int flags);
#endif /* merge_units */
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int); /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_14F680* m, int flags);
#endif /* merge_units */
void* cMessage_dtor(void* self, short deleteFlag); /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */



extern void cHuman_UpdateStats(Actor_14F680* a, int killer, char how, int x);
extern int cWeapon_IsFullyAutomatic(int inv);
extern void cWeapon_SetAmmoNpcDeath(int inv);
extern void cAITarget_dtor(Perc_14F680* p);
extern void cNPC_RemoveFromActiveList(Actor_14F680* a);
extern void std_list_cNPCPtr_push_back(void* list, Npc_14F680** npc);

}

static inline WTab_14F680* WT_14F680(int i) { return &SecondaryStateTable[i]; }
static inline bool Can_14F680(Wpn_14F680* w) { if (!w) return false; return WT_14F680(w->a)->ok && WT_14F680(w->b)->ok; }
extern "C" void cNPC_NoticeDeath(Npc_14F680* self, int unused, int killer, int x, char how)
{
    Actor_14F680* a = self->actor;
    if (a) {
        Msg_14F680 msg;
        bool ok;
        {
            void* mgr = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
            cPathSystem_ClearRequests(mgr, self->actor);
        }
        cMessage_ctor_cMessageNameR(&msg, g_ScriptAIDeadMsgKey);
        msg.vtable = D_004DCCF0;
        msg.killer = killer;
        msg.how = how;
        {
            unsigned char* k = &msg.kind;
            *k = 2;
            *k = 2;
        }
        QueueMessage_cMessageR_cSystemP_int(&msg, self->actor, 0);
        cHuman_UpdateStats(a, killer, how, x);
        if (self->hp > 0 && self->t84 <= 0.0f) {
            Bits_14F680* b = &self->perc->bits;
            ok = b->b0 && b->b2;
            if (ok && cWeapon_IsFullyAutomatic(a->inv)) {
                ok = Can_14F680(a->weapon);
                if (ok) ((VNpc_14F680*)self)->s100(self->hp, -1, 0.0f);
            }
        }
        cWeapon_SetAmmoNpcDeath(a->inv);
        cAITarget_dtor(self->perc);
        ok = a->f2D && a->f2C && !a->f2E && a->f3468;
        if (!ok) {
            Actor_14F680* b;
            cNPC_RemoveFromActiveList(self->actor);
            b = self->actor;
            ok = b->f2D && b->f2C && !b->f2E;
            if (ok) std_list_cNPCPtr_push_back(g_NpcDeadList, &self);
        }
        msg.vtable = D_004DCCF0;
        cMessage_dtor(&msg, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014F680(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014F680 */

/* merge_units: begin func_0014F910 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cAIDeadMsg_dtor, D_004DCCF0, cMessage_dtor)
static inline void merge_flush_func_0014F910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014F910 */

/* merge_units: begin func_0014F970 */
#pragma push /* merge_units */
/* NPC message object (vtable, base data, parameters). */
typedef struct NpcMsg {
    void* vtable;
    char base[0x20];
    unsigned char mode;
    char pad[3];
    int target;
    char pad2[4];
} NpcMsg;

typedef struct cNPC {
    char pad[0x1AC];
    int ai;
} cNPC;

extern void cAITarget_AddAwareness(int ai, int arg, int mode, float value);
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(NpcMsg* msg, void* name);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((void *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(NpcMsg* msg, cNPC* target, int flags);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (void *)(a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(NpcMsg* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */


extern char D_004EE550[];
extern char D_004D9340[]; /* AI mode message vtable */

/* cNPC vtable slot 0x1C: switches the AI to mode 8 and notifies itself. */
void cNPC_NoticeDamage(cNPC* self, int arg) {
    NpcMsg msg;
    cAITarget_AddAwareness(self->ai, arg, 8, 0.0f);
    cMessage_ctor_cMessageNameR(&msg, D_004EE550);
    msg.vtable = D_004D9340;
    msg.mode = 8;
    msg.target = -1;
    QueueMessage_cMessageR_cSystemP_int(&msg, self, 0);
    msg.vtable = D_004D9340;
    cMessage_dtor(&msg, 0);
}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_0014F970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014F970 */

/* merge_units: begin func_0014FA00 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#include "vslot_pad.h"

struct HObj4FA {
    char pad[0xC];
    int id;
};

struct Handle4FA {
    HObj4FA* obj;
    int id;
};

struct Node4FA {
    int unk0;
    Node4FA* next;
    Handle4FA* h;
};

class Ctl4FA {
public:
    VPAD32(p) VPAD32(q)
    virtual unsigned char GetMode();
};

struct Inner4FA {
    char pad[0x58];
    int owner;
};

class Npc4FA {
public:
    VPAD32(p)
    virtual unsigned char GetState();
    char pad[0x2C];
    Ctl4FA* ctl;
    char pad34[0xE0 - 0x34];
    int resA;
    int resB;
    char padE8[0x1B0 - 0xE8];
    Inner4FA* inner;
};

struct Obj4FA {
    char pad[0x58];
    Npc4FA* npc;
};

extern "C" {
extern Tree g_NpcThinkList;
#if 0 /* merge_units */
extern void std_list_cActiveListItemPtr_begin_void(Iter* out, Tree* t);
#endif /* merge_units */
void std_list_cActiveListItemPtr_begin_void(Iter* out, PtrVec* v); /* merge_units */
#define std_list_cActiveListItemPtr_begin_void(a0, a1) (std_list_cActiveListItemPtr_begin_void((a0), (PtrVec *)(a1))) /* merge_units */

extern Word* cLListIterator_cActiveListItemPtr_ctor(Word* dst, Word* src);
extern void std_list_cActiveListItemPtr_end_void(Iter* out, Tree* t);
}

static inline void FCopy4FA(float* d, float* s) { float* ss = s; float* dd = d; *dd = *ss; }

extern "C" Ctl4FA* cNPC_IsNodeOccupied(int node)
{
    Node4FA* it;
    int tmp;
    Word w;
    Word w2;
    Iter b;
    Iter end;
    Ctl4FA* result = 0;

    std_list_cActiveListItemPtr_begin_void(&b, &g_NpcThinkList);
    cLListIterator_cActiveListItemPtr_ctor(&w, (Word*)&b);
    { int v = w.value; tmp = v; }
    FCopy4FA((float*)&it, (float*)&tmp);
    std_list_cActiveListItemPtr_end_void(&end, &g_NpcThinkList);
    cLListIterator_cActiveListItemPtr_ctor(&w2, (Word*)&end);
    while (*(int*)&it != w2.value) {
        unsigned char valid;
        Handle4FA* h;
        HObj4FA* o;
        int isnull;
        h = it->h;
        o = h->obj;
        isnull = (o != 0) ^ 1;
        valid = 1;
        if (!isnull && o->id != h->id) {
            valid = 0;
        }
        if (valid ? o : 0) {
            if (o && o->id != h->id) {
                o = 0;
            }
            if (((Obj4FA*)o)->npc->GetState() == 1) {
                Npc4FA* npc;
                unsigned char v3;
                Handle4FA* h3;
                HObj4FA* o3;
                int n3;
                h3 = it->h;
                o3 = h3->obj;
                n3 = (o3 != 0) ^ 1;
                v3 = 1;
                if (!n3 && o3->id != h3->id) {
                    v3 = 0;
                }
                npc = ((Obj4FA*)(v3 ? o3 : 0))->npc;
                if (npc->ctl->GetMode() != 3) {
                    if (node == npc->resB || node == npc->resA || node == npc->inner->owner) {
                        result = npc->ctl;
                        break;
                    }
                }
            }
        }
        it = it->next;
        std_list_cActiveListItemPtr_end_void(&end, &g_NpcThinkList);
        cLListIterator_cActiveListItemPtr_ctor(&w2, (Word*)&end);
    }
    return result;
}
#undef std_list_cActiveListItemPtr_begin_void /* merge_units */
static inline void merge_flush_func_0014FA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014FA00 */

/* merge_units: begin func_0014FC00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc.
 */


int cGobjController_DetermineDeathType_int(void) {
    return 0;
}

void std_list_cActiveListItemPtr_begin_void(Iter* out, PtrVec* v) {
    out->p = v->data;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC00 */

/* merge_units: begin func_0014FC20 */
#pragma push /* merge_units */
typedef struct { char pad[0x120]; int priority; char pad124[0x13D - 0x124]; char kind; } Obj120;

/* Records a new kind/priority pair unless the current priority is higher. */
void cNPC_SetAimMode_eAimMode_int(Obj120* self, char kind, int priority)
{
    if (priority < self->priority)
        return;
    self->kind = kind;
    self->priority = priority;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC20 */

/* merge_units: begin func_0014FC40 */
#pragma push /* merge_units */
#pragma cplusplus on
struct CxNpcThunk { VPAD32(a) VPAD8(b) VPAD4(c) VPAD1(d)
virtual void Target(int,int);
};
extern "C" { static inline void CxNpcThunk_Call(CxNpcThunk* self,int arg) { self->Target(arg,100); } }
#pragma cplusplus off
void cNPC_SetAimMode_eAimMode(struct CxNpcThunk* self,int arg) { CxNpcThunk_Call(self,arg); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC40 */

/* merge_units: begin func_0014FC60 */
#pragma push /* merge_units */
typedef struct CxBurstActor { char pad0[0xC]; int serial; char pad10[0x3524-0x10]; void* weapons; } CxBurstActor;
typedef struct CxBurstNpc { char pad0[0x30]; CxBurstActor* actor; char pad34[0xA4-0x34]; int burst; int shots; } CxBurstNpc;
extern int cHuman_IsHoldingGun(CxBurstActor*);
extern int Libc_Rand(void);
extern int cWeapon_GetClipSize(void*,int);
void func_0014FC60(CxBurstNpc* self) {
    CxBurstActor* actor=self->actor;
    if(cHuman_IsHoldingGun(actor)) {
        void* weapons=actor->weapons;
        self->burst=(self->actor->serial&7)+3;
        if(Libc_Rand()&1)self->burst++;
        if(self->burst>cWeapon_GetClipSize(weapons,6)) {
            int n=cWeapon_GetClipSize(weapons,6)/2;
            if(n<=0)n=1;
            self->burst=n;
        }
    } else self->burst=0;
    self->shots=0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC60 */

/* merge_units: begin func_0014FD30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vc_copy.h"
struct V4 {
    __int128 q;
    V4() {}
};
struct Mat { V4 r[4]; Mat() {} };
class GObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58();
    virtual Mat GetMatrix();
};
struct PNode { char pad[0x7C]; int f7C; };
extern "C" PNode* cAIPathData_GetNode(int);
struct Self_S {
    char pad0[0x30]; GObj* obj; char pad34[0x3C]; float f70; float f74; char pad78[0x44];
    int bitsBC[8]; char padDC[4]; int fE0; char padE4[0x5B]; unsigned char f13F; char pad140; unsigned char u141;
    char pad142[0x6A]; V4* target; int f1B0;
};
extern "C" {
void* cSystemContainer_GetSystem(void* a, void* b);
int cPathSystem_IsRequestBeingProcessed(void* svc, GObj* id);
void cPathNavigator_Request_int(int r, int node);
int cPathNavigator_GetGroupIndexForPatrolPath(int r);
unsigned char cPathSystem_RequestNodeIndexFromGroup(float d, void* svc, GObj* obj, void* e0, V4* pos, V4* tgt, int reg, int n, int k, long m);
void cNodePickerParameters_ctor_float_float_bool(float a, float b, void* out, int k);
}

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" unsigned char cNPC_MoveToAttackNode(Self_S* self) {
    char e0[0x10];
    V4 pos;
    V4 tgt;
    unsigned char r = 0;
    if (!cPathSystem_IsRequestBeingProcessed(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), self->obj)) {
        void* svc;
        float dist;
        GObj* o;
        cNodePickerParameters_ctor_float_float_bool(self->f70, self->f74, e0, 0);
        { Mat m = self->obj->GetMatrix(); V4* d = &pos; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; asm { .set reorder; lq x, 0(s) } *(__int128*)d = x; } { V4* d = &tgt; *(__int128*)d = *(__int128*)self->target; }
        svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
        {
            V4 d;
            V4 rr;
            {
                V4* pr = &rr; V4* pa = &tgt; V4* pb = &pos;
                asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
            }
            {
                V4* dd; V4* ss; int t; __int128 x; V4* pv;
                ss = &rr; pv = &d; asm { mtc1 $zero, dist } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
                asm {
                    lqc2 vf1, 0(pv)
                    vmul.xyz vf2, vf1, vf1
                    vmulax.w ACC, vf0, vf2x
                    vmadday.w ACC, vf0, vf2y
                    vmaddz.w vf3, vf0, vf2z
                    vsqrt Q, vf3w
                    vwaitq
                    vaddq.x vf4, vf0, Q
                    qmfc2.ni t, vf4
                    mtc1 t, dist
                }
            }
        }
        { float lim = self->f74; if (dist < lim) dist = lim; }
        o = self->obj;
        r = cPathSystem_RequestNodeIndexFromGroup(15.0f + dist, svc, o, e0, &pos, &tgt, cPathNavigator_GetGroupIndexForPatrolPath(self->f1B0), 0x80, 1, -1);
        self->f13F = 4;
    }
    return r;
}
static inline void merge_flush_func_0014FD30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014FD30 */

/* merge_units: begin func_0014FEC0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
}

static inline bool Visited(Self_S* self, int i)
{
    bool r = 1;
    if (i >= 0)
        { int b = cAIPathData_GetNode(i)->f7C; r = (self->bitsBC[b / 32] >> (b & 31)) & 1; }
    return r;
}

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" unsigned char cNPC_MoveToAttackFromCoverNode(Self_S* self) {
    char e0[0x10];
    V4 pos;
    V4 tgt;
    unsigned char r = 0;
    int node = self->fE0;
    if (node >= 0 && Visited(self, node)) {
        int n = self->fE0;
        if (!cPathSystem_IsRequestBeingProcessed(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), self->obj)) {
            if (Visited(self, n)) cPathNavigator_Request_int(self->f1B0, n);
        }
        r = 1; self->u141 = (self->u141 & ~1) | r;
        self->f13F = 3;
    } else if (!cPathSystem_IsRequestBeingProcessed(cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr), self->obj)) {
        void* svc;
        float dist;
        GObj* o;
        cNodePickerParameters_ctor_float_float_bool(self->f70, self->f74, e0, 1);
        { Mat m = self->obj->GetMatrix(); V4* d = &pos; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; asm { .set reorder; lq x, 0(s) } *(__int128*)d = x; } { V4* d = &tgt; *(__int128*)d = *(__int128*)self->target; }
        svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
        {
            V4 d;
            V4 rr;
            {
                V4* pr = &rr; V4* pa = &tgt; V4* pb = &pos;
                asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
            }
            {
                V4* dd; V4* ss; int t; __int128 x; V4* pv;
                ss = &rr; pv = &d; asm { mtc1 $zero, dist } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
                asm {
                    lqc2 vf1, 0(pv)
                    vmul.xyz vf2, vf1, vf1
                    vmulax.w ACC, vf0, vf2x
                    vmadday.w ACC, vf0, vf2y
                    vmaddz.w vf3, vf0, vf2z
                    vsqrt Q, vf3w
                    vwaitq
                    vaddq.x vf4, vf0, Q
                    qmfc2.ni t, vf4
                    mtc1 t, dist
                }
            }
        }
        { float lim = self->f74; if (dist < lim) dist = lim; }
        o = self->obj;
        r = cPathSystem_RequestNodeIndexFromGroup(15.0f + dist, svc, o, e0, &pos, &tgt, cPathNavigator_GetGroupIndexForPatrolPath(self->f1B0), 0x40, 1, -1);
        self->f13F = 3;
    }
    return r;
}
static inline void merge_flush_func_0014FEC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014FEC0 */

/* merge_units: begin func_00150150 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Self_S_00150150 {
    char pad0[0x30]; GObj* obj; char pad34[0x3C]; float f70; float f74; char pad78[0x44];
    int bitsBC[8]; char padDC[4]; int fE0; int fE4; char padE8[0x57]; unsigned char f13F; char pad140; unsigned char u141;
    char pad142[0x6A]; V4* target; int f1B0;
};
extern "C" {
void cNPC_CheckLOSDestinationFromTarget(Self_S_00150150* s);
}

static inline bool Visited_00150150(Self_S_00150150* self, int i)
{
    bool r = 1;
    if (i >= 0)
        { int b = cAIPathData_GetNode(i)->f7C; r = (self->bitsBC[b / 32] >> (b & 31)) & 1; }
    return r;
}


#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" unsigned char cNPC_MoveToCoverNode(Self_S_00150150* self) {
    char e0[0x10];
    V4 pos;
    V4 tgt;
    unsigned char r = 0;
    int node = self->fE4;
    if (node >= 0 && Visited_00150150(self, node)) {
        cNPC_CheckLOSDestinationFromTarget(self);
        r = 1;
        self->f13F = 10;
    } else {
        void* svc = cSystemContainer_GetSystem(g_Game, g_NpcRouteMgr);
        if (!cPathSystem_IsRequestBeingProcessed(svc, self->obj)) {
        float dist;
        GObj* o;
        cNodePickerParameters_ctor_float_float_bool(self->f70, self->f74, e0, 1);
        { Mat m = self->obj->GetMatrix(); V4* d = &pos; Mat* pm = &m; V4* s = &pm->r[3]; __int128 x; asm { .set reorder; lq x, 0(s) } *(__int128*)d = x; } { V4* d = &tgt; V4* s = self->target; __int128 x; asm { lq x, 0(s) } *(__int128*)d = x; }
        {
            V4 d;
            V4 rr;
            {
                V4* pr = &rr; V4* pa = &tgt; V4* pb = &pos;
                asm { lqc2 vf1, 0(pa); lqc2 vf2, 0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
            }
            {
                V4* dd; V4* ss; int t; __int128 x; V4* pv;
                ss = &rr; pv = &d; asm { mtc1 $zero, dist } dd = &d; x = *(__int128*)ss; *(__int128*)dd = x;
                asm {
                    lqc2 vf1, 0(pv)
                    vmul.xyz vf2, vf1, vf1
                    vmulax.w ACC, vf0, vf2x
                    vmadday.w ACC, vf0, vf2y
                    vmaddz.w vf3, vf0, vf2z
                    vsqrt Q, vf3w
                    vwaitq
                    vaddq.x vf4, vf0, Q
                    qmfc2.ni t, vf4
                    mtc1 t, dist
                }
            }
        }
        { float lim = self->f74; if (dist < lim) dist = lim; }
        o = self->obj;
        r = cPathSystem_RequestNodeIndexFromGroup(15.0f + dist, svc, o, e0, &pos, &tgt, cPathNavigator_GetGroupIndexForPatrolPath(self->f1B0), 6, 2, -1);
        self->f13F = 2;
        }
    }
    return r;
}
static inline void merge_flush_func_00150150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00150150 */

/* merge_units: begin func_00150340 */
#pragma push /* merge_units */
#pragma cplusplus on

static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V() {} V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
  V(const V& o) { V* d = this; Q16(d, &o); } V& operator=(const V& o) { Q16(this, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4]; V& T() { return r[3]; } } __attribute__((aligned(16)));

struct Obj { VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual struct M GetMtx(); char pad4[8]; int serial; };
struct Sub58 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char Big(); };
struct Sub58Holder { char pad[0x58]; Sub58* s; };
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int DiffNV(int a, int b) { return a ^ b; }
static inline int SameNV(int a, int b) { return (unsigned)DiffNV(a, b) < 1; }
struct Hdl { Obj* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; } };
struct Ai { char pad0[0x20]; unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; char pad21[0x1F]; Obj* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj* Get() { return IsValid() ? obj : 0; } };
struct Cnt { char pad[0xC]; int n; };
struct Gun { char pad[0x310]; unsigned char a, b; };
struct Owner {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e) virtual M GetMtx(); VPAD4(f) virtual unsigned char Cls();
    char pad4[0x3208];
    int mode;               /* 0x320C */
    char pad3210[0x104];
    Gun* gun;               /* 0x3314 */
    char pad3318[0xCC];
    unsigned char busy;     /* 0x33E4 */
    char pad33E5[0x13F];
    void* inv;              /* 0x3524 */
    char pad3528[0x5C];
    char* stats;            /* 0x3584 */
};
struct Npc {
    VPAD32(a) VPAD8(b) virtual int Busy(int);
    char pad4[0x1C];
    float reach;            /* 0x20 */
    char pad24[0xC];
    Owner* owner;           /* 0x30 */
    char pad34[0x44];
    float range;            /* 0x78 */
    char pad7C[8];
    float cool;             /* 0x84 */
    float cool2;            /* 0x88 */
    char pad8C[4];
    float spread;           /* 0x90 */
    float rate;             /* 0x94 */
    char pad98[0xC];
    int burstMax;           /* 0xA4 */
    int burst;              /* 0xA8 */
    char padAC[0x70];
    int team;               /* 0x11C */
    char pad120[0x10];
    int forced;             /* 0x130 */
    char pad134[0xA];
    unsigned char fireMode; /* 0x13E */
    char pad13F[2];
    unsigned char : 4;
    unsigned char lead : 1; /* 0x141 */
    char pad142[0x6A];
    Ai* ai;                 /* 0x1AC */
    char pad1B0[8];
    Cnt* cnt;               /* 0x1B8 */
    char pad1BC[0xC];
    Hdl h2;                 /* 0x1C8 */
};



typedef unsigned char (*VFnB)(void*);
typedef int (*VFnI)(void*, int);
typedef M (*VFnM)(void*);
#define VF(o, off, T) (*(T*)((char*)((Obj*)(o))->vt + (off)))

extern "C" {
extern float WorthShootingThreshold;
extern int g_NoneWord;
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0200[];
extern unsigned char g_IsMultiplayer;
struct GunDef { char pad[0x4C]; unsigned char ok; char pad4D[3]; unsigned char Ok() { return ok; } };
#if 0 /* merge_units */
extern GunDef SecondaryStateTable[];
#endif /* merge_units */
#define SecondaryStateTable ((GunDef*)&SecondaryStateTable) /* merge_units */

#if 0 /* merge_units */
Obj* cSafePtr_cGOBJ_opCast_cGOBJPtr(Hdl*);
#endif /* merge_units */
struct C6Obj_150C60; /* merge_units */
struct C6Ref_150C60; /* merge_units */
C6Obj_150C60* cSafePtr_cGOBJ_opCast_cGOBJPtr(C6Ref_150C60* ref); /* merge_units */
#define cSafePtr_cGOBJ_opCast_cGOBJPtr(a0) ((Obj *)cSafePtr_cGOBJ_opCast_cGOBJPtr((C6Ref_150C60 *)(a0))) /* merge_units */

#if 0 /* merge_units */
int cWeapon_IsFullyAutomatic(void*);
#endif /* merge_units */
#define cWeapon_IsFullyAutomatic(a0) (cWeapon_IsFullyAutomatic((int)(a0))) /* merge_units */

unsigned char cWeapon_GetEquipmentType(void*);
int cWeapon_ReadyToFire(void*, int);
int cWeapon_Ready(void*);
void cWeapon_FireIfReady(void*, int, int, int, int);
int Libc_Rand(void);
void cMessage_ctor_cMessageNameR(void*, void*);
void QueueMessage_cMessageR_cSystemP_int(void*, void*, int);
#if 0 /* merge_units */
void cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

void cNPC_HandleWeaponFiring(Npc* self, float dt);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB {
    void* vtable; void* type; int pad8[6]; unsigned char kind; char pad21[3];
    MsgB(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB() { cMessage_dtor(this, 0); }
};
struct Msg3B : MsgB {
    int id; unsigned char sub; char pad29[7];
    Msg3B() : MsgB(g_ActorActionMsgClass) { vtable = D_004E0840; id = 0x3B; sub = 0xB; }
    __declspec(weak) __declspec(MSG_DTOR) ~Msg3B() { vtable = D_004E0840; }
};
struct FireMsg : Msg3B {
    int serial; int team; unsigned char f38; char pad39[7];
    V pos; float yaw;
    FireMsg(Obj* tgt, int tm, V p, float y);
    __declspec(weak) __declspec(MSG_DTOR) ~FireMsg() {}
} __attribute__((aligned(16)));
static inline bool NotNull(void* p) { return p != 0; }
static inline bool Eq(int a, int b) { return a == b; }
static inline Obj* RefGet(Hdl* h) {
    unsigned char ok = 1;
    if (!(!NotNull(h->obj) || Eq(h->obj->serial, h->serial))) ok = 0;
    return ok ? h->obj : 0;
}
static inline float RandF() { return (float)Libc_Rand() / 2147483648.0f; }
static inline void Scale(V* v, float k) {
    int t;
    __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%1); mfc1 %0, %2; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(v), "f"(k) : "memory");
}
static inline void Scale2(V* r, V* a, float k) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(a), "f"(k) : "memory"); }
static inline float Rad(float d) { return d * 0.017453292f; }
static inline void Sub(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void Add(V* r, V* a, V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline unsigned char GunReady(Gun* g) {
    unsigned char ok = 0;
    if (SecondaryStateTable[g->a].Ok() && SecondaryStateTable[g->b].Ok()) ok = 1;
    return ok;
}
static inline unsigned char HasGun(Owner* o) {
    if (o->gun) return GunReady(o->gun);
    return 0;
}
inline FireMsg::FireMsg(Obj* tgt, int tm, V p, float y) {
    vtable = D_004E0200;
    serial = *(tgt ? &tgt->serial : &g_NoneWord);
    team = tm;
    f38 = 0;
    pos = p;
    yaw = y;
}
static inline float Range(Npc* self) {
    float r = self->range;
    if (r < 0.0f) r = WorthShootingThreshold;
    return r;
}
static inline unsigned char InReach(Npc* self, void* inv) {
    if (cWeapon_GetEquipmentType(inv) == 1) return 1;
    float r = Range(self);
    if (self->ai->Get()) {
        Sub58* o = ((Sub58Holder*)cSafePtr_cGOBJ_opCast_cGOBJPtr((Hdl*)&self->ai->obj))->s;
        unsigned char big = 0;
        if (o && o->Big()) big = 1;
        if (!big) r *= 0.5f;
    }
    if (self->reach < r) return 0;
    return 1;
}

void cNPC_HandleWeaponFiring(Npc* self, float dt)
{
    Owner* own = self->owner;
    void* inv = own->inv;
    Obj* tgt = self->ai->Get();
    unsigned char fire = 0;

    if (self->burst <= 0 && self->cool <= 0.0f && self->owner->mode != 0x1A)
        self->burst = self->burstMax;

    if (self->forced > 0) {
        fire = 1;
    } else if (self->fireMode && self->burst > 0) {
        bool down;
        unsigned char c;
        c = self->owner->Cls();
        down = true;
        if (c != 3 && c != 2) down = false;
        if (!down) {
            if (self->fireMode == 2) {
                fire = 1;
            } else if (self->cnt->n > 0 && self->owner->mode == 0x1A && cWeapon_IsFullyAutomatic(inv)) {
                fire = 1;
            } else if (!self->Busy(1)) {
                Ai* ai = self->ai;
                unsigned char f = 0;
                if (ai->b0) { unsigned char b = ai->b2; if (b) f = 1; }
                if (f || (Range(self) < 0.01f && tgt)) {
                    if (cWeapon_GetEquipmentType(inv) != 1) {
                        float r = Range(self);
                        if (self->ai->Get()) {
                            Sub58* o = ((Sub58Holder*)cSafePtr_cGOBJ_opCast_cGOBJPtr((Hdl*)&self->ai->obj))->s;
                            unsigned char big = 0;
                            if (o && o->Big()) big = 1;
                            if (!big) r *= 0.5f;
                        }
                        if (!(self->reach < r)) fire = 1;
                    } else {
                        fire = 1;
                    }
                }
            }
        }
    }

    if (fire && cWeapon_Ready(inv) && self->cool2 <= 0.0f) {
        if (cWeapon_GetEquipmentType(inv) != 1) {
            if (cWeapon_ReadyToFire(inv, 0)) {
            if (HasGun(own)) {
                    FireMsg m(tgt, self->team, V(0.0f, 0.0f, 0.0f, 0.0f), 0.0f);
                    m.kind = 1;
                    QueueMessage_cMessageR_cSystemP_int(&m, self->owner, 0);
                } else {
                    cWeapon_FireIfReady(inv, 0, -1, 0, 0);
                }
            }
        } else {
            if (!own->busy) {
                if (self->h2.Get()) tgt = self->h2.Get();
                if (tgt) {
                    Obj* t = tgt;
                    float ry = RandF();
                    V off(RandF(), ry, 0.0f, 0.0f);
                    Scale(&off, self->spread);
                    V pos = t->GetMtx().T();
                    if (self->lead) {
                        Sub(&pos, &pos, &self->owner->GetMtx().T());
                        __int128 z = 0;
                        Scale2(&pos, &pos, 0.8f);
                        { V* b = &self->owner->GetMtx().T(); Add(&pos, &pos, b); }
                    }
                    Add(&pos, &pos, &off);
                    FireMsg m(0, self->team, pos, Rad(self->rate));
                    m.kind = 1;
                    QueueMessage_cMessageR_cSystemP_int(&m, self->owner, 0);
                }
            }
        }
    }

    if (cWeapon_Ready(inv)) {
        if (!(self->cool2 <= 0.0f)) self->cool2 -= dt;
        if (!(self->cool <= 0.0f)) self->cool -= dt;
    }

    if (g_IsMultiplayer) {
        char* s = self->owner->stats;
        if (s) s += 0x1C;
        unsigned short* p = (unsigned short*)s;
        if (p && fire) (*p)++;
    }
}
#undef SecondaryStateTable /* merge_units */
#undef cSafePtr_cGOBJ_opCast_cGOBJPtr /* merge_units */
#undef cWeapon_IsFullyAutomatic /* merge_units */
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00150340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00150340 */

/* merge_units: begin func_00150BF0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#pragma pop

#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cCharActionMsg_TargetInfo_dtor, D_004E0200, D_004E0840, cMessage_dtor)
static inline void merge_flush_func_00150BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00150BF0 */

/* merge_units: begin func_00150C60 */
#pragma push /* merge_units */
#pragma bool off
typedef struct C6Obj_150C60 { int pad[3]; int serial; } C6Obj_150C60;
typedef struct C6Ref_150C60 { C6Obj_150C60* obj; int serial; } C6Ref_150C60;
static inline int C6Valid(void* p) { return p != 0; }
C6Obj_150C60* cSafePtr_cGOBJ_opCast_cGOBJPtr(C6Ref_150C60* ref) {
    C6Obj_150C60* o = ref->obj;
    unsigned char ok = 1;
    if (!C6Valid(o) == 0) {
        if (o->serial != ref->serial) ok = 0;
    }
    return ok ? o : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00150C60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00150C60 */

/* merge_units: begin func_00150CA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)

struct V_00150CA0 { float x, y, z, w; V_00150CA0() {} V_00150CA0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
  V_00150CA0(const V_00150CA0& o) { V_00150CA0* d = this; Q16(d, &o); } V_00150CA0& operator=(const V_00150CA0& o) { V_00150CA0* d = this; Q16(d, &o); return *this; } } __attribute__((aligned(16)));
struct M_00150CA0 { V_00150CA0 r[4]; V_00150CA0& T() { return r[3]; } V_00150CA0& R(int i) { return r[i]; } } __attribute__((aligned(16)));

struct Obj_00150CA0 { VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d) virtual V_00150CA0 Pos(int); VPAD8(e) VPAD1(f) virtual M_00150CA0 Mtx(); VPAD2(g) virtual M_00150CA0 Mtx2();
    char pad4[8]; int serial; char pad10[0x3C]; int cls; const int& Ser() { return serial; } };
struct Hdl_00150CA0 { Obj_00150CA0* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj_00150CA0* Get() { return IsValid() ? obj : 0; } };
struct Ai_00150CA0 { V_00150CA0 pos; char pad10[0x10]; unsigned char b0 : 1; unsigned char b1 : 1; unsigned char b2 : 1; unsigned char b3 : 1; unsigned char b4 : 1; char pad21[0x1F]; Obj_00150CA0* obj; int serial;
    int IsValid() { unsigned char ok = 1; if (!IsNullNV(obj) && !SameNV(obj->serial, serial)) ok = 0; return ok; }
    Obj_00150CA0* Get() { return IsValid() ? obj : 0; } };
struct Inv { char pad[0x84]; unsigned char state; };
struct Owner_00150CA0 {
    VPAD32(a) VPAD16(b) VPAD8(c) virtual M_00150CA0 Mtx(); VPAD2(d) virtual M_00150CA0 Mtx2();
    char pad4[0x3520];
    Inv* inv;               /* 0x3524 */
    char pad3528[0x5C];
    char* stats;            /* 0x3584 */
};
struct Npc_00150CA0 {
    VPAD32(a) VPAD8(b) virtual int Busy(int); VPAD2(c) virtual unsigned char Stance();
    char pad4[0x2C];
    Owner_00150CA0* owner;           /* 0x30 */
    char pad34[0x44];
    float range;            /* 0x78 */
    char pad7C[0x98];
    int state;              /* 0x114 */
    char pad118[4];
    int team;               /* 0x11C */
    char pad120[0x10];
    int forced;             /* 0x130 */
    char pad134[8];
    unsigned char alert;    /* 0x13C */
    unsigned char mode;     /* 0x13D */
    char pad13E[0x42];
    Hdl_00150CA0 h180;               /* 0x180 */
    char pad188[8];
    unsigned char hasH;     /* 0x190 */
    char pad191[0x1B];
    Ai_00150CA0* ai;                 /* 0x1AC */
};

struct SRec { char pad[0x24]; float dist; };

extern "C" {
extern int g_HumanActorClassKey;
extern int D_004EA770;
extern char g_ActorActionMsgClass[], D_004E0840[], D_004E0140[], D_004E01A0[];
SRec* cAITarget_GetAwareness(Ai_00150CA0*, Obj_00150CA0*);
V_00150CA0* cMatrix_GetAxis(M_00150CA0*, int);
#if 0 /* merge_units */
void cMessage_dtor(void*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((a0), (short)(a1))) /* merge_units */

unsigned char cNPC_HandleWeaponAiming(Npc_00150CA0* self);
}

#pragma define_section MSG_DTOR ".dtors_drop" far_absolute RX

struct MsgB_00150CA0 {
    void* vtable; void* type; int pad8[6]; unsigned char kind; char pad21[3];
    MsgB_00150CA0(void* t) { cMessage_ctor_cMessageNameR(this, t); }
    void Send(void* to, int f) { kind = 1; QueueMessage_cMessageR_cSystemP_int(this, to, f); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgB_00150CA0() { cMessage_dtor(this, 0); }
};
struct MsgI : MsgB_00150CA0 {
    int id; unsigned char sub; char pad29[3];
    MsgI(int i, unsigned char s) : MsgB_00150CA0(g_ActorActionMsgClass) { vtable = D_004E0840; id = i; sub = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgI() { vtable = D_004E0840; }
};
struct MsgPos : MsgI {
    V_00150CA0 pos;
    MsgPos(const V_00150CA0& p) : MsgI(0x39, 4) { vtable = D_004E0140; V_00150CA0* d = &pos; Q16(d, &p); }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgPos() {}
} __attribute__((aligned(16)));
struct MsgSer : MsgI {
    int ser;
    MsgSer(const int& s) : MsgI(0x3E, 5) { vtable = D_004E01A0; ser = s; }
    __declspec(weak) __declspec(MSG_DTOR) ~MsgSer() {}
};

static inline int Ld(int* p) { return *p; }
static inline int Ld2(const int& p) { return p; }
static inline int Key0() { int* p = &g_HumanActorClassKey; return *p; }
static inline int Key1() { int* p = &D_004EA770; return *p; }
static inline float Range_00150CA0(Npc_00150CA0* self) {
    float r = self->range;
    if (r < 0.0f) r = WorthShootingThreshold;
    return r;
}
static inline unsigned char Engaged(Ai_00150CA0* ai) { unsigned char f = 0; if (ai->b0) { unsigned char b = ai->b2; if (b) f = 1; } return f; }
static inline Hdl_00150CA0* H180(Npc_00150CA0* self) { return self->hasH ? &self->h180 : 0; }
static inline void Sub_00150CA0(V_00150CA0* r, V_00150CA0* a, V_00150CA0* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void Add_00150CA0(V_00150CA0* r, V_00150CA0* a, V_00150CA0* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vadd.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void Scale2_00150CA0(V_00150CA0* r, V_00150CA0* a, float k) { int t; __asm__ volatile(".set noreorder; lqc2 vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, vf2; vmulx.xyzw vf1, vf1, vf2x; sqc2 vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(a), "f"(k) : "memory"); }
static inline float Len(V_00150CA0* a) { float r = 0.0f; int t; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline float Len2(const V_00150CA0& v) { float r = 0.0f; int t; const V_00150CA0* a = &v; __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
static inline void AddTo(V_00150CA0& d, const V_00150CA0& b) { Add_00150CA0(&d, &d, (V_00150CA0*)&b); }
/* Diff's return copy uses its own 16-byte copy (this/&o operands directly) to get retail's register choice. */
struct VD : V_00150CA0 { VD() {} VD(const VD& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
static inline VD Diff(const V_00150CA0& a, const V_00150CA0& b) { VD t; Sub_00150CA0(&t, (V_00150CA0*)&a, (V_00150CA0*)&b); return t; }
static inline V_00150CA0 Scaled(const V_00150CA0& a, float k) { V_00150CA0 t; Scale2_00150CA0(&t, (V_00150CA0*)&a, k); return t; }
static inline V_00150CA0 Sum(const V_00150CA0& a, const V_00150CA0& b) { V_00150CA0 t; Add_00150CA0(&t, (V_00150CA0*)&a, (V_00150CA0*)&b); return t; }

unsigned char cNPC_HandleWeaponAiming(Npc_00150CA0* p)
{
    Obj_00150CA0* tgt;
    Npc_00150CA0* self = p;
    unsigned char ok = 1;
    unsigned char idle = 1;
    unsigned char aim = 1;
    Inv* inv = self->owner->inv;
    tgt = self->ai->Get();
    V_00150CA0 pos;

    if (self->mode) {
        if (inv->state == 6 || (self->alert && (self->state == 4 || self->state == 11 || self->state == 3 || self->state == 9))) {
            ok = 0;
        } else if (self->forced > 0) {
            ok = 1;
        } else if (self->mode == 1) {
            if (!self->ai->b3 && !self->ai->b2) {
                ok = 0;
            } else {
                if (!Engaged(self->ai)) {
                    if (!self->ai->b3 || !self->ai->b1) {
                        if (!(Range_00150CA0(self) < 0.01f)) {
                            SRec* r = cAITarget_GetAwareness(self->ai, tgt);
                            if (!r || !(r->dist < 5.0f)) ok = 0;
                        }
                    }
                }
            }
        }
        if (self->Busy(1)) {
            { Hdl_00150CA0* h = 0; if (self->hasH) h = &self->h180; pos = h->Get()->Pos(-1); }
            { int* k = &D_004EA770; Hdl_00150CA0* h = 0; if (self->hasH) h = &self->h180; if (h->Get()->cls == Ld(k)) pos.z += 4.5f; }
            MsgPos(pos).Send(self->owner, 0);
            MsgI(0x3F, 0).Send(self->owner, 0);
            idle = 0;
        } else if (ok) {
            idle = 0;
            if (tgt && Engaged(self->ai)) {
                MsgPos(tgt->Pos(self->team)).Send(self->owner, 0);
                MsgSer(tgt->Ser()).Send(self->owner, 0);
                aim = 0;
            } else if (self->ai->b4) {
                pos = self->ai->pos;
                if (!(Len2(Diff(pos, self->owner->Mtx().T())) <= 3.0f)) {
                    if (tgt) { int c = tgt->cls; if (c == Key0() || c == Key1()) pos.z += 4.5f; }
                } else {
                    AddTo(pos, Scaled(self->owner->Mtx2().R(1), 20.0f));
                }
                if (!idle) {
                    MsgPos(pos).Send(self->owner, 0);
                    MsgI(0x3F, 0).Send(self->owner, 0);
                }
            } else {
                pos = Sum(self->owner->Mtx2().T(), Scaled(*cMatrix_GetAxis(&self->owner->Mtx2(), 1), 20.0f));


                pos.z += 4.5f;
                MsgPos(pos).Send(self->owner, 0);
                MsgI(0x3F, 0).Send(self->owner, 0);
            }
        }
    }
    if (idle) {
        MsgI(0x3A, 0).Send(self->owner, 0);
        MsgI(0x3F, 0).Send(self->owner, 0);
    }
    if (g_IsMultiplayer) {
        unsigned char st = self->Stance();
        char* s = self->owner->stats;
        if (s) s += 0x1C;
        if (s) { s[5] = !idle; s[4] = st; }
        char* q = self->owner->stats;
        if (q) {
            q[0] = aim;
            *(float*)(q + 0x10) = pos.x;
            *(float*)(q + 0x14) = pos.y;
            *(float*)(q + 0x18) = pos.z;
        }
    }
    return ok;
}
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00150CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00150CA0 */
