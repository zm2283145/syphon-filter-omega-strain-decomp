#include "types.h"
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