#include "types.h"

typedef struct ActionArgs {
    void* obj;
    signed char action;
} ActionArgs;

extern void* func_003CB1C0(void* obj);
extern void Global_PerformAction(void* actor, int action);

/* Script native: PerformAction(obj, action). */
int Script_PerformAction(ActionArgs* args) {
    Global_PerformAction(func_003CB1C0(args->obj), args->action);
    return 0;
}
