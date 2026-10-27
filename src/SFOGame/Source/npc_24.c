/*
 * SFOGame/Source/npc: 4 files, 0014D900-0014DD50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014D900 */
#pragma push /* merge_units */
#include "types.h"
typedef struct Msg_0014D900 {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
    char pad29[7];
} Msg_0014D900;
typedef struct Self_0014D900 {
    char pad[0x30]; void* target; char pad34[0x9C - 0x34]; int prio;
    char padA0[0x124 - 0xA0]; int flags; float f128;
} Self_0014D900;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern void cMessage_ctor_cMessageNameR(Msg_0014D900* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(Msg_0014D900* msg, void* target, int flags);
extern void cMessage_dtor(Msg_0014D900* msg, int flags);
#define SEND1(V) { Msg_0014D900 msg; cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass); msg.b28 = 0; msg.vtable = D_004E0840; msg.value = V; { void* t = self->target; msg.b20 = 1; QueueMessage_cMessageR_cSystemP_int(&msg, t, 0); } msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
#define SEND0(V) { Msg_0014D900 msg; cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass); msg.b28 = 0; msg.vtable = D_004E0840; msg.value = V; QueueMessage_cMessageR_cSystemP_int(&msg, self->target, 0); msg.vtable = D_004E0840; cMessage_dtor(&msg, 0); }
void cNPC_DoAction(Self_0014D900* self, unsigned char type, int prio, float f)
{
    switch (type) {
    case 9:
        if (prio >= self->prio) {
            self->prio = prio;
            SEND1(2)
            self->flags &= ~1;
        }
        break;
    case 1:
        if (prio >= self->prio) {
            self->prio = prio;
            SEND1(1)
            self->flags |= 1;
        }
        break;
    case 2:
        SEND0(8)
        self->flags |= 2;
        break;
    case 10:
        SEND1(0xA)
        self->flags &= ~4;
        break;
    case 4:
        SEND1(9)
        self->flags |= 4;
        break;
    case 8:
        if (!(self->flags & 8))
            SEND0(0x40)
        self->flags |= 8;
        self->f128 = f;
        break;
    case 11:
        if (self->flags & 8) {
            SEND0(0x41)
            self->flags &= ~8;
        }
        break;
    }
}
static inline void merge_flush_func_0014D900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014D900 */

/* merge_units: begin func_0014DCA0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef struct GObj {
    char pad[0x2C];
    unsigned char enabled; /* +0x2C */
    unsigned char active;  /* +0x2D */
    unsigned char paused;  /* +0x2E */
} GObj;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v4A();
    virtual void LookAround(int priority); /* +0x134 */
    virtual void v4C(); virtual void v4D(); virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51();
    virtual void v52();
    virtual void StopMovement(float time, int priority); /* +0x154 */
    char pad04[0x30 - 4];
    GObj* owner; /* +0x30 */
    char pad34[0x13C - 0x34];
    char alert; /* +0x13C */
    char pad13D[0x168 - 0x13D];
    unsigned char resumeAlert; /* +0x168 */
};

static inline bool IsLive(GObj* o)
{
    return o->active && o->enabled && !o->paused;
}

/* While the owner is live: look around, stop moving for a long time, and remember to resume if it was alert. */
extern "C" void cNPC_StopAndLookAround(cNPC* self, int priority)
{
    if (IsLive(self->owner)) {
        int wasAlert = self->alert;
        self->LookAround(priority);
        self->StopMovement(10000.0f, priority);
        if ((unsigned char)wasAlert)
            self->resumeAlert = 1;
    }
}
static inline void merge_flush_func_0014DCA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014DCA0 */

/* merge_units: begin func_0014DD50 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; unsigned char b2C; unsigned char b2D; unsigned char b2E; } NpcSt_14DD50;
typedef struct { char pad[0x4C]; int x4C; char pad50[4]; int x54; char pad58[4]; int x5C; } NpcAi_14DD50;
typedef struct {
    char pad0[0x30];
    NpcSt_14DD50* st;
    char pad34[0x13C - 0x34];
    unsigned char b13C;
    char pad13D[0x1B0 - 0x13D];
    NpcAi_14DD50* ai;
} Npc_14DD50;
extern void cNPC_NewLookAtList(Npc_14DD50* n, int a, int b, int c);
extern void cNPC_AddLinkedNodesToLookAt(Npc_14DD50* n, int a, int b, int c, float f);

void cNPC_LookAround(Npc_14DD50* n, int a)
{
    NpcSt_14DD50* st = n->st;
    int id;
    int ok = st->b2D && st->b2C && !st->b2E;
    if (ok) {
        id = -1;
        cNPC_NewLookAtList(n, 0, 1, a);
        if (n->b13C == 1)
            id = n->ai->x54;
        if (n->ai->x4C >= 0)
            cNPC_AddLinkedNodesToLookAt(n, -1, n->ai->x4C, id, 1.0f);
        else
            cNPC_AddLinkedNodesToLookAt(n, n->ai->x5C, -1, id, 1.0f);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014DD50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014DD50 */

/* merge_units: begin func_0014DE30 */
#pragma push /* merge_units */
typedef struct { int time; unsigned char active; char pad[0x14 - 5]; } E_DE30;
typedef struct { char pad[0x178]; E_DE30 e[3]; } S_DE30;
void cNPC_ResumeAILookAt(S_DE30* self, int t)
{
    int i = 0;
    S_DE30* p = self;
    do {
        if (p->e[0].active && p->e[0].time == t) {
            unsigned char k = i;
            E_DE30* e = &self->e[k]; S_DE30* q = (S_DE30*)((char*)self + k * 0x14); if (t >= q->e[0].time) { q->e[0].active = 0; e->time = 0;
            }
        }
        i++;
        p = (S_DE30*)((char*)p + 0x14);
    } while (i < 3);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014DE30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014DE30 */
