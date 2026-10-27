/*
 * SFOGame/Source/human: 8 files, 00184B90-00184CE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00184B90 */
#pragma push /* merge_units */
#include "types.h"

/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Obj: only the slots used here are named (vtable offset in comments). */
struct Obj {
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
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F();
    virtual unsigned char GetState(); /* +0x108 */
};

/* Returns 0 while the virtual +0x108 state is 2 or 3, else 2. */
extern "C" int cHuman_GetTargetPriority(Obj* self)
{
    unsigned char state = self->GetState();
    bool busy = true;
    if ((unsigned)(state - 2) > 1) busy = false;
    return busy ? 0 : 2;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184B90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184B90 */

/* merge_units: begin func_00184BE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int cHuman_GetNumSubTargets(void) {
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184BE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184BE0 */

/* merge_units: begin func_00184BF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x4C]; unsigned char ok; char pad4D[3]; } T_184BF0;
extern T_184BF0 SecondaryStateTable[];
typedef struct { char pad[0x310]; unsigned char a; unsigned char b; } P_184BF0;
typedef struct { char pad[0x3314]; P_184BF0* p; } O_184BF0;static inline T_184BF0* Get_184BF0(int i) { return &SecondaryStateTable[i]; }
int cHuman_IsAimed(O_184BF0* o) { P_184BF0* p = o->p; if (p) { return Get_184BF0(p->a)->ok != 0 && Get_184BF0(p->b)->ok != 0; } return 0; }
static inline void merge_flush_func_00184BF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00184BF0 */

/* merge_units: begin func_00184C60 */
#pragma push /* merge_units */
#include "human_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cHuman_SetStatus(Actor* actor, int value) {
    ActorLink3584* link = actor->unk3584;

    if (link != 0) {
        link->unk32 = value;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184C60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184C60 */

/* merge_units: begin func_00184C80 */
#pragma push /* merge_units */
typedef struct { char pad[0x32]; unsigned char b32; } Sub32;
typedef struct { char pad[0x3584]; Sub32* sub; } Obj3584;

/* Returns sub->b32, or 0 if there is no sub object. */
unsigned char cHuman_GetStatus(Obj3584* self)
{
    if (self->sub)
        return self->sub->b32;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184C80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184C80 */

/* merge_units: begin func_00184CA0 */
#pragma push /* merge_units */
typedef struct Sub33 {
    char pad[0x33];
    unsigned char value;
} Sub33;

typedef struct Holder3584 {
    char pad[0x3584];
    Sub33* sub;
} Holder3584;

/* Returns sub->value (byte at +0x33) or 0 when the sub-object at +0x3584 is absent. */
int cHuman_HasHeadset(Holder3584* self) {
    Sub33* sub = self->sub;
    if (sub) {
        return sub->value;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184CA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184CA0 */

/* merge_units: begin func_00184CC0 */
#pragma push /* merge_units */
int cHuman_IsNetworked(void) {
    return 1;
}

unsigned char cHuman_IsGeneratorCreated(Actor* actor) {
    return actor->unk3598;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00184CC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00184CC0 */

/* merge_units: begin func_00184CE0 */
#pragma push /* merge_units */
/* cHuman_Shock: stun countdown; when expired, notify, play sound and send death state */
typedef struct { char d[0x9C]; } Pt1StStr;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Pt1StStr s78;
    Pt1StStr s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Pt1StSnd;
typedef struct {
    void* vt;
    char pad4[0x20];
    char flag;
    char pad25[3];
    float time;
    float arg;
} Pt1StShockMsg;
typedef struct {
    void* vt;
    char pad4[0x1C];
    char immediate;
    char pad21[3];
    int state;
    char sub;
    char pad29[3];
    int stamp;
} Pt1StStateMsg;
typedef struct Pt1StActor {
    char pad0[0x33BC];
    float shockTime;
    float shockMax;
    char pad33C4[4];
    char shockFlag;
} Pt1StActor;
extern char D_004EF078[];
extern void cMessage_getSOBJClassId();
extern void cNetShockMsg_dtor();
extern void cNetShockMsg_Clone();
extern void cNetShockMsg_Pack();
extern void cNetShockMsg_v05();
extern void cNetMsg_Pack();
void * const D_004DA9F0[8] = { (void*)0x0, (void*)0x0, (void*)cNetShockMsg_dtor, (void*)cNetShockMsg_Clone, (void*)cNetMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)cNetShockMsg_Pack, (void*)cNetShockMsg_v05 };
extern char D_004DCF10[];
extern char D_004F12D0[];
extern char g_Game[];
extern char g_ActorActionMsgClass[];
extern char D_004E01E0[];
extern char D_004E0840[];
extern char D_004DAE30[];
extern int D_0048A308;
extern void cMessage_ctor_cMessageNameR(void* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
extern void cMessage_dtor(void* msg, int flags);
extern void cPlaySoundMsg_ctor_cSndFxR(Pt1StSnd* e, void* preset, void* owner);
extern void cFileMan_dtor(Pt1StStr* s, int flag);
extern void cHuman_SetParticleEffect(Pt1StActor* a, int kind, int b, float f);

void cHuman_Shock(Pt1StActor* a, char flag, int notify, float time, float arg)
{
    if (a->shockTime < 0.0f) {
        Pt1StSnd snd;
        Pt1StStateMsg sm;
        if (notify) {
            Pt1StShockMsg m;
            cMessage_ctor_cMessageNameR(&m, D_004EF078);
            m.vt = ((char*)D_004DA9F0);
            m.arg = arg;
            m.flag = flag;
            m.time = time;
            QueueMessage_cMessageR_cSystemP_int(&m, a, 0);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
        cHuman_SetParticleEffect(a, 2, 1, 1.0f);
        cPlaySoundMsg_ctor_cSndFxR(&snd, D_004F12D0, a);
        snd.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&snd, g_Game, 0);
        cMessage_ctor_cMessageNameR(&sm, g_ActorActionMsgClass);
        sm.state = 7;
        sm.sub = 2;
        sm.vt = D_004E01E0;
        sm.immediate = 1;
        sm.stamp = D_0048A308;
        QueueMessage_cMessageR_cSystemP_int(&sm, a, 1);
        a->shockTime = 0.0f;
        a->shockMax = time;
        a->shockFlag = flag;
        sm.vt = D_004E0840;
        cMessage_dtor(&sm, 0);
        snd.vt = D_004DAE30;
        cFileMan_dtor(&snd.s114, -1);
        cFileMan_dtor(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
    } else {
        if (!(time <= a->shockMax))
            a->shockMax = time;
        if (flag)
            a->shockFlag = 1;
    }
}
static inline void merge_flush_func_00184CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00184CE0 */
