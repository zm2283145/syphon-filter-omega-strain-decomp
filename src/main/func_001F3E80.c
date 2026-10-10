#include "types.h"
typedef struct { void* vt; char pad[0x20]; char x24[1]; } MS1F3E80;
extern char D_004DFBF0[];
extern void func_001F2420(void*, int);
extern void func_001F2A00(void*, int);
extern void operator_delete(void*);
MS1F3E80* MotionSlider_Dtor(MS1F3E80* self, short flag) {
    if (self) {
        self->vt = D_004DFBF0;
        func_001F2420(self->x24, -1);
        func_001F2A00(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}