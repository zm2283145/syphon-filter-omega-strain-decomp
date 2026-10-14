/*
 * main/gameSound: range (4 files, 001C67C0-001C6B70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#pragma push
#pragma cplusplus on
#include "sound_event.h"
#pragma pop

/* merge_units: begin func_001C67C0 */
#pragma push /* merge_units */
typedef struct { char pad[0x48]; char a[0x9C]; char b[0xA2]; unsigned char play; char pad2[9]; } E2SoundReq;
typedef struct { void* vtbl; char pad[0x74]; char a[0x9C]; char b[0xAC]; } E2SoundMsg;
#if 0 /* merge_units */
extern void SoundRequest_Ctor(E2SoundReq*, int, char*, int, int);
#endif /* merge_units */
#define SoundRequest_Ctor(a0, a1, a2, a3, a4) (SoundRequest_Ctor((void *)(a0), (a1), (void *)(a2), (void *)(a3), (a4))) /* merge_units */

extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_004FFB50[];
extern char D_004DAE10[];
#if 0 /* merge_units */
extern void SoundMsg_WrapAction(E2SoundMsg*, E2SoundReq*);
#endif /* merge_units */
#define SoundMsg_WrapAction(a0, a1) (SoundMsg_WrapAction((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(E2SoundMsg*, void*, int);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_0036E220(void*, int);
#endif /* merge_units */
#define func_0036E220(a0, a1) ((void)func_0036E220((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(E2SoundMsg*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void Voice_PlayQuip(char* name, int arg) {
    E2SoundReq req;
    E2SoundMsg msg;
    int ok;
    if (name == 0 || *name == 0) return;
    SoundRequest_Ctor(&req, 4, name, 0, arg);
    req.play = 1;
    ok = D_005721C8 ? D_005721C0 : 1;
    if (ok) {
        SoundMsg_WrapAction(&msg, &req);
        Event_Send(&msg, D_004FFB50, 0);
        msg.vtbl = D_004DAE10;
        func_0036E220(msg.b, -1);
        func_0036E220(msg.a, -1);
        cMessage_dtor(&msg, 0);
    }
    func_0036E220(req.b, -1);
    func_0036E220(req.a, -1);
}
#undef SoundRequest_Ctor /* merge_units */
#undef SoundMsg_WrapAction /* merge_units */
#undef Event_Send /* merge_units */
#undef func_0036E220 /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C67C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C67C0 */

/* merge_units: begin func_001C6890 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Ctl_6890 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct Hum_6890 { char pad[0xC]; unsigned int flags; char pad10[4]; unsigned char b14; char pad15[0x43]; Ctl_6890* ctl; };
extern "C" {
extern char D_004DADF0[];
void Transport_Send(int, void*, int, int);
void Global_StopMusic(const char* name, Hum_6890* h);
}
static inline unsigned char IsPlayer_6890(Hum_6890* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_6890(Hum_6890* h) { int id; if (D_005721C8) { if (IsPlayer_6890(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
extern "C" void Global_StopMusic(const char* name, Hum_6890* h)
{
    SoundEvent ev;
    SoundRequest req;
    SoundRequest_Ctor(&req, 5, name, 0, 0);
    SoundEvent_Ctor(&ev, &req, 1);
    func_0036E220(&req.b, -1);
    func_0036E220(&req.a, -1);
    if (D_005721C8) {
        if (h->b14) {
            ev.kind = 1;
            Event_Send(&ev, D_004FFB50, 0);
        } else {
            Transport_Send(0, &ev, 0, LocalId_6890(h));
        }
    } else {
        Event_Send(&ev, D_004FFB50, 0);
    }
    ev.vtable = D_004DADF0;
    func_0036E220(&ev.req.b, -1);
    func_0036E220(&ev.req.a, -1);
    cMessage_dtor(&ev, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6890(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6890 */

/* merge_units: begin func_001C6A00 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern char D_004DAE30[];
void EffectMsg_WrapRequest(void*, void*);
void Global_PlayMusic(const char* name, Hum_6890* h);
}
extern "C" void Global_PlayMusic(const char* name, Hum_6890* h)
{
    SoundEventP ev;
    SoundRequest req;
    SoundRequest_Ctor(&req, 5, name, 0, 0);
    EffectMsg_WrapRequest(&ev, &req);
    func_0036E220(&req.b, -1);
    func_0036E220(&req.a, -1);
    if (D_005721C8) {
        if (h->b14) {
            ev.kind = 1;
            Event_Send(&ev, D_004FFB50, 0);
        } else {
            Transport_Send(0, &ev, 0, LocalId_6890(h));
        }
    } else {
        Event_Send(&ev, D_004FFB50, 0);
    }
    ev.vtable = D_004DAE30;
    func_0036E220(&ev.req.b, -1);
    func_0036E220(&ev.req.a, -1);
    cMessage_dtor(&ev, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6A00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6A00 */

/* merge_units: begin func_001C6B70 */
#pragma push /* merge_units */
/* Sound command payload built on the stack. */
typedef struct SndCmd {
    char pad00[0x48];
    char partA[0x9C];           /* 0x48 */
    char partB[0xAC];           /* 0xE4, size 0x190 */
} SndCmd;

/* Event message built on the stack (C++ object with inlined destructor). */
typedef struct EventMsg {
    void* vtable;
    char pad04[0x1C];
    unsigned char immediate;    /* 0x20 */
    char pad21[0x57];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;

#if 0 /* merge_units */
extern int D_004FFB50;
#endif /* merge_units */
#define D_004FFB50 (*(int*)&D_004FFB50) /* merge_units */

#if 0 /* merge_units */
extern int D_004DADF0;
#endif /* merge_units */
#define D_004DADF0 (*(int*)&D_004DADF0) /* merge_units */

#if 0 /* merge_units */
extern void SoundRequest_Ctor(SndCmd*, signed char, int, int, int);
#endif /* merge_units */
#define SoundRequest_Ctor(a0, a1, a2, a3, a4) (SoundRequest_Ctor((void *)(a0), (int)(a1), (void *)(a2), (void *)(a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern void SoundEvent_Ctor(EventMsg*, void*, int);
#endif /* merge_units */
#define SoundEvent_Ctor(a0, a1, a2) (SoundEvent_Ctor((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(EventMsg*, void*, int);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_0036E220(void*, int);
#endif /* merge_units */
#define func_0036E220(a0, a1) ((void)func_0036E220((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(EventMsg*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

static inline int Snd_Allowed(void) { return D_005721C8 ? D_005721C0 : 1; }
void Sound_StopForObject(int channel, int id, int obj) {
    EventMsg msg;
    SndCmd cmd;
    SoundRequest_Ctor(&cmd, (signed char)channel, id, obj, 0);
    SoundEvent_Ctor(&msg, &cmd, 0);
    func_0036E220(cmd.partB, -1);
    func_0036E220(cmd.partA, -1);
    if (!D_005721C8 || !Snd_Allowed()) msg.immediate = 1;
    Event_Send(&msg, &D_004FFB50, 0);
    msg.vtable = &D_004DADF0;
    func_0036E220(msg.partB, -1);
    func_0036E220(msg.partA, -1);
    cMessage_dtor(&msg, 0);
}
#undef D_004FFB50 /* merge_units */
#undef D_004DADF0 /* merge_units */
#undef SoundRequest_Ctor /* merge_units */
#undef SoundEvent_Ctor /* merge_units */
#undef Event_Send /* merge_units */
#undef func_0036E220 /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6B70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6B70 */
