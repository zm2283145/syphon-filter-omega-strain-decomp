/*
 * main/message: 5 files, 00327090-00327530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00327090 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "message_two_member_dtor.h"

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_00327090, D_004DADF0)
#pragma pop /* merge_units */
/* merge_units: end func_00327090 */

/* merge_units: begin func_00327120 */
#pragma push /* merge_units */
/* Stops the current voice line and plays a new one. */

typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; } SoundMsg_327120;
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; char pad1C0[0x10]; } SoundEventMsg_327120;
typedef struct {
    char pad0[0x90]; char action[0x44]; unsigned char playing;
} Self_327120;

extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern void SoundEvent_Ctor(SoundEventMsg_327120* msg, void* action, int flags);
extern void Event_Send(void* msg, void* target, int flags);
#if 0 /* merge_units */
extern void FileMan_Release(void* part, int flags);
#endif /* merge_units */
#define FileMan_Release(a0, a1) (FileMan_Release((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

extern void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_327120* msg, void* action);

static inline void StopVoice_327120(Self_327120* self)
{
    SoundEventMsg_327120 stop;
    self->playing = 0;
    SoundEvent_Ctor(&stop, self->action, 0);
    stop.flag = 1;
    Event_Send(&stop, D_004FFB50, 1);
    stop.vtbl = D_004DADF0;
    FileMan_Release(stop.partB, -1);
    FileMan_Release(stop.partA, -1);
    cMessage_dtor(&stop, 0);
}

static inline void PlayVoice_327120(Self_327120* self, char* voice)
{
    SoundMsg_327120 play;
    StopVoice_327120(self);
    SoundAction_CtorVoice(self->action, 4, voice, 0, 0);
    self->playing = 0;
    SoundMsg_WrapAction(&play, self->action);
    play.flag = 1;
    Event_Send(&play, D_004FFB50, 1);
    play.vtbl = D_004DAE10;
    FileMan_Release(play.partB, -1);
    FileMan_Release(play.partA, -1);
    cMessage_dtor(&play, 0);
}

void func_00327120(Self_327120* self, char* voice)
{
    PlayVoice_327120(self, voice);
}
#undef FileMan_Release /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327120 */

/* merge_units: begin func_00327220 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_00327220, D_004DAE10)
#pragma pop /* merge_units */
/* merge_units: end func_00327220 */

/* merge_units: begin func_003272B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x10]; int n; char pad14[8]; int sel; } G_3272B0;
typedef struct { char pad[0x4C]; int count; G_3272B0* groups; int pad54; int cur; } S_3272B0;
extern "C" void GuiSlideShow_Refresh(S_3272B0* o, int dir);

static inline G_3272B0* At_3272B0(G_3272B0** gp, int i) { return &(*gp)[i]; }
#pragma push
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
extern "C" bool GuiSlideShow_Step(S_3272B0* o, int dir)
{
    unsigned char any = 0;
    int i;
    bool f;
    int oldSel;
    int oldCur;
    G_3272B0** gp;
    G_3272B0* g;
    for (i = 0; (unsigned char)any == 0 && i < o->count; i++) {
        if (o->groups[i].n) any = 1;
    }
    if (!any) return 0;
    if (o->cur < 0 || o->cur >= o->count) o->cur = 0;
    oldCur = o->cur;
    g = o->groups;
    g += oldCur;
    oldSel = g->sel;
    gp = &o->groups;
    if (oldSel < 0 || oldSel >= g->n) g->sel = 0;
    if (dir) {
        At_3272B0(gp, o->cur)->sel++;
        if (At_3272B0(gp, o->cur)->sel >= At_3272B0(gp, o->cur)->n) {
            f = 0;
            do {
                o->cur++;
                if (o->cur == o->count) o->cur = 0;
                if (o->groups[o->cur].n) f = 1;
            } while (!f);
            At_3272B0(gp, o->cur)->sel = 0;
        }
    } else {
        At_3272B0(gp, o->cur)->sel--;
        if (At_3272B0(gp, o->cur)->sel < 0) {
            f = 0;
            do {
                o->cur--;
                if (o->cur < 0) o->cur = o->count - 1;
                if (o->groups[o->cur].n) f = 1;
            } while (!f);
            At_3272B0(gp, o->cur)->sel = At_3272B0(gp, o->cur)->n - 1;
        }
    }
    GuiSlideShow_Refresh(o, dir);
    {
        bool r = 1;
        if (oldCur == o->cur && oldSel == At_3272B0(gp, o->cur)->sel) r = 0;
        return r;
    }
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003272B0 */

