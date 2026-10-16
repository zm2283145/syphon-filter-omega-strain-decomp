/*
 * main/pickup_menu: 5 files, 00251290-00251690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00251290 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xC]; int fx0; int fx1; void* s0; void* s1; } Obj_251290;
extern void Object_DeleteLater(int fx, float t);
extern void IeElement_Release(void* s);
extern void operator_delete(void* p);
Obj_251290* PickupMenuEntry_dtor(Obj_251290* o, short flag)
{
    if (o) {
        if (o->fx0)
            Object_DeleteLater(o->fx0, 0.1f);
        if (o->fx1)
            Object_DeleteLater(o->fx1, 0.1f);
        if (o->s0)
            IeElement_Release(o->s0);
        if (o->s1)
            IeElement_Release(o->s1);
        if (flag > 0)
            operator_delete(o);
    }
    return o;
}
#pragma pop /* merge_units */
/* merge_units: end func_00251290 */

/* merge_units: begin func_00251350 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

Unk251350* PickupMenuEntry_ctor(Unk251350* self) {
    self->unk0C = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00251350 */

/* merge_units: begin func_00251370 */
#pragma push /* merge_units */
#pragma cplusplus on
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
#pragma pop /* merge_units */
/* merge_units: end func_00251370 */

/* merge_units: begin func_00251500 */
#pragma push /* merge_units */
#pragma cplusplus on
struct H_251500 { int v; };
struct Act_251500 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_251500 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Msg_251500 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
struct Ent_251500 { int a0; int pad4; int v; char pad0C[0x10]; };
struct Self_251500 { Ent_251500 e[5]; char pad8C[4]; int count; int cur; };
extern "C" {
#if 0 /* merge_units */
void EffectMsg_WrapRequest(Msg_251500* msg, void* action);
#endif /* merge_units */
#define EffectMsg_WrapRequest(a0, a1) (EffectMsg_WrapRequest((Msg_251370 *)(a0), (a1))) /* merge_units */

}
#pragma push
#pragma opt_propagation off
extern "C" void PickupMenu_OnRight(Self_251500* s)
{
    int v = func_00254CA0(s->e[0].a0, s->e[s->cur].v, 0);
    if (v != s->e[s->cur].v) {
        Act_251500 act;
        Msg_251500 m;
        Act_251500* p;
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
        { H_251500 h; H_251500* hp = &h; h.v = -1; p->h24 = *hp; }
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
#undef EffectMsg_WrapRequest /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00251500 */

/* merge_units: begin func_00251690 */
#pragma push /* merge_units */
#pragma cplusplus on
struct H_251690 { int v; };
struct Act_251690 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_251690 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Msg_251690 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
struct Self_251690 { char pad0[0x90]; int count; int cur; };
extern "C" {
#if 0 /* merge_units */
void EffectMsg_WrapRequest(Msg_251690* msg, void* action);
#endif /* merge_units */
#define EffectMsg_WrapRequest(a0, a1) (EffectMsg_WrapRequest((Msg_251370 *)(a0), (a1))) /* merge_units */

}
#pragma push
#pragma opt_propagation off
extern "C" void PickupMenu_CursorPrev(Self_251690* s)
{
    if (s->cur > 0) {
        Act_251690 act;
        Msg_251690 m;
        Act_251690* p;
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
        { H_251690 h; H_251690* hp = &h; h.v = -1; p->h24 = *hp; }
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
        s->cur--;
        FileMan_Release(pb, -1);
        FileMan_Release(pa, -1);
    }
}
#pragma pop
#undef EffectMsg_WrapRequest /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00251690 */
