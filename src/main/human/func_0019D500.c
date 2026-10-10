#include "types.h"
extern int Root_GetParent(void* self);
extern void Root_RefreshWorldCache(void* self);
extern char* Root_Identity(void* self);
void* Root_GetWorldQuat(void* self) {
    if (Root_GetParent(self)) {
        Root_RefreshWorldCache(self);
        return Root_Identity(self);
    }
    return Root_Identity(self) + 0x50;
}