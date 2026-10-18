#include "types.h"

typedef struct { char data[0x9C]; } SubObj;
typedef struct {
    void* vtable;          /* +0x00 */
    char pad04[0x20 - 4];
    unsigned char flag;    /* +0x20 */
    char pad21[0x78 - 0x21];
    SubObj a;              /* +0x78 */
    SubObj b;              /* +0x114 */
    char pad1B0[0x1D0 - 0x1B0];
} Event; /* 0x1D0-byte stack object */
typedef struct {
    char pad[0x58];
    int state;             /* +0x58 */
    char pad5C[0x90 - 0x5C];
    char ev[0x44];         /* +0x90 */
    unsigned char active;  /* +0xD4 */
} Screen;
extern char D_004FFB50[];
extern char D_004DADF0[];
extern void GuiWidget_BaseSleep(Screen* self);
extern void SoundEvent_Ctor(Event* e, void* src, int a2);
extern void Event_Send(Event* e, const char* name, int enable);
extern void FileMan_Release(SubObj* s, int flags);
extern void cMessage_dtor(Event* e, int flags);
extern void* Fstream_GetLoader(void);
extern void FStream_CancelRequests(void* p);
extern void Heap_ReleaseSlot(int a0);

/* Closes the screen: base handler, dispatches a close event, then resets global state. */
void GuiSlideShow_Sleep(Screen* self)
{
    Event e;
    GuiWidget_BaseSleep(self);
    self->active = 0;
    SoundEvent_Ctor(&e, self->ev, 0);
    e.flag = 1;
    Event_Send(&e, D_004FFB50, 1);
    e.vtable = D_004DADF0;
    FileMan_Release(&e.b, -1);
    FileMan_Release(&e.a, -1);
    cMessage_dtor(&e, 0);
    FStream_CancelRequests(Fstream_GetLoader());
    Heap_ReleaseSlot(1);
    self->state = -1;
}
