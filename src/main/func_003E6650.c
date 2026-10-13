#include "types.h"

typedef struct ActionArgs {
    void* obj;
    signed char action;
} ActionArgs;

extern void* Script_ValueToObj(void* obj);
extern void Global_PerformAction(void* actor, int action);

/* Script native: PerformAction(obj, action). */
int Script_PerformAction(ActionArgs* args) {
    Global_PerformAction(Script_ValueToObj(args->obj), args->action);
    return 0;
}
