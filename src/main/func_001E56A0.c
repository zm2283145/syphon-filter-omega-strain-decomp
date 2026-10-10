#include "types.h"
extern void* Root_GetParent(void* r);
extern void* Root_GetWorldPose(void* r);
extern char* Root_Identity(void* r);
void* Root_GetPose(void* r) {
    if (Root_GetParent(r) != 0) {
        Root_GetWorldPose(r);
        return Root_Identity(r) + 0x30;
    }
    return Root_Identity(r) + 0x80;
}