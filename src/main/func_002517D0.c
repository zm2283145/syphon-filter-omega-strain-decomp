#pragma cplusplus on
#include "types.h"
struct H_2517D0 { int v; };
struct Act_2517D0 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_2517D0 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Msg_2517D0 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
struct Self_2517D0 { char pad0[0x90]; int count; int cur; };
extern "C" {
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004A79A8[];
void func_0036E5D0(void* m);
void func_0036E220(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void Event_Send(void* msg, void* target, int flags);
void SoundAction_CtorVoice(void* action, int kind, char* name, int a, int b);
void EffectMsg_WrapRequest(Msg_2517D0* msg, void* action);
}
#pragma push
#pragma opt_propagation off
extern "C" void func_002517D0(Self_2517D0* s)
{
    if (s->cur + 1 < s->count) {
        Act_2517D0 act;
        Msg_2517D0 m;
        Act_2517D0* p;
        char* pb;
        char* pa;
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
        { H_2517D0 h; H_2517D0* hp = &h; h.v = -1; p->h24 = *hp; }
        p->w30 = 0;
        p->w34 = 0;
        p->w38 = 0;
        p->h184 = -1;
        p->w180 = 0;
        p->b186 = 0;
        SoundAction_CtorVoice(p, 3, D_004A79A8, 0, 0);
        EffectMsg_WrapRequest(&m, &act);
        m.flag = 1;
        Event_Send(&m, D_004FFB50, 1);
        m.vtbl = D_004DAE30;
        func_0036E220(m.partB, -1);
        func_0036E220(m.partA, -1);
        cMessage_dtor(&m, 0);
        s->cur++;
        func_0036E220(pb, -1);
        func_0036E220(pa, -1);
    }
}
#pragma pop


