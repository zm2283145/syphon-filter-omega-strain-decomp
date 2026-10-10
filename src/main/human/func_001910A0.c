#include "types.h"
typedef struct RootObj RootObj;
extern void* Root_GetParent(RootObj* r);
extern void Root_RefreshWorldCache(RootObj* r);
extern char* Root_Identity(RootObj* r);
char* Root_ResolveWorldPlacement(RootObj* r) {
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        return Root_Identity(r);
    }
    return Root_Identity(r) + 0x50;
}