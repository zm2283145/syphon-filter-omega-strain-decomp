#include "types.h"
typedef struct { int pad0; int pad4; int id; int padC; } Slot_39B0;
typedef struct { Slot_39B0 slots[6]; } S_39B0;
int func_00143BC0(S_39B0* self);
void func_00143B60(S_39B0* self);
int func_00143D20(int id);
void func_00142C50(S_39B0* self, int slot);
unsigned char func_001439B0(S_39B0* self, int id)
{
    unsigned char r = 0;
    if (func_00143BC0(self)) {
        if (id == -1) {
            func_00143B60(self);
            r = 1;
        } else {
            int slot = func_00143D20(id);
            int* p = (int*)((char*)&self->slots[0].id + ((unsigned char)slot << 4));
            if (id == *p) {
                func_00142C50(self, slot);
                r = (id == *p);
            }
        }
    }
    return r;
}