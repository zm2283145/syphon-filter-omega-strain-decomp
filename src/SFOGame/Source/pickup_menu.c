/*
 * SFOGame/Source/pickup_menu: 9 files, 00250EE0-002517D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00250EE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct Ent_250EE0 { unsigned char a; float b; };
struct Vec_250EE0 { int cap; int count; Ent_250EE0* data; };
extern "C" Ent_250EE0* std_vector_imp_cTargetZRotationStackSlot_erase(Vec_250EE0* v, Ent_250EE0* first, Ent_250EE0* last)
{
    Ent_250EE0* end;
    Ent_250EE0* s;
    Ent_250EE0* d;
    if (first == last)
        return first;
    end = v->data + v->count;
    if (end - last) {
        d = first;
        for (s = last; s < end; s++, d++)
            *d = *s;
    }
    v->count -= last - first;
    return first;
}
static inline void merge_flush_func_00250EE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00250EE0 */

/* merge_units: begin func_00251040 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "pickup_menu_types.h"

extern char g_PickupTextColour[]; /* text colour (Vec4f; set by sinit and backpack Global_SetPickupTextColor) */
extern float cTextArea_SetColor(PickupMenu* text, char* color);

/* Applies the pickup-menu text colour to a model's text object (model +0x74),
 * setting the two flags at +0x10/+0x11 first. */
float cPickupMenu_PickupEntry_SetupTextArea(PickupMenu* text) {
    text->unk10 = 1;
    text->unk11 = 1;
    return cTextArea_SetColor(text, g_PickupTextColour);
}
static inline void merge_flush_func_00251040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00251040 */

/* merge_units: begin func_00251060 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
/* Interface model instance (0x80 bytes, made by cInterfaceModel_CreateInstance); +0x74 is its text object. */
struct PickupMenuModel { char pad[0x74]; int text; };
/* The pickup menu: one or two interface models (the second is only made when
 * t == 0), each paired with a 0x68-byte game object (cHudWeapon_ctor). */
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
void* cMemMan_Allocate(int pool, int size, char* file, int line);
PickupMenuModel* cInterfaceModel_CreateInstance(int tmpl);
void viBufGetTs(float t, PickupMenuModel* m);
void cAnimator_AnimateTo(float t, PickupMenuModel* m);
#if 0 /* merge_units */
void cPickupMenu_PickupEntry_SetupTextArea(int x);
#endif /* merge_units */
#define cPickupMenu_PickupEntry_SetupTextArea(a0) ((void)cPickupMenu_PickupEntry_SetupTextArea((PickupMenu *)(a0))) /* merge_units */



