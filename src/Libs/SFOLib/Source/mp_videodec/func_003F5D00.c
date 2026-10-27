#include "types.h"

extern void viBufDelete(void* member);
extern void sceMpegDelete(void* self);

/* Releases the member at +0x48, then the object itself; returns 1. */
int videoDecDelete(char* self) {
    viBufDelete(self + 0x48);
    sceMpegDelete(self);
    return 1;
}
