/*
 * SFOGame/Source/Generator: 13 files, 0021CA30-0021D110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021CA30 */
#pragma push /* merge_units */
#include "types.h"

typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char b20;
    char pad21[3];
    int value;
    unsigned char b28;
} E7Msg;
typedef struct { char pad[0xB8]; float minDistSq; } E7Gen;
extern unsigned char g_IsMultiplayer;
extern char D_004A4A78[];
extern char D_004DB5E0[];
extern void cMessage_ctor_cMessageNameR(E7Msg* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(E7Msg* msg, void* target, int flags);
extern void cMessage_dtor(E7Msg* msg, int flags);
int Script_cGenerator_SetMinSpawnDistance(int* args)
{
    volatile int iv = args[1];
    float d = *(float*)&iv;
    E7Gen* gen = (E7Gen*)args[0];
    gen->minDistSq = d * d;
    if (g_IsMultiplayer) {
        float v = gen->minDistSq;
        E7Msg msg;
        cMessage_ctor_cMessageNameR(&msg, D_004A4A78);
        msg.vtable = D_004DB5E0;
        msg.b28 = 1;
        msg.b20 = 4;
        msg.value = (int)v;
        QueueMessage_cMessageR_cSystemP_int(&msg, gen, 0);
        msg.vtable = D_004DB5E0;
        cMessage_dtor(&msg, 0);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CA30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CA30 */

/* merge_units: begin func_0021CAF0 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int state; signed char b28; char pad29[3]; } Msg_21CAF0;
typedef struct { char pad[0xD1]; unsigned char paused; } Gen_21CAF0;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_21CAF0* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((E7Msg *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg_21CAF0* m, void* target, int x);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((E7Msg *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Msg_21CAF0* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((E7Msg *)(a0), (a1))) /* merge_units */


int Script_cGenerator_Unpause(Gen_21CAF0** args)
{
    unsigned char st;
    Gen_21CAF0* g;
    g = args[0];
    g->paused = 0;
    if (g_IsMultiplayer) {
        Msg_21CAF0 m;
        st = g->paused;
        cMessage_ctor_cMessageNameR(&m, D_004A4A78);
        m.state = st;
        m.b28 = 0;
        m.vt = D_004DB5E0;
        m.kind = 4;
        QueueMessage_cMessageR_cSystemP_int(&m, g, 0);
        m.vt = D_004DB5E0;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CAF0(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021CAF0 */

/* merge_units: begin func_0021CB90 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad04[0x1C]; signed char kind; char pad21[3]; int state; signed char b28; char pad29[3]; } Msg_21CB90;
typedef struct { char pad[0xD1]; unsigned char paused; } Gen_21CB90;
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg_21CB90* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) (cMessage_ctor_cMessageNameR((E7Msg *)(a0), (a1))) /* merge_units */


#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg_21CB90* m, void* target, int x);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((E7Msg *)(a0), (a1), (a2))) /* merge_units */


#if 0 /* merge_units */
extern void cMessage_dtor(Msg_21CB90* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((E7Msg *)(a0), (a1))) /* merge_units */


int Script_cGenerator_Pause(Gen_21CB90** args)
{
    unsigned char st;
    Gen_21CB90* g;
    g = args[0];
    g->paused = 1;
    if (g_IsMultiplayer) {
        Msg_21CB90 m;
        st = g->paused;
        cMessage_ctor_cMessageNameR(&m, D_004A4A78);
        m.state = st;
        m.b28 = 0;
        m.vt = D_004DB5E0;
        m.kind = 4;
        QueueMessage_cMessageR_cSystemP_int(&m, g, 0);
        m.vt = D_004DB5E0;
        cMessage_dtor(&m, 0);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CB90(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021CB90 */

/* merge_units: begin func_0021CC30 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;

struct cGenerator {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Disable(int value); /* +0x68 */
};

/* Script native: cGenerator::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cGenerator_DisableAnon(ScriptArg* args)
{
    cGenerator* obj = (cGenerator*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CC30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CC30 */

/* merge_units: begin func_0021CC60 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0021CC60 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_0021CC60;

/* Virtual-call view of cGenerator: only the slots used here are named (vtable offset in comments). */
struct cGenerator_0021CC60 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cGenerator::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cGenerator_EnableAnon(ScriptArg_0021CC60* args)
{
    cGenerator_0021CC60* obj = (cGenerator_0021CC60*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CC60 */

/* merge_units: begin func_0021CC90 */
#pragma push /* merge_units */
#pragma cplusplus on
class F7Sub_21C {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB(); virtual void v22(); virtual void v23(); virtual void Disable(int v);
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; F7Sub_21C* sub; } F7Gen_21C;
typedef struct { F7Sub_21C* target; int arg; } F7Ctx_21C;
extern "C" {
F7Gen_21C* cGOBJ_SOBJ_convert(int h);
void cNPCInfoObject_ctor(int* t);
int cNPCInfoObject_GetOwner_cObjectIdR(int* t, unsigned int* id);
void cNPCInfoObject_dtor(int* t, int f);
}
static inline unsigned char F7IsA(F7Gen_21C* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char F7IsB(F7Gen_21C* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" int Script_cGenerator_DisableBy(F7Ctx_21C* c)
{
    F7Gen_21C* g = cGOBJ_SOBJ_convert(c->arg);
    F7Sub_21C* t = c->target;
    if (g_IsMultiplayer) {
        int v = -1;
        if (g) {
            if (F7IsA(g) || F7IsB(g)) {
                int tmp[1];
                cNPCInfoObject_ctor(tmp);
                v = cNPCInfoObject_GetOwner_cObjectIdR(tmp, &g->id);
                cNPCInfoObject_dtor(tmp, -1);
            } else {
                v = ((g->id & 0x7F000000) >> 24) - 1;
            }
        }
        t->Disable(v);
    } else {
        t->Disable(-1);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CC90 */

/* merge_units: begin func_0021CDD0 */
#pragma push /* merge_units */
#pragma cplusplus on
class F8Sub_21C {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(); virtual int IsB(); virtual void v22(); virtual void Enable(int v);
};
typedef struct { char pad[0xC]; unsigned int id; char pad10[0x48]; F8Sub_21C* sub; } F8Gen_21C;
typedef struct { F8Sub_21C* target; int arg; } F8Ctx_21C;
extern "C" {
#if 0 /* merge_units */
F8Gen_21C* cGOBJ_SOBJ_convert(int h);
#endif /* merge_units */
#define cGOBJ_SOBJ_convert(a0) ((F8Gen_21C *)cGOBJ_SOBJ_convert((a0))) /* merge_units */


}
static inline unsigned char F8IsA(F8Gen_21C* g) { unsigned char r = 0; if (g->sub && g->sub->IsA()) r = 1; return r; }
static inline unsigned char F8IsB(F8Gen_21C* g) { unsigned char r = 0; if (g->sub && g->sub->IsB()) r = 1; return r; }
extern "C" int Script_cGenerator_EnableBy(F8Ctx_21C* c)
{
    F8Gen_21C* g = cGOBJ_SOBJ_convert(c->arg);
    F8Sub_21C* t = c->target;
    if (g_IsMultiplayer) {
        int v = -1;
        if (g) {
            if (F8IsA(g) || F8IsB(g)) {
                int tmp[1];
                cNPCInfoObject_ctor(tmp);
                v = cNPCInfoObject_GetOwner_cObjectIdR(tmp, &g->id);
                cNPCInfoObject_dtor(tmp, -1);
            } else {
                v = ((g->id & 0x7F000000) >> 24) - 1;
            }
        }
        t->Enable(v);
    } else {
        t->Enable(-1);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CDD0(void) {}
#undef cGOBJ_SOBJ_convert /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021CDD0 */

/* merge_units: begin func_0021CF10 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Script native: cGenerator::Disable(-1) on args[0]; returns 0. */
extern "C" int Script_cGenerator_Disable(ScriptArg* args)
{
    cGenerator* obj = (cGenerator*)args[0].p;
    obj->Disable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CF10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CF10 */

/* merge_units: begin func_0021CF40 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef union ScriptArg_0021CF40 { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg_0021CF40;

/* Virtual-call view of cGenerator: only the slots used here are named (vtable offset in comments). */
struct cGenerator_0021CF40 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void Enable(int who); /* +0x64 */
};

/* Script native: cGenerator::Enable(-1) on args[0]; returns 0. */
extern "C" int Script_cGenerator_Enable(ScriptArg_0021CF40* args)
{
    cGenerator_0021CF40* obj = (cGenerator_0021CF40*)args[0].p;
    obj->Enable(-1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CF40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CF40 */

/* merge_units: begin func_0021CF70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004F56D8;      /* NPC message base script type key */
extern int D_004F56F0;      /* cSpawnedNPCMsg type key */
extern int D_004F56F8;      /* cSpawnedNPCMsg script type id */
extern int D_004F5700;      /* cDespawnedNPCMsg type key */
extern int D_004F5708;      /* cDespawnedNPCMsg script type id */
extern int D_004F5710;      /* cGenerator script type key */
extern int D_004F5718;      /* cGenerator script type id */
extern char D_00555070[];   /* global script filter */
extern int cScriptInterpreter_CallEvent(void* filter, int a1, int a2);
extern int* cGOBJ_SOBJ_getClassId(void);
extern int cScriptBase_declareMsgUse(int type, int iface);
extern void cScriptBase_declareParent(int type, int parentType);

/* cGenerator derives from cGObj and accepts the spawned/despawned messages. */
int cGenerator_SOBJ_init(void) {
    cScriptBase_declareParent(D_004F5718, *cGOBJ_SOBJ_getClassId());
    cScriptBase_declareMsgUse(D_004F5718, D_004F56F0);
    return cScriptBase_declareMsgUse(D_004F5718, D_004F5700);
}

int cGenerator_getSOBJClassId(void) {
    return D_004F5710;
}

int cGenerator_ScriptHandleMessage(int a0, int a1) {
    return cScriptInterpreter_CallEvent(D_00555070, a0, a1);
}

void cDespawnedNPCMsg_SOBJ_init(void) {
    cScriptBase_declareParent(D_004F5708, D_004F56D8);
}

int cDespawnedNPCMsg_getSOBJClassId(void) {
    return D_004F5700;
}

void cSpawnedNPCMsg_SOBJ_init(void) {
    cScriptBase_declareParent(D_004F56F8, D_004F56D8);
}

int cSpawnedNPCMsg_getSOBJClassId(void) {
    return D_004F56F0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021CF70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021CF70 */

/* merge_units: begin func_0021D060 */
#pragma push /* merge_units */
#pragma cplusplus on

class NpcE6 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual bool IsDead();
};

typedef struct GenE6 {
    char pad[0x58];
    NpcE6* npc;
} GenE6;

typedef struct GenMsgE6 {
    char pad[0x24];
    GenE6* gen;
} GenMsgE6;

extern "C" int cNPC_SOBJ_toInt(NpcE6* npc);

/* Script native: the NPC spawned by a generator message (null if dead). */
static inline bool GenE6_NpcDead(GenE6* g)
{
    bool dead = false;
    if (g->npc != 0 && g->npc->IsDead()) {
        dead = true;
    }
    return dead;
}

extern "C" int Script_cGeneratorMessageBase_GetNPC(GenMsgE6** args)
{
    GenMsgE6* msg = args[0];
    NpcE6* npc;
    if (msg->gen != 0 && !GenE6_NpcDead(msg->gen) && msg->gen->npc != 0) {
        npc = msg->gen->npc;
    } else {
        npc = 0;
    }
    return cNPC_SOBJ_toInt(npc);
}
static inline void merge_flush_func_0021D060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D060 */

/* merge_units: begin func_0021D0F0 */
#pragma push /* merge_units */
void cGeneratorMessageBase_SOBJ_init(void) {
}

int cGeneratorMessageBase_getSOBJClassId(void) {
    return D_004F56D8;
}
static inline void merge_flush_func_0021D0F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D0F0 */

/* merge_units: begin func_0021D110 */
#pragma push /* merge_units */
#include "message_pack.h"

#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(e, 0x24); MP_S(b, 8) = MP_S(e, 0x28);

DEFINE_MESSAGE_PACK(cGeneratorDataMessage_Pack, 16, D_004F56D0, PACK_BODY)
static inline void merge_flush_func_0021D110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021D110 */
