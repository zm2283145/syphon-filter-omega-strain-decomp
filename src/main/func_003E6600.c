#include "types.h"

typedef struct ActionArgs3 {
    void* obj;
    signed char action;
    char pad5[3];
    int param;
} ActionArgs3;

extern void* func_003CB1C0(void* obj);
extern void Global_PerformAction_2(void* actor, int action, int param, int extra, float time);

/* Script native: PerformAction(obj, action, param). */
int Script_PerformAction_2(ActionArgs3* args) {
    volatile int paramSlot = args->param;
    Global_PerformAction_2(func_003CB1C0(args->obj), args->action, paramSlot, 0, -1.0f);
    return 0;
}
