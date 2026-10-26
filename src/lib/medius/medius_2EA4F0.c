#include "types.h"

extern int NetIRegisterMallocFreeCallbacks(void);

int NetRegisterMallocFreeCallbacks(void) {
    return NetIRegisterMallocFreeCallbacks();
}
