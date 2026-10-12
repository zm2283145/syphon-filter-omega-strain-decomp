#pragma cplusplus on
#include "types.h"
struct H_245400 { int v; };
struct Act_245400 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_245400 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Msg_245400 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
extern "C" {
extern char D_004FFB50[];
extern char D_004FFC90[];
extern char D_004DAE10[];
extern char D_004A72A8[];
void func_0036E5D0(void* m);
void func_0036E220(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void Event_Send(void* msg, void* target, int flags);
int Objective_GetLevelMissionNumber(void* o);
int sprintf(char* buf, const char* fmt, ...);
void SoundAction_CtorVoice(void* action, int kind, char* name, int a, int b);
void SoundMsg_WrapAction(Msg_245400* msg, void* action);
}
#pragma push
#pragma opt_propagation off
extern "C" void Objective_QueueThresholdVoice(int a, int b)
{
    Act_245400 act;
    char buf[32];
    Act_245400* p;
    char* pb;
    char* pa;
    int n;
    p = &act;
    act.h24.v = -2;
    act.w20 = 0;
    pa = act.memberA;
    func_0036E5D0(pa);
    pb = act.memberB;
    func_0036E5D0(pb);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H_245400 h; H_245400* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    n = Objective_GetLevelMissionNumber(D_004FFC90);
    if (n > 0) {
        Msg_245400 m;
        sprintf(buf, D_004A72A8, n, a, b);
        SoundAction_CtorVoice(p, 4, buf, 0, 0);
        SoundMsg_WrapAction(&m, &act);
        m.flag = 1;
        Event_Send(&m, D_004FFB50, 1);
        m.vtbl = D_004DAE10;
        func_0036E220(m.partB, -1);
        func_0036E220(m.partA, -1);
        cMessage_dtor(&m, 0);
    }
    func_0036E220(pb, -1);
    func_0036E220(pa, -1);
}
#pragma pop

