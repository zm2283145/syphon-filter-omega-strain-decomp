#include "types.h"

typedef struct { int value; } Temp;
extern void std_list_cSkaTransBLENDPtr_end(Temp* out);
extern void cConstLListIterator_cSkaTransBLENDPtr_ctor(void* self, Temp* in);

/* Builds a temporary with std_list_cSkaTransBLENDPtr_end and applies it to self. */
void cLList_cSkaTransBLENDPtr_End(void* self)
{
    Temp t;
    std_list_cSkaTransBLENDPtr_end(&t);
    cConstLListIterator_cSkaTransBLENDPtr_ctor(self, &t);
}
