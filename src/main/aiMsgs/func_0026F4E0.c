#include "types.h"
extern int func_002E9A10(void);
extern int func_003C9C30(void* p);
extern int func_002E9A98(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_004FF118;
extern int func_0026F400();
typedef struct { long long buf; int a[2]; } L4E0;

unsigned char func_0026F4E0(void) {
    L4E0 L;
    unsigned char r = 0;
    unsigned char ok;
    if (!func_002E9A10()) { ok = 0; do { if (!func_003C9C30(&L.buf)) break; if (func_002E9A98(&L.buf, L.a, 4, 1) != 0) break; ok = 1; } while (0); if (ok && NetMsg_RegisterType(&D_004FF118, 2, func_0026F400) == 0) r = 1; }
    return r;
}