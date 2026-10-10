#include "types.h"

typedef struct { char pad[0x4C]; int id; } Slot;
extern char D_004ABF08[];
extern int sprintf(char* buf, const char* fmt, ...);
extern int func_0041DB80(void* self, const char* name);
extern void func_0041F150(void* self);

/* Looks up four numbered children by name into the ids at +0x4C, then finishes setup. */
void func_002B1B30(void* self)
{
    char buf[0x20];
    Slot* slot;
    int i;
    for (i = 0, slot = (Slot*)self; i < 4; i++) {
        sprintf(buf, D_004ABF08, i);
        slot->id = func_0041DB80(self, buf);
        slot = (Slot*)((int*)slot + 1);
    }
    func_0041F150(self);
}