void* cHudWeapon_ctor(void* obj);
void cInterfaceModel_Activate(int node, int visible, int recurse); /* show/hide a model tree */
}
/* Sets up the pickup menu: instantiates the panel model(s) and their game objects. */
extern "C" void cPickupMenu_PickupEntry_Activate(PickupMenuObj* s, signed char kind, int id, int t)
{
    void* p;
    s->kind = kind;
    s->id = id;
    s->x8 = 0;
    s->model1 = cInterfaceModel_CreateInstance(D_004F7E90);
    viBufGetTs(t, s->model1);
    cAnimator_AnimateTo(t + D_0048AEF8, s->model1);
    cPickupMenu_PickupEntry_SetupTextArea(s->model1->text);
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, 0x68, D_004A7998, 0x352);
    }
    if (p)
        p = cHudWeapon_ctor(p);
    s->obj1 = p;
    if (t) {
        cInterfaceModel_Activate(D_004F7E98, 0, 1);
        return;
    }
    cInterfaceModel_Activate(D_004F7E98, 1, 1);
    s->model2 = cInterfaceModel_CreateInstance(D_004F7E98);
    viBufGetTs(t, s->model2);
    cAnimator_AnimateTo(t + D_0048AEF8, s->model2);
    cPickupMenu_PickupEntry_SetupTextArea(s->model2->text);
    {
        AllocGuard g;
        p = cMemMan_Allocate(0, 0x68, D_004A7998, 0x35D);
    }
    if (p)
        p = cHudWeapon_ctor(p);
    s->obj2 = p;
}
#undef cPickupMenu_PickupEntry_SetupTextArea /* merge_units */
static inline void merge_flush_func_00251060(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00251060 */

/* merge_units: begin func_00251290 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int fx0; int fx1; void* s0; void* s1; } Obj_251290;
extern void cSystem_ActualScheduleDelete(int fx, float t);
extern void cInterfaceElement_Destroy(void* s);
extern void operator_delete(void* p);
Obj_251290* cPickupMenu_PickupEntry_dtor(Obj_251290* o, short flag)
{
    if (o) {
        if (o->fx0)
            cSystem_ActualScheduleDelete(o->fx0, 0.1f);
        if (o->fx1)
            cSystem_ActualScheduleDelete(o->fx1, 0.1f);
        if (o->s0)
            cInterfaceElement_Destroy(o->s0);
        if (o->s1)
            cInterfaceElement_Destroy(o->s1);
        if (flag > 0)
            operator_delete(o);
    }
    return o;
}
static inline void merge_flush_func_00251290(void) {} /* merge_units */
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

Unk251350* cPickupMenu_PickupEntry_ctor(Unk251350* self) {
    self->unk0C = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    return self;
}
static inline void merge_flush_func_00251350(void) {} /* merge_units */
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
void cFileMan_ctor_void(void* m);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
void cSndFx_SetSndFx(void* action, int kind, char* name, int a, int b);
int cBackpack_GetNextWeapon(int a, int b, int c);
void EffectMsg_WrapRequest(Msg_251370* msg, void* action);
}
#pragma push
#pragma opt_propagation off
extern "C" void cPickupMenu_PrevWeapon(Self_251370* s)
{
    Act_251370* p;
    int v;
    char* pb;
    char* pa;
    v = cBackpack_GetNextWeapon(s->e[0].a0, s->e[s->cur].v, 1);
    if (v != s->e[s->cur].v) {
        Act_251370 act;
        Msg_251370 m;
        p = &act;
        act.h24.v = -2;
        act.w20 = 0;
        pa = act.memberA;
        cFileMan_ctor_void(pa);
        pb = act.memberB;
        cFileMan_ctor_void(pb);
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
        cSndFx_SetSndFx(p, 3, D_004A79A8, 0, 0);
        EffectMsg_WrapRequest(&m, &act);
        m.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
        m.vtbl = D_004DAE30;
        cFileMan_dtor(m.partB, -1);
        cFileMan_dtor(m.partA, -1);
        cMessage_dtor(&m, 0);
        s->e[s->cur].v = v;
        cFileMan_dtor(pb, -1);
        cFileMan_dtor(pa, -1);
    }
}
#pragma pop
static inline void merge_flush_func_00251370(void) {} /* merge_units */
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
    int v = cBackpack_GetNextWeapon(s->e[0].a0, s->e[s->cur].v, 0);
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
        cFileMan_ctor_void(pa);
        pb = act.memberB;
        cFileMan_ctor_void(pb);
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
        cSndFx_SetSndFx(p, 3, D_004A79A8, 0, 0);
        EffectMsg_WrapRequest(&m, &act);
        m.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
        m.vtbl = D_004DAE30;
        cFileMan_dtor(m.partB, -1);
        cFileMan_dtor(m.partA, -1);
        cMessage_dtor(&m, 0);
        s->e[s->cur].v = v;
        cFileMan_dtor(pb, -1);
        cFileMan_dtor(pa, -1);
    }
}
#pragma pop
#undef EffectMsg_WrapRequest /* merge_units */
static inline void merge_flush_func_00251500(void) {} /* merge_units */
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
extern "C" void cPickupMenu_Prev(Self_251690* s)
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
        cFileMan_ctor_void(pa);
        pb = act.memberB;
        cFileMan_ctor_void(pb);
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
        cSndFx_SetSndFx(p, 3, D_004A79A8, 0, 0);
        EffectMsg_WrapRequest(&m, &act);
        m.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
        m.vtbl = D_004DAE30;
        cFileMan_dtor(m.partB, -1);
        cFileMan_dtor(m.partA, -1);
        cMessage_dtor(&m, 0);
        s->cur--;
        cFileMan_dtor(pb, -1);
        cFileMan_dtor(pa, -1);
    }
}
#pragma pop
#undef EffectMsg_WrapRequest /* merge_units */
static inline void merge_flush_func_00251690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00251690 */

/* merge_units: begin func_002517D0 */
#pragma push /* merge_units */
#pragma cplusplus on
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
#if 0 /* merge_units */
void EffectMsg_WrapRequest(Msg_2517D0* msg, void* action);
#endif /* merge_units */
#define EffectMsg_WrapRequest(a0, a1) (EffectMsg_WrapRequest((Msg_251370 *)(a0), (a1))) /* merge_units */

}
#pragma push
#pragma opt_propagation off
extern "C" void cPickupMenu_Next(Self_2517D0* s)
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
        cFileMan_ctor_void(pa);
        pb = act.memberB;
        cFileMan_ctor_void(pb);
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
        cSndFx_SetSndFx(p, 3, D_004A79A8, 0, 0);
        EffectMsg_WrapRequest(&m, &act);
        m.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
        m.vtbl = D_004DAE30;
        cFileMan_dtor(m.partB, -1);
        cFileMan_dtor(m.partA, -1);
        cMessage_dtor(&m, 0);
        s->cur++;
        cFileMan_dtor(pb, -1);
        cFileMan_dtor(pa, -1);
    }
}
#pragma pop
#undef EffectMsg_WrapRequest /* merge_units */
static inline void merge_flush_func_002517D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002517D0 */
