#include "loose05_types.h"

/* Initialize an empty lookup table without touching its inline storage. */
Lookup43FDD0* func_0043FDD0(Lookup43FDD0* self) {
    int index;
    self->count = 0;
    for (index = 0; index < 256; index++) {
        self->pages[index] = 0;
    }
    return self;
}
