#include "types.h"

typedef struct { char pad[0x20]; int value; } Child;
typedef struct { char pad[0x54]; int value; char pad2[0x20]; Child* child; } Obj;
extern void* func_00414790(void);
extern int func_00418420(void* mgr, int key);

/* Resolves a value by key and propagates it to the child. */
void func_0041C010(Obj* self, int key)
{
    self->value = func_00418420(func_00414790(), key);
    if (self->child) {
        self->child->value = self->value;
    }
}
