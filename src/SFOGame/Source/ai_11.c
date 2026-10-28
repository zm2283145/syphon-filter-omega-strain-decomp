/*
 * SFOGame/Source/ai: 7 files, 0016A970-0016ADB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016A970 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int cMemMan_Allocate(...);
int cTeam_TeamNetCreate(...);
int cTeam_InitTeamData(...);
extern unsigned char D_0048A100;
extern char D_0049C650;
extern int D_004EE620;
extern unsigned char D_004EE628;
extern unsigned char g_ProfileLockEnabled;
extern unsigned char g_IsMultiplayer;
}
extern "C" void cTeam_Init(void) {
    int temp_s0;

    if (g_IsMultiplayer != 0) {
        if (D_004EE628 == 0) {
            cTeam_TeamNetCreate();
        }
        if (D_0048A100 != 0) {
            D_0048A100 = 0;
            cTeam_InitTeamData(D_004EE620);
        }
    } else {
        if (D_004EE620 == 0) {
            {
                AllocGuard g;
            temp_s0 = cMemMan_Allocate(0, 0x100, &D_0049C650, 0x71B);
            }
            asm { nop } /* scheduling barrier: keeps the store after the unlock, as in retail */
            D_004EE620 = temp_s0;
        }
        cTeam_InitTeamData(D_004EE620);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016A970(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016A970 */

/* merge_units: begin func_0016AA80 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
extern void* D_004EE620;
#endif /* merge_units */
#define D_004EE620 (*(void **)&D_004EE620) /* merge_units */



#if 0 /* merge_units */
extern signed char D_0048A100;
#endif /* merge_units */
#define D_0048A100 (*(signed char*)&D_0048A100) /* merge_units */



extern unsigned char D_005723C8;
#if 0 /* merge_units */
extern char D_0049C650[];
#endif /* merge_units */
#define D_0049C650 ((char*)&D_0049C650) /* merge_units */



}
extern "C" void cTeam_Reset(void)
{
    void* p = D_004EE620;
    if (p && !D_004EE628) {
        AllocGuard g;
        cMemMan_Deallocate(0, p, D_0049C650, 0x6FE);
    }
    D_004EE620 = 0;
    D_004EE628 = 0;
    D_0048A100 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016AA80(void) {}
#undef D_004EE620 /* merge_units */
#undef D_0048A100 /* merge_units */
#undef D_0049C650 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016AA80 */

/* merge_units: begin func_0016AB50 */
#pragma push /* merge_units */
#include "ai_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * cAI script-native bindings. args[0] is the cAI receiver.
 */


extern int cGOBJ_SOBJ_toInt(AIGObj*);

/* Stores the elapsed time (args[1]) on the AI; volatile mirrors the original stack temporary. */
int Script_cAI_SendTimeElapsedMessage(AIScriptArg* args) {
    volatile int bits = args[1].i;
    ((cAI*)args[0].p)->timeElapsed = *(float*)&bits;
    return 0;
}

int Script_GetGOBJ_AI(AIScriptArg* args) {
    return cGOBJ_SOBJ_toInt(((cAI*)args[0].p)->gobj);
}

int Script_cAI_IsVisible(AIScriptArg* args) {
    return ((cAI*)args[0].p)->gobj->unk38 != 0x80;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016AB50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016AB50 */

/* merge_units: begin func_0016ABB0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cAI_0016ABB0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual int GetTeam(); /* +0x68 */
};

/* Script native: returns the team of args[0]. */
extern "C" int Script_cAI_Team(ScriptArg* args)
{
    cAI_0016ABB0* ai = (cAI_0016ABB0*)args[0].p;
    volatile int team = ai->GetTeam();
    return team;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016ABB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016ABB0 */

/* merge_units: begin func_0016ABE0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


struct cAI_0016ABE0 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25();
    virtual void SetTeam(int value); /* +0xA0 */
};

/* Script native: cAI::SetTeam(args[1]) on args[0]; returns 0. */
extern "C" int Script_cAI_SetTeam(ScriptArg* args)
{
    int part[1];
    cAI_0016ABE0* obj;
    part[0] = args[1].i;
    obj = (cAI_0016ABE0*)args[0].p;
    obj->SetTeam(*(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016ABE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016ABE0 */

/* merge_units: begin func_0016AC20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cAI script-type registration.
 */


extern char D_004EE5D8[];
extern char D_004EE5E0[];
extern char D_00555070[];
extern int cScriptInterpreter_CallEvent(int, int, int);
extern int* func_0022F170(void);
extern int* func_0026ED30(void);
extern int* func_0026ED70(void);
extern int* cAIBodyMovedMsg_SOBJ_getClassId(void);
extern int* cAIPickupableAwarenessMsg_SOBJ_getClassId(void);
extern int* cAIWeaponFiredMsg_SOBJ_getClassId(void);
extern int* cAINewAwarenessMsg_SOBJ_getClassId(void);
extern int* cAIDestinationReachedMsg_SOBJ_getClassId(void);
extern int* cAIWaypointReachedMsg_SOBJ_getClassId(void);
extern int* cAITimeElapsedMsg_SOBJ_getClassId(void);
extern int* cAIDeadMsg_SOBJ_getClassId(void);
extern int* cAIDeactivatedMsg_SOBJ_getClassId(void);
extern int* cAIActivatedMsg_SOBJ_getClassId(void);
extern int cScriptBase_declareMsgUse(int, int);
extern void cScriptBase_declareParent(int, int);

/*
 * Registers the cAI script type under its parent, then registers each of the
 * message script types cAI accepts (one key getter per message type).
 */
int cAI_SOBJ_init(void) {
    int* key;

    key = func_0022F170();
    cScriptBase_declareParent(*(int*)D_004EE5E0, *key);
    key = cAIActivatedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIDeactivatedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIDeadMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAITimeElapsedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIWaypointReachedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIDestinationReachedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAINewAwarenessMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIWeaponFiredMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIPickupableAwarenessMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = cAIBodyMovedMsg_SOBJ_getClassId();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = func_0026ED70();
    cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
    key = func_0026ED30();
    return cScriptBase_declareMsgUse(*(int*)D_004EE5E0, *key);
}

/* Address of the cAI script-type key. */
int cAI_SOBJ_getClassId(void) {
    return (int)D_004EE5D8;
}

int cAI_getSOBJClassId(void) {
    return *(int*)D_004EE5D8;
}

int cAI_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent((int)D_00555070, a0, a1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016AC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016AC20 */

/* merge_units: begin func_0016ADB0 */
#pragma push /* merge_units */
#include "vslot_pad.h"

#pragma cplusplus on
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); }
    V& operator-=(const V& o) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { V r[4]; const V& Pos() const { return r[3]; } };
static inline void SubEq(V* d, const V* a, const V* b) {
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void Copy(V* d, const V* s) { __int128 t = *(__int128*)s; *(__int128*)d = t; }
static inline float Len(V* p) {
    float len;
    len = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2 %0, vf4" : "=r"(len) : "r"(p) : "memory");
    return len;
}
class Actor;
class Ctrl {
public:
    VPAD16(a) VPAD4(b)
    virtual int IsNpc();
    virtual int IsOther();
    VPAD16(c) VPAD8(d) VPAD4(e)
    virtual void Hear(char kind, Actor* who, float dist);
};
class Actor {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual V GetPos();
    virtual M GetMtx();
    VPAD4(f) VPAD2(h) VPAD1(i)
    virtual unsigned char State();
    char pad04[0x8];
    int id;
    char pad10[0x1C];
    unsigned char enabled;
    unsigned char active;
    unsigned char streaming;
    char pad2F[0x29];
    Ctrl* ctrl;
};
struct Hnd { Actor* p; int id; };
static inline bool IdEq(Actor* p, Hnd* h) { return p->id == h->id; }
static inline Actor* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
struct Grenade { char pad[0x124]; Hnd mThrower; };
struct Human { char pad[0x33AC]; float deafTimer; };
struct Awareness { char pad[0x38]; unsigned char inViewcone; unsigned char los; };
struct Npc : Ctrl { };
struct NpcF { char pad[0x1AC]; void* target; };
struct Msg {
    void* vt;
    char pad04[0x20];
    unsigned char type;
    unsigned char kind;
    char pad26[6];
    float radius;
    int objectId;
    int toObjectId;
    char pad38[8];
    V position;
};
struct MName { int id; };
struct LNode { LNode* prev; LNode* next; Hnd* value; };
union It { LNode* p; };
struct Sys;
extern "C" {
extern MName D_004EE5C8;
extern char g_NpcThinkList[];
MName* cMessage_Name(Msg* m);
Actor* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
unsigned char cSystem_HandleMessage(Sys* s, Msg* m);
Human* cNPC_Human(Npc* n);
Awareness* cAITarget_GetAwareness(void* t, Actor* a);
void std_list_cActiveListItemPtr_begin_void_2(It* r, void* l);
void std_list_cActiveListItemPtr_end_void_2(It* r, void* l);
void cConstLListIterator_cActiveListItemPtr_ctor(It* d, It* s);
}
static inline bool Downed(Actor* a) { bool r; unsigned char s = a->State(); r = true; if (s != 3 && s != 2) r = false; return r; }
static inline bool IsNpc(Actor* a) { bool r = false; if (a->ctrl && a->ctrl->IsNpc()) r = true; return r; }
static inline bool IsOther(Actor* a) { bool r = false; if (a->ctrl && a->ctrl->IsOther()) r = true; return r; }
static inline bool Alive(Actor* a) { bool r = 0; if (a->active && a->enabled) r = 1; return r; }
static inline bool Live(Actor* a) { return !a->streaming; }
static inline bool Targetable(Actor* a) { bool r = 0; if (Alive(a) && Live(a)) r = 1; return r; }
static inline bool NotEnd(It& it, void* l, It& t2, It& t3) { std_list_cActiveListItemPtr_end_void_2(&t2, l); cConstLListIterator_cActiveListItemPtr_ctor(&t3, &t2); return it.p != t3.p; }
static inline It Begin(void* l) { It t; std_list_cActiveListItemPtr_begin_void_2(&t, l); It r; cConstLListIterator_cActiveListItemPtr_ctor(&r, &t); return r; }
static inline It End(void* l) { It t; std_list_cActiveListItemPtr_end_void_2(&t, l); It r; cConstLListIterator_cActiveListItemPtr_ctor(&r, &t); return r; }

extern "C" unsigned char cAISoundSystem_HandleMessage(Sys* self, Msg* message)
{
    unsigned char res = 1;
    unsigned char soundHeard = 0;
    MName* nm = cMessage_Name(message);
    if (nm->id == D_004EE5C8.id) {
        Msg& msg = *message;
        Actor* who = nGobjManager_LookupGOBJ_cObjectIdR(&msg.objectId);
        if (who) {
            if (msg.type == 2) {
                Actor* gobj = nGobjManager_LookupGOBJ_cObjectIdR(&msg.toObjectId);
                if (msg.kind == 7) {
                    if (IsNpc(gobj) || IsOther(gobj))
                        gobj->ctrl->Hear(msg.kind, who, 0.0f);
                }
            } else {
                void* activeList = g_NpcThinkList;
                It it; It t1; It t3; It t0; It t2;
                std_list_cActiveListItemPtr_begin_void_2(&t0, activeList);
                cConstLListIterator_cActiveListItemPtr_ctor(&t1, &t0);
                it = t1;
                for (; NotEnd(it, activeList, t2, t3); it.p = it.p->next) {
                    Actor* gobj = HGet(it.p->value);
                    if (!gobj) continue;
                    if (gobj->id == msg.objectId) continue;
                    if (Downed(gobj)) continue;
                    if (!IsNpc(gobj)) continue;
                    Npc* npc = (Npc*)gobj->ctrl;
                    if (cNPC_Human(npc)->deafTimer <= 0.0f) {
                        V delta(gobj->GetMtx().Pos());
                        if (msg.type == 0) {
                            delta -= who->GetMtx().Pos();
                        } else {
                            delta -= msg.position;
                        }
                        float distance = Len(&delta);
                        if (distance < msg.radius)
                            npc->Hear(msg.kind, who, distance);
                    }
                    if (!soundHeard && msg.kind == 5) {
                        Grenade* grenade = (Grenade*)who;
                        Actor* thrower = HGet(&grenade->mThrower);
                        if (thrower && Targetable(thrower) && HGet(&grenade->mThrower) != gobj) {
                            Awareness* awareness = cAITarget_GetAwareness(((NpcF*)npc)->target, thrower);
                            if (awareness && awareness->los && awareness->inViewcone)
                                npc->Hear(msg.kind, who, 0.0f);
                        }
                    }
                }
            }
        }
    } else {
        res = cSystem_HandleMessage(self, message);
    }
    return res;
}
static inline void merge_flush_func_0016ADB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016ADB0 */
