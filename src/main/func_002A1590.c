#include "types.h"

typedef struct { char pad[0x40]; void* list; } Owner40;
typedef struct { char pad[0xDC]; void* widget; char padE0[0xF4 - 0xE0]; Owner40* owner; } Obj2A;
extern void* func_002A1A50(void* list, int a1, int a2, void* item);
extern void func_002A1670(Obj2A* self);
extern void* func_004147A0(void);
extern void func_0041E0F0(void* widget, void* ctx, int a2, int a3, int a4);

/* Adds item to the owner's list, refreshes self and pokes the widget with event 0x10. */
void func_002A1590(Obj2A* self, void* item)
{
    self->owner->list = func_002A1A50(self->owner->list, 2, 4, item);
    func_002A1670(self);
    func_0041E0F0(self->widget, func_004147A0(), 0x10, 0, 0);
}
