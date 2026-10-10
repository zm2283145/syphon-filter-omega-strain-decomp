#include "types.h"
typedef struct HdrBitsEP { unsigned int type : 2; unsigned int time : 30; } HdrBitsEP;
typedef union HdrEP { HdrBitsEP b; unsigned int raw; } HdrEP;
typedef struct PacketEP { unsigned int hdr; int data; } PacketEP;
typedef struct EventEP { char pad[0x18]; int type; } EventEP;
extern unsigned int func_0042B1A0(int a);
int Event_PackHeader(EventEP* e, int data, int a2, int a3, int a4, unsigned int size, void* buf)
{
    HdrEP h;
    if (size >= 8 && buf) {
        PacketEP* out = (PacketEP*)buf;
        if (e->type < 4) {
            h.b.type = e->type;
        } else {
            h.b.type = 3;
        }
        h.b.time = func_0042B1A0(0);
        out->hdr = h.raw;
        out->data = data;
    }
    return -1;
}