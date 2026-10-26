#include "types.h"

extern int sce_sync(int);

int sceNetcnfifSync(int a0) {
    return sce_sync(a0);
}
