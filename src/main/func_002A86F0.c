#include "types.h"

typedef struct Entry20 {
    int value;
    int pad[4];
} Entry20;

typedef struct Selector {
    char pad[0x20];
    int current;
    char pad2[0x48 - 0x24];
    int state;
    char pad3[0x54 - 0x4C];
    int index;
    char pad4[0x68 - 0x58];
    Entry20 entries[1];
} Selector;

extern void func_0041EFA0(Selector* self);

/* Updates the base, then in state 5 copies the selected entry's value to current. */
void func_002A86F0(Selector* self) {
    func_0041EFA0(self);
    if (self->state == 5) {
        self->current = self->entries[self->index].value;
    }
}
