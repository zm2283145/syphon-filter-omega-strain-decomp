#include "types.h"

extern void* IeNode_FindChild(void* p);
extern int IeElement_Create(void* obj);

/* Resolves an object with IeNode_FindChild and returns IeElement_Create of it, or 0 if none. */
int Hud_FindOrCreateElement(void* p)
{
    void* obj = IeNode_FindChild(p);
    if (obj)
        return IeElement_Create(obj);
    return 0;
}
