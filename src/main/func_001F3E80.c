#include "types.h"
typedef struct { void* vt; char pad[0x20]; char x24[1]; } MS1F3E80;
extern void MotionSlider_Evaluate();
extern void func_003B4630();
extern void * const D_004DFBF0[];
extern void func_001F2420(void*, int);
extern void func_001F2A00(void*, int);
extern void operator_delete(void*);
MS1F3E80* MotionSlider_Dtor(MS1F3E80* self, short flag) {
    if (self) {
        self->vt = ((char*)D_004DFBF0);
        func_001F2420(self->x24, -1);
        func_001F2A00(self, 0);
        if (flag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DFBF0[8] = { (void*)0x0, (void*)0x0, (void*)MotionSlider_Dtor, (void*)MotionSlider_Evaluate, (void*)func_003B4630, (void*)0x0, (void*)0x0, (void*)0x0 };
