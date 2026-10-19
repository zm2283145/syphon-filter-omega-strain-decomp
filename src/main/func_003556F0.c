#include "types.h"

/* Event message built on the stack (C++ object with inlined destructor). */
typedef struct EventMsg {
    void* vtable;
    char pad04[0x1C];
    unsigned char immediate;    /* 0x20 */
    char pad21[0x57];
    char partA[0x9C];           /* 0x78 */
    char partB[0xBC];           /* 0x114 */
} EventMsg;

typedef struct ObjF4 {
    char pad[0xB0];
    char target[0x44];
    unsigned char pending;      /* 0xF4 */
} ObjF4;

extern int g_Game;
extern int D_004DADF0;
extern void SoundEvent_Ctor(EventMsg*, void*, int);
extern void Event_Send(EventMsg*, void*, int);
extern void FileMan_Release(void*, int);
extern void cMessage_dtor(EventMsg*, int);
extern void GuiWidget_BaseSleep(ObjF4*);
extern void* Fstream_GetLoader(void);
extern void FStream_CancelRequests(void*);
extern void Heap_ReleaseSlot(int);

/* Shutdown: base cleanup, sends an immediate event for the target, then notifies the singleton. */
void GuiPersonnelMenu_Sleep(ObjF4* o) {
    EventMsg msg;
    GuiWidget_BaseSleep(o);
    o->pending = 0;
    SoundEvent_Ctor(&msg, o->target, 0);
    msg.immediate = 1;
    Event_Send(&msg, &g_Game, 1);
    msg.vtable = &D_004DADF0;
    FileMan_Release(msg.partB, -1);
    FileMan_Release(msg.partA, -1);
    cMessage_dtor(&msg, 0);
    FStream_CancelRequests(Fstream_GetLoader());
    Heap_ReleaseSlot(1);
}
