#include "types.h"
extern void std_list_cSkaBlendSequenceItemPtr_begin(int* out);
extern void cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(void* obj, int* value);
/* Fetch a value with std_list_cSkaBlendSequenceItemPtr_begin and pass it to cConstLListIterator_cSkaBlendSequenceItemPtr_ctor. */
void cLList_cSkaBlendSequenceItemPtr_Begin(void* obj)
{
    int value;
    std_list_cSkaBlendSequenceItemPtr_begin(&value);
    cConstLListIterator_cSkaBlendSequenceItemPtr_ctor(obj, &value);
}
