#include "types.h"
typedef struct { char pad0[0x14]; int value; char pad1[0x4]; char item[0x1C]; } EDBB0;
typedef struct { EDBB0 e[(0x560) / 0x38]; char pad[0x560 - (0x560 / 0x38) * 0x38]; int count; } PDBB0;
typedef struct { PDBB0* p; } ODBB0;
extern int MemCardWrap_MatchName(void* key, void* item);
static inline int dbb0find(PDBB0* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((MemCardWrap_MatchName(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* Returns the value of the entry whose item matches key, or 0. */
int func_0040DBB0(ODBB0* o, void* key) {
    int i = dbb0find(o->p, key);
    if (i < 0)
        return 0;
    return o->p->e[i].value;
}