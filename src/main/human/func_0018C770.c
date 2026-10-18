#include "types.h"
#pragma cplusplus on
extern "C" int sprintf(void *, const void *, ...);
struct H_18C770 { int v; };
struct Act_18C770 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_18C770 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Msg_18C770 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
struct Ctl_18C770 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); 
    virtual int v19();
};
struct Actor_18C770 {
    char pad00[0xC];
    unsigned int flags;
    char pad10[0x58 - 0x10];
    Ctl_18C770* ctl;
};
extern "C" {
extern char D_004FFB50[];
extern char D_004DAE10[];
extern char D_0049DC10[];
extern char D_004FFC90[];
extern unsigned char D_005721C8;
void Resource_Construct(void* m);
void FileMan_Release(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void Event_Send(void* msg, void* target, int flags);
int Objective_GetLevelMissionNumber(void* o);
void SoundAction_CtorVoice(void* action, int kind, char* name, int a, int b);
void SoundMsg_WrapAction(Msg_18C770* msg, void* action);
}
static inline bool HasCtl(Actor_18C770* a)
{
    bool ok = false;
    if (a->ctl && a->ctl->v19()) ok = true;
    return ok;
}
#pragma opt_propagation off
extern "C" void Actor_BuildVoiceKey(Actor_18C770* actor, int b)
{
    Act_18C770 act;
    char buf[32];
    Act_18C770* p; int n; char* pb; char* pa;
    p = &act;
    act.h24.v = -2;
    act.w20 = 0;
    pa = act.memberA;
    Resource_Construct(pa);
    pb = act.memberB;
    Resource_Construct(pb);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H_18C770 h; H_18C770* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    n = Objective_GetLevelMissionNumber(D_004FFC90);
    if (n > 0) {
        Msg_18C770 m;
        int idx;
        if (D_005721C8) {
            if (HasCtl(actor)) idx = ((actor->flags & 0x7F000000) >> 24) - 1;
            else idx = -1;
        } else {
            idx = 0;
        }
        sprintf(buf, D_0049DC10, n, b, idx + 1);
        SoundAction_CtorVoice(&act, 4, buf, 0, 0);
        SoundMsg_WrapAction(&m, &act);
        m.flag = 1;
        Event_Send(&m, D_004FFB50, 1);
        m.vtbl = D_004DAE10;
        FileMan_Release(m.partB, -1);
        FileMan_Release(m.partA, -1);
        cMessage_dtor(&m, 0);
    }
    FileMan_Release(pb, -1);
    FileMan_Release(pa, -1);
}
