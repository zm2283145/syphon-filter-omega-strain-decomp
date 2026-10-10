#include "types.h"

/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma opt_common_subs off

typedef struct Obj3929 {
    char pad0000[0x60];
    char part60[0x2C04];    /* 0x0060 */
    void* current;          /* 0x2C64 */
    char pad2C68[0x1E8];
    char part2E50[4];       /* 0x2E50 */
} Obj3929;

extern void func_003A9F10(void* part);
extern void func_0038E100(void* part);
extern void Object_Activate(Obj3929* self, int arg);

/* Initializes the sub-parts and activates the object. */
void func_00392940(Obj3929* self, int arg) {
    func_003A9F10(self->part2E50);
    self->current = self->part2E50;
    func_0038E100(self->part60);
    Object_Activate(self, arg);
}

#pragma pop
