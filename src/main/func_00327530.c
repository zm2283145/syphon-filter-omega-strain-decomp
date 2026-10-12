#include "types.h"

typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; } SoundMsg_327530;
typedef struct { void* vtbl; char pad004[0x1C]; unsigned char flag; char pad021[0x57]; char partA[0x9C]; char partB[0xAC]; char pad1C0[0x10]; } SoundEventMsg_327530;
typedef struct { char pad[0x14]; unsigned short flags; } Widget_327530;
typedef struct { char name[0xC]; int fC; char sound[0xC]; unsigned char b1C; char pad1D[3]; int f20; int f24; int f28; } Item_327530;
typedef struct { char name[0x10]; int n; Item_327530* items; char pad18[4]; int sel; } Group_327530;
typedef struct {
    char pad0[0x4C]; int count; Group_327530* groups; char pad54[4]; int cur; int w5C; int w60; int w64; Widget_327530* w68;
    char pad6C[0x24]; char action[0x44]; unsigned char playing;
} Self_327530;

extern char D_004FFB50[];
extern char D_004DADF0[];
extern char D_004DAE10[];
extern char D_004B8790[];
extern void SoundEvent_Ctor(SoundEventMsg_327530* msg, void* action, int flags);
extern void Event_Send(void* msg, void* target, int flags);
extern void func_0036E220(void* part, int flags);
extern void cMessage_dtor(void* msg, int flags);
extern void SoundAction_CtorVoice(void* action, int kind, char* voice, int a, int b);
extern void SoundMsg_WrapAction(SoundMsg_327530* msg, void* action);
extern char* func_001692D0(void* s);
extern int func_002071F0(void* s);
extern void func_0043C890(int w, char* s, int v);
extern void func_0041BEB0(int w, char* s, int v);
extern int sprintf(char* buf, const char* fmt, ...);
extern int Agent_GetSelected(void* a, int i);
extern int func_00332950(int agent, int a, int b, int c);
extern void func_003328D0(int agent, int a, int b, int c, int d);

static inline void PlayVoice_327530(Self_327530* self, char* voice)
{
    SoundMsg_327530 play;
    SoundEventMsg_327530 stop;
    self->playing = 0;
    SoundEvent_Ctor(&stop, self->action, 0);
    stop.flag = 1;
    Event_Send(&stop, D_004FFB50, 1);
    stop.vtbl = D_004DADF0;
    func_0036E220(stop.partB, -1);
    func_0036E220(stop.partA, -1);
    cMessage_dtor(&stop, 0);
    SoundAction_CtorVoice(self->action, 4, voice, 0, 0);
    self->playing = 0;
    SoundMsg_WrapAction(&play, self->action);
    play.flag = 1;
    Event_Send(&play, D_004FFB50, 1);
    play.vtbl = D_004DAE10;
    func_0036E220(play.partB, -1);
    func_0036E220(play.partA, -1);
    cMessage_dtor(&play, 0);
}

void func_00327530(Self_327530* self, int sel, int sub)
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
        if (self->w5C) func_0043C890(self->w5C, func_001692D0(item), item->fC);
        if (func_002071F0(item->sound)) PlayVoice_327530(self, func_001692D0(item->sound));
        if (self->w60) func_0041BEB0(self->w60, func_001692D0(g), 0);
        if (self->w64) {
            sprintf(buf, "%d/%d", sub + 1, g->n);
            func_0041BEB0(self->w64, buf, 0);
        }
        if (item->b1C) {
            int a = Agent_GetSelected(D_004FFB50, -1);
            if (!func_00332950(a, item->f20, item->f24, item->f28)) {
                if (self->w68) self->w68->flags |= 2;
                func_003328D0(a, item->f20, item->f24, item->f28, 1);
            }
        }
    } else {
        if (self->w5C) func_0043C890(self->w5C, D_004B8790, 0);
        if (self->w60) func_0041BEB0(self->w60, D_004B8790, 0);
        if (self->w64) func_0041BEB0(self->w64, D_004B8790, 0);
        if (self->w68) self->w68->flags &= ~2;
    }
}