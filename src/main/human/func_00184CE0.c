#include "types.h"
/* Global_ShockToDeath: stun countdown; when expired, notify, play sound and send death state */
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
extern void Message_GetScriptTypeKey();
extern void cNetShockMsg_dtor();
extern void cNetShockMsg_v01();
extern void cNetShockMsg_v04();
extern void cNetShockMsg_v05();
extern void cNetMsg_Pack();
void * const D_004DA9F0[8] = { (void*)0x0, (void*)0x0, (void*)cNetShockMsg_dtor, (void*)cNetShockMsg_v01, (void*)cNetMsg_Pack, (void*)Message_GetScriptTypeKey, (void*)cNetShockMsg_v04, (void*)cNetShockMsg_v05 };
extern char D_004DCF10[];
extern char D_004F12D0[];
extern char g_Game[];
extern char g_ActorActionMsgClass[];
extern char D_004E01E0[];
extern char D_004E0840[];
extern char D_004DAE30[];
extern int D_0048A308;
extern void Event_Construct(void* msg, void* name);
extern void Event_Send(void* msg, void* target, int immediate);
extern void cMessage_dtor(void* msg, int flags);
extern void SoundEvent_CtorFromPreset(Pt1StSnd* e, void* preset, void* owner);
extern void FileMan_Release(Pt1StStr* s, int flag);
extern void Actor_ShockReaction(Pt1StActor* a, int kind, int b, float f);

void Global_ShockToDeath(Pt1StActor* a, char flag, int notify, float time, float arg)
{
    if (a->shockTime < 0.0f) {
        Pt1StSnd snd;
        Pt1StStateMsg sm;
        if (notify) {
            Pt1StShockMsg m;
            Event_Construct(&m, D_004EF078);
            m.vt = ((char*)D_004DA9F0);
            m.arg = arg;
            m.flag = flag;
            m.time = time;
            Event_Send(&m, a, 0);
            m.vt = D_004DCF10;
            cMessage_dtor(&m, 0);
        }
        Actor_ShockReaction(a, 2, 1, 1.0f);
        SoundEvent_CtorFromPreset(&snd, D_004F12D0, a);
        snd.flag = 1;
        Event_Send(&snd, g_Game, 0);
        Event_Construct(&sm, g_ActorActionMsgClass);
        sm.state = 7;
        sm.sub = 2;
        sm.vt = D_004E01E0;
        sm.immediate = 1;
        sm.stamp = D_0048A308;
        Event_Send(&sm, a, 1);
        a->shockTime = 0.0f;
        a->shockMax = time;
        a->shockFlag = flag;
        sm.vt = D_004E0840;
        cMessage_dtor(&sm, 0);
        snd.vt = D_004DAE30;
        FileMan_Release(&snd.s114, -1);
        FileMan_Release(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
    } else {
        if (!(time <= a->shockMax))
            a->shockMax = time;
        if (flag)
            a->shockFlag = 1;
    }
}