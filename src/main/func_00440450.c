#include "types.h"
#include "message_pack.h"
extern int D_00583998;
extern void printf(char* s);
int NetLevelInfoMsg_Send(void* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    int r = -1;
    if (sz >= 12 && buf) {
        char* b = (char*)buf;
        Event_PackHeader(e, a1, type, a3, a4, sz, buf);
        MP_I(b, 8) = MP_I(e, 0x24);
        if (type) {
            r = 12;
            *type = D_00583998;
        }
    }
    printf("\n\n*** cNetLevelInfoMsg: sending\n");
    return r;
}