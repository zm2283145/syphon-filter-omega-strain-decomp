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
extern void cSndFx_ctor_int_charP_cGOBJP_int(E2SoundReq*, int, char*, int, int);
#endif /* merge_units */
#define cSndFx_ctor_int_charP_cGOBJP_int(a0, a1, a2, a3, a4) (cSndFx_ctor_int_charP_cGOBJP_int((void *)(a0), (a1), (void *)(a2), (void *)(a3), (a4))) /* merge_units */

extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern char g_Game[];
extern char D_004DAE10[];
#if 0 /* merge_units */
extern void SoundMsg_WrapAction(E2SoundMsg*, E2SoundReq*);
#endif /* merge_units */
#define SoundMsg_WrapAction(a0, a1) (SoundMsg_WrapAction((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(E2SoundMsg*, void*, int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cFileMan_dtor(void*, int);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(E2SoundMsg*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

void Voice_PlayQuip(char* name, int arg) {
    E2SoundReq req;
    E2SoundMsg msg;
    int ok;
    if (name == 0 || *name == 0) return;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 4, name, 0, arg);
    req.play = 1;
    ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        SoundMsg_WrapAction(&msg, &req);
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
        msg.vtbl = D_004DAE10;
        cFileMan_dtor(msg.b, -1);
        cFileMan_dtor(msg.a, -1);
        cMessage_dtor(&msg, 0);
    }
    cFileMan_dtor(req.b, -1);
    cFileMan_dtor(req.a, -1);
}
#undef cSndFx_ctor_int_charP_cGOBJP_int /* merge_units */
#undef SoundMsg_WrapAction /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cFileMan_dtor /* merge_units */
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
void cNetObj_SendMessage_int_cMessageR_int_int(int, void*, int, int);
void nGameSound_StopMusic(const char* name, Hum_6890* h);
}
static inline unsigned char IsPlayer_6890(Hum_6890* h) { unsigned char r = 0; if (h->ctl && h->ctl->IsPlayer()) r = 1; return r; }
static inline int LocalId_6890(Hum_6890* h) { int id; if (g_IsMultiplayer) { if (IsPlayer_6890(h)) id = ((h->flags & 0x7F000000) >> 24) - 1; else id = -1; } else id = 0; return id; }
extern "C" void nGameSound_StopMusic(const char* name, Hum_6890* h)
{
    SoundEvent ev;
    SoundRequest req;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 5, name, 0, 0);
    cStopSoundMsg_ctor_cSndFxR_bool(&ev, &req, 1);
    cFileMan_dtor(&req.b, -1);
    cFileMan_dtor(&req.a, -1);
    if (g_IsMultiplayer) {
        if (h->b14) {
            ev.kind = 1;
            QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
        } else {
            cNetObj_SendMessage_int_cMessageR_int_int(0, &ev, 0, LocalId_6890(h));
        }
    } else {
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
    }
    ev.vtable = D_004DADF0;
    cFileMan_dtor(&ev.req.b, -1);
    cFileMan_dtor(&ev.req.a, -1);
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
void nGameSound_PlayMusic(const char* name, Hum_6890* h);
}
extern "C" void nGameSound_PlayMusic(const char* name, Hum_6890* h)
{
    SoundEventP ev;
    SoundRequest req;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 5, name, 0, 0);
    EffectMsg_WrapRequest(&ev, &req);
    cFileMan_dtor(&req.b, -1);
    cFileMan_dtor(&req.a, -1);
    if (g_IsMultiplayer) {
        if (h->b14) {
            ev.kind = 1;
            QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
        } else {
            cNetObj_SendMessage_int_cMessageR_int_int(0, &ev, 0, LocalId_6890(h));
        }
    } else {
        QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 0);
    }
    ev.vtable = D_004DAE30;
    cFileMan_dtor(&ev.req.b, -1);
    cFileMan_dtor(&ev.req.a, -1);
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
extern int g_Game;
#endif /* merge_units */
#define g_Game (*(int*)&g_Game) /* merge_units */

#if 0 /* merge_units */
extern int D_004DADF0;
#endif /* merge_units */
#define D_004DADF0 (*(int*)&D_004DADF0) /* merge_units */

#if 0 /* merge_units */
extern void cSndFx_ctor_int_charP_cGOBJP_int(SndCmd*, signed char, int, int, int);
#endif /* merge_units */
#define cSndFx_ctor_int_charP_cGOBJP_int(a0, a1, a2, a3, a4) (cSndFx_ctor_int_charP_cGOBJP_int((void *)(a0), (int)(a1), (void *)(a2), (void *)(a3), (a4))) /* merge_units */

#if 0 /* merge_units */
extern void cStopSoundMsg_ctor_cSndFxR_bool(EventMsg*, void*, int);
#endif /* merge_units */
#define cStopSoundMsg_ctor_cSndFxR_bool(a0, a1, a2) (cStopSoundMsg_ctor_cSndFxR_bool((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(EventMsg*, void*, int);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) (QueueMessage_cMessageR_cSystemP_int((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cFileMan_dtor(void*, int);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) ((void)cFileMan_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(EventMsg*, int);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

static inline int Snd_Allowed(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
void nGameSound_StopSnd_eSndBank_charP_cGOBJP(int channel, int id, int obj) {
    EventMsg msg;
    SndCmd cmd;
    cSndFx_ctor_int_charP_cGOBJP_int(&cmd, (signed char)channel, id, obj, 0);
    cStopSoundMsg_ctor_cSndFxR_bool(&msg, &cmd, 0);
    cFileMan_dtor(cmd.partB, -1);
    cFileMan_dtor(cmd.partA, -1);
    if (!g_IsMultiplayer || !Snd_Allowed()) msg.immediate = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, &g_Game, 0);
    msg.vtable = &D_004DADF0;
    cFileMan_dtor(msg.partB, -1);
    cFileMan_dtor(msg.partA, -1);
    cMessage_dtor(&msg, 0);
}
#undef g_Game /* merge_units */
#undef D_004DADF0 /* merge_units */
#undef cSndFx_ctor_int_charP_cGOBJP_int /* merge_units */
#undef cStopSoundMsg_ctor_cSndFxR_bool /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cFileMan_dtor /* merge_units */
#undef cMessage_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6B70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6B70 */
