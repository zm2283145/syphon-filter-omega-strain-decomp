#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_004FF120;
extern int func_0026F1D0();
unsigned char func_0026F2B0(void) {
    struct { long long buf; int a[2]; } L;
    int busy;
    unsigned char r = 0;
    unsigned char ok;
    busy = func_002E9A10();
    if (!busy) { ok = 0; do { if (!func_003C9C30(&L.buf)) break; if (func_002E9A98(&L.buf, L.a, 4, 1) != 0) break; ok = 1; } while (0); if (ok && !busy && NetMsg_RegisterType(&D_004FF120, 2, func_0026F1D0) == 0) r = 1; }
    return r;
}