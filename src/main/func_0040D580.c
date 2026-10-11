#include "types.h"
typedef struct { char pad[0x59F]; unsigned char flag; } CD580;
typedef struct { CD580* cfg; } OD580;
/* Number of 1 KB blocks needed for a payload, plus overhead. */
int func_0040D580(OD580* o, int bytes) {
    int n = (bytes + 0x3FF) / 1024 + 1;
    if (!o->cfg->flag)
        n += 0x2E;
    else if (bytes == 0)
        n = 0;
    return n;
}
