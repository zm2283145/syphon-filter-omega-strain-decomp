/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Runtime array constructor: (array, ctor, dtor, element size, count). */
extern int __construct_array(void* array, void* ctor, void* dtor, int size, int count);
extern int cXViewport_ctor(void*);
extern List* std_list_deleter_tDataDelRec_ctor(List*);
extern int cUserFrameEnv_dtor(int, int);
extern int cUserFrameEnv_ctor(int);

/* Constructor: 8 sub-objects, two counters, six Slot20 entries. */
Manager37F9D0* XLib_ctor(Manager37F9D0* self) {
    char* item;

    self->unk00 = -1;
    item = self->items[0];
    do {
        cXViewport_ctor(item);
        item += 272;
    } while (item != self->items[8]);
    self->unk1058 = 0;
    self->unk105C = 0;
    __construct_array(self->slots, cUserFrameEnv_ctor, cUserFrameEnv_dtor, 20, 6);
    std_list_deleter_tDataDelRec_ctor(&self->unk1108);
    return self;
}
