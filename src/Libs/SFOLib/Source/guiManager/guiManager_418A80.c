#include "types.h"
typedef struct { char pad[0x18]; unsigned short count; } E418A80;
extern E418A80* GuiManager_FindOpenGui(void* a, void* b, void* c);
extern E418A80* GuiManager_ConstructGui(void* a, void* b, void* c);
E418A80* GuiManager_OpenGui(void* a, void* b, void* c) {
    E418A80* e = GuiManager_FindOpenGui(a, b, c);
    if (e) {
        if (e->count) e->count++;
    } else {
        e = GuiManager_ConstructGui(a, b, c);
        if (e) e->count++;
    }
    return e;
}