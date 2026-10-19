#include "types.h"
typedef struct { unsigned char flag; char pad[3]; float t; } K_1B7940;
typedef struct { int cap; int count; K_1B7940* data; } KV_1B7940;
typedef struct { char pad[0x20]; char chan[0x38]; KV_1B7940 keys; } O_1B7940;
extern void Vector_Insert_1BE090(KV_1B7940* v, K_1B7940* pos, int n, K_1B7940* k);
extern K_1B7940* func_001B79D0(KV_1B7940* v);
extern void func_001B79C0(void* chan, float* t);
extern void AnimChannel_SetDuration(void* chan, float d);
int func_001B7940(O_1B7940* o, float t, float d)
{
    K_1B7940 k;
    k.t = t;
    k.flag = 1;
    Vector_Insert_1BE090(&o->keys, o->keys.data + o->keys.count, 1, &k);
    func_001B79C0(o->chan, &func_001B79D0(&o->keys)->t);
    AnimChannel_SetDuration(o->chan, d);
    return o->keys.count - 1;
}
