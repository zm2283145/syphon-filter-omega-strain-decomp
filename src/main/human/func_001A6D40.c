#include "types.h"
extern void Root_SetParent(void* child, void* parent);
extern void Root_ResetLocalBase(void* child);
void Root_Attach(void* parent, void* child, int reset) {
    Root_SetParent(child, parent);
    if (reset) {
        Root_ResetLocalBase(child);
    }
}