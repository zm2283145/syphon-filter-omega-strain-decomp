#pragma cplusplus on
#include "types.h"
struct H_251370 { int v; };
struct Act_251370 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_251370 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Msg_251370 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
struct Ent_251370 { int a0; int pad4; int v; char pad0C[0x10]; };
struct Self_251370 { Ent_251370 e[5]; char pad8C[4]; int count; int cur; };
extern "C" {
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004A79A8[];
void func_0036E5D0(void* m);
void FileMan_Release(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void Event_Send(void* msg, void* target, int flags);
void SoundAction_CtorVoice(void* action, int kind, char* name, int a, int b);
int func_00254CA0(int a, int b, int c);
void EffectMsg_WrapRequest(Msg_251370* msg, void* action);
}
#pragma push
#pragma opt_propagation off
extern "C" void PickupMenu_OnLeft(Self_251370* s)
{
    Act_251370* p;
    int v;
    char* pb;
    char* pa;
    v = func_00254CA0(s->e[0].a0, s->e[s->cur].v, 1);
    if (v != s->e[s->cur].v) {
        Act_251370 act;
        Msg_251370 m;
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
        { H_251370 h; H_251370* hp = &h; h.v = -1; p->h24 = *hp; }
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
        FileMan_Release(m.partB, -1);
        FileMan_Release(m.partA, -1);
        cMessage_dtor(&m, 0);
        s->e[s->cur].v = v;
        FileMan_Release(pb, -1);
        FileMan_Release(pa, -1);
    }
}
#pragma pop





