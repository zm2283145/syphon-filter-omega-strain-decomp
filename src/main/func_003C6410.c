#include "types.h"
void nCollision_SyncAfterTransferDataToVu0(void) {
    asm {
        vnop
        sync
    }
}
