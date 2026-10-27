#include "types.h"
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern int g_LocalPlayer;
extern char g_Game[];
extern char D_004DADF0[];
extern void cStopSoundMsg_ctor_cSndFxR_cGOBJP(SoundEvent* ev, void* src, void* voice);

int Script_cSoundGOBJ_KillSnd(void** arg0) {
    SoundEvent ev;
    char* o = *arg0;
    char* v;
    if (F_(o, 0x1F2, unsigned char)) v = o;
    else if (g_LocalPlayer) v = 0;
    else v = o;
    cStopSoundMsg_ctor_cSndFxR_cGOBJP(&ev, o + 0x60, v);
    QueueMessage_cMessageR_cSystemP_int(&ev, g_Game, 1);
    ev.vtable = D_004DADF0;
    cFileMan_dtor(&ev.req.b, -1);
    cFileMan_dtor(&ev.req.a, -1);
    cMessage_dtor(&ev, 0);
    F_(o, 0x1F0, unsigned char) = 0;
    return 0;
}
