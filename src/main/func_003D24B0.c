#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Base_24B0 { char pad[0x10]; };
struct Obj_24B0 : Base_24B0 { virtual void Update(float); virtual void Reset(); };
struct Raw_24B0 { int p; };
struct S_24B0 { int a, b, c; unsigned char dirty; };
extern "C" {
Raw_24B0 func_0013B180(void*);
Raw_24B0 func_003D2610(void*);
void func_003D2620(char**, const Raw_24B0&);
void func_003D2600(char**, const Raw_24B0&);
}
extern "C" void func_003D24B0(S_24B0* self, float dt) {
    char* end1;
    char* end2;
    if (self->dirty) {
        char* it;
        char* n;
        func_003D2620(&it, func_0013B180(self));
        n = it;
        while ((func_003D2600(&end1, func_003D2610(self)), n != end1)) {
            F_(n, 0x8, Obj_24B0*)->Reset();
            n = F_(n, 0x4, char*);
        }
        self->dirty = 0;
    }
    {
        char* it;
        char* n;
        func_003D2620(&it, func_0013B180(self));
        n = it;
        while ((func_003D2600(&end2, func_003D2610(self)), n != end2)) {
            F_(n, 0x8, Obj_24B0*)->Update(dt);
            n = F_(n, 0x4, char*);
        }
    }
}