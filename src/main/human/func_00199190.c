#include "types.h"
typedef struct { void* vtable; char base[0x20]; signed char value; signed char which; char pad26[2]; } Msg_199190;
extern char D_004EEE98[];
extern char D_004DA9D0[];
extern char D_004DCF10[];
extern void Event_Construct(Msg_199190* msg, void* name);
extern void cMessage_dtor(Msg_199190* msg, int flags);
extern signed char NetStream_ReadS8(void);
extern void Stream_ReadByte(signed char* out);
extern void func_001990F0(void* self, unsigned char v, int silent);
extern void func_00198F90(void* self, unsigned char v, int silent);
extern void func_00199040(void* self, unsigned char v, int silent);
void func_00199190(void* self)
{
    Msg_199190 msg;
    signed char* wp;
    signed char* vp;
    Event_Construct(&msg, D_004EEE98);
    msg.vtable = D_004DA9D0;
    wp = &msg.which;
    *wp = NetStream_ReadS8();
    vp = &msg.value;
    Stream_ReadByte(vp);
    if (self) {
        signed char w = *wp;
        if (w == 0) func_001990F0(self, *vp != 0, 1);
        else if (w == 2) func_00198F90(self, *vp != 0, 1);
        else if (w == 1) func_00199040(self, *vp != 0, 1);
    }
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
