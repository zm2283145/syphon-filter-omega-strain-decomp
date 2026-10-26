#include "types.h"

extern void std_list_cSkaSwitchItemPtr_begin(int* out, int a1);
extern void cConstLListIterator_cSkaSwitchItemPtr_ctor(void* self, int* value);

/* Fetches a value with std_list_cSkaSwitchItemPtr_begin into a temporary and passes it to cConstLListIterator_cSkaSwitchItemPtr_ctor. */
void cLList_cSkaSwitchItemPtr_Begin(void* self, int a1)
{
    int value;
    std_list_cSkaSwitchItemPtr_begin(&value, a1);
    cConstLListIterator_cSkaSwitchItemPtr_ctor(self, &value);
}
