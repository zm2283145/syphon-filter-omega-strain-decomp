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
extern char D_004FFB50[];
extern char D_004DADF0[]; /* vtable used while tearing down */
extern void func_0020EBA0(Event* e, void* src, void* arg);
extern void Event_Send(Event* e, const char* name, int enable);
extern void func_0036E220(SubObj* s, int flags);
extern void cMessage_dtor(Event* e, int flags);

/* Builds a temporary event from self+0x10 and arg, dispatches it as D_004FFB50, then destroys it. */
void func_002395A0(char* self, void* arg)
{
    Event e;
    func_0020EBA0(&e, self + 0x10, arg);
    e.flag = 1;
    Event_Send(&e, D_004FFB50, 1);
    e.vtable = D_004DADF0;
    func_0036E220(&e.b, -1);
    func_0036E220(&e.a, -1);
    cMessage_dtor(&e, 0);
}
