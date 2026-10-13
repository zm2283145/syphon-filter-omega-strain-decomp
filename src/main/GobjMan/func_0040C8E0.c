#include "types.h"
extern void GobjScopeBase_Dtor(void* self, short del);
extern void operator_delete(void* p);
/* Scope destructor: run the base destructor, then delete when del > 0. */
void* GobjScope_Dtor(void* self, short del)
{
    if (self) {
        GobjScopeBase_Dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}