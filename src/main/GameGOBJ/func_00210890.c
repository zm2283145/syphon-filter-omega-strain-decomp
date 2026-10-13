#include "types.h"
#define SOUND_EVENT_NO_PROTOS
#include "sound_event.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern int D_004FFC0C;
extern char D_004FFB50[];
extern char D_004DADF0[];
extern void func_0020EBA0(SoundEvent* ev, void* src, void* voice);

int Script_cSoundGOBJ_KillSnd(void** arg0) {
    SoundEvent ev;
    char* o = *arg0;
    char* v;
    if (F_(o, 0x1F2, unsigned char)) v = o;
    else if (D_004FFC0C) v = 0;
    else v = o;
    func_0020EBA0(&ev, o + 0x60, v);
    Event_Send(&ev, D_004FFB50, 1);
    ev.vtable = D_004DADF0;
    func_0036E220(&ev.req.b, -1);
    func_0036E220(&ev.req.a, -1);
    cMessage_dtor(&ev, 0);
    F_(o, 0x1F0, unsigned char) = 0;
    return 0;
}
