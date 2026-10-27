#ifndef SOUND_EVENT_H
#define SOUND_EVENT_H

/*
 * Sound request / sound event stack objects (gameSound + cSoundGOBJ users,
 * ~35 src files). Plain C or C++; MW kinds.
 *
 * SoundRequest (0x190), built by cSndFx_ctor_int_charP_cGOBJP_int 0x001CA210
 *   (req, type, name, voice, x180); two FileManEntry at +0x48/+0xE4.
 * SoundEvent (0x1D0) = CMsg header + SoundRequest at +0x30 + 0x10 tail,
 *   built by cStopSoundMsg_ctor_cSndFxR_bool 0x0020ECB0 (ev, action, 0). After QueueMessage_cMessageR_cSystemP_int
 *   the vtable is reset to D_004DADF0 (or D_004DAE30), then
 *     cFileMan_dtor(&ev.req.b, -1); cFileMan_dtor(&ev.req.a, -1);
 *     cMessage_dtor(&ev, 0);
 * SoundEventP (0x1C0, aligned 16) is the shorter form built by
 *   cPlaySoundMsg_ctor_cSndFxR 0x0020F990 / SoundMsg_WrapAction 0x0020F2A0.
 *   Pick the one whose size matches the target's stack frame.
 * The byte at +0x20 (CMsg.kind) is set to 1 for "immediate" sends.
 */
#include "cmessage.h"
#include "fileman_entry.h"

typedef struct SoundRequest {
    int type;               /* +0x00 */
    char pad04[0xC];
    char name[0x10];        /* +0x10 */
    void* voice;            /* +0x20 */
    int voiceId;            /* +0x24 -2 = none */
    char pad28[8];
    int x30;                /* +0x30 */
    int x34;
    int x38;
    char pad3C[0xC];
    FileManEntry a;         /* +0x48 */
    FileManEntry b;         /* +0xE4 */
    int x180;               /* +0x180 */
    short x184;
    char x186;
    char pad187[9];
} SoundRequest; /* 0x190 */

typedef struct SoundEvent {
    CMSG_HEADER;
    char pad24[0xC];
    SoundRequest req;       /* +0x30 (files at +0x78/+0x114) */
    char pad1C0[0x10];
} SoundEvent; /* 0x1D0 */

typedef struct SoundEventP {
    CMSG_HEADER;
    char pad24[0xC];
    SoundRequest req;       /* +0x30 */
} __attribute__((aligned(16))) SoundEventP; /* 0x1C0 */

LAYOUT_SIZE(SoundRequest, 0x190);
LAYOUT_OFFSET(SoundRequest, b, 0xE4);
LAYOUT_SIZE(SoundEvent, 0x1D0);
LAYOUT_OFFSET(SoundEvent, req, 0x30);
LAYOUT_SIZE(SoundEventP, 0x1C0);

#ifndef SOUND_EVENT_NO_PROTOS
#ifdef __cplusplus
extern "C" {
#endif
void cSndFx_ctor_int_charP_cGOBJP_int(void* req, int type, const char* name, void* voice, int x180);
void cStopSoundMsg_ctor_cSndFxR_bool(void* ev, void* action, int flags);
void cPlaySoundMsg_ctor_cSndFxR(void* ev, void* preset, void* owner);
void SoundMsg_WrapAction(void* ev, void* action);
#ifdef __cplusplus
}
#endif
#endif

#endif /* SOUND_EVENT_H */
