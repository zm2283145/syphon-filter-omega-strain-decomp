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
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004A79A8[];
void Resource_Construct(void* m);
void FileMan_Release(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void Event_Send(void* msg, void* target, int flags);
void SoundAction_CtorVoice(void* action, int kind, char* name, int a, int b);
void EffectMsg_WrapRequest(Msg_2517D0* msg, void* action);
}
#pragma push
#pragma opt_propagation off
extern "C" void PickupMenu_CursorNext(Self_2517D0* s)
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
        Resource_Construct(pa);
        pb = act.memberB;
        Resource_Construct(pb);
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
        Event_Send(&m, g_Game, 1);
        m.vtbl = D_004DAE30;
        FileMan_Release(m.partB, -1);
        FileMan_Release(m.partA, -1);
        cMessage_dtor(&m, 0);
        s->cur++;
        FileMan_Release(pb, -1);
        FileMan_Release(pa, -1);
    }
}
#pragma pop


