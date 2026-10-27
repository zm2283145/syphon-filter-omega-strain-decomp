#include "types.h"

extern void std_list_cSkaTransBLENDPtr_begin(int* out);
extern void cConstLListIterator_cSkaTransBLENDPtr_ctor(void* self, int* value);

/* Fetches a value via std_list_cSkaTransBLENDPtr_begin and applies it to self via cConstLListIterator_cSkaTransBLENDPtr_ctor. */
void cLList_cSkaTransBLENDPtr_Begin(void* self) {
    int value;
    std_list_cSkaTransBLENDPtr_begin(&value);
    cConstLListIterator_cSkaTransBLENDPtr_ctor(self, &value);
}
