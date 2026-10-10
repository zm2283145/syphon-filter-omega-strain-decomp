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
extern char D_004FFB50[];
extern char D_004DADF0[];
extern void SoundEvent_Ctor(SoundEvent* ev, int id, int flags);
extern void Event_Send(SoundEvent* ev, void* target, int flags);
extern void func_0036E220(SoundPart* p, int flags);
extern void cMessage_dtor(SoundEvent* ev, int flags);

/* Builds a local sound event for id and sends it to the sound system; returns 1. */
int func_00465B50(void* self, int id)
{
    SoundEvent ev;
    SoundEvent_Ctor(&ev, id, 0);
    ev.local = 1;
    Event_Send(&ev, D_004FFB50, 1);
    ev.vtable = D_004DADF0;
    func_0036E220(&ev.b, -1);
    func_0036E220(&ev.a, -1);
    cMessage_dtor(&ev, 0);
    return 1;
}
