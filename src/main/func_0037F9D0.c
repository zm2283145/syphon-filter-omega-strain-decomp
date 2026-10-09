/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Runtime array constructor: (array, ctor, dtor, element size, count). */
extern int func_001004B0(void* array, void* ctor, void* dtor, int size, int count);
extern int func_003755C0(void*);
extern List* func_0037FE80(List*);
extern int func_003BB2F0(int, int);
extern int func_003BB340(int);

/* Constructor: 8 sub-objects, two counters, six Slot20 entries. */
Manager37F9D0* func_0037F9D0(Manager37F9D0* self) {
    char* item;

    self->unk00 = -1;
    item = self->items[0];
    do {
        func_003755C0(item);
        item += 272;
    } while (item != self->items[8]);
    self->unk1058 = 0;
    self->unk105C = 0;
    func_001004B0(self->slots, func_003BB340, func_003BB2F0, 20, 6);
    func_0037FE80(&self->unk1108);
    return self;
}
