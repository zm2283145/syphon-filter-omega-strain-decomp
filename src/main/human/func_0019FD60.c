#include "types.h"
extern void* func_001913D0(void* r);
extern int func_0019FDE0(void* v);
extern void** PtrVec_Back(void* v);
extern void func_0019FDF0(void* r, void* c);
void Root_ClearChildren(void* r)
{
    while (!func_0019FDE0(func_001913D0(r))) {
        func_0019FDF0(r, *PtrVec_Back(func_001913D0(r)));
    }
}