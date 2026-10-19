/*
 * main/pickup_menu: 7 files, 00251040-00251290
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00251040 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "pickup_menu_types.h"

extern char g_PickupTextColour[]; /* text colour (Vec4f; set by sinit and backpack Global_SetPickupTextColor) */
extern float TextObj_SetColour(PickupMenu* text, char* color);

/* Applies the pickup-menu text colour to a model's text object (model +0x74),
 * setting the two flags at +0x10/+0x11 first. */
float PickupMenuEntry_SetPickupColor(PickupMenu* text) {
    text->unk10 = 1;
    text->unk11 = 1;
    return TextObj_SetColour(text, g_PickupTextColour);
}
#pragma pop /* merge_units */
/* merge_units: end func_00251040 */

/* merge_units: begin func_00251060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* Interface model instance (0x80 bytes, made by IeElement_Create); +0x74 is its text object. */
struct PickupMenuModel { char pad[0x74]; int text; };
/* The pickup menu: one or two interface models (the second is only made when
 * t == 0), each paired with a 0x68-byte game object (WeaponPreview_ctor). */
struct PickupMenuObj {
    signed char kind;        /* 0x00 */
    char pad1[3];
    int id;                  /* 0x04 */
    int x8;                  /* 0x08 cleared */
    void* obj1;              /* 0x0C game object for model1 */
    void* obj2;              /* 0x10 game object for model2 */
    PickupMenuModel* model1; /* 0x14 */
    PickupMenuModel* model2; /* 0x18 */
};
extern "C" {
extern int D_004F7E90; /* interface model template of the first panel */
extern int D_004F7E98; /* interface model template of the second panel */
extern int D_0048AEF8;
extern char D_004A7998[]; /* "pickup_menu.cc" */
void* Mem_Alloc(int pool, int size, char* file, int line);
PickupMenuModel* IeElement_Create(int tmpl);
void IeElement_EvaluateAt(float t, PickupMenuModel* m);
void IeElement_Fade(float t, PickupMenuModel* m);
#if 0 /* merge_units */
void PickupMenuEntry_SetPickupColor(int x);
#endif /* merge_units */
#define PickupMenuEntry_SetPickupColor(a0) ((void)PickupMenuEntry_SetPickupColor((PickupMenu *)(a0))) /* merge_units */


void* WeaponPreview_ctor(void* obj);
void IeNode_SetShown(int node, int visible, int recurse); /* show/hide a model tree */
}
/* Sets up the pickup menu: instantiates the panel model(s) and their game objects. */
extern "C" void PickupMenu_AddEntry(PickupMenuObj* s, signed char kind, int id, int t)
{
    void* p;
    s->kind = kind;
    s->id = id;
    s->x8 = 0;
    s->model1 = IeElement_Create(D_004F7E90);
    IeElement_EvaluateAt(t, s->model1);
    IeElement_Fade(t + D_0048AEF8, s->model1);
    PickupMenuEntry_SetPickupColor(s->model1->text);
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x68, D_004A7998, 0x352);
    }
    if (p)
        p = WeaponPreview_ctor(p);
    s->obj1 = p;
    if (t) {
        IeNode_SetShown(D_004F7E98, 0, 1);
        return;
    }
    IeNode_SetShown(D_004F7E98, 1, 1);
    s->model2 = IeElement_Create(D_004F7E98);
    IeElement_EvaluateAt(t, s->model2);
    IeElement_Fade(t + D_0048AEF8, s->model2);
    PickupMenuEntry_SetPickupColor(s->model2->text);
    {
        AllocGuard g;
        p = Mem_Alloc(0, 0x68, D_004A7998, 0x35D);
    }
    if (p)
        p = WeaponPreview_ctor(p);
    s->obj2 = p;
}
#undef PickupMenuEntry_SetPickupColor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00251060 */

/* merge_units: begin func_00251290 */
#pragma push /* merge_units */
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
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004A79A8[];
void Resource_Construct(void* m);
void FileMan_Release(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void Event_Send(void* msg, void* target, int flags);
void SoundAction_CtorVoice(void* action, int kind, char* name, int a, int b);
int Backpack_CycleItem(int a, int b, int c);
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
    v = Backpack_CycleItem(s->e[0].a0, s->e[s->cur].v, 1);
    if (v != s->e[s->cur].v) {
        Act_251370 act;
        Msg_251370 m;
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
        Event_Send(&m, g_Game, 1);
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
    int v = Backpack_CycleItem(s->e[0].a0, s->e[s->cur].v, 0);
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
        Resource_Construct(pa);
        pb = act.memberB;
        Resource_Construct(pb);
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
        Event_Send(&m, g_Game, 1);
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
        Resource_Construct(pa);
        pb = act.memberB;
        Resource_Construct(pb);
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
        Event_Send(&m, g_Game, 1);
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
