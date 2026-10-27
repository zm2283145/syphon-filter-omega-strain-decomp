#include "types.h"

extern void std_list_cSkaSwitchItemPtr_end(int* out);
extern void cConstLListIterator_cSkaSwitchItemPtr_ctor(void* self, int* value);

/* Fetches a value with std_list_cSkaSwitchItemPtr_end and passes it to cConstLListIterator_cSkaSwitchItemPtr_ctor. */
void cLList_cSkaSwitchItemPtr_End(void* self)
{
    int value;
    std_list_cSkaSwitchItemPtr_end(&value);
    cConstLListIterator_cSkaSwitchItemPtr_ctor(self, &value);
}
