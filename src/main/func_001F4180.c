#include "types.h"

extern void std_list_cSkaBlendSequenceItemPtr_end(int*);
extern void cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(void*, int*);

/* Fetches a value via std_list_cSkaBlendSequenceItemPtr_end and passes it to cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(self, &value). */
void cLList_cSkaBlendSequenceItemPtr_End(void* self) {
    int value;
    std_list_cSkaBlendSequenceItemPtr_end(&value);
    cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(self, &value);
}
