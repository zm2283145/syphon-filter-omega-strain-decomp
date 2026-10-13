#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_004FF0F0;
extern int cAIDeadMsg_NetReceive();
/* Registers the cAIDeadMsg network message (field formats, then the receive
 * handler cAIDeadMsg_NetReceive). Returns 1 on success. */
unsigned char cAIDeadMsg_NetRegister(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (func_002E9A10() == 0 && func_003C9C30(buf) != 0 && func_002E9A98(buf, ok, 4, 1) == 0 &&
        NetMsg_RegisterType(&D_004FF0F0, 2, cAIDeadMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
