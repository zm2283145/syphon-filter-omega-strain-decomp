#include "types.h"
typedef struct { void* vtable; char base[0x20]; int id; unsigned char a; signed char b; char pad2A[6]; } Msg_187230;
extern char D_004EF008[];
extern char D_004DA990[];
extern char D_004DCF10[];
extern signed char* D_005061D0;
extern void Event_Construct(Msg_187230* msg, void* name);
extern void cMessage_dtor(Msg_187230* msg, int flags);
extern void func_00282160(int* out);
extern void func_00186F30(void* self, int id, int a, int b);
static inline void ReadU8_187230(unsigned char* out) { signed char v = *D_005061D0; D_005061D0++; *out = v; }
static inline void ReadS8_187230(signed char* out) { signed char v = *D_005061D0; D_005061D0++; *out = v; }
void func_00187230(void* self)
{
    Msg_187230 msg;
    Event_Construct(&msg, D_004EF008);
    msg.vtable = D_004DA990;
    func_00282160(&msg.id);
    ReadU8_187230(&msg.a);
    ReadS8_187230(&msg.b);
    func_00186F30(self, msg.id, msg.a, msg.b);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}

