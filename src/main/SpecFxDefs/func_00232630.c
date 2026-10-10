#include "types.h"

typedef struct AtmosArgs {
    signed char type;
    char pad[3];
    int p1, p2, p3, p4; /* float parameters passed as raw words */
} AtmosArgs;

extern void func_00232BF0(int type, int id, float p1, float p2, float p3, float p4);

/* Script native: AtmosphericEffect(type, p1, p2, p3, p4). */
int Script_AtmosphericEffect(AtmosArgs* args) {
    float p1, p2, p3, p4;
    volatile int w4, w3, w2, w1;
    w4 = args->p4;
    p4 = *(float*)&w4;
    w3 = args->p3;
    p3 = *(float*)&w3;
    w2 = args->p2;
    p2 = *(float*)&w2;
    w1 = args->p1;
    p1 = *(float*)&w1;
    func_00232BF0(args->type, -1, p1, p2, p3, p4);
    return 0;
}
