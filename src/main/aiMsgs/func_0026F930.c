#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_004FF108;
extern int cAINewAwarenessMsg_NetReceive();
typedef struct { long long buf; int a; char b; } L_0026F930;
/* Registers the cAINewAwarenessMsg network message (field formats, then the receive
 * handler cAINewAwarenessMsg_NetReceive). Returns 1 on success. */
unsigned char cAINewAwarenessMsg_NetRegister(void) {
    L_0026F930 L;
    unsigned char r = 0;
    unsigned char ok;
    if (!func_002E9A10()) {
        ok = 0;
        do {
            if (!func_003C9C30(&L.buf)) break;
            if (func_002E9A98(&L.buf, &L.a, 4, 1) != 0) break;
            ok = 1;
        } while (0);
        if (ok && func_002E9A98(&L.buf, &L.b, 1, 1) == 0 && NetMsg_RegisterType(&D_004FF108, 2, cAINewAwarenessMsg_NetReceive) == 0) r = 1;
    }
    return r;
}