/* merge_units: begin func_00327530 */
#pragma push /* merge_units */
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; } SoundMsg_327530;
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; char pad1C0[0x10]; } SoundEventMsg_327530;
typedef struct { char pad[0x14]; unsigned short flags; } Widget_327530;
typedef struct { char name[0xC]; int fC; char sound[0xC]; unsigned char b1C; char pad1D[3]; int f20; int f24; int f28; } Item_327530;
typedef struct { char name[0x10]; int n; Item_327530* items; char pad18[4]; int sel; } Group_327530;
typedef struct {
    char pad0[0x4C]; int count; Group_327530* groups; char pad54[4]; int cur; int w5C; int w60; int w64; Widget_327530* w68;
    char pad6C[0x24]; char action[0x44]; unsigned char playing;
} Self_327530;
extern char D_004B8790[];
#if 0 /* merge_units */
extern void SoundEvent_Ctor(SoundEventMsg_327530* msg, void* action, int flags);
#endif /* merge_units */
#define SoundEvent_Ctor(a0, a1, a2) (SoundEvent_Ctor((SoundEventMsg_327120 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void FileMan_Release(void* part, int flags);
#endif /* merge_units */
#define FileMan_Release(a0, a1) (FileMan_Release((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void SoundMsg_WrapAction(SoundMsg_327530* msg, void* action);
#endif /* merge_units */
#define SoundMsg_WrapAction(a0, a1) (SoundMsg_WrapAction((SoundMsg_327120 *)(a0), (a1))) /* merge_units */

extern char* String_CStr(void* s);
extern int String_Length(void* s);
extern void GuiBitmapWidget_SetImage(int w, char* s, int v);
extern void GuiTextWidget_SetText(int w, char* s, int v);
extern int sprintf(char* buf, const char* fmt, ...);
extern int Agent_GetSelected(void* a, int i);
extern int AgentData_IsZeusViewed(int agent, int a, int b, int c);
extern void AgentData_SetLevelFlag(int agent, int a, int b, int c, int d);

static inline void PlayVoice_327530(Self_327530* self, char* voice)
{
    SoundMsg_327530 play;
    SoundEventMsg_327530 stop;
    self->playing = 0;
    SoundEvent_Ctor(&stop, self->action, 0);
    stop.flag = 1;
    Event_Send(&stop, D_004FFB50, 1);
    stop.vtbl = D_004DADF0;
    FileMan_Release(stop.partB, -1);
    FileMan_Release(stop.partA, -1);
    cMessage_dtor(&stop, 0);
    SoundAction_CtorVoice(self->action, 4, voice, 0, 0);
    self->playing = 0;
    SoundMsg_WrapAction(&play, self->action);
    play.flag = 1;
    Event_Send(&play, D_004FFB50, 1);
    play.vtbl = D_004DAE10;
    FileMan_Release(play.partB, -1);
    FileMan_Release(play.partA, -1);
    cMessage_dtor(&play, 0);
}

void GuiSlideShow_Show(Self_327530* self, int sel, int sub)
{
    char buf[0x20];
    Group_327530* g;
    int i;
    if (sel < 0 || sel >= self->count) sel = 0;
    if (sub < 0 || sub >= ((Group_327530*)((char*)self->groups + (sel << 5)))->n) sub = 0;
    self->cur = sel;
    if (self->w68) self->w68->flags &= ~2;
    i = self->cur;
    if (i < 0 || self->count <= i) g = 0;
    else g = &self->groups[i];
    if (g && g->n) {
        Item_327530* item;
        g->sel = sub;
        item = &g->items[sub];
        if (self->w5C) GuiBitmapWidget_SetImage(self->w5C, String_CStr(item), item->fC);
        if (String_Length(item->sound)) PlayVoice_327530(self, String_CStr(item->sound));
        if (self->w60) GuiTextWidget_SetText(self->w60, String_CStr(g), 0);
        if (self->w64) {
            sprintf(buf, "%d/%d", sub + 1, g->n);
            GuiTextWidget_SetText(self->w64, buf, 0);
        }
        if (item->b1C) {
            int a = Agent_GetSelected(D_004FFB50, -1);
            if (!AgentData_IsZeusViewed(a, item->f20, item->f24, item->f28)) {
                if (self->w68) self->w68->flags |= 2;
                AgentData_SetLevelFlag(a, item->f20, item->f24, item->f28, 1);
            }
        }
    } else {
        if (self->w5C) GuiBitmapWidget_SetImage(self->w5C, D_004B8790, 0);
        if (self->w60) GuiTextWidget_SetText(self->w60, D_004B8790, 0);
        if (self->w64) GuiTextWidget_SetText(self->w64, D_004B8790, 0);
        if (self->w68) self->w68->flags &= ~2;
    }
}
#undef SoundEvent_Ctor /* merge_units */
#undef FileMan_Release /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef SoundMsg_WrapAction /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00327530 */
