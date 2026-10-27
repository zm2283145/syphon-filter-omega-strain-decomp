#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Factory: allocate a 0xA8-byte GuiScreen-derived object and construct it inline. */
extern "C" {
extern char D_004DEB10[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiLobbyScreen_ctor(void* self);
}
struct O349CA0 { void* vtable; char pad[0x80]; int a84; int a88; char pad8C[0x10]; int a9C; };
extern "C" O349CA0* GuiNetMessages_Create(void)
{
    O349CA0* p;
    {
        AllocGuard guard;
        p = (O349CA0*)cMemMan_Allocate(0, 0xA8, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiLobbyScreen_ctor(p);
        p->vtable = D_004DEB10;
        p->a84 = 9;
        p->a88 = 0;
        p->a9C = -1;
    }
    return p;
}