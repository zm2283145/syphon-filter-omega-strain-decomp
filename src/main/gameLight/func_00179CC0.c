#include "types.h"
#pragma cplusplus on
struct Light_e1;
typedef void (*LightFn_e1)(Light_e1*);
class LightV_e1 { public: int pad; virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void Disable(); };
struct Light_e1 { int pad; LightFn_e1* vt; int id; };
extern LightFn_e1 D_004DA070[];
extern LightFn_e1 D_004D9240[];
extern LightFn_e1 D_004D9280[];
extern char D_00535D62;
extern char D_00535D20[];
extern "C" void func_00373D70(void*, Light_e1*);
extern "C" Light_e1* func_00179CC0(Light_e1* self, short reg)
{
    if (self != 0) {
        self->vt = D_004DA070;
        if (self != 0) {
            self->vt = D_004D9240;
            self->id = -1;
            ((LightV_e1*)self)->Disable();
            D_00535D62 = 1;
            if (self != 0) {
                self->vt = D_004D9280;
            }
        }
        if (reg > 0) {
            func_00373D70(D_00535D20, self);
        }
    }
    return self;
}