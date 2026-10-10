#include "types.h"

typedef struct { char pad[0x68]; void* p68; } Obj_42E0;
typedef struct { float v[4]; } Buf_42E0;
extern void func_00260D90(Buf_42E0* out, float t);
extern void func_003E7EE0(void* p, Buf_42E0* b);
extern void func_003F45A0(void* p, float f);

void func_002442E0(Obj_42E0* o, float t) {
    Buf_42E0 b;
    if (o->p68) {
        func_00260D90(&b, 1.0f - t);
        func_003E7EE0(o->p68, &b);
        if (t < 0.95f) func_003F45A0(o->p68, 15.0f * t);
        else func_003F45A0(o->p68, 15.0f);
    }
}