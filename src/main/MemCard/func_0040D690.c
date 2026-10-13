#include "types.h"
typedef struct { char pad[0x1C]; char item[0x1C]; } ED690;
typedef struct { ED690 e[(0x560) / 0x38]; char pad[0x560 - (0x560 / 0x38) * 0x38]; int count; } PD690;
typedef struct { PD690* p; } OD690;
extern int MemCardWrap_MatchName(void* key, void* item);
static inline int d690find(PD690* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((MemCardWrap_MatchName(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* True when some entry's item matches key. */
int func_0040D690(OD690* o, void* key) {
    return d690find(o->p, key) >= 0;
}


