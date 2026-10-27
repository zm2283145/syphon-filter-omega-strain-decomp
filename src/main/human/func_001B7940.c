#include "types.h"
typedef struct { unsigned char flag; char pad[3]; float t; } K_1B7940;
typedef struct { int cap; int count; K_1B7940* data; } KV_1B7940;
typedef struct { char pad[0x20]; char chan[0x38]; KV_1B7940 keys; } O_1B7940;
extern void std_vector_imp_cTargetZRotationStackSlot_insert(KV_1B7940* v, K_1B7940* pos, int n, K_1B7940* k);
extern K_1B7940* cArray_cTargetZRotationStackSlot_Back(KV_1B7940* v);
extern void cSplinedMotion_float_SetTargetVal(void* chan, float* t);
extern void cSplinedMotion_float_RestartTransition(void* chan, float d);
int cHumanMotionParams_PushTargetZRotationOnStack(O_1B7940* o, float t, float d)
{
    K_1B7940 k;
    k.t = t;
    k.flag = 1;
    std_vector_imp_cTargetZRotationStackSlot_insert(&o->keys, o->keys.data + o->keys.count, 1, &k);
    cSplinedMotion_float_SetTargetVal(o->chan, &cArray_cTargetZRotationStackSlot_Back(&o->keys)->t);
    cSplinedMotion_float_RestartTransition(o->chan, d);
    return o->keys.count - 1;
}
