/*
 * Libs/SFOLib/Source/xlib: 2 files, 0037F950-0037F9D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0037F950 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* List destructor (three inlined null tests): erase [first, sentinel), then delete. */
struct N37F950;
struct L37F950 { int count; N37F950* sentinelPrev; N37F950* first; };
extern "C" {
void operator_delete(void* allocation);
void std_list_deleter_tDataDelRec_erase_listdeleter_listdeleter(N37F950** result, L37F950* self, N37F950** first, N37F950** last);
}
extern "C" L37F950* std_list_tDataDelRec_dtor(L37F950* self, short deleteFlag)
{
    if (self) {
        if (self) {
            if (self) {
                N37F950* result;
                N37F950* first;
                N37F950* last;
                last = (N37F950*)&self->sentinelPrev;
                first = self->first;
                std_list_deleter_tDataDelRec_erase_listdeleter_listdeleter(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0037F950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037F950 */

/* merge_units: begin func_0037F9D0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0037F9D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0037F9D0 */
