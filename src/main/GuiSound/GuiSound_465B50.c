#include "types.h"

typedef struct { char b[0x9C]; } SoundPart;
typedef struct {
    void* vtable;
    char base[0x1C];
    unsigned char local;
    char pad[0x57];
    SoundPart a;
    SoundPart b;
    char pad2[0x20];
} SoundEvent;
extern char g_Game[];
extern char D_004DADF0[];
extern void cStopSoundMsg_ctor_cSndFxR_bool(SoundEvent* ev, int id, int flags);
extern void QueueMessage_cMessageR_cSystemP_int(SoundEvent* ev, void* target, int flags);
extern void cFileMan_dtor(SoundPart* p, int flags);
extern void cMessage_dtor(SoundEvent* ev, int flags);

/* Builds a local sound event for id and sends it to the sound system; returns 1. */
int StopGuiSound(void* self, int id)
{
    SoundEvent ev;
    cStopSoundMsg_ctor_cSndFxR_bool(&ev, id, 0);
    ev.local = 1;
    QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
    ev.vtable = D_004DADF0;
    cFileMan_dtor(&ev.b, -1);
    cFileMan_dtor(&ev.a, -1);
    cMessage_dtor(&ev, 0);
    return 1;
}
