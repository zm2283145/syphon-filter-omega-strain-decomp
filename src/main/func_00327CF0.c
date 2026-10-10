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
extern void func_0041EBF0(Screen* self);
extern void SoundEvent_Ctor(Event* e, void* src, int a2);
extern void Event_Send(Event* e, const char* name, int enable);
extern void func_0036E220(SubObj* s, int flags);
extern void cMessage_dtor(Event* e, int flags);
extern void* func_003EBA50(void);
extern void func_003EB750(void* p);
extern void func_0036B250(int a0);

/* Closes the screen: base handler, dispatches a close event, then resets global state. */
void func_00327CF0(Screen* self)
{
    Event e;
    func_0041EBF0(self);
    self->active = 0;
    SoundEvent_Ctor(&e, self->ev, 0);
    e.flag = 1;
    Event_Send(&e, D_004FFB50, 1);
    e.vtable = D_004DADF0;
    func_0036E220(&e.b, -1);
    func_0036E220(&e.a, -1);
    cMessage_dtor(&e, 0);
    func_003EB750(func_003EBA50());
    func_0036B250(1);
    self->state = -1;
}
