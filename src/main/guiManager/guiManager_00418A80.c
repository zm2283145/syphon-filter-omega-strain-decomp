#include "types.h"
typedef struct { char pad[0x18]; unsigned short count; } E418A80;
extern E418A80* GuiManager_FindByName(void* a, void* b, void* c);
extern E418A80* GuiManager_CreateRoot(void* a, void* b, void* c);
E418A80* GuiManager_FindOrLoad(void* a, void* b, void* c) {
    E418A80* e = GuiManager_FindByName(a, b, c);
    if (e) {
        if (e->count) e->count++;
    } else {
        e = GuiManager_CreateRoot(a, b, c);
        if (e) e->count++;
    }
    return e;
}